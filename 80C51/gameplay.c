#include "gameplay.h"
#include "display.h"

Gameplay_T* game = 0x00;

//Checks if the entity at indice i is in collision with any other entity
void CheckCollision(char i)
{
    char j;
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
    char j, k;
    game->nb_entities--;
    for(j = *i; j < game->nb_entities; j++) // slide all following entities to the left
    {
        game->entities[j].x = game->entities[j + 1].x;
        game->entities[j].y = game->entities[j + 1].y;
        game->entities[j].type = game->entities[j + 1].type;
        for(k = 0; k < EXTRA_DATA; k++)
            game->entities[j].extra[k] = game->entities[j + 1].extra[k];
        game->entities[j].Update = game->entities[j + 1].Update;
        game->entities[j].Collision = game->entities[j + 1].Collision;
    }
    *i--;
}


//Checks if the entity at indice i is out of bounds. i is a pointer to allow removal of the entity if need be
void CheckBounds(char* i)
{
    if(game->entities[*i].y < 0)
    {
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

        //Clear display buffer
        ClearDisplayBuffer();

        //Remove destroyed entities
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i].health <= 0)
                RemoveEntity(&i);


        //Update entities and check for collisions / Out of bounds
        for(i = 0; i < game->nb_entities; i++)
        {
            game->entities[i].Update(game->entities + i);
            CheckCollision(i);
            CheckBounds(&i);
        }

        game->LevelLogic();

        //Fill display buffer
        for(i = 0; i < game->nb_entities; i++)
            game->display_buffer[game->entities[i].x][game->entities[i].y] = game->entities[i].type;

        //Clear screen and Draw board
        PushDisplayBuffer();

        //exit if game over
        if(game->state != 0)
            return game->state;
    }
}
