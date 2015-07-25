#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
#include "string.h"
int cursorX;
int cursorY;
const uint8 sw;
const uint8 sh;
const uint8 sd;
void clearLine(uint8,uint8);
void updateCursor();
void clearScreen();
void scrollUp(uint8);
void print(string);
#endif
