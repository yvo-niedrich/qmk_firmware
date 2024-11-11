#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_german.h"

// Layer names
#define BASE 0 // default layer
#define SYMB 1 // symbol layer
#define NAVI 2 // navigation layer

// Macros
#define M_LSHFT M(1)
#define M_RSHFT M(2)
#define XXXXXXX KC_NO

// Key Combos
#define MY_EXPO LGUI(KC_TAB)
#define MY_TERM TD(TAB_ALT_TERM)
#define MY_SYS  LCA_T(KC_TAB)
#define TD_EQL  TD(TAB_EQL)
#define TD_TICK TD(TAP_BTICK_TICK)
#define TD_BACK TD(TAP_ESC_BSLSH)
#define TD_A    TD(TAB_A_AE)
#define TD_O    TD(TAB_O_OE)
#define TD_U    TD(TAB_U_UE)
#define TD_CURR TD(TAB_CURRENCIES)

// TAP DANCES
enum {
    TAP_BTICK_TICK,
    TAP_ESC_BSLSH,
    TAB_CURRENCIES,
    TAB_EQL,
    TAB_ALT_TERM,
    TAB_A_AE,
    TAB_O_OE,
    TAB_U_UE,
    TAB_S_SS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,-------------------------------------------.     ,---------------------------------------------.
 * | Esc \  |  1  |  2  |  3  |  4  |  5  | `´ |     | Play |  6  |  7  |  8  |  9  |  0  |   ß    |
 * |--------+-----+-----+-----+-----+----------|     |------+-----+-----+-----+-----+-----+--------|
 * |  Tab   |  Q  |  W  |  E  |  R  |  T  | L2 |     | Vol. |  Z  | U Ü |  I  | O Ö |  P  | Tab/L2 |
 * |--------+-----+-----+-----+-----+-----|    |     |  Up  |-----+-----+-----+-----+-----+--------|
 * | LShift | A Ä |  S  |  D  |  F  |  G  |----|     |------|  H  |  J  |  K  |  L  |  #  | RShift |
 * |--------+-----+-----+-----+-----+-----| L1 |     | Vol. |-----+-----+-----+-----+-----+--------|
 * | CTRL L |  Y  |  X  |  C  |  V  |  B  |    |     | Down |  N  |  M  |  ,  |  .  |  -  |  +/L1  |
 * `--------+-----+-----+-----+-----+----------'     `------------+-----+-----+-----+-----+--------'
 *   | =/CS |  ^  | ALT | LFT | RGHT|                             | Dwn | Up  |  <  |  >  | LGui  |
 *   `------------------------------'                             `-------------------------------'
 *                                ,-------------.    ,--------------.
 *                                |      | Tab  |    | Home |  End  |
 *                         ,------+------+------|    |------+-------+------.
 *                         |      |      |      |    | PgUp |       |      |
 *                         | Bkspc|  Del |------|    |------| Enter | Space|
 *                         |      |      |LCA/^Ö|    | PgDn |       |      |
 *                         `--------------------'    `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        TD_BACK,   KC_1,       KC_2,     KC_3,     KC_4,     KC_5,     TD_TICK,
        KC_TAB,    KC_Q,       KC_W,     KC_E,     KC_R,     KC_T,     TT(NAVI),
        M_LSHFT,   TD_A,       KC_S,     KC_D,     KC_F,     KC_G,
        KC_LCTRL,  DE_Y,       KC_X,     KC_C,     KC_V,     KC_B,     TT(SYMB),
        TD_EQL,    DE_CIRC,    KC_LALT,  KC_LEFT,  KC_RIGHT,
                                                             XXXXXXX,  MY_SYS,
                                                                       XXXXXXX,
                                                   KC_BSPC,  KC_DELT,  MY_TERM,
        // right hand
        KC_MPLY,  KC_6,   KC_7,    KC_8,    KC_9,    KC_0,       KC_MINS,
        KC_VOLU,  DE_Z,   TD_U,    KC_I,    TD_O,    KC_P,       LT(NAVI, KC_TAB),
                  KC_H,   KC_J,    KC_K,    KC_L,    DE_HASH,    M_RSHFT,
        KC_VOLD,  KC_N,   KC_M,    KC_COMM, KC_DOT,  DE_MINS,    LT(SYMB, DE_PLUS),
                          KC_DOWN, KC_UP,   DE_LESS, DE_MORE,    KC_LGUI,
        KC_HOME, KC_END,
        KC_PGUP,
        KC_PGDN, KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.      ,------------------------------------------.
 * |      | F1  | F2  | F3  | F4  | F5  |    |      |    |  F6  | F7  | F8  | F9  | F10 | F11  |
 * |------+-----+-----+-----+-----+----------|      |----+------+-----+-----+-----+-----+------|
 * | WinT |  !  |  @  |  {  |  }  |  |  |    |      |    |  Up  |  7  |  8  |  9  |  /  |      |
 * |------+-----+-----+-----+-----+-----|    |      | >> |------+-----+-----+-----+-----+------|
 * |      |  #  | $€£ |  (  |  )  |  ´  |----|      |----| Down |  4  |  5  |  6  |  *  |      |
 * |------+-----+-----+-----+-----+-----|    |      | << |------+-----+-----+-----+-----+------|
 * | F12  |  %  |  ^  |  [  |  ]  |  ~  |    |      |    |   &  |  1  |  2  |  3  |  -  | F12  |
 * `------+-----+-----+-----+-----+----------'      `-----------+-----+-----+-----+-----+------'
 *   |    |     |     |     |     |                             |  0  |  0  |  ,  |  +  |    |
 *   `----------------------------'                             `----------------------------'
 *                              ,-------------.    ,-------------.
 *                              |      |      |    |      |      |
 *                       ,------|------|------|    |------+------+------.
 *                       |      |      |      |    |      |      |      |
 *                       |      |      |------|    |------|      |      |
 *                       |      |      |      |    |      |      |      |
 *                       `--------------------'    `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       MY_EXPO, DE_EXLM, DE_AT,   DE_LCBR, DE_RCBR, DE_PIPE, KC_TRNS,
       KC_TRNS, DE_HASH, TD_CURR, DE_LPRN, DE_RPRN, DE_ACUT,
       KC_F12,  DE_PERC, DE_CIRC, DE_LBRC, DE_RBRC, DE_TILD, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,     KC_F10,  KC_F11,
       KC_MNXT, KC_UP,   KC_P7,  KC_P8,   KC_P9,     KC_PSLS, KC_TRNS,
                KC_DOWN, KC_P4,  KC_P5,   KC_P6,     KC_PAST, KC_TRNS,
       KC_MPRV, DE_AMPR, KC_P1,  KC_P2,   KC_P3,     KC_PMNS, KC_TRNS,
                         KC_P0,  KC_P0,   KC_KP_DOT, KC_PPLS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Navi and mouse keys
 *
 * ,----------------------------------------------.      ,----------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |    |      | PR |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+-----------|      |----+------+------+------+------+------+------|
 * |      |      | Lclk | MsUp | Rclk |      |    |      |    | PgUp | POS1 |  UP  | END  |^PgUp |      |
 * |------+------+------+------+------+------|    |      |    |------+------+------+------+------+------|
 * |      | Btn4 |MsLeft|MsDown|MsRght| Btn5 |----|      |----| PgDn | LEFT | DOWN | RIGHT|^PgDn |      |
 * |------+------+------+------+------+------|    |      |    |------+------+------+------+------+------|
 * | F12  |WhRght| WhUp |WhDown|WhLeft|WhClk |    |      |    |      |      |      |      |      |      |
 * `------+------+------+------+------+-----------'      `-----------+------+------+------+------+------'
 *   |    |      |MsAcl0|MsAcl1|MsAcl2|                              |      |      |      |      |    |
 *   `--------------------------------'                              `--------------------------------'
 *                                   ,-------------.    ,-------------.
 *                                   |      |      |    |      |      |
 *                            ,------|------|------|    |------+------+------.
 *                            |      |      |      |    |      |      |      |
 *                            | Lclk | Rclk |------|    |------|      |      |
 *                            |      |      |      |    |      |      |      |
 *                            `--------------------'    `--------------------'
 */
// NAVIGATION AND MOUSE
[NAVI] = KEYMAP(
       KC_TRNS,     LSFT(KC_F1), LSFT(KC_F2), LSFT(KC_F3), LSFT(KC_F4), LSFT(KC_F5), KC_TRNS,
       KC_TRNS,     KC_TRNS,     KC_BTN1,     KC_MS_U,     KC_BTN2,     KC_TRNS,     KC_TRNS,
       KC_TRNS,     KC_BTN4,     KC_MS_L,     KC_MS_D,     KC_MS_R,     KC_BTN5,
       KC_F12,      KC_WH_L,     KC_WH_U,     KC_WH_D,     KC_WH_R,     KC_BTN3,     KC_TRNS,
       KC_TRNS,     KC_TRNS,     KC_ACL0,     KC_ACL1,     KC_ACL2,
                                                KC_TRNS,  KC_TRNS,
                                                          KC_TRNS,
                                      KC_BTN1,  KC_BTN2,  KC_TRNS,
    // right hand
       KC_PSCREEN, LSFT(KC_F6),   LSFT(KC_F7),   LSFT(KC_F8),   LSFT(KC_F9),    LSFT(KC_F10),  LSFT(KC_F11),
       KC_TRNS,    LSFT(KC_PGUP), LSFT(KC_HOME), LSFT(KC_UP),   LSFT(KC_END),   KC_TRNS,       KC_TRNS,
                   LSFT(KC_PGDN), LSFT(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_RIGHT), KC_TRNS,       KC_TRNS,
       KC_TRNS,    KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,
                                  KC_TRNS,       KC_TRNS,       KC_TRNS,        KC_TRNS,       KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

short is_shifted = 0;
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case 1:
        case 2:
            if (record->event.pressed) {
                register_code(id == 1 ? KC_LSHIFT : KC_RSHIFT);
                is_shifted++;
            } else {
                unregister_code(id == 1 ? KC_LSHIFT : KC_RSHIFT);
                is_shifted--;
            }

            if (is_shifted < 0) {
                is_shifted = 0;
            }

            break;
    }

    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    is_shifted = 0;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case SYMB:
            ergodox_right_led_2_on();
            break;
        case NAVI:
            ergodox_right_led_1_on();
            break;
        default:
            ergodox_right_led_3_on();
            break;
    }

};

