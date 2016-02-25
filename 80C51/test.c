#ifdef TEST
#include "gameplay.h"
#include "level.h"
#include "settings.h"

char TestPosition(int x, int y)
{
    if(game->display_buffer[x][y] == ref_game->display_buffer[x][y])
        return 0;
    return 1;
}

void TestPositions(int* errors)
{
    int i, j;
    for(i = 0; i < SCENE_WIDTH; i++)
        for(j = 0; j < SCENE_HEIGHT; j++)
            if(TestPosition(i, j))
            {
                *errors++;
                //print "Display error at (%d,%d)", i, j
            }
}

void TestEntities(int* errors)
{
    int i;
    if(game->nb_entities != ref_game->nb_entities)
    {
        *errors++;
        //print "Diverging nb of entities (game: %d, reference: %d)", game->nb_entities, ref_game->nb_entities
    }
    else
        for(i = 0; i < game->nb_entities; i++)
            if(compare_entities(game->entities + i, ref_game->entities + i))
                {
                    *errors++;
                    //print "Mismatched entities (%c and %c)", game->entities[i].type, ref_game->entities[i].type   
                } 
}




int TestFullStep()
{
    int errors = 0;
    MainLoop();

    TestPositions(&errors);
    TestEntities(&errors);

    if(game->state != ref_game->state)
    {
        errors++;
        //print "Mismatched game states (%s and %s)", game->state, ref_game->state
    }
    if(game->turn != ref_game->turn)
    {
        errors++;
        //print "Mismatched game turns (%d and %d)", game->turn, ref_game->turn
    }

    // not iplemented if(game->next_turn_cycle != ref_game->next_turn_cycle)
    
    return errors;
}

void Test()
{
    Gameplay_T ref_object;
    Gameplay_T* tmp;
    
    //Test Initialization
    InitTestLevelOne();
    tmp = game;
    game = &ref_object;
    InitTestLevelOne();
    ref_game = game;
    game = tmp;
    TestFullStep();


    while(1);
}
#endif
