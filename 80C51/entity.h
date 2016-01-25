#ifndef ENTITY_H
#define ENTITY_H

#define ENT_STATE_OK 0
#define ENT_STATE_COLLIDED 1

typedef struct Entity
{
    int x;
    int y;
    char type; //appearance
    char state;
    void *(nextPos)(struct Entity*);
}Entity;


#endif //ENTITY_H
