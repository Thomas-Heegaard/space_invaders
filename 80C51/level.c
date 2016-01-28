#include "level.h"
#include "entity.h"
#include "level.h"

// ============= USEFULL FUNCTIONS =====================================================================

void StandardInit()
{
    game->nb_entities = 0;
    game->state = GAME_RUNNING;
    game->turn = 0;
    game->player = 0;
    AddPlayer(SCENE_WIDTH/2, SCENE_HEIGHT - 1);
}

// ============= TEST LEVEL ============================================================================

void TestLevel()
{
    if(game->nb_entities < MAX_ENTITIES)
        AddSimpleTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
    if(game->nb_entities < MAX_ENTITIES)
        AddMovingTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
}

void InitTestLevel()
{
    char i = 0;
    StandardInit();
    RemoveEntity(&i);
    AddTestPlayer(SCENE_WIDTH/2, SCENE_HEIGHT - 2);
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
