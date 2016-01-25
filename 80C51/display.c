#include "display.h"
#include "stdio-t6963c.h"

void ClearDisplayBuffer(Gameplay_T* game)
{
    int i, j;
    for(i = 0; i < SCENE_WIDTH; i++)
        for(j = 0; j < SCENE_HEIGHT; j++)
            game->display_buffer[i][j] = EMPTY;
}

void PushDisplayBuffer(Gameplay_T* game)
{
    int i, j;
    for(i = 0; i < SCENE_WIDTH; i++)
        for(j = 0; j < SCENE_HEIGHT; j++)
            T6963C_writeAt(i, j, game->display_buffer[i][j]);
}
