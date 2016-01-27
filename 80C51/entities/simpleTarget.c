#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"

#define NEXT_SHOT 0
#define SHOT_DELAY 1

void SimpleTargetUpdate(Entity* self)
{
}

void SimpleTargetCollision(Entity* self)
{
    self->health--;
    if(self->health <= 0)
        self->type = EXPLOSION_CHAR;
}

void InitSimpleTarget(Entity* self, char x, char y)
{
    self->x = x;
    self->y = y;
    self->type = 'T';
    self->health = 1;
    self->Update = &SimpleTargetUpdate;
    self->Collision = &SimpleTargetCollision;
}
