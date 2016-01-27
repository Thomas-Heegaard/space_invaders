#ifndef ENTITY_H
#define ENTITY_H

#include "characters.h"

#define EXTRA_DATA 3

typedef struct Entity
{
    char x;
    char y;
    char type; //appearance
    char health;
    char extra[EXTRA_DATA]; //can be used for firing countdown, variable speed, movement counters, etc...
    void (*Update)(struct Entity* self) __reentrant;
    void (*Collision)(struct Entity* self) __reentrant;
}Entity;

void InitPlayer(Entity* player, char x, char y);

void InitProjectileUp(Entity* projectile, char x, char y);

void InitProjectileDown(Entity* projectile, char x, char y);

#endif //ENTITY_H
