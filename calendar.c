/*
calendar
*/
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"
int AppointmentCount = 0;
int countAppointments = 0;
TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
   TDate date;
   TTime time;
   unsigned char *title = "Erfassung eines neuen Termins";
   char *points[5] = {  "Datum        : ",
                     "Uhrzeit      : ",
                     "Beschreibung : ",
                     "Ort          : ",
                     "Dauer        : "
            };

   getSubMenu(title/*, points, 5*/);
   POSITION (4,0);
   getDate(points[0], &date);
   POSITION (5,0);
   getTime(points[1], &time);
   printf("Termin wurde gespeichert");
}

void editAppointment()
{
   printf("Termin bearbeiten");
}

void deleteAppointment()
{
   printf("Termin löschen");
}

void searchAppointment()
{
   printf("Termin suchen");
}

void sortCalendar()
{
   printf("Termine sortieren");
}

void listCalendar()
{
   printf("Termine auflisten");
}
