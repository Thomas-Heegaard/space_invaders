#ifndef ENTITY_H
#define ENTITY_H

#include "characters.h"

#define ENT_STATE_OK 0
#define ENT_STATE_COLLIDED 1

typedef struct Entity
{
    int x;
    int y;
    char type; //appearance
    char state;
    void (*nextPos)(struct Entity*) __reentrant;
}Entity;

void InitPlayer(Entity* player, int x, int y);

void InitProjectileUp(Entity* projectile, int x, int y);

void InitProjectileDown(Entity* projectile, int x, int y);

#endif //ENTITY_H
