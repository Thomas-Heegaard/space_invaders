#include "entity.h"
#include "gameplay.h"

Entity* AddEntity()
{
    Entity* ret = game->entities + game->nb_entities;
    game->nb_entities++;
    return ret;
}
