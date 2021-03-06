#include "../level.h"
#include "../entity.h"

//WORKS BEST WITH 50 - 100 max entities, is as slow as can be expected...

#define CURRENT_DIR 0 // next direction of the enemy, see enemy1.c
#define ENEMY_ROWS_LEFT 1
#define ADD_ROW 2

void TestLevelOne()
{
    char i;
    if(game->nb_entities == 0)
        game->state = GAME_LOST;
    if(game->extra[ENEMY_ROWS_LEFT] >= 0)
    {
        game->extra[ADD_ROW]--;
        if(game->extra[ADD_ROW] == 0)
        {
           for(i = 0; i < SCENE_WIDTH; i++)
              if(i % 2 == 0)
                 AddEnemyOne(i, 0, game->extra[CURRENT_DIR]); 
           if(game->extra[CURRENT_DIR] == 0)
               game->extra[CURRENT_DIR] = 2;
           else
               game->extra[CURRENT_DIR] = 0;
           game->extra[ADD_ROW] = 0;
           game->extra[ENEMY_ROWS_LEFT]--;
           game->extra[ADD_ROW] = 10;
        }
    }
}

void InitTestLevelOne()
{
    char i = 0;
    StandardInit();
    RemoveEntity(&i);
    AddTestPlayer(SCENE_WIDTH/2, SCENE_HEIGHT - 2);
    game->LevelLogic = TestLevelOne;
    game->extra[CURRENT_DIR] = 0;
    game->extra[ENEMY_ROWS_LEFT] = 5;
    game->extra[ADD_ROW] = 1;
}
