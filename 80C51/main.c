#include <mcs51reg.h>
#include "timer.h"
#include "level.h"
#include "stdio-t6963c.h"

#ifndef TEST

// final prog

#else
#include <stdio.h>

void main()
{
    char ret;
    Gameplay_T current_game; // MOVE THIS TO XDATA
    game = &current_game;

    InitTimer();

	STDIO_initialize();

    InitTestLevelOne();
    ret = MainLoop();
    InitTestLevel();
    ret = MainLoop();

    while(1);
}

#endif