/* ################################################# *
 * ##### TAP DANCE FUNCTIONS (Modifier Keys) ####### *
 * ################################################# */

void dance_backtick_tick (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
      case 1:
          register_code (KC_LSHIFT);
          register_code (DE_ACUT);
          unregister_code (DE_ACUT);
          unregister_code (KC_LSHIFT);
          break;
      case 2:
          register_code (DE_ACUT);
          unregister_code (DE_ACUT);
          break;
      default:
          reset_tap_dance(state);
  }
}

void dance_esc_bslash (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code (KC_ESC);
            unregister_code (KC_ESC);
            break;
        case 2:
            register_code (DE_ALGR);
            register_code (DE_SS);
            unregister_code (DE_SS);
            unregister_code (DE_ALGR);
            break;
        default:
            reset_tap_dance(state);
    }
}

void dance_currencies (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            // DE_DLR --> $
            register_code (KC_LSHIFT);
            register_code (KC_4);
            unregister_code (KC_4);
            unregister_code (KC_LSHIFT);
            break;
        case 2:
            // DE_EUR --> €
            register_code (KC_RALT);
            register_code (KC_E);
            unregister_code (KC_E);
            unregister_code (KC_RALT);
            break;
        case 3:
            // Alt+0163 --> £
            register_code (KC_LALT);
            register_code (KC_P0);
            unregister_code (KC_P0);
            register_code (KC_P1);
            unregister_code (KC_P1);
            register_code (KC_P6);
            unregister_code (KC_P6);
            register_code (KC_P3);
            unregister_code (KC_P3);
            unregister_code (KC_LALT);
            break;
        default:
            reset_tap_dance(state);
    }
}
/* ################################################# *
 * ####### SHIFT AWARE DOUBLE TAPPING ############## *
 * ################################################# */
