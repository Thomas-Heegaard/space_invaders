#include <stdio.h>
#include "../level.h"
#include "../entity.h"

#define CURRENT_DIR 0 // next direction of the enemy, see enemy1.c
#define ENEMY_ROWS_LEFT 1
#define ADD_ROW 2

void Level1()
{
    char i;
    if(game->extra[ENEMY_ROWS_LEFT] >= 0)
    {
        game->extra[ADD_ROW]--;
        if(game->extra[ADD_ROW] == 0)
        {
           for(i = 0; i < SCENE_WIDTH; i++)
              if(i % 3 == 0)
                 AddEnemyOne(i, 0, game->extra[CURRENT_DIR]); 
           if(game->extra[CURRENT_DIR] == 0)
               game->extra[CURRENT_DIR] = 2;
           else
               game->extra[CURRENT_DIR] = 0;
           game->extra[ENEMY_ROWS_LEFT]--;
           game->extra[ADD_ROW] = 20;
        }
    }
    if(game->nb_entities - game->nb_projectiles == 1)
        if(game->turn > 10)
            game->state = GAME_WON;
}

void InitLevel1()
{
    StandardInit();
    game->LevelLogic = Level1;
    game->extra[CURRENT_DIR] = 0;
    game->extra[ENEMY_ROWS_LEFT] = 2;
    game->extra[ADD_ROW] = 1;
}
