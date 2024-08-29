#include QMK_KEYBOARD_H

#define BASE_LAYER_TIMEOUT 5000 // configure your timeout in milliseconds

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _CMD,
    _MED,
    _FNP,
    _FNI
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_3x3(
        TG(_MED),         TG(_FNP),   TG(_FNI), \
        LT(_CMD, KC_DEL), KC_UP,      KC_ESC, \
        KC_LEFT,          KC_DOWN,    KC_RIGHT \
    ),

    // extra commands
    [_CMD] = LAYOUT_ortho_3x3(
        QK_BOOT,       KC_PWR,       KC_SLEP,
        KC_TRNS,       KC_ENT,       KC_PGUP,
        KC_WAKE,       KC_SPACE,     KC_PGDN
    ),

    // media layer
    [_MED] = LAYOUT_ortho_3x3(
        KC_TRNS,      KC_TRNS,       KC_TRNS,
        KC_MUTE,      KC_VOLU,       KC_MPLY,
        KC_MPRV,      KC_VOLD,       KC_MNXT
    ),

    // function keys odd
    [_FNP] = LAYOUT_ortho_3x3(
        KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_F8,      KC_F10,     KC_F12,
        KC_F2,      KC_F4,      KC_F6
    ),

    // function keys odd
    [_FNI] = LAYOUT_ortho_3x3(
        KC_TRNS,    KC_TRNS,   KC_TRNS,
        KC_F7,      KC_F9,     KC_F11,
        KC_F1,      KC_F3,     KC_F5
    ),

    // numpad layer (disabled)
    //[_NUM] = LAYOUT_ortho_3x3(
    //    KC_7,       KC_8,       KC_9,
    //    KC_4,       KC_8,       KC_6,
    //    KC_1,       KC_2,       LT(1, KC_3)
    //),

    //// numpad operations layer (disabled)
    //[_NUMOP] = LAYOUT_ortho_3x3(
    //    KC_ESC,   KC_PLUS, KC_MINS,
    //    KC_ENTER, KC_ASTR, KC_SLSH,
    //    KC_0,     KC_DOT,  KC_TRNS
    //)

};

/*
 * ROTARY ENCODER
 */

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_CMD]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_MED]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [_FNP]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [_FNI]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)}
};

#endif
