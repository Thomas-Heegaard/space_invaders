#include "level.h"
#include "entity.h"
#include "level.h"

// ============= USEFULL FUNCTIONS =====================================================================

void StandardInit()
{
    game->nb_entities = 1;
    game->state = GAME_RUNNING;
    game->turn = 0;
    game->player = 0;
    InitPlayer(game->entities, SCENE_WIDTH/2, SCENE_HEIGHT - 1);
}

// ============= TEST LEVEL ============================================================================

void TestLevel()
{
    if(game->nb_entities < 10)
    {
        InitSimpleTarget(game->entities + game->nb_entities, rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
        game->nb_entities++;
        //InitMovingTarget(game->entities + game->nb_entities, rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
        //game->nb_entities++;
    }
}

void InitTestLevel()
{
    char i = 0;
    StandardInit();
    RemoveEntity(&i);
    InitTestPlayer(game->entities + game->nb_entities, SCENE_WIDTH/2, SCENE_HEIGHT - 2);
    game->nb_entities++;
    game->LevelLogic = TestLevel;
}

// ============= LEVEL 1 ===============================================================================

void Level1()
{
    //Add enemies etc...
}

void InitLevel1()
{
    StandardInit();
    game->LevelLogic = Level1;
    game->entities[game->player].health = 3;
    game->entities[game->player].extra[1] = 10; //firing delay
}
