#include "xd60.h"
#include "action_layer.h"

#define _QWERTY 0
#define _COLEMAK 1

enum planck_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK
};

enum {
    FN_TAP_DANCE = 0
};

#define _QWERTY 0
#define _COLEMAK 1
#define _PROG 2
#define _FN1 3
#define _FN2 4
#define _MOUSE 5

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define MO_MOUS     MO(_MOUSE)                  // Hold for mouse
#define CPS_FN1    LT(_FN1, KC_CAPS)                  // Hold for mouse
#define SPC_MOUS   LT(_MOUSE, KC_SPC)                  // Hold for mouse
#define TAP_FNS    TD(FN_TAP_DANCE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Qwerty layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │GRESC│  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │H_TAB│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │▒▒▒▒▒│BKSPC│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │CAPSL│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│▒▒▒▒▒│ENTER│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │ UP  │▒▒▒▒▒│RSHFT│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│L_ALT│█████│█████│█████│ SPC │█████│█████│█████│ APP │LEFT │DOWN │RIGHT│R_GUI│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  [_QWERTY] = KEYMAP(
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,  \
    HPR_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_BSPC,  \
    CPS_FN1,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,              KC_ENT,  \
    KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    KC_RSFT,  KC_RSFT, \
    KC_LCTL,  KC_LALT,  KC_LGUI,                                SPC_MOUS,                               KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT,  TAP_FNS),

  [_COLEMAK] = KEYMAP(
    KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,   \
    HPR_TAB,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,            KC_BSPC,  \
    CPS_FN1,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NO,              KC_ENT,   \
    KC_LSFT,  KC_NO,    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_UP,    KC_RSFT,  KC_RSFT,  \
    KC_LCTL,  KC_LALT,  KC_LGUI,                                SPC_MOUS,                               KC_APP,   KC_LEFT,  KC_DOWN,  KC_RGHT,  TAP_FNS),


  [_PROG] = KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    KC_LCTL,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    KC_LSPO,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_RSPC,  KC_RSPC,  \
    MO(_FN1), _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______),

  [_FN1] = KEYMAP(
    KC_GRV,     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             KC_DEL,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_PGUP,   _______, _______,  \
    _______,  _______,  _______,                                _______,                                KC_INS,   KC_HOME,  KC_PGDOWN, KC_END,  _______),

  [_FN2] = KEYMAP(
    RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  QWERTY,   COLEMAK,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,  _______),

  [_MOUSE] = KEYMAP(
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  \
    _______,  _______,  KC_ACL0,  KC_ACL1,  KC_ACL2,  _______,  _______,  _______,  _______,  _______,  KC_WH_U,  _______,  KC_MS_U,  _______,  _______,  \
    KC_BTN1,  _______,  _______,                                _______,                                KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2),

};
// Custom Actions
const uint16_t PROGMEM fn_actions[] = {
    // [0] = ACTION_LAYER_MODS(_LS, MOD_LSFT)
};


void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
        if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_QWERTY);
        }
        return false;
        break;
        case COLEMAK:
        if (record->event.pressed) {
            persistent_default_layer_set(1UL<<_COLEMAK);
        }
        return false;
    }
    return true;
}

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_TAP = 3,
    DOUBLE_HOLD = 4,
    DOUBLE_SINGLE_TAP = 5 //send SINGLE_TAP twice - NOT DOUBLE_TAP
    // Add more enums here if you want for triple, quadruple, etc.
  };


typedef struct {
    bool is_press_action;
    int state;
} tap;

int cur_dance (qk_tap_dance_state_t *state) {
    if (state->count == 1) {
      //If count = 1, and it has been interrupted - it doesn't matter if it is pressed or not: Send SINGLE_TAP
      if (state->interrupted || !state->pressed) return SINGLE_TAP;
      else return SINGLE_HOLD;
    }
    //If count = 2, and it has been interrupted - assume that user is trying to type the letter associated
    //with single tap. In example below, that means to send `xx` instead of `Escape`.
    else if (state->count > 1) {
      if (state->interrupted) return DOUBLE_SINGLE_TAP;
      else if (state->pressed) return DOUBLE_HOLD;
      else return DOUBLE_TAP;
    }
    else return 6; //magic number. At some point this method will expand to work for more presses
  }

// instanalize an instance of 'tap' for the 'FN' tap dance.
static tap fn_tap_state = {
    .is_press_action = true,
    .state = 0
};

void fn_finished (qk_tap_dance_state_t *state, void *user_data) {
    fn_tap_state.state = cur_dance(state);
    switch (fn_tap_state.state) {
      case SINGLE_HOLD: layer_on(_FN1); break;
      case DOUBLE_HOLD: layer_on(_FN2); break;
    }
  }

void fn_reset (qk_tap_dance_state_t *state, void *user_data) {
    switch (fn_tap_state.state) {
        case SINGLE_HOLD: layer_off(_FN1); break;
        case DOUBLE_HOLD: layer_off(_FN2);
    }
    fn_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [FN_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, fn_finished, fn_reset)
};

/*

// // Right Shift Layer
//   [_RS] = KEYMAP(
//       KC_GRV, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
//       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
//       ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
//       KC_CAPS, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, \
//       ______, ______, ______,                            ______,                        ______, ______, ______, ______, ______),

*/

/*
// Function Layer
  [_FL] = KEYMAP(
      KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL,  \
      ______, KC_MPRV, KC_MPLY, KC_MNXT, ______, KC_CALC, KC_INS,  KC_PGUP,  KC_UP,   KC_PGDN, KC_PSCR, KC_SLCK, KC_PAUS, ______, \
      ______, KC_VOLD, KC_MUTE, KC_VOLU,  ______,  ______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, ______, ______, ______, \
      ______, ______, KC_APP,  ______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,  KC_PGUP, ______, ______, \
      ______, ______, ______,                            ______,                        ______, KC_HOME, KC_PGDN, KC_END),
*/
  /* 0: Qwerty layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │▒▒▒▒▒│BKSPC│  `  │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │H_TAB│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │  \  │█████│ DEL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │C_ESC│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │▒▒▒▒▒│ENTER│█████│PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│▒▒▒▒▒│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │▒▒▒▒▒│RSHFT│ UP  │PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│L_GUI│█████│█████│█████│ SPC │█████│█████│█████│R_ALT│ _FL │R_GUI│LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

