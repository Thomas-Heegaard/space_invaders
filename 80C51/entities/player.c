#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"

#define NEXT_SHOT 0
#define SHOT_DELAY 1

void PlayerUpdate(Entity* self)
{
    //todo: movement
    
    //player auto shoots
    self->extra[NEXT_SHOT]--;
    if(self->extra[NEXT_SHOT] <= 0)
    {
        self->extra[NEXT_SHOT] = self->extra[SHOT_DELAY];
        if(game->nb_entities < MAX_ENTITIES)
            AddProjectileUp(self->x, self->y - 1);
    }
}

void PlayerCollision(Entity* self)
{
    self->health--;
    if(self->health <= 0)
        self->type = EXPLOSION_CHAR;
}

void AddPlayer(char x, char y)
{
    Entity* player = AddEntity();
    if(player == NULL)
        return;
    player->x = x;
    player->y = y;
    player->type = PLAYER_CHAR;
    player->health = 1;
    player->extra[NEXT_SHOT] = 1;
    player->extra[SHOT_DELAY] = 1;
    player->Update = &PlayerUpdate;
    player->Collision = &PlayerCollision;
}
