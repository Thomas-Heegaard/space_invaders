#include <mcs51reg.h>
#include "level.h"
#include "stdio-t6963c.h"
void main()
{
    char ret;
    Gameplay_T current_game; // MOVE THIS TO XDATA
    game = &current_game;

	STDIO_initialize();

    InitTestLevel();
    ret = MainLoop();

    while(1);
}
