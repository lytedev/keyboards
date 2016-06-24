#include "planck.h"
#include "action_layer.h"

#ifdef AUDIO_ENABLE
	#include "audio.h"
#endif

#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY  0
#define _COLEMAK 1
#define _LOWER   2
#define _LOWER2  3
#define _RAISE   4
#define _RAISE2  5
#define _PLOVER  6
#define _ADJUST  7

// macro shortcuts
#define QWERTY  M(_QWERTY)
#define COLEMAK M(_COLEMAK)
#define LOWER   M(_LOWER)
#define RAISE   M(_RAISE)
#define PLOVER  M(_PLOVER)
#define ADJUST  MO(_ADJUST)
#define LOWER2  M(_LOWER2)
#define RAISE2  M(_RAISE2)
#define EXT_PLV M(13)
#define TOG_OUT M(14)

// visually clearer key notation
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = {
		{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
		{KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
		{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
		{KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
	},
	[_COLEMAK] = {
		{KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
		{KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
		{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
		{KC_LCTL, ADJUST,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
	},
	[_LOWER] = {
		{KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
		{KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
		{_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, RESET},
		{_______, _______, _______, _______, _______,  _______, _______, LOWER2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
	},
	[_LOWER2] = {
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
	},
	[_RAISE] = {
		{KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
		{KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
		{_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, _______, _______, _______},
		{ADJUST,  _______, _______, _______, RAISE2,  _______, _______, _______, KC_MNXT, KC_PGDN, KC_PGUP, KC_MPLY}
	},
	[_RAISE2] = {
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
	},
	[_PLOVER] = {
		{KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
		{XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
		{TOG_OUT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
		{EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
	},
	[_ADJUST] = {
		{KC_J,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_DEL},
		{MUV_IN,  _______, _______, _______, _______, _______, _______, QWERTY,  COLEMAK, PLOVER,  _______, _______},
		{MUV_DE,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
		{MU_TOG,  _______, AU_TOG,  _______, _______, _______, _______, _______, _______, _______, _______, RESET  }
	}
};

const uint16_t PROGMEM fn_actions[] = {

};

#ifdef AUDIO_ENABLE

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

#endif


void persistant_default_layer_set(uint16_t default_layer) {
	eeconfig_update_default_layer(default_layer);
	default_layer_set(default_layer);
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	switch(id) {
		case _QWERTY:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
				#endif
				persistant_default_layer_set(1UL<<_QWERTY);
			}
			break;
		case _COLEMAK:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_colemak, false, 0);
				#endif
				persistant_default_layer_set(1UL<<_COLEMAK);
			}
			break;
		case _LOWER:
			if (record->event.pressed) {
				layer_on(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_LOWER);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			break;
		case _RAISE:
			if (record->event.pressed) {
				layer_on(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			} else {
				layer_off(_RAISE);
				update_tri_layer(_LOWER, _RAISE, _ADJUST);
			}
			break;
		case 12:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					stop_all_notes();
					PLAY_NOTE_ARRAY(tone_plover, false, 0);
				#endif
				layer_off(_RAISE);
				layer_off(_LOWER);
				layer_off(_ADJUST);
				layer_on(_PLOVER);
				if (!eeconfig_is_enabled()) {
					eeconfig_init();
				}
				keymap_config.raw = eeconfig_read_keymap();
				keymap_config.nkro = 1;
				eeconfig_update_keymap(keymap_config.raw);
			}
			break;
		case 13:
			if (record->event.pressed) {
				#ifdef AUDIO_ENABLE
					PLAY_NOTE_ARRAY(tone_plover_gb, false, 0);
				#endif
				layer_off(_PLOVER);
			}
			break;
		case 14:
			if (record->event.pressed) {
				return MACRO( D(E), D(R), D(F), D(V), D(O), D(L), U(E), U(R), U(F), U(V), U(O), U(L), END );
			}
			break;
	}
	return MACRO_NONE;
};

void matrix_init_user(void) {
	#ifdef AUDIO_ENABLE
		startup_user();
	#endif
}

#ifdef AUDIO_ENABLE

void startup_user()
{
	_delay_ms(20); // gets rid of tick
	PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user()
{
	PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
	_delay_ms(150);
	stop_all_notes();
}

void music_on_user(void)
{
	music_scale_user();
}

void music_scale_user(void)
{
	PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif

