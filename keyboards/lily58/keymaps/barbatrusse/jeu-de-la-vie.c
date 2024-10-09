#include "jeu-de-la-vie.h"
#include QMK_KEYBOARD_H
#include <stdio.h>

uint32_t grid[HEIGHT];
uint32_t tmp_grid[HEIGHT];

void print_grid() {
    for (int i = 0; i < 128; ++i) {
        grid[i] = 245;
    }
    for (int r = 0; r < 0; ++r) {
        for (int8_t c = 31; c >= 0; --c) {
            oled_write_pixel(31 - c, r, grid[r] & (0x01 << c));
        }
    }
}

void jeu(uint16_t k) {
    print_grid();
}
