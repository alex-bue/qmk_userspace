/*
Planck Keymap
By Alex
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

enum planck_layers {
  _QWERTY,
  _NAVIGATION,
  _SYM,
  _NUM,
  _FN,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  CAMP,                 // For Song Campanella
  IMP,                  // For Fantasie Impromptue
  NOCT                  // For Nocture Op 9 1
};

#define SYM LT(_SYM, KC_ENTER)       // Lower layer on hold, backspace on tap
#define NUM_V LT(_NUM, KC_V)          // Raise layer on hold, enter on tap
#define NAV_UNDS LT(_NAVIGATION, KC_UNDS) // Navigation layer on hold, tap on space
#define NAV_TAB LT(_NAVIGATION, KC_TAB) // Alias for navigation layer
#define FN_SPC LT(_FN, KC_SPC) // Alias for navigation layer
#define NAV MO(_NAVIGATION) // Alias for navigation layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_Q,     KC_W,     KC_E,      KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,        KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,      KC_F,     KC_G,     KC_H,     KC_J,     KC_K,        KC_L,     KC_SCLN,  LCTL_T(KC_QUOT),
    KC_LSFT,         KC_Z,     KC_X,     KC_C,      NUM_V,    KC_B,   KC_N,     KC_M,     KC_COMM,     KC_DOT,   KC_SLSH,  SC_SENT,
    NAV, KC_LCTL,    KC_LALT,  KC_LGUI,  NAV_UNDS,  FN_SPC,   FN_SPC,   SYM,      KC_RGUI,  KC_RALT,  KC_RCTL,  NAV
),

[_NAVIGATION] = LAYOUT_ortho_4x12(
    _______,  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5), KC_HOME,  KC_PGDN,  KC_PGUP,  KC_BSPC,  KC_DEL,  KC_BSPC,
    _______,  KC_LCTL,     KC_LALT,     KC_LGUI,    KC_LSFT,     _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______, _______,
    _______,  _______,     _______,     _______,    _______,     _______,     KC_END,   _______,  _______,  _______,  _______, _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  _______,  _______,  _______,  _______, _______
),

[_SYM] = LAYOUT_ortho_4x12(
    _______,   _______,  LSFT(KC_COMM), LSFT(KC_DOT),  KC_BSLS,    KC_GRV,     KC_AMPR,    KC_GRV,     KC_LPRN,    KC_RPRN,    KC_PERC,   _______,
    _______,   KC_EXLM,  KC_MINS,       KC_PLUS,       KC_EQL,     KC_HASH,    KC_PIPE,    KC_COLN,    KC_LBRC,    KC_RBRC,    KC_DLR,    _______,
    _______,   KC_UNDS,  KC_SLSH,       KC_ASTR,       KC_CIRC,    KC_AMPR,    KC_TILD,    KC_SCLN,    KC_LCBR,    KC_RCBR,    KC_AT,     _______,
    _______,   _______,  _______,       _______,       _______,    _______,    _______,    _______,    _______,    _______,    _______,   _______
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_PLUS,  _______,
    _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  _______,  KC_ASTR,  KC_4,     KC_5,     KC_6,     KC_MINS,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  KC_COMM,  KC_1,     KC_2,     KC_3,     KC_DOT,   _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_0,     _______,  _______,  _______,  _______
),

[_FN] = LAYOUT_ortho_4x12(
    _______,   KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_TRNS,   KC_MPLY,   KC_MUTE,    KC_TRNS,   KC_TRNS,   _______,
    _______,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_MPRV,   KC_VOLD,   KC_VOLU,    KC_MNXT,   KC_TRNS,   _______,
    _______,   KC_F11,     KC_F12,     KC_F13,     KC_F14,     KC_F15,     KC_TRNS,   KC_BRID,   KC_BRIU,    KC_TRNS,   KC_TRNS,  _______,
    _______,   _______,   _______,   _______,      KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   _______,   _______,   _______,   _______
),

[_ADJUST] = LAYOUT_ortho_4x12(
    _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,   _______,  _______,  _______,  AG_TOGG,  RGB_TOG,
    _______,  _______,  _______,  _______,  _______,  _______,  RGB_RMOD,  RGB_VAD,  RGB_VAI,  RGB_MOD,  _______,  AU_TOGG,
    _______,  CAMP,     IMP,      NOCT,     _______,  _______,  _______,   RGB_HUD,  RGB_HUI,  _______,  _______,  _______,
    QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  QK_BOOT
)
};

#ifdef AUDIO_ENABLE
  float campanella[][2]         = SONG(CAMPANELLA);
  float fantasie_impromptu[][2] = SONG(FANTASIE_IMPROMPTU);
  float nocturne[][2]           = SONG(NOCTURNE_OP_9_NO_1);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAVIGATION, _SYM, _ADJUST);
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
    case CAMP:
      if (record->event.pressed) {
        PLAY_SONG(campanella);
      }
      break;
    case IMP:
      if (record->event.pressed) {
        PLAY_SONG(fantasie_impromptu);
      }
      break;
    case NOCT:
      if (record->event.pressed) {
        PLAY_SONG(nocturne);
      }
      break;
  }
  return true;
};

// Adjust tapping term on certain keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN_SPC: // Increase time that space needs to be held to access nav layer
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
