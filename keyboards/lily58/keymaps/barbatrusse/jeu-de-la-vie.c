#include "jeu-de-la-vie.h"
#include QMK_KEYBOARD_H
#include <stdio.h>

uint32_t grid[HEIGHT];
uint32_t tmp_grid[HEIGHT];

void print_grid(void) {
    for (int i = 0; i < HEIGHT; ++i) {
        grid[i] = 245;
    }
    for (int r = 0; r < HEIGHT; ++r) {
        for (int8_t c = 31; c >= 0; --c) {
            oled_write_pixel(31 - c, r, grid[r] & (0x01 << c));
        }
    }
}

uint8_t get_cell(int16_t x, int16_t y) {
    while (x < 0)
        x += WIDTH;
    while (x >= WIDTH)
        x -= WIDTH;
    while (y < 0)
        y += HEIGHT;
    while (y >= HEIGHT)
        y -= HEIGHT;

    uint32_t* cell_ptr = grid + y;

    return ((*(cell_ptr) >> x) & 0x01) ? 1 : 0;
}

void cell_on(int8_t x, int8_t y) {}

void update_grid() {
    uint8_t neighbors_count;
}

void jeu(uint16_t k) {
    print_grid();
}
