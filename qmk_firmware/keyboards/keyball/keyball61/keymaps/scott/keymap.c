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
    {0, RGBLED_NUM, LOWER_LIGHT_BLUE}
);
const rgblight_segment_t PROGMEM shift_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, SHIFT_LIGHT_BLUE}
);
const rgblight_segment_t PROGMEM mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, MOUSE_ORANGE}
);
const rgblight_segment_t PROGMEM utils_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, UTILS_AQUA}
);
const rgblight_segment_t PROGMEM setup_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, SETUP_RED}
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

/*
 * RGBLIGHT backlight timer
 * https://docs.qmk.fm/custom_quantum_functions#keyboard-housekeeping
 */
static uint32_t key_timer;           // timer for last keyboard activity, use 32bit value and function to make longer idle time possible
static void refresh_rgb(void);       // refreshes the activity timer and RGB, invoke whenever any activity happens
static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
bool is_rgb_timeout = false;         // store if RGB has timed out or not in a boolean


void refresh_rgb(void) {
    key_timer = timer_read32(); // store time of last refresh
    if (is_rgb_timeout)
    {
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
}

void check_rgb_timeout(void) {
    if (!is_rgb_timeout && timer_elapsed32(key_timer) > RGBLIGHT_TIMEOUT)
    {
        rgblight_suspend();
        is_rgb_timeout = true;
    }
}

// Call QMK's built in post processing functions
void housekeeping_task_user(void) {
    // Runs at the end of each scan loop
    #ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
    #endif
}

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


void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Runs after each keypress
    #ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
    #endif
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Runs after each pointing device task to refresh RBG timer when mouse is in use
    // Note: QMK firmware does not make is_auto_mouse_active() globally available, so the following files must be edited in the linked QMK source
    //   quantum/pointing_device/pointing_device_auto_mouse.c: Change is_auto_mouse_active() signature to bool
    //   quantum/pointing_device/pointing_device_auto_mouse.h: Add header
    #ifdef RGBLIGHT_TIMEOUT
    if(is_auto_mouse_active()) refresh_rgb();
    #endif
    return mouse_report;
}

void suspend_power_down_user(void) {
    rgblight_suspend();
}

void suspend_wakeup_init_user(void) {
    rgblight_wakeup();
}
