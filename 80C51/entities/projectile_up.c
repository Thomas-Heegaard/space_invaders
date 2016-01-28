#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"


void ProjectileUpUpdate(Entity* self)
{
    self->y--;
}

void ProjectileUpCollision(Entity* self)
{
    self->type = EXPLOSION_CHAR;
    self->health = 0;
}

void AddProjectileUp(char x, char y)
{
    Entity* projectile = AddEntity();
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->health = 1;
    projectile->Update = &ProjectileUpUpdate;
    projectile->Collision = &ProjectileUpCollision;
}
