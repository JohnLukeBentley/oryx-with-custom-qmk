#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    CW_TOGG,        KC_B,           KC_L,           KC_D,           KC_W,           KC_Z,                                           KC_MINUS,       KC_F,           KC_O,           KC_U,           KC_J,           KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, KC_N),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_T),MT(MOD_LCTL, KC_S),KC_G,                                           KC_Y,           MT(MOD_RCTL, KC_H),MT(MOD_RSFT, KC_A),MT(MOD_LALT, KC_E),MT(MOD_RGUI, KC_I),KC_QUOTE,       
    KC_LEFT_CTRL,   KC_Q,           KC_X,           KC_M,           KC_C,           KC_V,                                           KC_K,           KC_P,           KC_COMMA,       KC_DOT,         KC_DQUO,        KC_DELETE,      
                                                    LT(2,KC_BSPC),  LT(3,KC_TAB),                                   LT(3,KC_ENTER), LT(2,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_NO,          KC_NO,          KC_NO,          QK_BOOT,        
    ST_MACRO_0,     KC_LABK,        KC_RABK,        KC_MINUS,       KC_COLN,        KC_NO,                                          KC_NO,          KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_NO,          ST_MACRO_2,     
    ST_MACRO_1,     TD(DANCE_0),    MT(MOD_LALT, KC_DOT),MT(MOD_LSFT, KC_SLASH),MT(MOD_LCTL, KC_COMMA),KC_NO,                                          KC_NUM,         KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_0,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LPRN,        KC_RPRN,        KC_PLUS,        KC_EQUAL,       KC_NO,                                          KC_NO,          KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    ST_MACRO_3,     KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_UNDS,        KC_TILD,        ST_MACRO_6,     
    ST_MACRO_4,     TD(DANCE_1),    TD(DANCE_2),    MT(MOD_LSFT, KC_SLASH),TD(DANCE_3),    KC_GRAVE,                                       KC_PLUS,        TD(DANCE_4),    TD(DANCE_5),    MT(MOD_LALT, KC_SCLN),TD(DANCE_6),    KC_TRANSPARENT, 
    KC_TRANSPARENT, ST_MACRO_5,     KC_LBRC,        KC_LCBR,        KC_BSLS,        KC_PIPE,                                        KC_NO,          KC_EQUAL,       KC_RCBR,        KC_RBRC,        KC_TRANSPARENT, KC_F12,         
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    RGB_TOG,        RGB_MODE_FORWARD,RGB_SPD,        RGB_SLD,        RGB_SPI,        TOGGLE_LAYER_COLOR,                                KC_NO,          KC_PSCR,        KC_SCRL,        KC_PAUSE,       QK_DYNAMIC_TAPPING_TERM_DOWN,QK_DYNAMIC_TAPPING_TERM_UP,
    RGB_SAI,        RGB_HUI,        KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,RGB_VAI,                                        KC_NO,          KC_HOME,        KC_NO,          KC_END,         KC_PAGE_UP,     QK_DYNAMIC_TAPPING_TERM_PRINT,
    KC_NO,          MT(MOD_LGUI, KC_MEDIA_PREV_TRACK),MT(MOD_LALT, KC_J),MT(MOD_LSFT, KC_MEDIA_PLAY_PAUSE),MT(MOD_LCTL, KC_L),KC_MEDIA_NEXT_TRACK,                                KC_NO,          KC_LEFT,        KC_UP,          KC_RIGHT,       KC_PGDN,        KC_TRANSPARENT, 
    RGB_SAD,        RGB_HUI,        KC_COMMA,       HSV_0_255_255,  KC_DOT,         RGB_VAD,                                        KC_NO,          KC_INSERT,      KC_DOWN,        KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { LT(2,KC_BSPC), LT(2,KC_SPACE), COMBO_END};
const uint16_t PROGMEM combo1[] = { MT(MOD_LSFT, KC_T), MT(MOD_RSFT, KC_A), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
    COMBO(combo1, CW_TOGG),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {0,0,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {0,0,0}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {0,0,0}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {0,0,0}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255}, {163,187,255} },

    [1] = { {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {206,255,253}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,0,255}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,0,0}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204}, {0,218,204} },

    [2] = { {74,251,140}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {0,0,0}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {206,255,253}, {206,255,253}, {206,255,253}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {0,0,0}, {74,251,140}, {74,251,140}, {74,251,140}, {74,251,140}, {206,255,253}, {74,251,140}, {74,251,140} },

    [3] = { {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {0,0,0}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {41,197,255}, {206,255,253}, {41,197,255}, {206,255,253}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,0}, {41,197,255}, {0,0,255}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,0}, {41,197,255}, {0,0,0}, {41,197,255}, {41,197,255}, {41,197,255}, {0,0,0}, {206,255,253}, {206,255,253}, {206,255,253}, {41,197,255}, {41,197,255}, {0,0,0}, {41,197,255}, {206,255,253}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255}, {41,197,255} },

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
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
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
  if (keyboard_config.disable_layer_led) { return false; }
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

      // Custom code start ********************************
      if (host_keyboard_led_state().scroll_lock) {
        SET_LED_ON(SCROLL_LOCK_LED_INDEX);
      }
      // Custom code end   ********************************
      
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
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
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_5) SS_TAP(X_KP_3) ));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6) ));
    }
    break;

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


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[7];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
        tap_code16(KC_ASTR);
    }
    if(state->count > 3) {
        tap_code16(KC_ASTR);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ASTR); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_ASTR); register_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ASTR); register_code16(KC_ASTR);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ASTR); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_ASTR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ASTR); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LABK);
        tap_code16(KC_LABK);
        tap_code16(KC_LABK);
    }
    if(state->count > 3) {
        tap_code16(KC_LABK);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_LABK); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_LABK); register_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LABK); register_code16(KC_LABK);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_LABK); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_LABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LABK); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RABK);
        tap_code16(KC_RABK);
        tap_code16(KC_RABK);
    }
    if(state->count > 3) {
        tap_code16(KC_RABK);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_RABK); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_RABK); register_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RABK); register_code16(KC_RABK);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_RABK); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_RABK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RABK); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_QUES);
        tap_code16(KC_QUES);
        tap_code16(KC_QUES);
    }
    if(state->count > 3) {
        tap_code16(KC_QUES);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_QUES); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_QUES); register_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_QUES); register_code16(KC_QUES);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_QUES); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_QUES); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_QUES); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
        tap_code16(KC_COLN);
    }
    if(state->count > 3) {
        tap_code16(KC_COLN);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_COLN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_COLN); register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COLN); register_code16(KC_COLN);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_COLN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COLN); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_RPRN);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_RPRN); register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RPRN); register_code16(KC_RPRN);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RPRN); break;
    }
    dance_state[6].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
};



