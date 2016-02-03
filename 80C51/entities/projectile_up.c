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
    self->flags |= DESTROYED_F;
    game->nb_projectiles--;
}

void AddProjectileUp(char x, char y)
{
    Entity* projectile = AddEntity();
    if(projectile == NULL)
        return;
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->flags |= PROJECTILE_F;
    projectile->flags |= COLLIDER_F;
    projectile->next_update = 1;
    projectile->update_delay = 1;
    projectile->Update = &ProjectileUpUpdate;
    projectile->Collision = &ProjectileUpCollision;
    game->nb_projectiles++;
}
