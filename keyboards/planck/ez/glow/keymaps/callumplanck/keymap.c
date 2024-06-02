#include QMK_KEYBOARD_H

#include "g/keymap_combo.h"

// layers mods
#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_NUM MO(_NUM)

// home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)


enum planck_layers {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
};

enum planck_keycodes {
    BASE = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12(
    KC_Q,     KC_W,     KC_E,     KC_R,               KC_T,              XXXXXXX,  XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HOME_A,   HOME_S,   HOME_D,   HOME_F,             KC_G,              XXXXXXX,  XXXXXXX,  KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,               KC_B,              XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  LT(LA_NAV, KC_BSPC), LT(LA_SYM, KC_ESC),   XXXXXXX,  XXXXXXX,  LT(LA_NUM, KC_ENT),  LT(LA_SYM, KC_SPC),  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_SYM] = LAYOUT_ortho_4x12(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX,  XXXXXXX,  KC_EQL,   KC_GRV,   KC_LPRN,  KC_RPRN,  KC_PLUS,
    KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  KC_CIRC,  XXXXXXX,  XXXXXXX,  KC_ASTR,  KC_COLN,  KC_LBRC,  KC_RBRC,  KC_MINS,
    _______,  _______,  KC_BSLS,  KC_PIPE,  KC_AMPR,  XXXXXXX,  XXXXXXX,  KC_TILD,  KC_SCLN,  KC_LCBR,  KC_RCBR,  KC_UNDS,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_NAV] = LAYOUT_ortho_4x12(
    LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5),  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_DEL,
    KC_LCTL,     KC_LALT,      KC_LGUI,      KC_LSFT,     _______,     XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSPC,
    _______,     _______,     _______,     _______,     _______,     XXXXXXX,  XXXXXXX,  _______,  KC_BRID,  KC_BRIU,  KC_MUTE,  KC_ENT,
    XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     _______,     XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  QK_BOOT
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      XXXXXXX,  XXXXXXX,  KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
    KC_LCTL,   KC_LALT,    KC_LGUI,    KC_LSFT,   _______,   XXXXXXX,  XXXXXXX,  _______,   KC_LSFT,   KC_LGUI,    KC_LALT,    KC_LCTL,
    _______,   _______,   _______,   _______,   _______,   XXXXXXX,  XXXXXXX,  _______,   _______,   _______,   _______,   _______,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   XXXXXXX,  XXXXXXX,  _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
),

};


// layer_state_t layer_state_set_user(layer_state_t state) {
//  return update_tri_layer_state(state, _SYM, _NAV, _NUM);
//};

