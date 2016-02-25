#ifndef ___KEYBOARD_H
#define ___KEYBOARD_H

#define ARROW_NEUTRAL 1
#define ARROW_UP 2
#define ARROW_DOWN 3
#define ARROW_LEFT 4
#define ARROW_RIGHT 5

extern unsigned char __xdata * keyboard;
char KEYBOARD_readArrows();

/*
#ifdef TEST
int testKeyboard();
#endif
*/
#endif

