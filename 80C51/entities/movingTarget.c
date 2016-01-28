#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"

#define NEXT_SHOT 0
#define SHOT_DELAY 1

void MovingTargetUpdate(Entity* self)
{
    self->x += rand()%3 - 1;
    self->y += rand()%3 - 1;
    if(self->y > SCENE_HEIGHT - 3)
        self->y--;
}

void MovingTargetCollision(Entity* self)
{
    self->health--;
    if(self->health <= 0)
        self->type = EXPLOSION_CHAR;
}

void AddMovingTarget(char x, char y)
{
    Entity* self = AddEntity();
    self->x = x;
    self->y = y;
    self->type = 'M';
    self->health = 1;
    self->Update = &MovingTargetUpdate;
    self->Collision = &MovingTargetCollision;
}
