#include <stdio.h>
#include "escapesequenzen.h"
#include "tools.h"
#include "datastructure.h"

int getMenu(unsigned char *mt, char *mp[], int i)
{
   int c = 0, p = 0;
   //print menue on empty screen
   do
   {
      c = 0;
      p = 0;
      clearScreen();
      printf("%s\n",mt);
      printLine('=', Strlen(mt));
      POSITION(3,0);
      do
      {
         printf("\n%d. %s",p + 1, mp[p]);
         p++;
      } while(p < NUMPOINTS);
      printf("\n\nIhre Wahl: ");
      scanf("%d", &c);
      clearBuffer();
   } while(c < 1 || c > NUMPOINTS);
   return c;
}
