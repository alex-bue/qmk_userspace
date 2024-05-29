#include QMK_KEYBOARD_H

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

// Left-hand home row mods
#define HOME_A LSFT_T(KC_A)
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RCTL_T(KC_L)
#define HOME_SCLN RSFT_T(KC_SCLN)

// EurKey macros for German Umlaute
// TODO

enum planck_layers {
    _QWERTY,
    _SYM,
    _NAV,
    _NUM,
};

enum planck_keycodes {
    // QWERTY = SAFE_RANGE,
    QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  HOME_A,     HOME_S,     HOME_D,     HOME_F,     KC_G,     KC_H,     HOME_J, HOME_K, HOME_L, HOME_SCLN,   KC_QUOT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    _______,         _______,  _______,  KC_LGUI,  LA_NAV,   KC_SPC,   KC_SPC,   LT(LA_SYM, KC_ENTER),   KC_RALT,  _______,  _______,  _______
),

[_SYM] = LAYOUT_ortho_4x12(
    _______, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______, KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  _______,  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,  KC_PLUS,  _______,  _______,  _______,
    _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[_NAV] = LAYOUT_ortho_4x12(
    _______,  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5),  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  _______,
    _______,  KC_LSFT,     KC_LCTL,     KC_LGUI,     KC_LALT,      _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_MPLY,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  KC_BRID,  KC_BRIU,  _______,  _______,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  _______,  _______,  _______,  _______,  QK_BOOT
),

[_NUM] = LAYOUT_ortho_4x12(
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_LSFT,  KC_LCTL, KC_LGUI,   KC_LALT,  _______,  _______,  KC_RALT,  KC_RGUI,  KC_RCTL,  KC_RSFT,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)

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



