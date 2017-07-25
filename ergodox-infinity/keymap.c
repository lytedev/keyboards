#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYM1 1 // symbols 1
#define SYM2 2 // symbols 2
#define MOUS 3 // mouse

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: Basic
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |   1  |   2  |   3  |   4  |   5  |  F11 |           | F12  |   6  |   7  |   8  |   9  |   0  |  Back  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |  ]   |   Y  |   U  |   I  |   O  |   P  |  Back  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Escape |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |    '   |
     * |--------+------+------+------+------+------|   (  |           |  )   |------+------+------+------+------+--------|
     * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | Enter  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | Ctrl |  Alt | Meta |  L2  |                                       |  L1  | Left | Down |  Up  | Right  |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Vol- | Menu |       | Ins  | Vol+ |
     *                                 ,------+------+------|       |------+------+------.
     *                                 |      |      | Home |       | End  |      |      |
     *                                 | Spce | Back |------|       |------| Enter| Spce |
     *                                 |      |      | NmLk |       | Prnt |      |      |
     *                                 `--------------------'       `--------------------'
     */

    [BASE] = KEYMAP(
        // Left Hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_F11,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G, /* ^^ */
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LPRN,
        KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, MO(SYM2),

                                                           // Thumb Cluster
                                                           KC_VOLD, KC_APP,
                                                           /* vv */ /* vv */ KC_HOME,
                                                           KC_SPC,  KC_BSPC, KC_NLCK,

        // Right Hand
        KC_F12,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        /* ^^ */ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_RPRN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                          MO(SYM1),KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,

        // Thumb Cluster
        KC_INS,  KC_VOLU,
        KC_END,  /* vv */ /* vv */
        KC_PSCR, KC_ENT,  KC_SPC
    ),

    /* Layer 1: Symbols1
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   ~    |   !  |   @  |   #  |   $  |   %  |  F11 |           | F12  |   ^  |   &  |   *  |   (  |   )  |  Del   |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   `    |   1  |   2  |   3  |   4  |   5  |   {  |           |  }   |   6  |   7  |   8  |   9  |   0  |  Del   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Escape |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   -  |   =  |   [  |  ]   |    \   |
     * |--------+------+------+------+------+------|   <  |           |  >   |------+------+------+------+------+--------|
     * | LShift |  F7  |  F8  |  F9  | F10  | F11  |      |           |      |  F12 |  Ins |   ,  |   .  |  /   | Enter  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | Ctrl |  Alt | Meta |  ()  |                                       |  ()  | Left | Down |  Up  | Right  |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Vol- | Menu |       | Ins  | Vol+ |
     *                                 ,------+------+------|       |------+------+------.
     *                                 |      |      | Home |       | End  |      |      |
     *                                 | Spce | Back |------|       |------| Enter| Spce |
     *                                 |      |      | FLSH |       | FLSH |      |      |
     *                                 `--------------------'       `--------------------'
     */

    [SYM1] = KEYMAP(
        // Left Hand
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_F11,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LCBR,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /* ^^ */
        KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_LABK,
        KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,

                                                           // Thumb Cluster
                                                           KC_VOLD, KC_APP,
                                                           /* vv */ /* vv */ KC_HOME,
                                                           KC_SPC,  KC_BSPC, RESET,

        // Right Hand
        KC_F12,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        /* ^^ */ KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        KC_RABK, KC_F12,  KC_INS,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                          KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,

        // Thumb Cluster
        KC_INS,  KC_VOLU,
        KC_END,  /* vv */ /* vv */
        RESET,  KC_ENT,  KC_SPC
    ),

    /* Layer 2: Symbols2
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   `    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |  Back  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   ~    |   !  |   @  |   #  |   $  |   %  |   {  |           |  }   |   ^  |   &  |   *  |   (  |   )  |  Back  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | Escape |  F1  |  F2  |  F3  |  F4  |  F5  |------|           |------|  F6  |   _  |   +  |   {  |  }   |    |   |
     * |--------+------+------+------+------+------|   <  |           |  >   |------+------+------+------+------+--------|
     * | LShift |  F7  |  F8  |  F9  | F10  | F11  |      |           |      |  F12 |  Ins |   <  |   >  |  /   | Enter  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | Ctrl | Ctrl |  Alt | Meta |  ()  |                                       |  ()  | Left | PgDn | PgUp | Right  |
     *   `----------------------------------'                                       `------------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Vol- | Menu |       | Ins  | Vol+ |
     *                                 ,------+------+------|       |------+------+------.
     *                                 |      |      | Home |       | End  |      |      |
     *                                 | Spce | Back |------|       |------| Enter| Spce |
     *                                 |      |      | FLSH |       | FLSH |      |      |
     *                                 `--------------------'       `--------------------'
     */

    [SYM2] = KEYMAP(
        // Left Hand
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_LCBR,
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /* ^^ */
        KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_LABK,
        KC_LCTL, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS,

        // Thumb Cluster
        KC_VOLD, KC_APP,
        /* vv */ /* vv */ KC_HOME,
        KC_SPC,  KC_BSPC, RESET,

        // Right Hand
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_RCBR, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        /* ^^ */ KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
        KC_RABK, KC_F12,  KC_INS,  KC_LABK, KC_RABK, KC_QUES, KC_ENT,
        KC_TRNS, KC_LEFT, KC_PGDN, KC_PGUP,   KC_RGHT,

        // Thumb Cluster
        KC_INS,  KC_VOLU,
        KC_END,  /* vv */ /* vv */
        RESET,   KC_ENT,  KC_SPC
    ),
};

/* const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYM1), // FN1 - Momentary Layer 1 (Symbols1)
    [2] = ACTION_LAYER_TAP_TOGGLE(SYM2)  // FN2 - Momentary Layer 2 (Symbols2)
}; */

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
        case 1:
            if (record->event.pressed) { // For resetting EEPROM
                eeconfig_init();
            }
            break;
    }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
            break;

        case VRSN:
            if (record->event.pressed) {
                SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
            break;

        case RGB_SLD:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    rgblight_mode(1);
                }
            #endif
            return false;
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
