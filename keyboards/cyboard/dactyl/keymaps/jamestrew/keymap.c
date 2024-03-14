/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include "action_layer.h"
#include "keyboard.h"
#include "keymap_us.h"
#include "quantum.h"
#include "rgb_matrix.h"
#include "process_tap_dance.h"
#include QMK_KEYBOARD_H

#define LAYER_CYCLE_START 0
#define LAYER_CYCLE_END 2

#define DEFAULT_PINK 213, 100, 50
#define DIM_RED 0, 255, 50
#define DIM_YELLOW 43, 255, 50
#define DIM_BLUE 170, 255, 50
#define DIM_AZURE 132, 102, 50
#define DIM_TEAL 128, 255, 50

enum custom_layers { _WORKMAN, _WASD, _DVORAK, _SYM, _HJKL, _MEDIA };

enum custom_keycodes {
    KC_CYCLE_LAYER = QK_USER,
};

enum tap_dance_keycodes {
    DANCE_0,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬─────┬────────────┬──────┬───────────┬─────┐                         ┌──────┬──────────┬─────┬─────┬─────┬─────────────┐
//    │ TD(DANCE_0) │  1  │     2      │  3   │     4     │  5  │                         │  6   │    7     │  8  │  9  │  0  │             │
//    ├─────────────┼─────┼────────────┼──────┼───────────┼─────┤                         ├──────┼──────────┼─────┼─────┼─────┼─────────────┤
//    │     tab     │  q  │     d      │  r   │     w     │  b  │                         │  j   │    f     │  u  │  p  │  `  │             │
//    ├─────────────┼─────┼────────────┼──────┼───────────┼─────┤                         ├──────┼──────────┼─────┼─────┼─────┼─────────────┤
//    │      \      │  a  │     s      │  h   │     t     │  g  │                         │  y   │    n     │  e  │  o  │  i  │      '      │
//    ├─────────────┼─────┼────────────┼──────┼───────────┼─────┤                         ├──────┼──────────┼─────┼─────┼─────┼─────────────┤
//    │    lsft     │  z  │     x      │  m   │     c     │  v  │                         │  k   │    l     │  ,  │  .  │  /  │  sEMICOLON  │
//    ├─────────────┼─────┼────────────┼──────┼───────────┼─────┼──────┐           ┌──────┼──────┼──────────┼─────┼─────┼─────┼─────────────┤
//    │    lctl     │     │ MO(_MEDIA) │ lalt │ MO(_HJKL) │ spc │ ent  │           │ rctl │ rsft │ MO(_SYM) │     │     │     │ cYCLE_LAYER │
//    └─────────────┴─────┴────────────┴──────┼───────────┼─────┼──────┤           ├──────┼──────┼──────────┼─────┴─────┴─────┴─────────────┘
//                                            │   bspc    │ del │ lgui │           │      │      │   esc    │
//                                            └───────────┴─────┴──────┘           └──────┴──────┴──────────┘
[_WORKMAN] = LAYOUT_manuform_num(
  TD(DANCE_0) , KC_1    , KC_2       , KC_3    , KC_4      , KC_5   ,                                 KC_6    , KC_7     , KC_8    , KC_9    , KC_0     , _______       ,
  KC_TAB      , KC_Q    , KC_D       , KC_R    , KC_W      , KC_B   ,                                 KC_J    , KC_F     , KC_U    , KC_P    , KC_GRAVE , _______       ,
  KC_BSLS     , KC_A    , KC_S       , KC_H    , KC_T      , KC_G   ,                                 KC_Y    , KC_N     , KC_E    , KC_O    , KC_I     , KC_QUOT       ,
  KC_LSFT     , KC_Z    , KC_X       , KC_M    , KC_C      , KC_V   ,                                 KC_K    , KC_L     , KC_COMM , KC_DOT  , KC_SLSH  , KC_SEMICOLON  ,
  KC_LCTL     , _______ , MO(_MEDIA) , KC_LALT , MO(_HJKL) , KC_SPC , KC_ENT  ,             KC_RCTL , KC_RSFT , MO(_SYM) , _______ , _______ , _______  , KC_CYCLE_LAYER,
                                                 KC_BSPC   , KC_DEL , KC_LGUI ,             _______ , _______ , KC_ESC
),

//    ┌──────┬─────┬────────────┬──────┬───┬─────┐                         ┌──────┬─────┬─────┬─────┬─────┬──────────────┐
//    │ esc  │  1  │     2      │  3   │ 4 │  5  │                         │  6   │  7  │  8  │  9  │  0  │              │
//    ├──────┼─────┼────────────┼──────┼───┼─────┤                         ├──────┼─────┼─────┼─────┼─────┼──────────────┤
//    │ tab  │  b  │     q      │  w   │ e │  r  │                         │      │     │     │     │     │              │
//    ├──────┼─────┼────────────┼──────┼───┼─────┤                         ├──────┼─────┼─────┼─────┼─────┼──────────────┤
//    │  y   │  m  │     a      │  s   │ d │  f  │                         │      │     │     │     │     │              │
//    ├──────┼─────┼────────────┼──────┼───┼─────┤                         ├──────┼─────┼─────┼─────┼─────┼──────────────┤
//    │ lsft │  h  │     z      │  x   │ c │  v  │                         │      │     │     │     │     │ TO(_WORKMAN) │
//    ├──────┼─────┼────────────┼──────┼───┼─────┼──────┐           ┌──────┼──────┼─────┼─────┼─────┼─────┼──────────────┤
//    │ lctl │     │ MO(_MEDIA) │ lalt │ g │ spc │ ent  │           │ rctl │ rsft │     │     │     │     │ cYCLE_LAYER  │
//    └──────┴─────┴────────────┴──────┼───┼─────┼──────┤           ├──────┼──────┼─────┼─────┴─────┴─────┴──────────────┘
//                                     │ t │  6  │ lgui │           │      │      │     │
//                                     └───┴─────┴──────┘           └──────┴──────┴─────┘
[_WASD] = LAYOUT_manuform_num(
  KC_ESC  , KC_1    , KC_2       , KC_3    , KC_4 , KC_5   ,                                 KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______       ,
  KC_TAB  , KC_B    , KC_Q       , KC_W    , KC_E , KC_R   ,                                 _______ , _______ , _______ , _______ , _______ , _______       ,
  KC_Y    , KC_M    , KC_A       , KC_S    , KC_D , KC_F   ,                                 _______ , _______ , _______ , _______ , _______ , _______       ,
  KC_LSFT , KC_H    , KC_Z       , KC_X    , KC_C , KC_V   ,                                 _______ , _______ , _______ , _______ , _______ , TO(_WORKMAN)  ,
  KC_LCTL , _______ , MO(_MEDIA) , KC_LALT , KC_G , KC_SPC , KC_ENT  ,             KC_RCTL , KC_RSFT , _______ , _______ , _______ , _______ , KC_CYCLE_LAYER,
                                             KC_T , KC_6   , KC_LGUI ,             _______ , _______ , _______
),

//    ┌─────┬───────────┬──────┬────┬──────┬──────┐                         ┌──────┬──────┬──────┬──────┬──────┬─────────────┐
//    │ esc │     1     │  2   │ 3  │  4   │  5   │                         │  6   │  7   │  8   │  9   │  0   │      `      │
//    ├─────┼───────────┼──────┼────┼──────┼──────┤                         ├──────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ tab │     '     │  ,   │ .  │  p   │  y   │                         │  f   │  g   │  c   │  r   │  l   │      /      │
//    ├─────┼───────────┼──────┼────┼──────┼──────┤                         ├──────┼──────┼──────┼──────┼──────┼─────────────┤
//    │ ent │     a     │  o   │ e  │  u   │  i   │                         │  d   │  h   │  t   │  n   │  s   │      -      │
//    ├─────┼───────────┼──────┼────┼──────┼──────┤                         ├──────┼──────┼──────┼──────┼──────┼─────────────┤
//    │  [  │ sEMICOLON │  q   │ j  │  k   │  x   │                         │  b   │  m   │  w   │  v   │  z   │      ]      │
//    ├─────┼───────────┼──────┼────┼──────┼──────┼──────┐           ┌──────┼──────┼──────┼──────┼──────┼──────┼─────────────┤
//    │     │     \     │ down │ up │      │ lsft │ lalt │           │ bspc │ spc  │ lgui │ left │ rght │ ralt │ cYCLE_LAYER │
//    └─────┴───────────┴──────┴────┼──────┼──────┼──────┤           ├──────┼──────┼──────┼──────┴──────┴──────┴─────────────┘
//                                  │ lctl │ end  │ home │           │ pgup │ pgdn │  =   │
//                                  └──────┴──────┴──────┘           └──────┴──────┴──────┘
[_DVORAK] = LAYOUT_manuform_num(
  KC_ESC  , KC_1         , KC_2    , KC_3   , KC_4    , KC_5    ,                                 KC_6    , KC_7    , KC_8    , KC_9     , KC_0    , KC_GRAVE      ,
  KC_TAB  , KC_QUOT      , KC_COMM , KC_DOT , KC_P    , KC_Y    ,                                 KC_F    , KC_G    , KC_C    , KC_R     , KC_L    , KC_SLSH       ,
  KC_ENT  , KC_A         , KC_O    , KC_E   , KC_U    , KC_I    ,                                 KC_D    , KC_H    , KC_T    , KC_N     , KC_S    , KC_MINUS      ,
  KC_LBRC , KC_SEMICOLON , KC_Q    , KC_J   , KC_K    , KC_X    ,                                 KC_B    , KC_M    , KC_W    , KC_V     , KC_Z    , KC_RBRC       ,
  _______ , KC_BSLS      , KC_DOWN , KC_UP  , _______ , KC_LSFT , KC_LALT ,             KC_BSPC , KC_SPC  , KC_LGUI , KC_LEFT , KC_RIGHT , KC_RALT , KC_CYCLE_LAYER,
                                              KC_LCTL , KC_END  , KC_HOME ,             KC_PGUP , KC_PGDN , KC_EQL
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │ f1  │ f2  │ f3  │ f4  │ f5  │                       │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  !  │  @  │  {  │  (  │  [  │                       │  ]  │  )  │  }  │  &  │  *  │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │  *  │  1  │  2  │  3  │  4  │  5  │                       │  6  │  7  │  8  │  9  │  0  │  .  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  %  │  ^  │  #  │  =  │  +  │                       │  -  │  _  │  $  │  |  │  ~  │  ,  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┐           ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │     │           │     │     │     │ ent │     │     │     │
//    └─────┴─────┴─────┴─────┼─────┼─────┼─────┤           ├─────┼─────┼─────┼─────┴─────┴─────┴─────┘
//                            │     │     │     │           │     │     │     │
//                            └─────┴─────┴─────┘           └─────┴─────┴─────┘
[_SYM] = LAYOUT_manuform_num(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                 KC_F6    , KC_F7   , KC_F8    , KC_F9   , KC_F10  , KC_F11  ,
  _______ , KC_EXLM , KC_AT   , KC_LCBR , KC_LPRN , KC_LBRC ,                                 KC_RBRC  , KC_RPRN , KC_RCBR  , KC_AMPR , KC_ASTR , KC_F12  ,
  KC_ASTR , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                                 KC_6     , KC_7    , KC_8     , KC_9    , KC_0    , KC_DOT  ,
  _______ , KC_PERC , KC_CIRC , KC_HASH , KC_EQL  , KC_PLUS ,                                 KC_MINUS , KC_UNDS , KC_DLR   , KC_PIPE , KC_TILD , KC_COMMA,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______  , _______ , KC_ENTER , _______ , _______ , _______ ,
                                          _______ , _______ , _______ ,             _______ , _______  , _______
),

//    ┌──────┬──────┬─────┬──────┬─────┬─────┐                       ┌──────┬──────┬─────┬─────┬─────┬─────────┐
//    │      │      │     │      │     │     │                       │      │      │     │     │     │ QK_BOOT │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                       ├──────┼──────┼─────┼─────┼─────┼─────────┤
//    │ pgup │      │     │      │     │     │                       │ down │      │     │     │     │         │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                       ├──────┼──────┼─────┼─────┼─────┼─────────┤
//    │ pgdn │ home │     │ left │     │     │                       │      │      │     │     │ end │         │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                       ├──────┼──────┼─────┼─────┼─────┼─────────┤
//    │      │      │     │ bspc │ del │     │                       │  up  │ rght │     │     │     │         │
//    ├──────┼──────┼─────┼──────┼─────┼─────┼─────┐           ┌─────┼──────┼──────┼─────┼─────┼─────┼─────────┤
//    │      │      │     │      │     │     │     │           │     │      │      │     │     │     │         │
//    └──────┴──────┴─────┴──────┼─────┼─────┼─────┤           ├─────┼──────┼──────┼─────┴─────┴─────┴─────────┘
//                               │     │     │     │           │     │      │      │
//                               └─────┴─────┴─────┘           └─────┴──────┴──────┘
[_HJKL] = LAYOUT_manuform_num(
  _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______  , _______ , _______ , _______ , QK_BOOT,
  KC_PGUP , _______ , _______ , _______ , _______ , _______ ,                                 KC_DOWN , _______  , _______ , _______ , _______ , _______,
  KC_PGDN , KC_HOME , _______ , KC_LEFT , _______ , _______ ,                                 _______ , _______  , _______ , _______ , KC_END  , _______,
  _______ , _______ , _______ , KC_BSPC , KC_DEL  , _______ ,                                 KC_UP   , KC_RIGHT , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______  , _______ , _______ , _______ , _______,
                                          _______ , _______ , _______ ,             _______ , _______ , _______
),

//    ┌──────┬──────┬──────┬─────┬─────┬─────┐                       ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │ mprv │ mply │ mnxt │     │     │     │                       │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ vold │ mute │ volu │     │     │     │                       │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │     │     │                       │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                       ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │     │     │                       │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┼─────┐           ┌─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │     │     │     │           │     │     │     │     │     │     │     │
//    └──────┴──────┴──────┴─────┼─────┼─────┼─────┤           ├─────┼─────┼─────┼─────┴─────┴─────┴─────┘
//                               │     │     │     │           │     │     │     │
//                               └─────┴─────┴─────┘           └─────┴─────┴─────┘
[_MEDIA] = LAYOUT_manuform_num(
  KC_MPRV , KC_MPLY , KC_MNXT , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______,
  KC_VOLD , KC_MUTE , KC_VOLU , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ ,                                 _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ ,             _______ , _______ , _______ , _______ , _______ , _______ , _______,
                                          _______ , _______ , _______ ,             _______ , _______ , _______
)
};

// clang-format on

static uint8_t current_layer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mod_state;
    mod_state = get_mods();

