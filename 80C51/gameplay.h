#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "entity.h"

typedef struct Gameplay_T
{
    char display_buffer[SCENE_WIDTH][SCENE_HEIGHT];
    
    Entity entities[MAX_ENTITIES];
    int nb_entities;

    char state;

    int player; //index of player in entities
    int shot_delay;
    int next_shot;
}Gameplay_T;

#endif //GAMEPLAY_H