short dance_is_shifted = 0;

#define ACTION_TAP_DANCE_DOUBLE_SHIFT_AWARE(kc1, kc2) { \
    .fn = { dance_update_shifting, dance_pair_finished_shift_aware, dance_reset_shifting }, \
    .user_data = (void *)&((qk_tap_dance_pair_t) { kc1, kc2 }),  \
}

void dance_update_shifting(qk_tap_dance_state_t *state, void *user_data) {
    if (is_shifted) { dance_is_shifted = is_shifted; }
}

void dance_reset_shifting(qk_tap_dance_state_t *state, void *user_data) {
    dance_is_shifted = 0;
    qk_tap_dance_pair_reset(state, user_data);
}

void dance_pair_finished_shift_aware (qk_tap_dance_state_t *state, void *user_data) {
    if (dance_is_shifted && !is_shifted) { register_code (KC_LSHIFT); }
    qk_tap_dance_pair_finished(state, user_data);
    if (dance_is_shifted && !is_shifted) { unregister_code (KC_LSHIFT); }
}


/* ################################################# *
 * ###### MODIFIER: MOD1+MOD2 -> MOD+KEY ########## *
 * ################################################# */

#define ACTION_MOD_KC(mod1, mod2, kc1, kc2) { \
    .fn = { dance_mod_kc_repeat, dance_mod_kc_finished, dance_mod_kc_reset }, \
    .user_data = (void *)&((td_mod_key_state_t) { false, mod1, mod2, kc1, kc2 }),  \
}

