#include "oneshot.h"
#include QMK_KEYBOARD_H


#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

enum planck_layers {
    _QWERTY,
    _SYM,
    _NAV,
    _NUM,
};

enum planck_keycodes {
    // QWERTY = SAFE_RANGE,
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    _______,         _______,  _______,  KC_LGUI,  LA_NAV,   KC_SPC,   KC_SPC,   LA_SYM,   KC_RGUI,  _______,  _______,  _______
),

[_SYM] = LAYOUT_ortho_4x12(
    _______, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  OS_CMD,  OS_ALT,  OS_CTRL,   OS_SHFT,   KC_BSLS,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,  KC_PLUS,  _______,  _______,  _______,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[_NAV] = LAYOUT_ortho_4x12(
    _______,  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5),  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  _______,
    _______,  OS_SHFT,     OS_CTRL,     OS_ALT,     OS_CMD,      _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_MPLY,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  KC_BRID,  KC_BRIU,  _______,  _______,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  _______,  _______,  _______,  _______,  QK_BOOT
),

[_NUM] = LAYOUT_ortho_4x12(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  OS_SHFT,  OS_CTRL,  OS_ALT,   OS_CMD,  _______,  _______,   OS_CMD,  OS_ALT,  OS_CTRL,   OS_SHFT,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,     KC_2,     KC_3,     _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)

};

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
};

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _NUM);
};

