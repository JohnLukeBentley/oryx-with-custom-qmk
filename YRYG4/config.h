#undef TAPPING_TERM
#define TAPPING_TERM 300

#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#define SERIAL_NUMBER "YRYG4/DzZNpN"
#define LAYER_STATE_8BIT
#define COMBO_COUNT 2

#define RGB_MATRIX_STARTUP_SPD 60


// Custom code
// https://docs.qmk.fm/features/caps_word
// CAPS_WORD_IDLE_TIMEOUT is 5 seconds by default
// #define CAPS_WORD_IDLE_TIMEOUT 30000  // 30 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 0  // Caps Word to never time out. Caps Word then remains active indefinitely until a word breaking key is pressed.
#define CAPS_WORD_INVERT_ON_SHIFT
