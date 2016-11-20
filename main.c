#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"
#include <string.h>

int main()
{
   int choice = -1;
   unsigned char *menuTitle = "Terminverwaltung V 0.3";
   char *menuPoints[NUMPOINTS] = { "Neuen Termin anlegen",
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
      choice = getMenu(menuTitle, menuPoints, NUMPOINTS);
      printf("ToDo: ");
      switch (choice)
      {
         case 1: createAppointment();     break;
         case 2: editAppointment();       break;
         case 3: deleteAppointment();     break;
         case 4: searchAppointment();     break;
         case 5: sortCalendar();          break;
         case 6: listCalendar();          break;
         case NUMPOINTS: exitProg();      break;
      }
      if (choice != NUMPOINTS)
         waitForEnter();
   } while (choice != NUMPOINTS);
   return 0;
}
