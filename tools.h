#ifndef TOOLS_H
   #define TOOLS_H TOOLS_H

void clearScreen();
int askYesOrNo(char[]);
void clearBuffer();
void waitForEnter();
void printLine(char, int);
void exitProg();
//Code from info1. Maybe obsolete, but don't throw away, yet.
int Strlen(unsigned char *str);
void getText(unsigned char *text);


#endif
