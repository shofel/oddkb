/* A layout for the Dactyl Manuform 5x6_5 Keyboard */

// TODO dvorak layer
// TODO combo mods
// TODO mouse control
// TODO arrow up + 
// TODO type "make" + arrow up

#include QMK_KEYBOARD_H

// Home-row mods (Boo).
// TODO rename LT3
//
#define GUI_A LGUI_T(KC_A)
#define ALT_O LALT_T(KC_O)
#define LT3_E LT(3, KC_E)
#define CTL_S LCTL_T(KC_S)
//
#define CTL_N RCTL_T(KC_N)
#define LT3_T LT(3, KC_T)
#define ALT_R RALT_T(KC_R)
#define GUI_I RGUI_T(KC_I)

// Home-row mods (qwerty).
// TODO rename LT3
//
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define LT3_D LT(3, KC_D)
#define CTL_F LCTL_T(KC_F)
//
#define CTL_J RCTL_T(KC_J)
#define LT3_K LT(3, KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCLN RGUI_T(KC_SCLN)

#define OSM_SFT OSM(MOD_LSFT)

/* Key aliases */

#define __ KC_TRNS
#define XX KC_NO

#define SFT_1 LSFT(KC_1)
#define SFT_2 LSFT(KC_2)
#define SFT_3 LSFT(KC_3)
#define SFT_4 LSFT(KC_4)
#define SFT_5 LSFT(KC_5)
#define SFT_6 LSFT(KC_6)
#define SFT_7 LSFT(KC_7)
#define SFT_8 LSFT(KC_8)

/* Layer names */
enum my_layer_names {
  L_BOO,
  L_QWERTY,
  L_SYMBOLS,
  L_NUM_NAV,
  L_RGB_SYSTEM,
  L_MOUSE,
  L_6,
  L_7,
  L_8,
};

#define TG_QWER TG(L_QWERTY)
#define OSL_SYM OSL(L_SYMBOLS)
#define OSL_SYS OSL(L_RGB_SYSTEM)
#define MO_MOUS MO(L_MOUSE)

/* Combos */

#define COMBO_ONLY_FROM_LAYER 0

const uint16_t PROGMEM esc_combo[] = {OSM_SFT, KC_SPACE, COMBO_END};
const uint16_t PROGMEM mouse_combo[] = {OSL_SYM,OSL_SYS, COMBO_END};

combo_t key_combos[] = {
  COMBO(esc_combo, KC_ESC),
  COMBO(mouse_combo, MO_MOUS)
};

