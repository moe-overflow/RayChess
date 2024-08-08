#include <raylib.h>

const int DIMENSION = 800;

int main(void) {

    InitWindow(DIMENSION, DIMENSION, "Chess");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("HelloRayChess", 200, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}
