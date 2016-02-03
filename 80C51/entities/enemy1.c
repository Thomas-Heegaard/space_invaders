#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"
#include "characters.h"

#define NEXT_DIR 0

#define DOWN1 0
#define RIGHT 1
#define DOWN2 2
#define LEFT  3

void EnemyOneUpdate(Entity* self)
{
    switch(self->extra[NEXT_DIR])   
    {
        case DOWN1:
            self->y++;
            self->extra[NEXT_DIR]++;
            break;
        case RIGHT:
            self->x++;
            self->extra[NEXT_DIR]++;
            break;
        case DOWN2:
            self->y++;
            self->extra[NEXT_DIR]++;
            break;
        case LEFT:
            self->x--;
            self->extra[NEXT_DIR] = DOWN1;
            break;
    }
	if(rand() % 5 == 0)
		AddProjectileDown(self->x, self->y+1);
}

void EnemyOneCollision(Entity* self)
{
    self->flags |= DESTROYED_F;
    self->type = EXPLOSION_CHAR;
}

void AddEnemyOne(char x, char y, char next_dir)
{
    Entity* self = AddEntity();
    if(self == NULL)
        return;
    self->x = x;
    self->y = y;
    self->type = ALIENLVL1_CHAR;
    self->Update = &EnemyOneUpdate;
    self->Collision = &EnemyOneCollision;
    self->extra[NEXT_DIR] = next_dir;
}
