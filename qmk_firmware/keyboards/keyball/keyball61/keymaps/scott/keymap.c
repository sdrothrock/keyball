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
    _UPPER,
    _UTILS,
    _SETUP,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LOWER] = LAYOUT(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_BSPC  ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , KC_QUOT  ,
    LT(2, KC_LSFT), KC_Z, KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
    KC_LALT  , KC_DEL   , KC_LGUI  , XXXXXXX  ,LT(4, KC_LNG2),LT(3,KC_SPC), KC_ENT ,        LT(4,KC_LNG1),LT(1,KC_LBRC),                           KC_INT3  , KC_EQL
  ),
  // immediately above lower layer so that almost all keys can be transparent for immediate typing
  [_MOUSE] = LAYOUT(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  ,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , SCRL_MO  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  ,                                  _______  , _______
  ),
  [_UPPER] = LAYOUT(
    S(KC_ESC) ,S(KC_1)  , S(KC_2)   ,S(KC_3)  , S(KC_4)  , S(KC_5)  ,                                  S(KC_6)  , S(KC_7)  , S(KC_8)  , S(KC_9)  , S(KC_EQL) ,S(KC_MINS),
    S(KC_TAB) ,S(KC_Q)  , S(KC_W)   ,S(KC_E)  , S(KC_R)  , S(KC_T)  ,                                  S(KC_Y)  , S(KC_U)  , S(KC_I)  , S(KC_O)  , S(KC_P)   ,S(KC_BSPC),
    S(KC_LCTL),S(KC_A)  , S(KC_S)   ,S(KC_D)  , S(KC_F)  , S(KC_G)  ,                                  S(KC_H)  , S(KC_J)  , S(KC_K)  , S(KC_L)  , S(KC_SCLN),S(KC_QUOT),
    _______   ,S(KC_Z)  , S(KC_X)   ,S(KC_C)  , S(KC_V)  , S(KC_B)  , S(KC_RBRC),         S(KC_NUHS),  S(KC_N)  , S(KC_M)  , S(KC_COMM),S(KC_DOT), S(KC_SLSH),S(KC_INT1),
    S(KC_LALT),S(KC_DEL), S(KC_LGUI),LSG(KC_S), _______  ,LT(2,KC_SPC),S(KC_ENT),           _______ ,  S(KC_LBRC),                                 S(KC_INT3),S(KC_EQL)
  ),
  [_UTILS] = LAYOUT(
    _______  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , KC_PGUP  , KC_UP    , KC_PGDN  , _______  , KC_HOME  ,                                  _______  , _______  , _______  , _______  , _______  , KC_F12   ,
    _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , KC_END   ,                                  _______  , _______  , _______  , _______  , _______  ,C(G(KC_SPC)),
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , G(KC_DOT),
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

#if defined(RGBLIGHT_ENABLE)
#define LOWER_LIGHT_BLUE    175,   0,  80
#define MOUSE_ORANGE         30, 255, 255
#define UPPER_BLUE          175, 255,  80
#define UTILS_BLUE          175, 140,  80
#define SETUP_RED             0, 255, 255

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, LOWER_LIGHT_BLUE}
);
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, MOUSE_ORANGE}
);
const rgblight_segment_t PROGMEM upper_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, UPPER_BLUE}
);
const rgblight_segment_t PROGMEM utils_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, UTILS_BLUE}
);
const rgblight_segment_t PROGMEM setup_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, SETUP_RED}
);

const rgblight_segment_t* const PROGMEM custom_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
    mouse_layer,
    upper_layer,
    utils_layer,
    setup_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = custom_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MOUSE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _UPPER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _UTILS));
    rgblight_set_layer_state(4, layer_state_cmp(state, _SETUP));
    return state;
}
#endif