    switch (keycode) {
        case MO(_HJKL):
            if (mod_state == MOD_BIT(KC_RSFT)) {
                if (record->event.pressed) {
                    register_code(KC_MINUS);
                } else {
                    unregister_code(KC_MINUS);
                }
                return false;
            }
            return true;

        case KC_CYCLE_LAYER:
            if (!record->event.pressed) {
                return false;
            }
            current_layer = get_highest_layer(layer_state);
            if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
                return false;
            }

            uint8_t next_layer = current_layer + 1;
            if (next_layer > LAYER_CYCLE_END) {
                next_layer = LAYER_CYCLE_START;
            }
            layer_move(next_layer);
            return false;
    }
    return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
    current_layer = get_highest_layer(state);

    if (current_layer == _WORKMAN) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
        rgb_matrix_sethsv_noeeprom(DEFAULT_PINK);
        return state;
    }

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    switch (current_layer) {
        case _WASD:
            rgb_matrix_sethsv_noeeprom(DIM_RED);
            break;
        case _DVORAK:
            rgb_matrix_sethsv_noeeprom(DIM_YELLOW);
            break;
        case _SYM:
            rgb_matrix_sethsv_noeeprom(DIM_TEAL);
            break;
        case _HJKL:
            rgb_matrix_sethsv_noeeprom(DIM_AZURE);
            break;
        case _MEDIA:
            rgb_matrix_sethsv_noeeprom(DIM_BLUE);
            break;
    }
    return state;
}

tap_dance_action_t tap_dance_actions_2[] = {
    // Tap once for Escape, twice for Caps Lock
    [DANCE_0] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

void keyboard_post_init_user() {
    debug_enable   = false;
    debug_matrix   = false;
    debug_keyboard = false;

    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    rgb_matrix_sethsv_noeeprom(DEFAULT_PINK);
}
