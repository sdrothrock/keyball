/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layer_number {
    _LOWER = 0,
    _MOUSE,
    _SHIFT,
    _UTILS,
    _SETUP,
};

enum custom_keycodes {
    LEDSHFT = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LOWER] = LAYOUT(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    LEDSHFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
    KC_LALT  , KC_DEL   , KC_LGUI  , XXXXXXX  ,LT(4, KC_LNG2),LT(3,KC_SPC), KC_ENT ,            LT(4,KC_LNG1),LT(1,KC_LBRC),                       KC_INT3  , KC_EQL
  ),
  // transparent shift layer for lighting detection/control
  [_SHIFT] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  ,                                  _______  , _______
  ),
  // immediately above lower layer so that almost all keys can be transparent for immediate typing
  [_MOUSE] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_LCTL  , _______  , _______  , _______  , _______  , _______  ,                                  _______  ,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, _______  , _______  ,
    KC_LSFT  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , SCRL_MO  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            KC_ENT   , _______  ,                                  _______  , _______
  ),
  [_UTILS] = LAYOUT(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_TAB   , KC_PGUP  , KC_UP    , KC_PGDN  , MEH(KC_R), KC_HOME  ,                                  _______  , _______  , _______  , _______  , _______  , KC_F12   ,
    KC_LCTL  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , KC_END   ,                                  _______  , _______  , _______  , _______  , _______  ,C(G(KC_SPC)),
    KC_LSFT  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , G(KC_DOT),
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  ,                                  _______  , _______  
  ),
  [_SETUP] = LAYOUT(
    QK_BOOT  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , QK_BOOT  ,
    _______  , _______  , SCRL_DVD , KBC_SAVE , _______  , SSNP_VRT ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , CPI_D100 , SCRL_DVI , CPI_I100 , _______  , SSNP_FRE ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , RGB_TOG  ,            RGB_TOG  , _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  ,                                  _______  , _______
  ),
};
// clang-format on

#ifdef OLED_ENABLE
#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

/*
 * RGBLIGHT per-layer lighting settings
 */

#if defined(RGBLIGHT_ENABLE)
//                          HUE  SAT  VAL
#define LOWER_LIGHT_BLUE    139,  69,  60
#define SHIFT_LIGHT_BLUE    139,  69, 100
#define MOUSE_ORANGE         25, 255, 100
#define UTILS_AQUA          103, 217,  72
#define SETUP_RED             0, 255, 100

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, LOWER_LIGHT_BLUE}
);
const rgblight_segment_t PROGMEM shift_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, SHIFT_LIGHT_BLUE}
);
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, MOUSE_ORANGE}
);
const rgblight_segment_t PROGMEM utils_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, UTILS_AQUA}
);
const rgblight_segment_t PROGMEM setup_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLIGHT_LED_COUNT, SETUP_RED}
);

const rgblight_segment_t* const PROGMEM custom_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    shift_layer,
    mouse_layer,
    utils_layer,
    setup_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = custom_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _SHIFT));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _UTILS));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SETUP));
    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LEDSHFT:
          if (record->event.pressed) {
              register_code(KC_LSFT);
              if (!layer_state_is(_SHIFT)) {
                  layer_move(_SHIFT);
              }
          } else {
              unregister_code(KC_LSFT);
              if (layer_state_is(_SHIFT)) {
                  layer_move(_LOWER);
              }
          }
          break;
    }
    return true;
}

void suspend_power_down_user(void) {
    rgblight_suspend();
}

void suspend_wakeup_init_user(void) {
    rgblight_wakeup();
}
