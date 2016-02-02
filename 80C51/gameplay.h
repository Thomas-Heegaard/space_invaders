#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "rand.h"
#include "entity.h"
#include "settings.h"
#include "timer.h"

#define GAME_RUNNING 0
#define GAME_WON 1
#define GAME_LOST 2

typedef struct Gameplay_T
{
    char display_buffer[SCENE_WIDTH][SCENE_HEIGHT];
    
    Entity entities[MAX_ENTITIES];
    char nb_entities;
    char nb_projectiles;

    char state;
    
    unsigned int turn;
    unsigned int next_turn_cycle;

    char player; //index of player in entities

    char extra[GAMEPLAY_DATA]; //to be used in levels for counters etc...

    void (*LevelLogic)(void) __reentrant;

}Gameplay_T;

extern Gameplay_T* game;

char MainLoop();

void RemoveEntity(char* i); // used in level.c

#endif //GAMEPLAY_H
