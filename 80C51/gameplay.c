#include "gameplay.h"
void CheckCollision(int entity, Gameplay_T* game)
{
    int i;
    int entity_x = game->entities[entity]->x;
    int entity_y = game->entities[entity]->y;
    for(i = 0; i < game->nb_entities; i++)
    {
        if(game->entities[i]->x == entity_x ||
            game->entities[i]->y == entity_y)
        {
            if(game->entities[i]->state == ENT_STATE_OK)
                game->entities[i]->state = ENT_STATE_COLLIDED;
            if(game->entities[entity]->state == ENT_STATE_OK)
                game->entities[entity]->state = ENT_STATE_COLLIDED;
        }

    }
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
            if(game->enties[i]->type == /*EXPLOSION CHAR*/)
            {
                game->entities--;
                for(j = i; j < game->nb_entities; j++)
                    game->entities[j] = game->entities[j+1];
            }


        //Update positions and check for collisions
        for(i = 0; i < game->nb_entities; i++)
            game->entities[i]->nextPos(entities + i);
            CheckCollision(i, game);

        //Handle collisions
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i]->state == ENT_STATE_COLLIDED)
            {
                game->entites[i]->state == ENT_STATE_EXPLODING;
                game->entites[i]->type == /*EXPLOSION CHAR*/;
            }

        //exit if game state was updated by a collision (ex. player destroyed)
        if(game->state != 0)
            return game->state;

        //player fires automaticaly
        if(game->next_shot == 0)
        {
            game->nb_entities++;
            InitProjectileUp(game->entities[nb_entities], game->entities[game->player]->x, game->entities[game->player]->y - 1)
            game->next_shot = game->shot_delay;
        }
        else
            game->next_shot--;

        //Draw board to screen
        PushDisplayBuffer(game->display_buffer);
    }
}
