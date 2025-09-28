#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
};



#define DUAL_FUNC_0 LT(10, KC_F20)
#define DUAL_FUNC_1 LT(3, KC_N)
#define DUAL_FUNC_2 LT(8, KC_E)
#define DUAL_FUNC_3 LT(8, KC_J)
#define DUAL_FUNC_4 LT(12, KC_F18)
#define DUAL_FUNC_5 LT(10, KC_F19)
#define DUAL_FUNC_6 LT(6, KC_8)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    CW_TOGG,        KC_B,           KC_L,           LT(3, KC_D),    KC_W,           KC_Z,                                           KC_MINUS,       KC_F,           KC_O,           KC_U,           KC_J,           KC_EQUAL,       
    KC_DQUO,        MT(MOD_LGUI, KC_N),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S),KC_G,                                           KC_Y,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A),MT(MOD_LALT, KC_E),MT(MOD_RGUI, KC_I),KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Q,           KC_X,           LT(3, KC_M),    KC_C,           KC_V,                                           KC_K,           KC_P,           KC_COMMA,       KC_DOT,         KC_EQUAL,       KC_DELETE,      
                                                    LT(2, KC_BSPC), LT(4, KC_TAB),                                  LT(4, KC_ENTER),LT(2, KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    ST_MACRO_0,     KC_LABK,        KC_RABK,        KC_MINUS,       KC_COLN,        KC_NO,                                          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        ST_MACRO_1,     ST_MACRO_2,     
    KC_TRANSPARENT, DUAL_FUNC_0,    MT(MOD_LALT, KC_DOT),MT(MOD_LSFT, KC_SLASH),MT(MOD_LCTL, KC_COMMA),KC_NO,                                          KC_NUM,         KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_0,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_PLUS,        KC_EQUAL,       KC_NO,                                          KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    ST_MACRO_3,     KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_UNDS,        ST_MACRO_4,     ST_MACRO_5,     
    KC_TRANSPARENT, DUAL_FUNC_1,    DUAL_FUNC_2,    MT(MOD_LSFT, KC_SLASH),DUAL_FUNC_3,    KC_GRAVE,                                       KC_TILD,        DUAL_FUNC_4,    DUAL_FUNC_5,    MT(MOD_LALT, KC_SCLN),DUAL_FUNC_6,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_NO,          KC_BSLS,        KC_LCBR,        KC_LBRC,        KC_NO,                                          KC_NO,          KC_RBRC,        KC_RCBR,        KC_PLUS,        KC_PIPE,        KC_F12,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_MINUS,       KC_0,           KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_QUOTE,       KC_DQUO,        KC_EQUAL,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    RGB_TOG,        RGB_MODE_FORWARD,RGB_SPD,        RGB_SLD,        RGB_SPI,        TOGGLE_LAYER_COLOR,                                KC_CAPS,        KC_PSCR,        KC_SCRL,        KC_PAUSE,       QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,
    RGB_SAI,        RGB_HUI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,RGB_VAI,                                        KC_NO,          KC_HOME,        KC_NO,          KC_END,         KC_PAGE_UP,     QK_DYNAMIC_TAPPING_TERM_PRINT,
    KC_NO,          MT(MOD_LGUI, KC_MEDIA_PREV_TRACK),MT(MOD_LALT, KC_J),MT(MOD_LSFT, KC_MEDIA_PLAY_PAUSE),MT(MOD_LCTL, KC_L),KC_MEDIA_NEXT_TRACK,                                KC_NO,          KC_LEFT,        KC_UP,          KC_RIGHT,       KC_PGDN,        KC_TRANSPARENT, 
    RGB_SAD,        RGB_HUI,        KC_COMMA,       HSV_0_255_255,  KC_DOT,         RGB_VAD,                                        KC_NO,          KC_INSERT,      KC_DOWN,        KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


const uint16_t PROGMEM combo0[] = { LT(2, KC_BSPC), LT(2, KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_T), MT(MOD_RSFT, KC_A), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
    COMBO(combo1, CW_TOGG),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {0,0,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {206,255,253}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {206,255,253}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {206,255,253}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {206,255,253}, {163,187,255}, {163,187,255} },

    [1] = { {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {206,255,253}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,255}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204} },

    [2] = { {74,251,140}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {0,0,0}, {0,0,0}, {74,251,140}, {74,251,140}, {74,251,140}, {0,0,0}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {206,255,253}, {206,255,253}, {206,255,253}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {0,0,0}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {206,255,253}, {74,251,140}, {74,251,140} },

    [3] = { {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235}, {185,170,235} },

    [4] = { {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {0,0,0}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {41,197,255}, {206,255,253}, {41,197,255}, {206,255,253}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,255}, {41,197,255}, {0,0,255}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,0}, {41,197,255}, {0,0,0}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,0}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {41,197,255}, {0,0,0}, {41,197,255}, {206,255,253}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

// Custom code start ********************************
// Voyager LED Index
// 00 01 02 03 04 05  26 27 28 29 30 31
// 06 07 08 09 10 11  32 33 34 35 36 37
// 12 13 14 15 16 17  38 39 40 41 42 43
// 18 19 20 21 22 23  44 45 46 47 48 49
//              24     50?
//               25   51? 

#define CAPS_WORD_LED_INDEX 06
#define CAPS_LOCK_LED_INDEX 26
#define SCROLL_LOCK_LED_INDEX 28
#define NUM_LOCK_LED_INDEX 38

// Single green color constant:
#define LED_ON_R 0
#define LED_ON_G 255
#define LED_ON_B 0

// Macro to quickly set the 'on' color:
#define SET_LED_ON(i) rgb_matrix_set_color((i), LED_ON_R, LED_ON_G, LED_ON_B)
// Custom code end   ********************************

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);

        // Custom code start ********************************
        if (is_caps_word_on()) {
          SET_LED_ON(CAPS_WORD_LED_INDEX);
        }
        // Custom code end   ********************************
        break;

      case 1:
        set_layer_color(1);

        // Custom code start ********************************
        if (host_keyboard_led_state().num_lock) {
          SET_LED_ON(NUM_LOCK_LED_INDEX);
        }
        // Custom code end   ********************************
        break;

      case 2:
        set_layer_color(2);
        break;

      case 3:
        set_layer_color(3);
        break;

      case 4:
        set_layer_color(4);
        // Custom code start ********************************
        if (host_keyboard_led_state().caps_lock) {
          SET_LED_ON(CAPS_LOCK_LED_INDEX);
        }
        if (host_keyboard_led_state().scroll_lock) {
          SET_LED_ON(SCROLL_LOCK_LED_INDEX);
        }
        // Custom code end   ********************************
        break;

     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}





bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6) ));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_2) SS_TAP(X_KP_8) ));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6) ));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_ASTR);
        } else {
          unregister_code16(KC_ASTR);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LPRN);
        } else {
          unregister_code16(KC_LPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LABK);
        } else {
          unregister_code16(KC_LABK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_ALT);
        } else {
          unregister_code16(KC_LEFT_ALT);
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RABK);
        } else {
          unregister_code16(KC_RABK);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_QUES);
        } else {
          unregister_code16(KC_QUES);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_CTRL);
        } else {
          unregister_code16(KC_RIGHT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_COLN);
        } else {
          unregister_code16(KC_COLN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_SHIFT);
        } else {
          unregister_code16(KC_RIGHT_SHIFT);
        }  
      }  
      return false;
    case DUAL_FUNC_6:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_RPRN);
        } else {
          unregister_code16(KC_RPRN);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_RIGHT_GUI);
        } else {
          unregister_code16(KC_RIGHT_GUI);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
  }
  return true;
}
