#include <mcs51reg.h>
#include "level.h"
#include "stdio-t6963c.h"
void main()
{
    char ret;
    Gameplay_T game;

	STDIO_initialize();

    InitTestLevel(&game);
    ret = MainLoop(&game);

    while(1);
}