// Custom QMK here


// bool led_update_user(led_t led_state) {
//   // If Num Lock is active, set underglow to green
//   if (led_state.num_lock) {
//       rgblight_setrgb(0x00, 0xFF, 0x00);  // R=0, G=255, B=0
//   } else {
//       rgblight_setrgb(0xFF, 0x00, 0x00);  // R=255, G=0,   B=0
//   }
//   return true;
// }


/* ## Key overrides */

// const key_override_t single_quote_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOTE, KC_UNDERSCORE);
// const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_QUESTION);
// const key_override_t minus_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINUS, KC_DOUBLE_QUOTE);
// const key_override_t forward_slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_LEFT_ANGLE_BRACKET);

// All key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//   &single_quote_key_override,
//   &comma_key_override,
//   &minus_key_override,
//   &forward_slash_key_override,
//   NULL // Required as last item in array to prevent compile error
// };


// // Custom code start ********************************
// #define CAPS_WORD_LED_INDEX 12
// #define SCROLL_LOCK_LED_INDEX 28
// #define NUM_LOCK_LED_INDEX 38

// // Single green color constant:
// #define LED_ON_R 0
// #define LED_ON_G 255
// #define LED_ON_B 0

// // Macro to quickly set the 'on' color:
// #define SET_LED_ON(i) rgb_matrix_set_color((i), LED_ON_R, LED_ON_G, LED_ON_B)
// // Custom code end   ********************************

// bool rgb_matrix_indicators_user(void) {
//   if (rawhid_state.rgb_control) {
//       return false;
//   }
//   if (keyboard_config.disable_layer_led) { return false; }
//   switch (biton32(layer_state)) {
//     case 0:
//       set_layer_color(0);
 
//       // Custom code start ********************************
//       if (is_caps_word_on()) {
//         SET_LED_ON(CAPS_WORD_LED_INDEX);
//       }
//       // Custom code end   ********************************

//       break;
//     case 1:
//       set_layer_color(1);
//       break;
//     case 2:
//       set_layer_color(2);

//       // Custom code start ********************************
//       if (host_keyboard_led_state().scroll_lock) {
//         SET_LED_ON(SCROLL_LOCK_LED_INDEX);
//       }
//       // Custom code end   ********************************

//       break;
//     case 3:
//       set_layer_color(3);

//       // Custom code start ********************************
//       if (host_keyboard_led_state().num_lock) {
//         SET_LED_ON(NUM_LOCK_LED_INDEX);
//       }
//       // Custom code end   ********************************

//       break;
//    default:
//     if (rgb_matrix_get_flags() == LED_FLAG_NONE)
//       rgb_matrix_set_color_all(0, 0, 0);
//     break;
//   }
//   return true;
// }
