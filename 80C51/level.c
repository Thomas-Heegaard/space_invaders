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
    InitPlayer(game->entities, SCENE_WIDTH/2, SCENE_HEIGHT - 2);
}

// ============= TEST LEVEL ============================================================================

void TestLevel()
{
    if(game->nb_entities == MAX_ENTITIES - 1)
        return;
    InitProjectileUp(game->entities + game->nb_entities, game->turn % SCENE_WIDTH, SCENE_HEIGHT - 1);
    game->nb_entities++;
}

void InitTestLevel()
{
    char i = 0;
    StandardInit();
    RemoveEntity(&i);
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
