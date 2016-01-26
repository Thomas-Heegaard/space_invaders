#include "entity.h"
#include "settings.h"

void PlayerNextPos(Entity* self)
{
    //todo
}

void InitPlayer(Entity* player, int x, int y)
{
    player->x = x;
    player->y = y;
    player->type = PLAYER_CHAR;
    player->nextPos = &PlayerNextPos;
}

void ProjectileUpNextPos(Entity* self)
{
    self->y--;
}

void InitProjectileUp(Entity* projectile, int x, int y)
{
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->nextPos = &ProjectileUpNextPos;
}

void ProjectileDownNextPos(Entity* self)
{
    self->y++;
}

void InitProjectileDown(Entity* projectile, int x, int y)
{
    projectile->x = x;
    projectile->y = y;
    projectile->type = PROJECTILE_CHAR;
    projectile->nextPos = &ProjectileDownNextPos;
}


