/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or   
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



#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_CUT LCTL(KC_X)


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  BATTLEFIELD,
  LOWER,
  RAISE,
  NUM,
  FUNC,
  BACKLIT
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , AC_TOGG  ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_EQL  ,
    KC_TAB   , LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                           KC_H     , LSFT_T(KC_J),   LCTL_T(KC_K),   LALT_T(KC_L),  LGUI_T(KC_SCLN)  , TO(1)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LBRC  ,                       KC_RBRC, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    KC_LCTL  , KC_LGUI  , KC_DEL, KC_LALT ,LT(3, KC_DEL),LT(2,KC_SPC),LT(4, KC_TAB),             KC_BSPC,  LT(2,KC_ENT),LT(3,KC_LNG2),KC_RGUI, _______ , KC_DEL  , KC_PSCR
  ),
  [1] = LAYOUT_universal(
    KC_ESC   , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_DEL   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_INT3  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , TO(0)  ,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LBRC  ,                       KC_RBRC, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    KC_LCTL  , KC_LGUI  , KC_DEL   , KC_LALT  , MO(2) , KC_SPC    , KC_TAB,                KC_BSPC ,  LT(2,KC_ENT),LT(2,KC_LNG2),KC_RGUI, _______ , KC_DEL  , KC_PSCR
  ),
   
  [2] = LAYOUT_universal(
    KC_GRV  , KC_F1    , KC_F2    , KC_F3    , KC_F4     , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,  _______  ,
    _______ , KC_F11  , KC_F12    , KC_UNDS     , KC_BSLS     , S(KC_BSLS)  ,                                  _______  , KC_LEFT  , KC_UP    , KC_RGHT  , _______  , _______   ,
    _______ , KC_HOME  , KC_END     , KC_MINS      , KC_EQL   ,_______ ,                             KC_PGUP  , KC_BTN1  , KC_DOWN  , KC_BTN2  , KC_BTN3  , _______  ,j
    _______  , KC_PPLS  , KC_CUT     , KC_COPY     , KC_PASTE  , KC_SCLN   , KC_QUOT  ,          KC_DQT, KC_PGDN  ,  KC_HOME  ,KC_END   , KC_PGUP  , KC_PGDN ,  _______  ,
    _______  , KC_PAST  , KC_DOT     , KC_0   , LT(3, KC_DEL),LT(2,KC_SPC),LT(4, KC_TAB),               KC_BSPC  , LT(4, KC_DEL)   , _______  , _______  , _______  , KC_DEL  , _______
  ),
  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_50  , _______  , SSNP_FRE  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SSNP_VRT  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SSNP_HOR  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU  , KBC_SAVE   ,
    QK_BOOT  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            KC_BSPC  , KC_DEL  , _______  , _______  , _______  , KC_DEL  , QK_BOOT
  ),
  [4] = LAYOUT_universal(
    KC_GRV  , _______    , _______    , KC_PAST    , KC_PSLS     , _______    ,                    _______    ,    _______  , _______    , _______ , _______   , KC_NUM   ,
    _______  , _______  , KC_P7    , KC_P8    , KC_P9   , KC_PMNS  ,                                     _______   ,  KC_P7    , KC_P8    , KC_P9  ,KC_PMNS  , KC_CALC,
    _______ , _______  ,KC_P4     , KC_P5   , KC_P6  , KC_PPLS  ,                                  KC_DOT    ,  KC_P4     , KC_P5   , KC_P6  ,KC_PSLS  ,_______,
    _______  , _______  , KC_P1     , KC_P2   , KC_P3  , _______  , _______   ,              _______   , KC_0  ,  KC_P1     , KC_P2   , KC_P3  ,KC_PPLS  ,_______,
    _______  , _______  , _______  , KC_DOT     , KC_0    , _______  , _______  ,              KC_BSPC  , KC_DEL    ,  KC_DOT     , KC_0   , KC_DEL ,KC_PAST  ,_______
  ),

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 4);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
