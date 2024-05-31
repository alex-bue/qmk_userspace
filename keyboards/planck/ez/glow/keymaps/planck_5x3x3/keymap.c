#include QMK_KEYBOARD_H

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
// #define LA_MEDIA MO(_MEDIA)
#define LA_NUM MO(_NUM)
#define LA_SYM MO(_SYM)

// EurKey macros for German Umlaute
// TODO

enum planck_layers {
    _QWERTY,
    _NAV,
    // _MEDIA,
    _NUM,
    _SYM,
};

enum planck_keycodes {
    // QWERTY = SAFE_RANGE,
    QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,    KC_Y,          KC_U,          KC_I,          KC_O,          KC_P, KC_BSPC,
    LCTL_T(KC_ESC), LT(LA_SYM, KC_A),  LALT_T(KC_S),  LGUI_T(KC_D),  LSFT_T(KC_F),  KC_G,    KC_H,   LSFT_T(KC_J),  LGUI_T(KC_K),  LALT_T(KC_L),  LT(LA_SYM, KC_SCLN), KC_QUOT,
    KC_LSFT,        ALGR_T(KC_Z),  KC_X,          KC_C,          KC_V,          KC_B,    KC_N,          KC_M,          KC_COMM,       KC_DOT,       ALGR_T(KC_SLSH), SC_SENT,
    XXXXXXX,       XXXXXXX,       XXXXXXX, LT(LA_NUM, KC_ESC), LT(LA_NAV, KC_TAB), LT(LA_NAV, KC_SPC), LT(LA_NAV, KC_SPC), LT(LA_NUM, KC_ENT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT_ortho_4x12(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,  KC_8,  KC_9,           KC_0,  KC_SLSH,
    _______,  XXXXXXX,  KC_LALT, KC_LGUI,   KC_LSFT,  _______,  _______,  KC_4,  KC_5,  KC_6,        KC_PLUS,  KC_ASTR,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_1,  KC_2,  KC_3,        KC_MINS,  _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,  _______,  _______,  _______,  KC_0,  _______,  XXXXXXX,  XXXXXXX, XXXXXXX
),

[_SYM] = LAYOUT_ortho_4x12(
    _______, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______, XXXXXXX,  KC_LALT,  KC_LGUI,  KC_LSFT,  _______,  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  _______,
    XXXXXXX,  XXXXXXX,  XXXXXXX, _______,  _______,  _______,  _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_NAV] = LAYOUT_ortho_4x12(
    _______,  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5), KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  KC_BSPC,
    _______,  XXXXXXX,     KC_LALT,     KC_LGUI,     KC_LSFT,      _______,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_MPLY,  _______,
    _______,  _______,     LGUI(KC_X),   LGUI(KC_C), LGUI(KC_V),   _______,     _______,  KC_BRID,  KC_BRIU,  _______,  _______,  _______,
    XXXXXXX,  XXXXXXX,     XXXXXXX,     _______,    _______,     _______,     _______,  _______,  _______,  XXXXXXX,  XXXXXXX,  QK_BOOT
),

// [_MEDIA] = LAYOUT_ortho_4x12(
//     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,
//     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_MPLY,
//     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID,  KC_BRIU, _______, _______,, _______,
//     XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, KC_MPLY, KC_MSTP, XXXXXXX, XXXXXXX
// ),


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    }
    return true;
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _SYM, _NAV, _NUM);
// };



