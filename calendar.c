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
   TAppointment apptmnt;
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
   POSITION(4,0);
   getDate(points[0], &date);
   apptmnt.Date.Day = date.Day;
   apptmnt.Date.Month = date.Month;
   apptmnt.Date.Year = date.Year;

   POSITION(15,0);
   printf("%d.%d.%d",apptmnt.Date.Day,apptmnt.Date.Month,apptmnt.Date.Year);
   POSITION(5,0);
   getTime(points[1], &time);
   POSITION(7,0);
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

void freeCalendar()
{

}
