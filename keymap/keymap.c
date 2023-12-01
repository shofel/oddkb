/* An odd layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

// In hope for the backlight :D
// Disable glow effects to save space
#undef RGBLIGHT_ANIMATIONS
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

// Home-row mods (Boo).
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

// Combos.

const uint16_t PROGMEM esc_combo[] = {OSM_SFT, KC_SPACE, COMBO_END};

// combo_t key_combos[] = {
//     COMBO(esc_combo, KC_ESC),
// };

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_5x6_5(
       KC_ESC ,   KC_F1,   KC_F2,   KC_F3,  KC_F4, KC_F5,     KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_ESC,
           __ , KC_QUOT, KC_COMM,    KC_U,   KC_C,  KC_V,     KC_Q,  KC_F,  KC_D,  KC_L,  KC_Y,   KC_SLASH,
           __ ,   GUI_A,   ALT_O,   LT3_E,  CTL_S,  KC_G,     KC_B,  CTL_N, LT3_T, ALT_R, GUI_I,  KC_MINUS,
       QK_BOOT, KC_SCLN,    KC_X,  KC_DOT,   KC_W,  KC_Z,     KC_P,  KC_H,  KC_M,  KC_K,  KC_J,   QK_BOOT,

       KC_F11, KC_F12,    OSM_SFT ,  OSL(2) , TG(1)  ,    KC_NO  , KC_ENTER  , KC_SPACE,   KC_UP, KC_DOWN,
                                     OSL(4) , KC_NO  ,    KC_NO  , KC_NO), 

  [1] = LAYOUT_5x6_5( // qwerty for Russian
       KC_ESC ,   SFT_1,   SFT_2,   SFT_3,  SFT_4, SFT_5,     SFT_6, SFT_7, SFT_8,   XX,     KC_MINUS, KC_RBRC,
           XX ,    KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,     KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,     KC_LBRC,
       KC_GRV ,   GUI_A,   ALT_S,   LT3_D,  CTL_F,  KC_G,     KC_H,  CTL_J, LT3_K,   ALT_L,  GUI_SCLN, KC_QUOTE,
           XX ,    KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,     KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_NO,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [2] = LAYOUT_5x6_5( // SYMBOLS
        XX,      XX,        XX,       XX,      XX,      XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,        XX,   KC_DOT, KC_LCBR,      XX,       XX,      KC_RCBR,  XX,       KC_PIPE, XX,      XX,
        XX,  KC_GRV,  KC_SLASH,  KC_LPRN, KC_LBRC,  KC_DEL,       KC_BSPC, KC_RBRC,  KC_RPRN,  KC_BSLS, KC_COLN, XX,
        XX,      XX,        XX,  KC_LABK,      XX,      XX,       XX,       KC_EQL,  KC_RABK,       XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [3] = LAYOUT_5x6_5( // NUMBERS - NAVIGATION
        XX,      XX,        XX,       XX,      XX,      XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX,      XX,      KC_7,     KC_8,    KC_9, KC_PSCR,       KC_HOME, KC_PGUP,  KC_UP,    KC_PGDN, KC_END,  XX,
        XX,    KC_0,      KC_4,     KC_5,    KC_6,  KC_DEL,       KC_BSPC, KC_LEFT,  KC_ENTER, KC_RGHT, XX,      XX,
        XX,    KC_0,      KC_1,     KC_2,    KC_3,      XX,       XX,      KC_TAB,   KC_DOWN,  XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),

  [4] = LAYOUT_5x6_5( // brightness volume keeb-rgb
        XX,      XX,   RGB_VAI,  RGB_M_P,      XX,      XX,       XX,      XX,       XX,       XX,      XX,      XX,
        XX, RGB_SAD,   RGB_TOG,  RGB_SAI,      XX,      XX,       XX, KC_BRIU,  KC_VOLU,       XX,      XX,      XX,
        XX,      XX,   RGB_VAD,       XX,      XX,      XX,       XX,      XX,  KC_MUTE,       XX,      XX,      XX,
        XX,      XX,        XX,       XX,      XX,      XX,       XX, KC_BRID,  KC_VOLD,       XX,      XX,      XX,

           __ ,     __ ,    KC_LSFT ,     __  ,    __  ,       __  ,    __  ,    __,          __ ,     __ ,
                                          __  ,    __  ,       __  ,    __ ),
 };
