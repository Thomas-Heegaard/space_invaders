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

void AddSimpleTarget(char x, char y)
{
    Entity* self = AddEntity();
    if(self == NULL)
        return;
    self->x = x;
    self->y = y;
    self->type = 'T';
    self->health = 1;
    self->Update = &SimpleTargetUpdate;
    self->Collision = &SimpleTargetCollision;
}
