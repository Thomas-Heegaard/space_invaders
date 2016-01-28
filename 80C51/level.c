#include "level.h"
#include "entity.h"

void StandardInit()
{
    game->nb_entities = 0;
    game->nb_projectiles = 0;
    game->state = GAME_RUNNING;
    game->turn = 0;
    game->player = 0;
    AddPlayer(SCENE_WIDTH/2, SCENE_HEIGHT - 1);
}
