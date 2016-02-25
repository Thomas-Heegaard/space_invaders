#include "entity.h"
#include "gameplay.h"

Entity* AddEntity()
{
    Entity* ret = NULL;
    if(game->nb_entities == MAX_ENTITIES)
        return ret;
    ret = game->entities + game->nb_entities;
    ret->flags = 0;
    game->nb_entities++;
    return ret;
}

#ifdef TEST
char compare_entities(Entity* ent1, Entity* ent2)
{
    int i;
    if(ent1->x != ent2->x)
        return 1;
    if(ent1->y != ent2->y)
        return 1;
    if(ent1->type != ent2->type)
        return 1;
    if(ent1->flags != ent2->flags)
        return 1;
    if(ent1->next_update != ent2->next_update)
        return 1;
    if(ent1->update_delay != ent2->update_delay)
        return 1;
    for(i = 0; i < ENTITY_DATA; i++)
        if(ent1->extra[i] != ent2->extra[i])
            return 1;
    return 0;
}
#endif //TEST
