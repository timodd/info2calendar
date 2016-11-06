#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"

int main()
{
   int choice = -1;
   char *menuTitle = "Terminverwaltung V 0.2";
   char *menuPoints[7] = { "Neuen Termin anlegen",
                           "Termin bearbeiten",
                           "Termin löschen",
                           "Termin suchen",
                           "Termine sortieren",
                           "Termine auflisten",
                           "Programm beenden"
                         };

   do
   {
      clearScreen();

     choice = getMenu(menuTitle, menuPoints, 7);

   } while (choice != 7);
   printf("\nToDo: %s",menuPoints[choice]);
   waitForEnter();

   return 0;
}
