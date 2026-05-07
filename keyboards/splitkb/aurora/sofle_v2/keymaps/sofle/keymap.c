#include QMK_KEYBOARD_H

// Left-hand home row mods
#define HOME_S LCTL_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LALT_T(KC_F)

// Right-hand home row mods
#define HOME_J LALT_T(KC_J)
#define HOME_K LGUI_T(KC_K)
#define HOME_L LCTL_T(KC_L)
#define HOME_SCLN LSFT_T(KC_SCLN)

// HYPER == SHIFT, CTRL, GUI and ALT
#define HYPER LCAG(KC_LSFT)

enum layers {
    BASE,
    SYMB,
    ARRW,
    UTIL,
    BOOT
};

enum custom_keycodes {
    EMAIL = SAFE_RANGE,
    ALIAS,
    YOUTUBE_SPEED_DOWN,
    YOUTUBE_SPEED_UP
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMAIL:
            if (record->event.pressed) {
                SEND_STRING("blackeagle10@icloud.com");
            }
            break;
        case ALIAS:
            if (record->event.pressed) {
                SEND_STRING("UnEmotioneD");
            }
            break;
        case YOUTUBE_SPEED_DOWN:
            if (record->event.pressed) {
                SEND_STRING("i<<<<" SS_TAP(X_ESCAPE));
            }
            return false;
        case YOUTUBE_SPEED_UP:
            if (record->event.pressed) {
                SEND_STRING("i>>>>" SS_TAP(X_ESCAPE));
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM cut[]   = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM copy[]  = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM paste[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM undo[]  = {KC_Z, KC_X, COMBO_END};

const uint16_t PROGMEM youtube_speed_down[] = {HOME_S, HOME_D, COMBO_END};
const uint16_t PROGMEM youtube_speed_up[] = {HOME_D, HOME_F, COMBO_END};

const uint16_t PROGMEM quot[] = {HOME_J, HOME_K, COMBO_END};
const uint16_t PROGMEM mins[] = {HOME_K, HOME_L, COMBO_END};
const uint16_t PROGMEM grv[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM bsls[] = {KC_COMM, KC_DOT, COMBO_END};

const uint16_t PROGMEM lt[] = {KC_MINS, KC_PLUS, COMBO_END};
const uint16_t PROGMEM gt[] = {KC_PLUS, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    COMBO(cut, LCTL(KC_X)),
    COMBO(copy, LCTL(KC_C)),
    COMBO(paste, LCTL(KC_V)),
    COMBO(undo, LCTL(KC_Z)),

    COMBO(youtube_speed_down, YOUTUBE_SPEED_DOWN),
    COMBO(youtube_speed_up, YOUTUBE_SPEED_UP),

    COMBO(quot, KC_QUOT),
    COMBO(mins, KC_MINS),
    COMBO(grv, KC_GRV),
    COMBO(bsls, KC_BSLS),

    COMBO(lt, KC_LT),
    COMBO(gt, KC_GT)
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_BSPC):
        case LT(SYMB, KC_ENT):
        case LT(ARRW, KC_ESC):
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
            KC_EQL    , KC_1        , KC_2   , KC_3   , KC_4  , KC_5           ,                                              KC_6  , KC_7   , KC_8   , KC_9  , KC_0     , KC_MINS,
            KC_TILD   , KC_Q        , KC_W   , KC_E   , KC_R  , KC_T           ,                                              KC_Y  , KC_U   , KC_I   , KC_O  , KC_P     , KC_PIPE,
            LCTL(KC_A), HYPR_T(KC_A), HOME_S , HOME_D , HOME_F, KC_G           ,                                              KC_H  , HOME_J , HOME_K , HOME_L, HOME_SCLN, KC_QUOT,
            KC_GRV    , KC_Z        , KC_X   , KC_C   , KC_V  , KC_B           , XXXXXXX         ,          XXXXXXX         , KC_N  , KC_M   , KC_COMM, KC_DOT, KC_SLSH  , KC_BSLS,
                                      KC_LEFT, KC_RGHT, KC_TAB, LSFT_T(KC_BSPC), LT(SYMB, KC_ENT),          LT(ARRW, KC_ESC), KC_SPC, KC_RALT, KC_DOWN, KC_UP
            ),

    [SYMB] = LAYOUT(
            _______, _______, _______, _______, _______, _______ ,                             _______, _______, _______, _______, _______, _______,
            _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC ,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5    ,                             KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DQUO,
            _______, KC_COMM, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR , XXXXXXX,          XXXXXXX , KC_UNDS, KC_MINS, KC_PLUS, _______, KC_EQL , _______,
                              _______, _______, _______, MO(BOOT), _______,          MO(UTIL), _______, _______, _______, _______
            ),

    [ARRW] = LAYOUT(
            _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
            _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_INS ,                                       KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_DEL , _______,
            _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_BRIU,                                       KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_MPLY, _______,
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_BRID, XXXXXXX ,                   XXXXXXX , KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, _______,
                              _______, _______, _______, _______, MO(UTIL),          _______, MO(BOOT), _______, _______, _______
            ),

    [UTIL] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX      , XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX     , XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX      , XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX     , XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, LCTL(KC_PGUP), LCTL(KC_PGDN), XXXXXXX,                            XXXXXXX, KC_PSCR, LCTL(KC_PSCR), LCS(KC_PSCR), XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX      , XXXXXXX      , XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, EMAIL  , ALIAS        , XXXXXXX     , XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX      , XXXXXXX      , _______, _______,          _______, _______, XXXXXXX, XXXXXXX      , XXXXXXX
            ),

    [BOOT] = LAYOUT(
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                            QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,          _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
            )
};
