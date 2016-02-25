#include "gameplay.h"
#include "display.h"


Gameplay_T* game = NULL;
#ifdef TEST
Gameplay_T* ref_game = NULL;
#endif //TEST

//Checks if the entity at indice i is in collision with any other entity
void CheckCollision(char i)
{
    char j;
    //if(game->entities[i].flags & COLLIDER_F)
        for(j = 0; j < game->nb_entities; j++)
        {
            if(i != j && 
                game->entities[j].x == game->entities[i].x &&
                game->entities[j].y == game->entities[i].y)
                {
                    game->entities[i].Collision(game->entities + i);
                    game->entities[j].Collision(game->entities + j);
                }
        }
}

//Remove the entity at indice i. i is a pointer, as it needs to be decremented to avoid skipping an entity when iterating over the array
void RemoveEntity(char* i)
{
    char k;
    game->nb_entities--;
    game->entities[*i].x = game->entities[game->nb_entities].x;
    game->entities[*i].y = game->entities[game->nb_entities].y;
    game->entities[*i].type = game->entities[game->nb_entities].type;
    game->entities[*i].next_update = game->entities[game->nb_entities].next_update;
    game->entities[*i].update_delay = game->entities[game->nb_entities].update_delay;
    game->entities[*i].flags = game->entities[game->nb_entities].flags;
    for(k = 0; k < ENTITY_DATA; k++)
        game->entities[*i].extra[k] = game->entities[game->nb_entities].extra[k];
    game->entities[*i].Update = game->entities[game->nb_entities].Update;
    game->entities[*i].Collision = game->entities[game->nb_entities].Collision;
    *i--;
}


//Checks if the entity at indice i is out of bounds. i is a pointer to allow removal of the entity if need be
void CheckBounds(char* i)
{
    if(game->entities[*i].y < 0)
    {
        if(game->entities[*i].flags & PROJECTILE_F)
            game->nb_projectiles--;
        RemoveEntity(i);
        return;
    }

    if(game->entities[*i].y >= SCENE_HEIGHT)
    {
        game->entities[*i].y = SCENE_HEIGHT - 1;
        game->entities[*i].Collision(game->entities + *i); //Collision if hits the ground
    }

    if(game->entities[*i].x < 0)
        game->entities[*i].x = 0;

    if(game->entities[*i].x >= SCENE_WIDTH)
        game->entities[*i].x = SCENE_WIDTH - 1;
}


char MainLoop()
{
    char i;
    while(1)
    {
        game->turn++;
        game->next_turn_cycle = cycles + CYCLES_PER_TURN;

        //Clear display buffer
        ClearDisplayBuffer();

        //Remove destroyed entities
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i].flags & DESTROYED_F)
                RemoveEntity(&i);

        //Update entities and check for collisions / Out of bounds
        for(i = 0; i < game->nb_entities; i++)
        {
            game->entities[i].next_update--;
            if(game->entities[i].next_update <= 0)
            {
                game->entities[i].next_update = game->entities[i].update_delay;
                game->entities[i].Update(game->entities + i);
                CheckCollision(i);
                CheckBounds(&i);
            }
        }


        game->LevelLogic();

        //Fill display buffer
        for(i = 0; i < game->nb_entities; i++)
            game->display_buffer[game->entities[i].x][game->entities[i].y] = game->entities[i].type;

        //manage framerate (if we ever get it fast enough to need it...)
        //while(cycles < game->next_turn_cycle);

        //Clear screen and Draw board
        PushDisplayBuffer();

        //exit if game over
        if(game->state != 0)
            return game->state;

        #ifdef TEST
        return game->state;
        #endif //TEST
    }
}
