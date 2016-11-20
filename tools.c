#include <stdio.h>
#include <stdlib.h>
#include "escapesequenzen.h"
#include "tools.h"
#include "datastructure.h"

//clear the input buffer
void clearBuffer()
{
   char dummy;
   do
   {
      scanf("%c", &dummy);
   } while (dummy != '\n');
}

void waitForEnter()
{
   unsigned char w;
   printf("\n\nBitte Eingabetaste druecken... ");
   while(w != '\n')
   {
      w = getchar();
   }
}

void clearScreen()
{
   HOME;
   CLEAR;
//use function system from stdlib.h eg. system("CLS") ****NUR WINDOWS??
}

//user input j/n if program restarts
int askYesOrNo(char question[])
{
   int i = 0;
   char sel;
   void printQuestion()
   {
      do
      {
         printf("%c",question[i]);
         i++;
      } while(question[i]);
   }

   printQuestion();

   while (!scanf("%[jJnN]", &sel))
   {
      i = 0;
      UP_LINE;
      CLEAR_LINE;
      printQuestion();
      clearBuffer();
   }
      if (sel == 'j' || sel =='J')
      {
         return 1;
      }
   return 0;
}

// prints i times c.
void printLine(char c,int i)
{
   do
   {
      printf("%c",c);
      i--;
   }while (i);
}

void exitProg()
{
   clearScreen();
   printf("exit\n");
}
// Code from info1. Maybe obsolete, but don't throw away, yet.

int Strlen(unsigned char *str)
{
    int len = 0;

    while (*str++ != '\0')
        {
            len++;
        }
    return len;
}

//Text einlesen
void getText(unsigned char *prompt, TAppointment *txt, int maxlen, int forceinput)
{
    char input[maxlen];
    do
    {
        printf("\n%s",prompt);
        scanf("%100[^\n]", input);
        clearBuffer();
        if (forceinput == 1)
         txt -> pDescription = input;
        else
         txt -> pPlace = input;
    }while (Strlen(input) == 0);
}
