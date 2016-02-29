#include <mcs51reg.h>
#include "timer.h"
#include "level.h"
#include "stdio-t6963c.h"
#include "characters.h"
#include "keyboard.h"
#include "test.h"

#include <stdio.h>

void main()
{
    char ret;
    Gameplay_T current_game; // MOVE THIS TO XDATA
    game = &current_game;

    keyboard = (unsigned char __xdata *) 0x3000;

    InitTimer();
	CHAR_initialize();
	STDIO_initialize();

#ifdef TEST
    Test();
#endif //TEST
    InitLevel1();
    ret = MainLoop();
    if(ret == GAME_WON)
        printf("\rYOU WIN!\r");
    else
        printf("\rYOU LOSE!\r");
    for(ret = 0; ret < 10000; ret++);
    InitRandomLevel();
    ret = MainLoop();

    while(1);
}

