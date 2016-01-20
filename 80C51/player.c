#include "entity.h"
#include "settings.h"

void PlayerNextPos(int* x, int* y)
{

}

char Init(Entity* player)
{
    player->x = PLAYER_START_X;
    player->y = PLAYER_START_Y;
    player->ship = //TODO;
    player->nextPos = &PlayerNextPos;
}
