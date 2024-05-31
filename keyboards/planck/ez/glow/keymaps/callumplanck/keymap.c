#include QMK_KEYBOARD_H

#include "g/keymap_combo.h"
#include "oneshot.h"

// layers mods
#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

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
    // BASE = SAFE_RANGE,
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_ortho_4x12(
    KC_Q,     KC_W,     KC_E,     KC_R,               KC_T,              XXXXXXX,  XXXXXXX,  KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
    HOME_A,   HOME_S,   HOME_D,   HOME_F,             KC_G,              XXXXXXX,  XXXXXXX,  KC_H,     HOME_J,   HOME_K,   HOME_L,   HOME_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,               KC_B,              XXXXXXX,  XXXXXXX,  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  LT(LA_NAV, KC_BSPC), LSFT_T(KC_ESC),   XXXXXXX,  XXXXXXX,  LT(LA_SYM, KC_ENT),  LT(LA_SYM, KC_SPC),  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_SYM] = LAYOUT_ortho_4x12(
    KC_TAB,   KC_LBRC,  KC_LCBR,  KC_LPRN,  KC_TILD,  XXXXXXX,  XXXXXXX,  KC_CIRC,  KC_RPRN,  KC_RCBR,  KC_RBRC,  KC_GRV,
    KC_MINS,  KC_ASTR,  KC_EQL,   KC_UNDS,  KC_DLR,   XXXXXXX,  XXXXXXX,  KC_HASH,  OS_SHFT,  OS_CMD,   OS_ALT,   KC_QUOT,
    KC_PLUS,  KC_PIPE,  KC_AT,    KC_SLSH,  KC_PERC,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSLS,  KC_AMPR,  KC_QUES,  KC_EXLM,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_NAV] = LAYOUT_ortho_4x12(
    LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5),  XXXXXXX,  XXXXXXX,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_DEL,
    OS_CTRL,     OS_ALT,      OS_CMD,      OS_SHFT,     _______,     XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSPC,
    _______,     _______,     _______,     _______,     _______,     XXXXXXX,  XXXXXXX,  _______,  KC_BRID,  KC_BRIU,  KC_MUTE,  KC_ENT,
    XXXXXXX,     XXXXXXX,     XXXXXXX,     _______,     _______,     XXXXXXX,  XXXXXXX,  _______,  _______,  XXXXXXX,  XXXXXXX,  QK_BOOT
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      XXXXXXX,  XXXXXXX,  KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
    OS_CTRL,   OS_ALT,    OS_CMD,    OS_SHFT,   _______,   XXXXXXX,  XXXXXXX,  _______,   OS_SHFT,   OS_CMD,    OS_ALT,    OS_CTRL,
    _______,   _______,   _______,   _______,   _______,   XXXXXXX,  XXXXXXX,  _______,   _______,   _______,   _______,   _______,
    XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,   XXXXXXX,  XXXXXXX,  _______,   _______,   XXXXXXX,   XXXXXXX,   XXXXXXX
),

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

