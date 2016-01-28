#include "entity.h"
#include "gameplay.h"

Entity* AddEntity()
{
    Entity* ret = NULL;
    if(game->nb_entities == MAX_ENTITIES)
        return ret;
    ret = game->entities + game->nb_entities;
    game->nb_entities++;
    return ret;
}
