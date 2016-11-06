#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"

int getMenu(char *mt, char *mp[], int i)
{
   int c = 0, j = 0, p = 0;
   char *question = "\n\nIhre Wahl: ";
   void printQuestion()
   {
      do
      {
         printf("%s",question);
         while (!scanf("%d[1-7]", &c))
         {
            c = 0;
            clearBuffer();
         }
      } while(c < 1 || c > 7);
   }

   clearScreen();
   printf("%s\n",mt);
   printLine('=', 30);
   do
   {
      printf("\n%d. %s",p + 1, mp[p]);
      p++;
   } while(p < 7);

   printQuestion();

return c;
}
