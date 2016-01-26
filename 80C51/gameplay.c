#include "gameplay.h"
#include "display.h"

//Checks if the entity at indice i is in collision with any other entity. Applies no logic, only sets the state for collided entities
void CheckCollision(int i, Gameplay_T* game)
{
    int j;
    for(j = 0; j < game->nb_entities; j++)
    {
        if(game->entities[j].x == game->entities[i].x ||
            game->entities[j].y == game->entities[i].y)
        {
            if(game->entities[j].state == ENT_STATE_OK)
                game->entities[j].state = ENT_STATE_COLLIDED;
            if(game->entities[i].state == ENT_STATE_OK)
                game->entities[i].state = ENT_STATE_COLLIDED;
        }

    }
}

//Remove the entity at indice i. i is a pointer, as it needs to be decremented to avoid skipping an entity when iterating over the array
void RemoveEntity(int* i, Gameplay_T* game)
{
    int j;
    game->nb_entities--;
    for(j = *i; j < game->nb_entities; j++)
    {
        game->entities[*i].x = game->entities[*i + 1].x;
        game->entities[*i].y = game->entities[*i + 1].y;
        game->entities[*i].type = game->entities[*i + 1].type;
        game->entities[*i].state = game->entities[*i + 1].state;
        game->entities[*i].nextPos = game->entities[*i + 1].nextPos;
    }
    *i--;
}


//Checks if the entity at indice i is out of bounds AND APPLIES GAME LOGIC IF THIS IS THE CASE. i is a pointer to allow removal of the entity if need be
void CheckBounds(int* i, Gameplay_T* game)
{
    if(game->entities[*i].y < 0)
    {
        RemoveEntity(i, game);
        return;
    }

    if(game->entities[*i].y > SCENE_HEIGHT)
    {
        game->entities[*i].y = SCENE_HEIGHT;
        game->entities[*i].type = EXPLOSION_CHAR;
    }

    if(game->entities[*i].x < 0)
        game->entities[*i].x = 0;

    if(game->entities[*i].x > SCENE_WIDTH)
        game->entities[*i].x = SCENE_WIDTH;
}


char Main_Loop(Gameplay_T* game)
{
    int i, j;
    while(1)
    {
        //Clear display buffer
        ClearDisplayBuffer(game);

        //Remove destroyed entities
        for(i = 0; i < game->nb_entities; i++)
            if(game->entities[i].type == EXPLOSION_CHAR)
                RemoveEntity(&i, game);


        //Update positions and check for collisions / Out of bounds
        for(i = 0; i < game->nb_entities; i++)
        {
            game->entities[i].nextPos(game->entities + i);
            CheckCollision(i, game);
            CheckBounds(&i, game);
        }

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
            InitProjectileUp(game->entities + game->nb_entities, game->entities[game->player].x, game->entities[game->player].y - 1);
            game->next_shot = game->shot_delay;
        }
        else
            game->next_shot--;

        //Fill display buffer
        for(i = 0; i < game->nb_entities; i++)
            game->display_buffer[game->entities[i].x][game->entities[i].y] = game->entities[i].type;

        //Draw board to screen
        PushDisplayBuffer(game);

        //exit if game state was updated by a collision (ex. player destroyed)
        if(game->state != 0)
            return game->state;

    }
}
