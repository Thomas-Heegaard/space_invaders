#include "display.h"
#include "t6963c.h"
#include "characters.h"
#include "settings.h"
#include "gameplay.h"

// ONLY WRITE TO THE DISPLAY WHERE CHANGES WHERE MADE = MAJOR SPEED DIFFERENCE!

void ClearDisplayBuffer()
{
    char i, j;
    for(i = 0; i < SCENE_WIDTH; i++)
        for(j = 0; j < SCENE_HEIGHT; j++)
            game->display_buffer[i][j] = UNMODIFIED_CHAR;
    for(i = 0; i < game->nb_entities; i++)
        game->display_buffer[game->entities[i].x][game->entities[i].y] = EMPTY_CHAR;
}

void PushDisplayBuffer()
{
    char i, j;
    for(i = 0; i < SCENE_WIDTH; i++)
        for(j = 0; j < SCENE_HEIGHT; j++)
            if(game->display_buffer[i][j] != UNMODIFIED_CHAR)
                T6963C_writeAt(i, j, game->display_buffer[i][j]);
}
