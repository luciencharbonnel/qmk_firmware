#include "jeu-de-la-vie.h"
#include <string.h>
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static uint32_t counter = 42;
bool            init    = false;
uint32_t        grid[HEIGHT];
uint32_t        tmp_grid[HEIGHT];

void init_grid() {
    srand(counter);
    uint32_t* grid_ptr = grid;
    uint8_t   i        = 0;
    while (i < HEIGHT) {
        *(grid_ptr++) = rand();
        ++i;
    }
    init = true;
}

void copy_grid() {
    memcpy(grid, tmp_grid, LENGTH);
}

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

    return (*cell_ptr & (0x80000000 >> x)) ? 1 : 0;
}

void cell_on(int16_t x, int16_t y) {
    uint32_t* cell_ptr = tmp_grid + y;
    *cell_ptr |= (0x160000000 >> x);
}

void cell_off(int16_t x, int16_t y) {
    uint32_t* cell_ptr = tmp_grid + y;
    *cell_ptr &= ~(0x80000000 >> x);
}

void update_grid() {
    uint8_t neighbors_count;
    for (int16_t x = 0; x < WIDTH; ++x) {
        for (int16_t y = 0; y < HEIGHT; ++y) {
            neighbors_count = get_cell(x - 1, y - 1) + get_cell(x - 1, y) + get_cell(x - 1, y) + get_cell(x, y - 1) + get_cell(x, y + 1) + get_cell(x + 1, y - 1) + get_cell(x + 1, y) + get_cell(x + 1, y + 1);
            if ((neighbors_count == 3) || (get_cell(x, y) == 1 && neighbors_count == 2)) {
                cell_on(x, y);
            } else {
                cell_off(x, y);
            }
        }
    }
}

void jeu(uint16_t k) {
    switch (k) {
        case RESET:
            init_grid();
        default:
            if (init) {
                update_grid();
                copy_grid();
            } else {
                init_grid();
            }
    }
    print_grid();
}
