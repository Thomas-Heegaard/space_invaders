#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "entity.h"

typedef struct Gameplay
{
    char display_buffer[SCENE_WIDTH][SCENE_HEIGHT];
    Entity entities[MAX_ENTITIES];
    int nb_entities;
}Gameplay;

#endif //GAMEPLAY_H
