#include "board.h"
#include <raylib.h>

Texture2D figure_textures[12];

char chessboard[GRID_SIZE][GRID_SIZE] = {

        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}

};


bool is_white_square(const Square* s){
    return (s->x % 2 == 0 && s->y % 2 == 0) || (s->x % 2 == 1 && s->y % 2 == 1);
}

void render_board(int edge){

    for(size_t i = 0; i < GRID_SIZE; i++){
        for(size_t j = 0; j < GRID_SIZE; j++){

            Square s = { .x = j, .y = i };
            Color color = is_white_square(&s) ? WHITE : GRAY;

            int pos_x = s.x * edge;
            int pos_y = s.y * edge;

            DrawRectangle((int)  pos_x , pos_y, edge, edge, color);

            char c = chessboard[i][j];
            if (c != '-'){
                Texture2D texture = get_figure_image(c);

                Rectangle source_rect = { 0.0f, 0.0f, (float)texture.width, (float)texture.height };
                Rectangle dest_rect = { pos_x, pos_y, (float)edge, (float)edge };
                DrawTexturePro(texture, source_rect, dest_rect, (Vector2){ 0, 0 }, 0.0f, WHITE);
            }

        }
    }

}

void load_textures(){

    figure_textures[0] = LoadTexture("../assets/figures/w-pawn.png");
    figure_textures[1] = LoadTexture("../assets/figures/w-king.png");
    figure_textures[2] = LoadTexture("../assets/figures/w-bishop.png");
    figure_textures[3] = LoadTexture("../assets/figures/w-knight.png");
    figure_textures[4] = LoadTexture("../assets/figures/w-queen.png");
    figure_textures[5] = LoadTexture("../assets/figures/w-rook.png");

    figure_textures[6] = LoadTexture("../assets/figures/b-pawn.png");
    figure_textures[7] = LoadTexture("../assets/figures/b-king.png");
    figure_textures[8] = LoadTexture("../assets/figures/b-bishop.png");
    figure_textures[9] = LoadTexture("../assets/figures/b-knight.png");
    figure_textures[10] = LoadTexture("../assets/figures/b-queen.png");
    figure_textures[11] = LoadTexture("../assets/figures/b-rook.png");
}

Texture get_figure_image(char c){

    switch (c){
        case 'P': return figure_textures[0]; break;
        case 'K': return figure_textures[1]; break;
        case 'B': return figure_textures[2];  break;
        case 'N': return figure_textures[3];  break;
        case 'Q': return figure_textures[4]; break;
        case 'R': return figure_textures[5]; break;

        case 'p': return figure_textures[6]; break;
        case 'k': return figure_textures[7]; break;
        case 'b': return figure_textures[8];  break;
        case 'n': return figure_textures[9];  break;
        case 'q': return figure_textures[10]; break;
        case 'r': return figure_textures[11]; break;

        default: break;
    }
}

void unload_textures(){
    for(size_t i = 0; i < 12; i++){
        UnloadTexture(figure_textures[i]);
    }
}
