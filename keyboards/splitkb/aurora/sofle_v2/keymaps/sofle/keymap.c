#include QMK_KEYBOARD_H

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("blackeagle10@icloud.com");
            }
            break;
    }
    return true;
}

const uint16_t PROGMEM xc_copy[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cv_paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM xv_cut[]   = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM zx_undo[]  = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM lt[]       = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM gt[]       = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(xc_copy, LCTL(KC_C)),
    COMBO(cv_paste, LCTL(KC_V)),
    COMBO(xv_cut, LCTL(KC_X)),
    COMBO(zx_undo, LCTL(KC_Z)),
    COMBO(lt, KC_LT),
    COMBO(gt, KC_GT),
};

// Left-hand home row mods
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K LGUI_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_SCLN LSFT_T(KC_SCLN)

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_BSPC):
        case LT(1, KC_ENT):
        case LT(2, KC_ESC):
        case LT(3, KC_ENT):
        case LT(3, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,
            KC_TILD, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      KC_PIPE,
            OS_HYPR, KC_A,    HOME_S,  HOME_D,  HOME_F,  KC_G,                                          KC_H,    HOME_J,  HOME_K,  HOME_L,  HOME_SCLN, KC_QUOT,
            KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,            XXXXXXX,       XXXXXXX,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   KC_BSLS,
                              XXXXXXX, XXXXXXX, KC_TAB,  LSFT_T(KC_BSPC), LT(1, KC_ENT), LT(2, KC_ESC), KC_SPC,  KC_RALT, XXXXXXX, XXXXXXX
            ),

    [1] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
            _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
            _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DQUO,
            _______, KC_COMM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX,        KC_UNDS, KC_MINS, KC_PLUS, _______, KC_EQL,  _______,
                              _______, _______, _______, MO(4)  , _______, LT(3, KC_BSPC), _______, _______, _______, _______
            ),

    [2] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
            _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,                           KC_MUTE, KC_PGUP, KC_PGDN, KC_MPLY, KC_DEL,  _______,
            _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BRIU, _______,
            _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_END,  XXXXXXX,        XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_BRID, _______,
                              _______, _______, _______, _______, LT(3, KC_ENT),  _______, MO(4)  , _______, _______, _______
            ),

    [3] = LAYOUT(
            _______, _______, _______, _______,       _______,       _______,                   _______, _______, _______, _______, _______, _______,
            EMAIL,   XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, LCTL(KC_PGUP), LCTL(KC_PGDN), XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                              _______, _______,       _______,       _______, _______, _______, _______, _______, _______, _______
            ),

    [4] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
            )
};
