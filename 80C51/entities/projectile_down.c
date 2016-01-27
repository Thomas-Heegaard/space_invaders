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

void InitProjectileDown(Entity* projectile, char x, char y)
{
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->health = 1;
    projectile->Update = &ProjectileDownUpdate;
    projectile->Collision = &ProjectileDownCollision;
}
