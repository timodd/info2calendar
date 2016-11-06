#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"

int main()
{
   int choice;
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

   return 0;
}