/* The keymap */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_BOO] = LAYOUT_5x6_5(/* BOO LAYOUT
       esc f1  f2  f3  f4  f5                       f6  f7  f8  f9  f10 esc
       --- '   ,   u   c   v                        q   f   d   l   y   /
       --- a   o   e   s   g                        b   n   t   r   i   -
       rst :   x   .   w   z                        p   h   m   k   j   rst
               f11 f12     sft SYM QWE     --- ret  spc     up  dwn
                               SYS ---     --- ---
       */
       KC_ESC ,   KC_F1,   KC_F2,   KC_F3,  KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_ESC,
           __ , KC_QUOT, KC_COMM,    KC_U,   KC_C,  KC_V,     KC_Q,  KC_F,  KC_D,  KC_L,  KC_Y,   KC_SLASH,
           __ ,   GUI_A,   ALT_O,   LT3_E,  CTL_S,  KC_G,     KC_B,  CTL_N, LT3_T, ALT_R, GUI_I,  KC_MINUS,
       QK_BOOT, KC_SCLN,    KC_X,  KC_DOT,   KC_W,  KC_Z,     KC_P,  KC_H,  KC_M,  KC_K,  KC_J,   QK_BOOT,

       KC_F11, KC_F12,    OSM_SFT , OSL_SYM , TG_QWER,    KC_NO  , KC_ENTER  , KC_SPACE,   KC_UP, KC_DOWN,
                                    OSL_SYS , KC_NO  ,    KC_NO  , KC_NO), 

  [L_QWERTY] = LAYOUT_5x6_5( // TODO why f-keys are replaced with shifted nums?
       KC_ESC ,   SFT_1,   SFT_2,   SFT_3,  SFT_4, SFT_5,     SFT_6, SFT_7, SFT_8,   XX,     KC_MINUS, KC_RBRC,
           XX ,    KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     KC_LBRC,
       KC_GRV ,   GUI_A,   ALT_S,   LT3_D,  CTL_F,  KC_G,     KC_H,  CTL_J, LT3_K,   ALT_L,  GUI_SCLN, KC_QUOTE,
           XX ,    KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_NO,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [L_SYMBOLS] = LAYOUT_5x6_5(/*
        __  __  __  __  __  __                       __  __  __  __  __  __
        __  __  __  .   {   __                       __  }   __  __  __  __
        __  `   /   (   [   del                      bs  ]   )   \   :   __
        __  __  __  <   +   __                       __  =   >   __  __  __
                __  __      sft ___ ___     ___ ___  ___     __  __
                                ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,      XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,   KC_DOT, KC_LCBR,      XX,       XX,      KC_RCBR,  XX,       KC_PIPE, XX,      XX,
        XX,  KC_GRV,  KC_SLASH,  KC_LPRN, KC_LBRC,  KC_DEL,       KC_BSPC, KC_RBRC,  KC_RPRN,  KC_BSLS, KC_COLN, XX,
        XX,      XX,        XX,  KC_LABK, KC_PLUS,      XX,       XX,       KC_EQL,  KC_RABK,       XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [L_NUM_NAV] = LAYOUT_5x6_5(/*
        __  __  __  __  __  __                       __  __  __  __  __  __
        __  __  7   8   9   scr                      __  }   __  __  __  __
        __  0   4   5   6   del                      bs  ]   )   \   :   __
        __  0   1   2   3   __                       __  =   >   __  __  __
                __  __      sft ___ ___     ___ ___  ___     __  __
                                ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,      XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,      KC_7,     KC_8,    KC_9, KC_PSCR,       KC_HOME, KC_PGUP,  KC_UP,    KC_PGDN, KC_END,  XX,
        XX,    KC_0,      KC_4,     KC_5,    KC_6,  KC_DEL,       KC_BSPC, KC_LEFT,  KC_ENTER, KC_RGHT, XX,      XX,
        XX,    KC_0,      KC_1,     KC_2,    KC_3,      XX,       XX,      KC_TAB,   KC_DOWN,  XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [L_RGB_SYSTEM] = LAYOUT_5x6_5(/* TODO replace arrows with unicode
        __  __  __  __  __  __                       __  __  __  __  __  __
        __  __  hu^ br^ mod __                       __  br^ vup __  __  __
        __  __  sav tog sa^ __                       __  __  mut __  __  __
        __  __  huv brv m_p __                       __  brv vdn __  __  __
                __  __      sft ___ ___     ___ ___  ___     __  __
                                ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,   RGB_HUI,  RGB_VAI, RGB_MOD,     XX,       XX, KC_BRIU,  KC_VOLU,       XX,      XX,      XX,
        XX,      XX,   RGB_SAD,  RGB_TOG, RGB_SAI,     XX,       XX,      XX,  KC_MUTE,       XX,      XX,      XX,
        XX,      XX,   RGB_HUD,  RGB_VAD, RGB_M_P,     XX,       XX, KC_BRID,  KC_VOLD,       XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),
  
  [L_MOUSE] = LAYOUT_5x6_5(/*
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  w_^ ↑   b2  __  __
        __ __  __  __  __  __                       __  <-- b1  --> __  __
        __ __  __  __  __  __                       __  w_v dn  __  __  __
               __  __      sft ___ ___     ___ ___  ___       __  __
                               ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX, KC_WH_U,  KC_MS_U,  KC_BTN2,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX, KC_MS_L,  KC_BTN1,  KC_MS_R,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX, KC_WH_D,  KC_MS_D,       XX,      XX,      XX,

           __ ,     __ ,         __ ,     __  ,    __  ,          __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,          __  ,    __ ),
  
  [L_6] = LAYOUT_5x6_5(/*
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
               __  __      __  ___ ___     ___ ___  ___       __  __
                               ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,

           __ ,     __ ,         __ ,     __  ,    __  ,          __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,          __  ,    __ ),
  
  [L_7] = LAYOUT_5x6_5(/*
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
               __  __      __  ___ ___     ___ ___  ___       __  __
                               ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,

           __ ,     __ ,         __ ,     __  ,    __  ,          __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,          __  ,    __ ),
  
  [L_8] = LAYOUT_5x6_5(/*
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
        __ __  __  __  __  __                       __  __  __  __  __  __
               __  __      __  ___ ___     ___ ___  ___       __  __
                               ___ ___     ___ ___
       */
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,     XX,       XX,      XX,       XX,       XX,      XX,      XX,

           __ ,     __ ,         __ ,     __  ,    __  ,          __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,          __  ,    __ ),
 };
