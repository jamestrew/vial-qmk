/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

enum custom_layers {
    _WORKMAN,
    _PLACEHOLDER_1,
    _PLACEHOLDER_2,
    _SYM,
    _HJKL,
    _MEDIA
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬─────┬────────────┬──────┬───────────┬─────┐                              ┌──────┬──────────┬─────┬─────┬─────┬──────┐
//    │ esc  │  1  │     2      │  3   │     4     │  5  │                              │  6   │    7     │  8  │  9  │  0  │ del  │
//    ├──────┼─────┼────────────┼──────┼───────────┼─────┤                              ├──────┼──────────┼─────┼─────┼─────┼──────┤
//    │ tab  │  q  │     d      │  r   │     w     │  b  │                              │  j   │    f     │  u  │  p  │  `  │  :   │
//    ├──────┼─────┼────────────┼──────┼───────────┼─────┤                              ├──────┼──────────┼─────┼─────┼─────┼──────┤
//    │  \   │  a  │     s      │  h   │     t     │  g  │                              │  y   │    n     │  e  │  o  │  i  │  '   │
//    ├──────┼─────┼────────────┼──────┼───────────┼─────┤                              ├──────┼──────────┼─────┼─────┼─────┼──────┤
//    │ lsft │  z  │     x      │  m   │     c     │  v  │                              │  k   │    l     │  ,  │  .  │  /  │ rsft │
//    ├──────┼─────┼────────────┼──────┼───────────┴─────┘                              └──────┴──────────┼─────┼─────┼─────┼──────┤
//    │ lctl │     │ MO(_MEDIA) │ lalt │                                                                  │     │     │     │      │
//    └──────┴─────┴────────────┴──────┼───────────┬─────┐                              ┌──────┬──────────┼─────┴─────┴─────┴──────┘
//                                     │ MO(_HJKL) │ spc │                              │ bspc │ MO(_SYM) │
//                                     └───────────┴─────┼──────┬──────┐   ┌─────┬──────┼──────┴──────────┘
//                                                       │ lgui │ lsft │   │     │ rctl │
//                                                       ├──────┼──────┤   ├─────┼──────┤
//                                                       │ ent  │      │   │     │ esc  │
//                                                       └──────┴──────┘   └─────┴──────┘
[_WORKMAN] = LAYOUT_manuform_num(
  KC_ESC  , KC_1    , KC_2       , KC_3    , KC_4      , KC_5   ,                                              KC_6    , KC_7     , KC_8    , KC_9    , KC_0     , KC_DEL  ,
  KC_TAB  , KC_Q    , KC_D       , KC_R    , KC_W      , KC_B   ,                                              KC_J    , KC_F     , KC_U    , KC_P    , KC_GRAVE , KC_COLON,
  KC_BSLS , KC_A    , KC_S       , KC_H    , KC_T      , KC_G   ,                                              KC_Y    , KC_N     , KC_E    , KC_O    , KC_I     , KC_QUOT ,
  KC_LSFT , KC_Z    , KC_X       , KC_M    , KC_C      , KC_V   ,                                              KC_K    , KC_L     , KC_COMM , KC_DOT  , KC_SLSH  , KC_RSFT ,
  KC_LCTL , KC_TRNS , MO(_MEDIA) , KC_LALT ,                                                                                        KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS ,
                                             MO(_HJKL) , KC_SPC ,                                              KC_BSPC , MO(_SYM)                                          ,
                                                                  KC_LGUI  , KC_LSFT ,     KC_TRNS , KC_RCTL                                                               ,
                                                                  KC_ENTER , KC_TRNS ,     KC_TRNS , KC_ESC
),

//    ┌──────┬─────┬────────────┬──────┬─────┬─────┐                            ┌───────────┬─────┬─────┬─────┬─────┬──────┐
//    │ esc  │  1  │     2      │  3   │  4  │  5  │                            │     6     │  7  │  8  │  9  │  0  │      │
//    ├──────┼─────┼────────────┼──────┼─────┼─────┤                            ├───────────┼─────┼─────┼─────┼─────┼──────┤
//    │ tab  │  q  │     d      │  r   │  w  │  b  │                            │     j     │  f  │  u  │  p  │  `  │  :   │
//    ├──────┼─────┼────────────┼──────┼─────┼─────┤                            ├───────────┼─────┼─────┼─────┼─────┼──────┤
//    │  \   │  a  │     s      │  h   │  t  │  g  │                            │     y     │  n  │  e  │  o  │  i  │  '   │
//    ├──────┼─────┼────────────┼──────┼─────┼─────┤                            ├───────────┼─────┼─────┼─────┼─────┼──────┤
//    │ lsft │  z  │     x      │  m   │  c  │  v  │                            │     k     │  l  │  ,  │  .  │  /  │ rsft │
//    ├──────┼─────┼────────────┼──────┼─────┴─────┘                            └───────────┴─────┼─────┼─────┼─────┼──────┤
//    │ lctl │     │ MO(_MEDIA) │ lalt │                                                          │     │     │     │      │
//    └──────┴─────┴────────────┴──────┼─────┬─────┐                            ┌───────────┬─────┼─────┴─────┴─────┴──────┘
//                                     │     │     │                            │ MO(_HJKL) │ spc │
//                                     └─────┴─────┼──────┬─────┐   ┌─────┬─────┼───────────┴─────┘
//                                                 │      │ ent │   │     │     │
//                                                 ├──────┼─────┤   ├─────┼─────┤
//                                                 │ rctl │     │   │     │ esc │
//                                                 └──────┴─────┘   └─────┴─────┘
[_PLACEHOLDER_1] = LAYOUT_manuform_num(
  KC_ESC  , KC_1    , KC_2       , KC_3    , KC_4    , KC_5    ,                                             KC_6      , KC_7   , KC_8    , KC_9    , KC_0     , KC_TRNS ,
  KC_TAB  , KC_Q    , KC_D       , KC_R    , KC_W    , KC_B    ,                                             KC_J      , KC_F   , KC_U    , KC_P    , KC_GRAVE , KC_COLON,
  KC_BSLS , KC_A    , KC_S       , KC_H    , KC_T    , KC_G    ,                                             KC_Y      , KC_N   , KC_E    , KC_O    , KC_I     , KC_QUOT ,
  KC_LSFT , KC_Z    , KC_X       , KC_M    , KC_C    , KC_V    ,                                             KC_K      , KC_L   , KC_COMM , KC_DOT  , KC_SLSH  , KC_RSFT ,
  KC_LCTL , KC_TRNS , MO(_MEDIA) , KC_LALT ,                                                                                      KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS ,
                                             KC_TRNS , KC_TRNS ,                                             MO(_HJKL) , KC_SPC                                          ,
                                                                 KC_TRNS , KC_ENT  ,     KC_TRNS , KC_TRNS                                                               ,
                                                                 KC_RCTL , KC_TRNS ,     KC_TRNS , KC_ESC
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │                           │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┴─────┘                           └─────┴─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │                                                   │     │     │     │     │
//    └─────┴─────┴─────┴─────┼─────┬─────┐                           ┌─────┬─────┼─────┴─────┴─────┴─────┘
//                            │     │     │                           │     │     │
//                            └─────┴─────┼─────┬─────┐   ┌─────┬─────┼─────┴─────┘
//                                        │     │     │   │     │     │
//                                        ├─────┼─────┤   ├─────┼─────┤
//                                        │     │     │   │     │     │
//                                        └─────┴─────┘   └─────┴─────┘
[_PLACEHOLDER_2] = LAYOUT_manuform_num(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                                                     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS                                        ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS                                                            ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │ f1  │ f2  │ f3  │ f4  │ f5  │                           │ f6  │ f7  │ f8  │ f9  │ f10 │ f11 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  !  │  @  │  {  │  (  │  [  │                           │  ]  │  (  │  }  │  &  │  *  │ f12 │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │  *  │  1  │  2  │  3  │  4  │  5  │                           │  6  │  7  │  8  │  9  │  0  │  .  │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  %  │  ^  │  #  │  =  │  +  │                           │  -  │  _  │  $  │  |  │  ~  │  ,  │
//    ├─────┼─────┼─────┼─────┼─────┴─────┘                           └─────┴─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │                                                   │     │     │     │     │
//    └─────┴─────┴─────┴─────┼─────┬─────┐                           ┌─────┬─────┼─────┴─────┴─────┴─────┘
//                            │     │     │                           │ ent │     │
//                            └─────┴─────┼─────┬─────┐   ┌─────┬─────┼─────┴─────┘
//                                        │     │     │   │     │     │
//                                        ├─────┼─────┤   ├─────┼─────┤
//                                        │     │     │   │     │     │
//                                        └─────┴─────┘   └─────┴─────┘
[_SYM] = LAYOUT_manuform_num(
  KC_TRNS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                             KC_F6    , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  ,
  KC_TRNS , KC_EXLM , KC_AT   , KC_LCBR , KC_LPRN , KC_LBRC ,                                             KC_RBRC  , KC_LPRN , KC_RCBR , KC_AMPR , KC_ASTR , KC_F12  ,
  KC_ASTR , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    ,                                             KC_6     , KC_7    , KC_8    , KC_9    , KC_0    , KC_DOT  ,
  KC_TRNS , KC_PERC , KC_CIRC , KC_HASH , KC_EQL  , KC_PLUS ,                                             KC_MINUS , KC_UNDS , KC_DLR  , KC_PIPE , KC_TILD , KC_COMMA,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                                                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
                                          KC_TRNS , KC_TRNS ,                                             KC_ENTER , KC_TRNS                                         ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS                                                              ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬─────┬──────┬─────┬─────┐                           ┌──────┬──────┬─────┬─────┬─────┬─────┐
//    │      │      │     │      │     │     │                           │      │      │     │     │     │     │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                           ├──────┼──────┼─────┼─────┼─────┼─────┤
//    │ pgdn │      │     │      │     │     │                           │ down │      │     │     │     │     │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                           ├──────┼──────┼─────┼─────┼─────┼─────┤
//    │ pgup │ home │     │ left │     │     │                           │      │      │     │     │ end │     │
//    ├──────┼──────┼─────┼──────┼─────┼─────┤                           ├──────┼──────┼─────┼─────┼─────┼─────┤
//    │      │      │     │ bspc │ del │     │                           │  up  │ rght │     │     │     │     │
//    ├──────┼──────┼─────┼──────┼─────┴─────┘                           └──────┴──────┼─────┼─────┼─────┼─────┤
//    │      │      │     │      │                                                     │     │     │     │     │
//    └──────┴──────┴─────┴──────┼─────┬─────┐                           ┌──────┬──────┼─────┴─────┴─────┴─────┘
//                               │     │     │                           │      │      │
//                               └─────┴─────┼─────┬─────┐   ┌─────┬─────┼──────┴──────┘
//                                           │     │     │   │     │     │
//                                           ├─────┼─────┤   ├─────┼─────┤
//                                           │     │     │   │     │     │
//                                           └─────┴─────┘   └─────┴─────┘
[_HJKL] = LAYOUT_manuform_num(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_PGDN , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_DOWN , KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_PGUP , KC_HOME , KC_TRNS , KC_LEFT , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS  , KC_TRNS , KC_TRNS , KC_END  , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_BSPC , KC_DEL  , KC_TRNS ,                                             KC_UP   , KC_RIGHT , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                                                      KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS                                         ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS                                                             ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
),

//    ┌──────┬──────┬──────┬─────┬─────┬─────┐                           ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │ mprv │ mply │ mnxt │     │     │     │                           │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │ vold │ mute │ volu │     │     │     │                           │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │     │     │                           │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┼─────┤                           ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │     │     │                           │     │     │     │     │     │     │
//    ├──────┼──────┼──────┼─────┼─────┴─────┘                           └─────┴─────┼─────┼─────┼─────┼─────┤
//    │      │      │      │     │                                                   │     │     │     │     │
//    └──────┴──────┴──────┴─────┼─────┬─────┐                           ┌─────┬─────┼─────┴─────┴─────┴─────┘
//                               │     │     │                           │     │     │
//                               └─────┴─────┼─────┬─────┐   ┌─────┬─────┼─────┴─────┘
//                                           │     │     │   │     │     │
//                                           ├─────┼─────┤   ├─────┼─────┤
//                                           │     │     │   │     │     │
//                                           └─────┴─────┘   └─────┴─────┘
[_MEDIA] = LAYOUT_manuform_num(
  KC_MPRV , KC_MPLY , KC_MNXT , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_VOLD , KC_MUTE , KC_VOLU , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                                                                                     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS,
                                          KC_TRNS , KC_TRNS ,                                             KC_TRNS , KC_TRNS                                        ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS                                                            ,
                                                              KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS
)
};
