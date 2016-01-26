#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "entity.h"
#include "settings.h"

#define GAME_RUNNING 0
#define GAME_WON 1
#define GAME_LOST 2

typedef struct Gameplay_T
{
    char display_buffer[SCENE_WIDTH][SCENE_HEIGHT];
    
    Entity entities[MAX_ENTITIES];
    int nb_entities;

    char state;
    
    int turn;

    int player; //index of player in entities
    int shot_delay;
    int next_shot;

    void (*LevelLogic)(struct Gameplay_T* game) __reentrant;

}Gameplay_T;

char MainLoop(Gameplay_T* game);

void RemoveEntity(int* i, Gameplay_T* game); // used in level.c

#endif //GAMEPLAY_H
