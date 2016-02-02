
#include <mcs51reg.h>
#include <stdio.h>
#include "timer.h"

/*------------------------------------------------
Timer 0 Interrupt Service Routine.

Set a breakpoint on 'overflow_count++' and run the
program in the debugger.  You will see this line
executes every 65536 clock cycles.
------------------------------------------------*/
unsigned long cycles;

void timer0_ISR (void) __interrupt 1
{
    cycles++;   /* Increment the overflow count */
}

/*------------------------------------------------
MAIN C function
------------------------------------------------*/
void InitTimer(void)
{
/*--------------------------------------
Set Timer0 for 16-bit timer mode.  The
timer counts to 65535, overflows, and
generates an interrupt.
--------------------------------------*/

    TMOD = (TMOD & 0xF0) | 0x01;  /* Set T/C0 Mode */
    ET0 = 1;                      /* Enable Timer 0 Interrupts */
    TR0 = 1;                      /* Start Timer 0 Running */
    EA = 1;                       /* Global Interrupt Enable */

    cycles = 0;                     /* Init time*/
}

