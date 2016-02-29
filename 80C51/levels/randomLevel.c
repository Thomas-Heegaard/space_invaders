#include "../level.h"
#include "../entity.h"

void RandomLevel()
{
    if(game->nb_entities < MAX_ENTITIES - RESERVED_PROJECTILES)
        AddSimpleTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
    if(game->nb_entities < MAX_ENTITIES - RESERVED_PROJECTILES)
        AddMovingTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
}

void InitRandomLevel()
{
    StandardInit();
    game->LevelLogic = RandomLevel;
	
}
