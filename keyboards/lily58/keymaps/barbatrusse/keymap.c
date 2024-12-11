#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include <stdio.h>
#include "jeu-de-la-vie.h"

char wpm_str[10];

enum layer_number { _QWERTY = 0, _LOWER, _RAISE, _ADJUST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |   &  |   é  |   "  |   '  |   (  |                    |   §  |   è  |   !  |   ç  |   à  |  )   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   Z  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LCTRL |   Q  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   M  |  ù   |
     * |------+------+------+------+------+------|   ^   |    |    $  |------+------+------+------+------+------|
     * |LShift|   W  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   ,  |   ;  |   :  |   !  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |RAISE | /Enter  /       \Space \  |LOWER |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, FR_RPRN, KC_TAB, FR_A, FR_Z, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, FR_EQL, KC_LCTL, FR_Q, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, FR_M, KC_QUOT, KC_LSFT, FR_W, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, FR_COMM, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LALT, KC_LGUI, MO(_RAISE), KC_ENT, KC_SPC, MO(_LOWER), KC_BSPC, KC_RGUI),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |   ~  |   #  |  {   |   [  |                    |      |   `  |  \   |   ^  |  @   |  ]   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |  }   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |  *   |  +   |  =   |  -   |  /   |
     * |------+------+------+------+------+------|       |    |   €   |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |RAISE | /Space  /       \Enter \  |LOWER |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_LOWER] = LAYOUT(XXXXXXX, XXXXXXX, FR_TILD, FR_HASH, FR_LCBR, FR_LBRC, FR_PIPE, FR_GRV, FR_BSLS, FR_CIRC, FR_AT, FR_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_ASTR, FR_PLUS, FR_EQL, FR_MINS, FR_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_EURO, XXXXXXX, XXXXXXX, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------| Left | Down |  Up  |Right |      |      |
     * |------+------+------+------+------+------|   <   |    |   >   |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|   (  |   )  |   {  |   }  |   [  |   ]  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |RAISE | /Space  /       \Enter \  |LOWER |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_LABK, FR_RABK, FR_LPRN, FR_RPRN, FR_LCBR, FR_RCBR, FR_LBRC, FR_RBRC, _______, _______, _______, _______, _______, _______, _______, _______),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   1  |   2  |  3   |  4   |   5  |                    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   6  |   7  |  8   |  9   |   0  |-------.    ,-------|  F7  |  F8  |  F9  | F10  |  F11 | F12  |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |RAISE | /Space  /       \Enter \  |LOWER |BackSP| RGUI |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, FR_1, FR_2, FR_3, FR_4, FR_5, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, XXXXXXX, FR_6, FR_7, FR_8, FR_9, FR_0, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_0; // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
// const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
// const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
    if (!is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        // oled_write_ln(read_keylog(), false);
        // oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        print_grid();
        // oled_write(read_logo(), false);
        // oled_set_cursor(0,0);
        // sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
        // oled_write(wpm_str, false);
    }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
        jeu(keycode);
#endif
        // set_timelog();
    }
    return true;
}
