#include "level.h"

// ============= USEFULL FUNCTIONS =====================================================================

void PlayerAutoshoot(Gameplay_T* game)
{
        //player fires automaticaly
        if(game->next_shot == 0 && game->state == 0)
        {
            game->nb_entities++;
            InitProjectileUp(game->entities + game->nb_entities, game->entities[game->player].x, game->entities[game->player].y - 1);
            game->next_shot = game->shot_delay;
        }
        else
            game->next_shot--;
}

void StandardInit(Gameplay_T* game)
{
    game->nb_entities = 1;
    game->state = GAME_RUNNING;
    game->turn = 0;
    game->player = 0;
    InitPlayer(game->entities, SCENE_WIDTH/2, SCENE_HEIGHT - 2);
}

// ============= TEST LEVEL ============================================================================

void TestLevel(Gameplay_T* game)
{
    if(game->nb_entities == MAX_ENTITIES - 1)
        return;
    InitProjectileUp(game->entities + game->nb_entities, game->turn % SCENE_WIDTH, SCENE_HEIGHT - 1);
    game->nb_entities++;
}

void InitTestLevel(Gameplay_T* game)
{
    int i = 0;
    StandardInit(game);
    RemoveEntity(&i, game);
    game->LevelLogic = TestLevel;
}

// ============= LEVEL 1 ===============================================================================

void Level1(Gameplay_T* game)
{
    PlayerAutoshoot(game);
    //Add enemies etc...
}

void InitLevel1(Gameplay_T* game)
{
    StandardInit(game);
    game->LevelLogic = Level1;
}
