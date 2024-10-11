#ifndef JEU_H
#define JEU_H

#include <stdint.h>
#include QMK_KEYBOARD_H
#define WIDTH 128
#define HEIGHT 32
#define LENGTH_BYTES 512
#define WIDTH_U32 4

#define RESET KC_BSPC

void print_grid(void);
void jeu(uint16_t k);

#endif
