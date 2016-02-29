#ifdef TEST
#include <stdio.h>
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
                printf("Display error at (%d,%d)", i, j);
            }
}

void TestEntities(int* errors)
{
    int i;
    if(game->nb_entities != ref_game->nb_entities)
    {
        *errors++;
        printf("Diverging nb of entities (game: %d, reference: %d)", game->nb_entities, ref_game->nb_entities);
    }
    else
        for(i = 0; i < game->nb_entities; i++)
            if(compare_entities(game->entities + i, ref_game->entities + i))
                {
                    *errors++;
                    printf("Mismatched entities (%c and %c)", game->entities[i].type, ref_game->entities[i].type);
                } 
}


int TestFull()
{
    int errors = 0;

    TestPositions(&errors);
    TestEntities(&errors);

    if(game->state != ref_game->state)
    {
        errors++;
        printf("Mismatched game states (%d and %d)", game->state, ref_game->state);
    }
    if(game->turn != ref_game->turn)
    {
        errors++;
        printf("Mismatched game turns (%d and %d)", game->turn, ref_game->turn);
    }

    // not iplemented if(game->next_turn_cycle != ref_game->next_turn_cycle)
    
    return errors;
}

void GameStep() //One go through the main loop for game
{
    MainLoop();
}

void RefStep() //One go through the main loop for the reference game
{
    Gameplay_T* tmp = game;
    game = ref_game;
    MainLoop();
    game = tmp;
}

void Test()
{
    Gameplay_T ref_object;
    Gameplay_T* tmp;
    int errors;
    
    //Test Initialization
    InitTestLevelOne();
    tmp = game;
    game = &ref_object;
    InitTestLevelOne();
    ref_game = game;
    game = tmp;
    errors = TestFull();
    printf("Step 1 completed with %d errors\r", errors);

    GameStep();
    RefStep();

    printf("Tests completed with %d errors\r", errors);

    while(1);
}
#endif
