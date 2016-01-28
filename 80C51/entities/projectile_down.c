#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"


void ProjectileDownUpdate(Entity* self)
{
    self->y++;
}

void ProjectileDownCollision(Entity* self)
{
    self->type = EXPLOSION_CHAR;
    self->health = 0;
}

void AddProjectileDown(char x, char y)
{
    Entity* projectile = AddEntity();
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->health = 1;
    projectile->Update = &ProjectileDownUpdate;
    projectile->Collision = &ProjectileDownCollision;
}
