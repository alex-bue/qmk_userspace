#include QMK_KEYBOARD_H

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)
#define LA_MEDIA MO(_MEDIA)
#define LA_NUM MO(_NUM)
#define LA_SYM MO(_SYM)

// EurKey macros for German Umlaute
// TODO

enum planck_layers {
    _QWERTY,
    _NAV,
    _MEDIA,
    _NUM,
    _SYM,
};

enum planck_keycodes {
    // QWERTY = SAFE_RANGE,
    QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,    XXXXXXX,    XXXXXXX,    KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,
    LCTL_T(KC_A),  LALT_T(KC_S),  LGUI_T(KC_D),  LSFT_T(KC_F),  KC_G,    XXXXXXX,    XXXXXXX,    KC_H,          LSFT_T(KC_J),  LGUI_T(KC_K),  LALT_T(KC_L),  LCTL_T(KC_QUOT),
    ALGR_T(KC_Z),  KC_X,          KC_C,          KC_V,          KC_B,    XXXXXXX,    XXXXXXX,    KC_N,          KC_M,          KC_COMM,       KC_DOT,       ALGR_T(KC_SLSH),
    XXXXXXX,       XXXXXXX,       LT(LA_MEDIA, KC_ESC), LT(LA_NAV, KC_TRNS), LT(LA_SYM, KC_TAB), XXXXXXX, XXXXXXX, LT(_NUM, KC_SPC), KC_ENT, KC_BSPC, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, KC_DOT,  XXXXXXX, XXXXXXX, KC_0,    KC_MINS, XXXXXXX, XXXXXXX,    XXXXXXX
),

[_SYM] = LAYOUT_ortho_4x12(
    KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, KC_LPRN, XXXXXXX, XXXXXXX, KC_RPRN, KC_UNDS, XXXXXXX, XXXXXXX,    XXXXXXX
),

[_MEDIA] = LAYOUT_ortho_4x12(
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX
),

[_NAV] = LAYOUT_ortho_4x12(
    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    U_UND,   U_CUT,   U_CPY,   U_PST,   U_RDO,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, KC_DEL,  XXXXXXX, XXXXXXX, KC_BSPC, KC_ENT,  XXXXXXX, XXXXXXX,    XXXXXXX
),

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

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NAV, _NUM);
};



