/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"

// Mod-Tap: Tap for KC_ESC, hold for KC_LCTL
#define KC_CTES LCTL_T(KC_ESC) // MT(MOD_LCTL, KC_ESC)

// Mod-Tap: Tap for KC_SPC, hold for KC_LSFT
// This is unused as of February 13, 2025.
// #define KC_LSSP LSFT_T(KC_SPC)

// Mod-Tap: Tap for KC_F24 and hold for KC_RSFT.
// This is used only for macOS to switch input sources (e.g., English and Japanese).
#define KC_RS24 RSFT_T(KC_F24) // MT(MOD_LSFT | MOD_RSFT, KC_F24)

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
    FN3, // New layer, but I have no way to activate it.
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,        KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,           KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,        KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_PGUP,
        KC_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                 KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGDN,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,        KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RS24, KC_UP,
        MO(MAC_FN1), KC_LOPT,        KC_LCMMD,         KC_SPC,  MO(MAC_FN1), MO(FN2),  KC_SPC,  KC_RCMMD,                              KC_LEFT, KC_DOWN,  KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_69(
        KC_GRV,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,        KC_7,     KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,           KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,        KC_U,     KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,           KC_PGUP,
        KC_CTES, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,                 KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,            KC_PGDN,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,        KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        MO(FN2), KC_LALT,            KC_LWIN,          KC_SPC,  MO(WIN_FN1), MO(FN3),  KC_SPC,  KC_RWIN,                               KC_LEFT, KC_DOWN,  KC_RGHT),

    [MAC_FN1] = LAYOUT_ansi_69(
        _______, KC_BRID,  KC_BRIU,  KC_MCTRL,KC_F23,  RGB_VAD, RGB_VAI,     KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,            RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,  _______,  _______,     _______, _______,  _______, _______,  _______,  _______,  _______,           KC_HOME,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,              KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,           KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,     _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,            _______,          _______, _______,     _______,  KC_ENT,  _______,                               _______, _______,  _______),

    // [WIN_FN1] = LAYOUT_ansi_69(
    //     _______, KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,     KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,            RGB_TOG,
    //     _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______,     _______, _______,  _______, _______,  _______,  _______,  _______,           KC_HOME,
    //     RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI,              KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,           KC_END,
    //     _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,     _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
    //     _______, _______,            _______,          _______, _______,     _______,  KC_ENT,  _______,                               _______, _______,  _______),

    [WIN_FN1] = LAYOUT_ansi_69(
        _______, KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI,     KC_MPRV,  KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,            RGB_TOG,
        _______, BT_HST1,  KC_UP,  BT_HST3, P2P4G,   _______, _______,     KC_HOME, _______,  KC_END, _______,  _______,  _______,  _______,           KC_HOME,
        RGB_TOG, KC_LEFT,  KC_DOWN,  KC_RGHT, RGB_SAI, RGB_SPI,              KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,  _______,  _______,  _______,           KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,     _______,  NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,            _______,          _______, _______,     _______,  KC_ENT,  _______,                               _______, _______,  _______),

    [FN2] = LAYOUT_ansi_69(
        KC_F24,  KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,           _______,
        _______, BT_HST1,  BT_HST2,  KC_END,  P2P4G,   _______, _______,     _______,  _______, _______, KC_UP,    _______,  _______,  _______,           _______,
        _______, KC_HOME,  _______,  KC_DEL,  KC_RGHT, _______,              KC_BSPC,  _______, _______, _______,  _______,  _______,  _______,           _______,
        _______,           _______,  _______, _______, _______, KC_LEFT,     KC_LEFT, KC_DOWN,  _______, _______,  _______,  _______,  _______, _______,
        _______, _______,            _______,          KC_BSPC, _______,     _______,  _______, _______,                               _______, _______,  _______),

    [FN3] = LAYOUT_ansi_69(
        _______, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,    KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,           _______,
        _______, BT_HST1,  BT_HST2,  _______, P2P4G,   _______, _______,     _______,  _______, _______,  _______,  _______,  _______, DT_PRNT,           _______,
        _______, _______,  _______,  _______, _______, _______,              _______,  _______, _______,  _______,  _______,  _______, _______,           _______,
        _______,           _______,  _______, _______, _______, _______,     _______,  _______, _______,  _______,  _______,  _______, _______, _______,
        _______, _______,  _______,           _______,          _______,     _______,           _______,            _______,           _______, _______,  _______)
};

// Rotary encoder is used to dynamically set TAPPING_TERM.
// Use the MO(4) key to increase/decrease the TAPPING_TERM.
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [MAC_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN1]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]      = {ENCODER_CCW_CW(DT_DOWN, DT_UP)},
    [FN3]      = {ENCODER_CCW_CW(DT_UP, DT_DOWN)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}
