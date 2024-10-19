/*
Planck Keymap
By Alex
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _NAVIGATION,
  _SYM,
  _NUM,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  CAMP,                 // For Song Campanella
  IMP,                  // For Fantasie Impromptue
  NOCT                  // For Nocture Op 9 1
};

#define SYM LT(_SYM, KC_ESC)       // Lower layer on hold, backspace on tap
#define NUM LT(_NUM, KC_ENTER)      // Raise layer on hold, enter on tap
#define NAVSPC LT(_NAVIGATION, KC_SPC) // Navigation layer on hold, tap on space
#define NAVTAB LT(_NAVIGATION, KC_TAB) // Alias for navigation layer
#define NAV MO(_NAVIGATION) // Alias for navigation layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_TAB,          KC_Q,     KC_W,     KC_E,     KC_R,   KC_T,     KC_Y,     KC_U,  KC_I,     KC_O,     KC_P,     KC_BSPC,
    LCTL_T(KC_ESC),  KC_A,     KC_S,     KC_D,     KC_F,   KC_G,     KC_H,     KC_J,  KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,     KC_V,   KC_B,     KC_N,     KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,  SC_SENT,
    NAV, KC_LCTL,    KC_LALT,  KC_LGUI,  SYM,  NAVSPC, NAVSPC,       NUM,  KC_RGUI,  KC_RALT, KC_RCTL, NAV
),

[_NAVIGATION] = LAYOUT_ortho_4x12(
    _______,  LALT(KC_1),  LALT(KC_2),  LALT(KC_3),  LALT(KC_4),  LALT(KC_5), KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_MUTE,  KC_DEL,
    _______,  KC_LCTL,     KC_LALT,     KC_LGUI,    KC_LSFT,     _______,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_MPLY,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  KC_BRID, KC_BRIU,  _______,  _______,  _______,
    _______,  _______,     _______,     _______,    _______,     _______,     _______,  _______,  _______,  _______,  _______,  _______
),

[_SYM] = LAYOUT_ortho_4x12(
    KC_TILDE, KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
    _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  _______,  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_UNDS,  KC_PLUS,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
),

[_NUM] = LAYOUT_ortho_4x12(
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    _______,  KC_LCTL,  KC_LALT,  KC_LGUI,  KC_LSFT,  _______,  _______,  KC_LSFT,  KC_LGUI,  KC_LALT,  KC_LCTL,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______, _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,  _______,  _______,  _______
),

[_ADJUST] = LAYOUT_ortho_4x12(
    _______,  _______,  _______,  _______,  QK_BOOT,  _______,  _______,   _______,  _______,  _______,  AG_TOGG,  RGB_TOG,
    _______,  _______,  _______,  _______,  _______,  _______,  RGB_RMOD,  RGB_VAD,  RGB_VAI,  RGB_MOD,  _______,  AU_TOGG,
    _______,  CAMP,     IMP,      NOCT,     _______,  _______,  _______,   RGB_HUD,  RGB_HUI,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______
)
};

#ifdef AUDIO_ENABLE
  float campanella[][2]         = SONG(CAMPANELLA);
  float fantasie_impromptu[][2] = SONG(FANTASIE_IMPROMPTU);
  float nocturne[][2]           = SONG(NOCTURNE_OP_9_NO_1);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NUM, _ADJUST);
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
        case NAVSPC: // Increase time that space needs to be held to access nav layer
            return TAPPING_TERM + 150;
        default:
            return TAPPING_TERM;
    }
}
