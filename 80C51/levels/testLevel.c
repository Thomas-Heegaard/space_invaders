#include "../level.h"
#include "../entity.h"

void TestLevel()
{
    if(game->nb_entities < MAX_ENTITIES - RESERVED_PROJECTILES)
        AddSimpleTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
    if(game->nb_entities < MAX_ENTITIES - RESERVED_PROJECTILES)
        AddMovingTarget(rand()%SCENE_WIDTH, rand()%(SCENE_HEIGHT - 3));
}

void InitTestLevel()
{
	
    char i = 0;
    StandardInit();
    RemoveEntity(&i);
    AddTestPlayer(SCENE_WIDTH/2, SCENE_HEIGHT - 2);
    game->LevelLogic = TestLevel;
	
}
