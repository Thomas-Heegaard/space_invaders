#ifndef SETTINGS_H
#define SETTINGS_H

#define NULL 0x00

#ifndef TEST
#define SCENE_HEIGHT 16
#define SCENE_WIDTH 30

#define MAX_ENTITIES 50
#define RESERVED_PROJECTILES 10
#define MAX_PROJECTIES 10
#endif //not TEST
#define CYCLES_PER_TURN 1

#define GAMEPLAY_DATA 10 // nb chars in gameplay extra array
#define ENTITY_DATA 5    // nb chars in entity extra array

#ifdef TEST
#define SCENE_HEIGHT 5
#define SCENE_WIDTH 5

#define MAX_ENTITIES 10
#define RESERVED_PROJECTILES 5
#define MAX_PROJECTIES 5
#endif //TEST
#endif //SETTINGS_H
