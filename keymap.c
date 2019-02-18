/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _ARROW,
  _INTJ,
  _MODS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  PW,
  DELETE_EMAIL,
  ARCHIVE_EMAIL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ARROW MO(_ARROW)
#define INTJ MO(_INTJ)
#define MODS MO(_MODS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | IntJ | Ctrl | Alt  | GUI  |Lower |Space | Mods |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {LT(ARROW,KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {MT(MOD_LSFT,KC_KP_DOT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {LT(INTJ,KC_F4), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  LT(MODS,KC_DEL),  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |DelEml|ArcEml|  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   DELETE_EMAIL, ARCHIVE_EMAIL,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_PLOVER] = {
  {KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   },
  {XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC},
  {XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {EXT_PLV, XXXXXXX, XXXXXXX, KC_C,    KC_V,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______,  PLOVER,  _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Arrow (Hold Escape)
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | Home | Left | Down | Right|      | MENU |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |  End |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ARROW] = {
  {_______, KC_F1, KC_F2, KC_F3, KC_F4, _______, _______, _______, KC_UP, _______, _______, _______ },
  {_______, KC_F5, KC_F6, KC_F7, KC_F8, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_MENU },
  {_______, KC_F9, KC_F10, KC_F11, KC_F12, _______, KC_END, _______, _______, _______, _______, _______ },
  {_______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, _______, _______, _______ }
},

/* IntelliJ (Fn)
 * ,-----------------------------------------------------------------------------------.
 * |      | Close|      |  End |Refctr|OpenIn|      |Usages|Prev_M|Outlin|  Run |  PW  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |HidWin|RnTgts|Symbol|DbugIt|Search|  VCS |Hierar| Prev |Next_M| Next |FntRes|TglBrk|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |ReRun |Run It|Create|S.BkMk|G.BkMk| File | Menu |Font- |Font+ | Info |BrkPts|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    KP_0     |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_INTJ] = {
  {_______, LCTL(KC_F4), _______, LCTL(KC_F2), LCTL(LALT(LSFT(KC_T))), LALT(KC_F1), _______, LALT(KC_F7), LALT(KC_UP), LCTL(KC_F12), LSFT(LALT(KC_F10)), PW },
  {LCTL(LSFT(KC_F12)), LALT(LSFT(KC_F10)), LCTL(LALT(LSFT(KC_N))), LCTL(LSFT(KC_F9)), LCTL(LSFT(KC_F)), LALT(KC_GRV), LCTL(LALT(KC_H)), LCTL(LALT(KC_LEFT)), LALT(KC_DOWN), LCTL(LALT(KC_RIGHT)), LCTL(LALT(LSFT(KC_SCLN))), LCTL(LSFT(LALT(KC_F8))) },
  {_______, LCTL(KC_F5), LCTL(LSFT(KC_F10)), LALT(KC_INS), LCTL(KC_F11), KC_F11, LCTL(LSFT(KC_N)), LSFT(LALT(KC_SCLN)), LCTL(LALT(LSFT(KC_MINS))), LCTL(LALT(LSFT(KC_EQL))), LCTL(KC_F1), LCTL(LSFT(KC_F8)) },
  {_______, _______, _______, _______, _______, LCTL(LALT(KC_SCLN)), LCTL(LALT(KC_SCLN)), _______, _______, _______, _______, _______ }
},

/* Mods
 * ,-----------------------------------------------------------------------------------.
 * |CtrlF4|Alt+1 |Alt+2 |Alt+3 |Alt+4 |Alt+5 |Alt+6 |Alt+7 |Alt+8 |Alt+9 |Alt+0 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Ctrl+`|Ctrl+1|Ctrl+2|Ctrl+3|Ctrl+4|Ctrl+5|Ctrl+6|Ctrl+7|Ctrl+8|Ctrl+9|Ctrl+0|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Gui+1 |Gui+2 |Gui+3 |Gui+4 |Gui+5 |Gui+6 |Gui+7 |Gui+8 |Gui+9 |Gui+0 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LftScr|FulScr|RgtScr|      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
 
[_MODS] = {
  {LCTL(KC_F4), LALT(KC_1), LALT(KC_2), LALT(KC_3), LALT(KC_4), LALT(KC_5), LALT(KC_6), LALT(KC_7), LALT(KC_8), LALT(KC_9), LALT(KC_0), _______ },
  {LCTL(KC_GRV), LCTL(KC_1), LCTL(KC_2), LCTL(KC_3), LCTL(KC_4), LCTL(KC_5), LCTL(KC_6), LCTL(KC_7), LCTL(KC_8), LCTL(KC_9), LCTL(KC_0), _______ },
  {_______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), _______ },
  {LSFT(LCTL(LGUI(KC_F))), LSFT(LCTL(LGUI(KC_G))), LSFT(LCTL(LGUI(KC_H))), _______, _______, _______, _______, _______, _______, _______, _______, _______ }
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        PORTE &= ~(1<<6);
      } else {
        unregister_code(KC_RSFT);
        PORTE |= (1<<6);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(plover_song);
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
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_PLOVER);
      }
      return false;
      break;
    case PW:
      if (record->event.pressed) {
        SEND_STRING("PW");
      }
      return false;
      break;
    case DELETE_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("x#");
      }
      return false;
      break;
    case ARCHIVE_EMAIL:
      if (record->event.pressed) {
        SEND_STRING("xE");
      }
      return false;
      break;
  }
  return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
