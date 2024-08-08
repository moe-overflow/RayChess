#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <raylib.h>

#define GRID_SIZE 8

typedef struct Square{
    size_t x;
    size_t y;

} Square;

bool is_white_square(const Square* s);
void render_board(int edge);
void load_textures();
void unload_textures();
Texture get_figure_image(char c);


