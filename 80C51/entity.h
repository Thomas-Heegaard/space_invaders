#ifndef ENTITY_H
#define ENTITY_H

#include "characters.h"
#include "settings.h"

#define DESTROYED_F 1
#define PROJECTILE_F 2
#define COLLIDER_F 4

typedef struct Entity
{
    char x;
    char y;
    char type; //appearance
    char flags;
    char next_update;
    char update_delay;
    char extra[ENTITY_DATA]; //can be used for firing countdown, variable speed, movement counters, etc...
    void (*Update)(struct Entity* self) __reentrant;
    void (*Collision)(struct Entity* self) __reentrant;
}Entity;

Entity* AddEntity(); //only for use by the following functions

void AddPlayer(char x, char y);

void AddTestPlayer(char x, char y);

void AddProjectileUp(char x, char y);

void AddProjectileDown(char x, char y);

void AddSimpleTarget(char x, char y);

void AddMovingTarget(char x, char y);

void AddEnemyOne(char x, char y, char next_dir);


#ifdef TEST
char compare_entities(Entity* ent1, Entity* ent2);
#endif //TEST
#endif //ENTITY_H
