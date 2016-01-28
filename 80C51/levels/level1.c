#include "../level.h"
#include "../entity.h"

void Level1()
{
    //Add enemies etc...
}

void InitLevel1()
{
    StandardInit();
    game->LevelLogic = Level1;
    game->entities[game->player].extra[0] = 3; //health
    game->entities[game->player].extra[2] = 10; //firing delay
}
