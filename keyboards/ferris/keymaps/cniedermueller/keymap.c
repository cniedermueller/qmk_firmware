#include QMK_KEYBOARD_H

enum {
    TD_SPC_TAB = 0
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_TAB)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_2(
            LALT_T(KC_Q), KC_W, KC_E, KC_R, KC_T,                           KC_Y, KC_U, KC_I, KC_O, RALT_T(KC_P),
            KC_A, LCTL_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), KC_G,           KC_H, RSFT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), KC_BSPC,
            KC_Z, KC_X, KC_C, KC_V, KC_B,                                   KC_N, KC_M, KC_COMM, KC_DOT, KC_ENT,
            TT(2), KC_ESC,                                                  TD(TD_SPC_TAB), TT(1)),
	[1] = LAYOUT_split_3x5_2(
            KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_GRV, KC_TILD,
            KC_DQUO, KC_LBRC, KC_LCBR, KC_LPRN, KC_TRNS,                    KC_SLSH, KC_UNDS, KC_EQL, KC_COLN, KC_SCLN,
            KC_QUOT, KC_RBRC, KC_RCBR, KC_RPRN, KC_TRNS,                    KC_BSLS, KC_MINS, KC_PLUS, KC_PIPE, KC_QUES,
            TO(3), KC_TRNS,                                                 KC_TRNS, TO(0)),
	[2] = LAYOUT_split_3x5_2(
            KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS,
            KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME,                    KC_0, KC_4, KC_5, KC_6, KC_TRNS,
            KC_PGDN, KC_TRNS, KC_TRNS, KC_TRNS, KC_END,                     KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS,
            TO(0), KC_TRNS,                                                 KC_TRNS, TO(3)),
	[3] = LAYOUT_split_3x5_2(
            KC_F11, KC_F12, KC_VOLU, KC_VOLD, KC_MUTE,                      KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_PWR,
            KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,                             KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,
            KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                              KC_TRNS, KC_LSFT, KC_LGUI, KC_LCTL, KC_LALT,
            TO(0), KC_TRNS,                                                 QK_BOOT, TO(0))
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

