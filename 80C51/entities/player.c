#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"
#include "../keyboard.h"
#include <stdio.h>

#define HEALTH 0
#define NEXT_SHOT 1
#define SHOT_DELAY 2

void PlayerUpdate(Entity* self)
{
    switch(KEYBOARD_readArrows())
    {
        case ARROW_LEFT: self->x--; break;
        case ARROW_RIGHT: self->x++; break;
    }

    
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
    self->extra[HEALTH]--;
    if(self->extra[HEALTH] <= 0)
    {
        self->type = EXPLOSION_CHAR;
        self->flags |= DESTROYED_F;
        game->state = GAME_LOST;
    }
}

void AddPlayer(char x, char y)
{
    Entity* player = AddEntity();
    if(player == NULL)
        return;
    player->x = x;
    player->y = y;
    player->type = PLAYER_CHAR;
    player->next_update = 0;
    player->update_delay = 5;
    player->flags |= COLLIDER_F;
    player->extra[HEALTH] = 1;
    player->extra[NEXT_SHOT] = 1;
    player->extra[SHOT_DELAY] = 1;
    player->Update = &PlayerUpdate;
    player->Collision = &PlayerCollision;
}
