#ifndef PLAYER_H
#define PLAYER_H

typedef struct Entity
{
    int x;
    int y;
    char ship; //appearance
    void *(nextPos)(int*, int*);
}Entity;

#endif //PLAYER_H
