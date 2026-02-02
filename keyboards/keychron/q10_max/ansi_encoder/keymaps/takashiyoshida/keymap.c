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

// Mod-Tap: Tap for KC_ESC and hold for KC_LCTL
#define MT_CTES LCTL_T(KC_ESC) // MT(MOD_LCTL, KC_ESC)

// Mod-Tap: Tap for KC_SPC and hold for KC_LSFT
// This is unused as of February 13, 2025.
// I could not get consistent results with this. I'd have random title-cased sentences.
#define MT_LSSP LSFT_T(KC_SPC) // MOD(MOD_LSFT, KC_SPC)?

// Mod-Tap: Tap for KC_F24 and hold for KC_RSFT
// This is used only for macOS to switch input languages (e.g., English and Japanese)
#define MT_RS24 RSFT_T(KC_F24) // MT(MOD_LSFT | MOD_RSFT, KC_F24)

// Home Row Mod
// Taken from [A guide to home row mods](https://precondition.github.io/home-row-mods#gacs)
// CAGS: Ctrl, Alt, Gui, Shift, recommended for macOS
#define MT_CTLA LCTL_T(KC_A)
#define MT_OPTS LOPT_T(KC_S)
#define MT_CMDD LCMD_T(KC_D)
#define MT_SFTF LSFT_T(KC_F)

#define MT_SFTJ RSFT_T(KC_J)
#define MT_CMDK RCMD_T(KC_K)
#define MT_OPTL ROPT_T(KC_L)
#define MT_CTLS RCTL_T(KC_SCLN)

// GACS: Gui, Alt, Ctrl, Shift, recommended for Windows
#define MT_WINA LWIN_T(KC_A)
#define MT_ALTS LALT_T(KC_S)
#define MT_CTLD LCTL_T(KC_D)
// #define MT_SFTF LSFT_T(KC_F) // This is the same for both macOS and Windows

// #define MT_SFTJ RSFT_T(KC_J) // This is the same for both macOS and Windows
#define MT_CTLK RCTL_T(KC_K)
#define MT_ALTL RALT_T(KC_L)
#define MT_WINS RWIN_T(KC_SCLN)

// TODO: I need to come up with how to activate MAC_HRMD and WIN_HRMD.
enum layers {
    MAC_BASE, // macOS base layer
    MAC_FN,
    WIN_BASE, // Windows base layer
    WIN_FN,
    FN2,      // Function layer 2
    MAC_HRMD, // Home Row Mod for macOS
    WIN_HRMD, // Home Row Mod for Windows
};

// clang-format off
// To use the DT_PRNT key, you need to set DYNAMIC_TAPPING_TERM_ENABLE = yes in rules.mk.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_90(
        KC_MUTE,    KC_F24,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_F23, RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_F5,              _______,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       MT_CTES,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             MO(FN2),
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MT_RS24,  KC_UP,
        MC_5,       MO(MAC_FN), KC_LOPT,          KC_LCMMD, KC_SPC,  MO(MAC_FN),                     KC_SPC,             KC_RCMMD, KC_ROPT,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_90(
        RGB_TOG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_DEL,             KC_HOME,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            KC_END,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       KC_ENT,             _______,  _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_90(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,             KC_F14,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       MT_CTES,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             MO(FN2),
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       MO(WIN_FN), KC_LALT,          KC_LWIN,  KC_SPC,   MO(WIN_FN),                    KC_SPC,             KC_RWIN,  KC_RALT,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    // [WIN_FN] = LAYOUT_ansi_90(
    //         RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
    //         _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_DEL,             KC_HOME,
    //         _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            KC_END,
    //         _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,             _______,            _______,
    //         _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
    //         _______,    _______,  _______,            _______,  _______,  _______,                       KC_ENT,             _______,  _______,             _______,  _______,  _______),
    
    [WIN_FN] = LAYOUT_ansi_90(
        RGB_TOG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_DEL,             KC_HOME,
        _______,    RGB_TOG,  RGB_MOD,  KC_UP,    RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  KC_HOME,  _______,  KC_END,   _______,  _______,   _______,  _______,            KC_END,
        _______,    _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  RGB_SAD,  RGB_SPD,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,             _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       KC_ENT,             _______,  _______,             _______,  _______,  _______),

    [FN2] = LAYOUT_ansi_90(
        RGB_TOG,    DT_PRNT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,                       _______,            _______,  _______,            _______,  _______,  _______),

    [MAC_HRMD] = LAYOUT_ansi_90(
        KC_MUTE,    KC_F24,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_F23, RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_F5,              _______,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       MT_CTES,  MT_CTLA,  MT_OPTS,  MT_CMDD,  MT_SFTF,  KC_G,      KC_H,     MT_SFTJ,  MT_CMDK,  MT_OPTL,  MT_CTLS,  KC_QUOT,            KC_ENT,             MO(FN2),
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  MT_RS24,  KC_UP,
        MC_5,       MO(MAC_FN), KC_LOPT,          KC_LCMMD, KC_SPC,  MO(MAC_FN),                     KC_SPC,             KC_RCMMD, KC_ROPT,            KC_LEFT,  KC_DOWN,  KC_RGHT),
            
    [WIN_HRMD] = LAYOUT_ansi_90(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,             KC_F14,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       MT_CTES,  MT_WINA,  MT_ALTS,  MT_CTLD,  MT_SFTF,  KC_G,      KC_H,     MT_SFTJ,  MT_CTLK,  MT_ALTL,  MT_WINS,  KC_QUOT,            KC_ENT,             MO(FN2),
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       MO(WIN_FN), KC_LALT,          KC_LWIN,  KC_SPC,   MO(WIN_FN),                    KC_SPC,             KC_RWIN,  KC_RALT,            KC_LEFT,  KC_DOWN,  KC_RGHT),

};

#if defined(ENCODER_MAP_ENABLE)
// To use the DT_UP and DT_DOWN keys, you need to set DYNAMIC_TAPPING_TERM_ENABLE = yes in rules.mk.
// Turning the encoder knob to the left decreases the current tapping term by 5.
// Turning the encoder knob to the right increases the current tapping term by 5.
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]      = {ENCODER_CCW_CW(DT_DOWN, DT_UP)},
    [MAC_HRMD] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [WIN_HRMD] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}

// Define TAPPING_TERM_PER_KEY in config.h if you want to set a different tapping term for each key.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}
