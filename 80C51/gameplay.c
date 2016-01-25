#include "gameplay.h"
#include "scene.h"

void CheckCollision(int entity, Gameplay_T* game)
{
    int i;
    int entity_x = game->entities[entity].x;
    int entity_y = game->entities[entity].y;
    for(i = 0; i < game->nb_entities; i++)
    {
        if(game->entities[i].x == entity_x ||
            game->entities[i].y == entity_y)
        {
            if(game->entities[i].state == ENT_STATE_OK)
                game->entities[i].state = ENT_STATE_COLLIDED;
            if(game->entities[entity].state == ENT_STATE_OK)
                game->entities[entity].state = ENT_STATE_COLLIDED;
        }

    }
}

void SlideEntityLeft(Gameplay_T* game, int i)
{
    game->entities[i].x = game->entities[i + 1].x;
    game->entities[i].y = game->entities[i + 1].y;
    game->entities[i].type = game->entities[i + 1].type;
    game->entities[i].state = game->entities[i + 1].state;
    game->entities[i].nextPos = game->entities[i + 1].nextPos;
}

char Main_Loop(Gameplay_T* game)
{
    int i, j;
    while(1)
    {
        //Clear display buffer
        ClearDisplayBuffer(game->display_buffer);

        //Remove destroyed entities
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i].type == EXPLOSION_CHAR)
            {
                game->entities--;
                for(j = i; j < game->nb_entities; j++)
                    SlideEntityLeft(game, j);
                i--;
            }


        //Update positions and check for collisions
        for(i = 0; i < game->nb_entities; i++)
            game->entities[i].nextPos(game->entities + i);
            CheckCollision(i, game);

        //Handle collisions
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i].state == ENT_STATE_COLLIDED)
                game->entities[i].type == EXPLOSION_CHAR;

//Insert gamplay logic here
//    Add enemies
//    Check victory/failure conditions
//    etc...

        //player fires automaticaly
        if(game->next_shot == 0 && game->state == 0)
        {
            game->nb_entities++;
            InitProjectileUp(game->entities[nb_entities], game->entities[game->player].x, game->entities[game->player].y - 1);
            game->next_shot = game->shot_delay;
        }
        else
            game->next_shot--;

        //Fill display buffer
        for(i = 0; i < game->nb_entities; i++)
            game->display_buffer[game->entities[i].x][game->entities[i].y] = game->entities[i].type;

        //Draw board to screen
        PushDisplayBuffer(game->display_buffer);

        //exit if game state was updated by a collision (ex. player destroyed)
        if(game->state != 0)
            return game->state;

    }
}
