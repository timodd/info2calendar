#ifndef TOOLS_H
   #define TOOLS_H TOOLS_H
#include "datastructure.h"

void clearScreen();
int askYesOrNo(char[]);
void clearBuffer();
void waitForEnter();
void printLine(char, int);
void exitProg();
//Code from info1. Maybe obsolete, but don't throw away, yet.
int Strlen(char *str);
void getText(char *, TAppointment *, int, int);


#endif