typedef struct {
    bool modifier_mode;
    uint16_t mod1;
    uint16_t mod2;
    uint16_t kc1;
    uint16_t kc2;
} td_mod_key_state_t;

void dance_mod_kc_repeat (qk_tap_dance_state_t *state, void *user_data) {
    td_mod_key_state_t *s = (td_mod_key_state_t *)user_data;

    if (state->count > 1 && !s->modifier_mode) {
        if (s->kc1) { register_code (s->kc1); }
        if (s->kc2) { register_code (s->kc2); }

        if (s->kc2) { unregister_code (s->kc2); }
        if (s->kc1) { unregister_code (s->kc1); }
    }
}

void dance_mod_kc_finished (qk_tap_dance_state_t *state, void *user_data) {
    td_mod_key_state_t *s = (td_mod_key_state_t *)user_data;

    if (s->modifier_mode)
        return;

    if (state->pressed) {
        s->modifier_mode = true;
        if (s->mod1) { register_code (s->mod1); }
        if (s->mod2) { register_code (s->mod2); }
    } else {
        if (s->kc1) { register_code (s->kc1); }
        if (s->kc2) { register_code (s->kc2); }
    }
}

void dance_mod_kc_reset (qk_tap_dance_state_t *state, void *user_data) {
    td_mod_key_state_t *s = (td_mod_key_state_t *)user_data;

    if (s->modifier_mode) {
        if (s->mod2) { unregister_code (s->mod2); }
        if (s->mod1) { unregister_code (s->mod1); }
    } else {
        if (s->kc2) { unregister_code (s->kc2); }
        if (s->kc1) { unregister_code (s->kc1); }
    }

    s->modifier_mode = false;
}

/* ################################################# *
 * ####### SHIFT AWARE DOUBLE TAPPING ############## *
 * ################################################# */

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAP_BTICK_TICK] = ACTION_TAP_DANCE_FN (dance_backtick_tick),
    [TAP_ESC_BSLSH] = ACTION_TAP_DANCE_FN (dance_esc_bslash),
    [TAB_CURRENCIES] = ACTION_TAP_DANCE_FN (dance_currencies),
    [TAB_A_AE] = ACTION_TAP_DANCE_DOUBLE_SHIFT_AWARE(DE_A, DE_AE),
    [TAB_O_OE] = ACTION_TAP_DANCE_DOUBLE_SHIFT_AWARE(DE_O, DE_OE),
    [TAB_U_UE] = ACTION_TAP_DANCE_DOUBLE_SHIFT_AWARE(DE_U, DE_UE),
    [TAB_EQL] = ACTION_MOD_KC(KC_LCTRL, KC_LSHIFT, KC_LSHIFT, KC_0),
    [TAB_ALT_TERM] = ACTION_MOD_KC(KC_LCTRL, KC_LALT, KC_LCTRL, DE_OE),
};
