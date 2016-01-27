#include "../entity.h"
#include "../gameplay.h"
#include "../settings.h"

#define NEXT_SHOT 0
#define SHOT_DELAY 1
#define DIRECTION 2

void TestPlayerUpdate(Entity* self)
{
    //movement
    self->x += self->extra[DIRECTION];

    if(self->x >= SCENE_WIDTH)
        self->extra[DIRECTION] = -1;
    if(self->x <= 0)
        self->extra[DIRECTION] = 1;
    
    //player auto shoots
    self->extra[NEXT_SHOT]--;
    if(self->extra[NEXT_SHOT] <= 0)
    {
        self->extra[NEXT_SHOT] = self->extra[SHOT_DELAY];
        if(game->nb_entities <= MAX_ENTITIES)
        {
            InitProjectileUp(game->entities + game->nb_entities, self->x, self->y - 1);
            game->nb_entities++;
        }
    }
}

void TestPlayerCollision(Entity* self)
{
    self->health--;
    if(self->health <= 0)
        self->type = EXPLOSION_CHAR;
}

void InitTestPlayer(Entity* player, char x, char y)
{
    player->x = x;
    player->y = y;
    player->type = PLAYER_CHAR;
    player->health = 1;
    player->extra[NEXT_SHOT] = 1;
    player->extra[SHOT_DELAY] = 2;
    player->extra[DIRECTION] = 1;
    player->Update = &TestPlayerUpdate;
    player->Collision = &TestPlayerCollision;
}
