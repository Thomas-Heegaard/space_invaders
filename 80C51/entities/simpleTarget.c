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
    self->type = EXPLOSION_CHAR;
    self->flags |= DESTROYED_F;
}

void AddSimpleTarget(char x, char y)
{
    Entity* self = AddEntity();
    if(self == NULL)
        return;
    self->x = x;
    self->y = y;
    self->type = 'T';
    self->Update = &SimpleTargetUpdate;
    self->Collision = &SimpleTargetCollision;
}
