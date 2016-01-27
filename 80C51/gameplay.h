#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "rand.h"
#include "entity.h"
#include "settings.h"

#define GAME_RUNNING 0
#define GAME_WON 1
#define GAME_LOST 2

typedef struct Gameplay_T
{
    char display_buffer[SCENE_WIDTH][SCENE_HEIGHT];
    
    Entity entities[MAX_ENTITIES];
    char nb_entities;

    char state;
    
    int turn;

    char player; //index of player in entities
    int shot_delay;
    int next_shot;

    void (*LevelLogic)(void) __reentrant;

}Gameplay_T;

extern Gameplay_T* game;

char MainLoop();

void RemoveEntity(char* i); // used in level.c

#endif //GAMEPLAY_H
