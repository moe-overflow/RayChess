#include <raylib.h>
#include "board.h"

const int DIMENSION = 800;

int main(void) {

    InitWindow(DIMENSION, DIMENSION, "Chess");
    SetTargetFPS(60);

    load_textures();
    while (!WindowShouldClose()){
        BeginDrawing();
        render_board(DIMENSION / 8);
        EndDrawing();
    }
    unload_textures();
    CloseWindow();

    return 0;
}
