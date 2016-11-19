/*
calendar

Funktionen:

   void createAppointment();
   void editAppointment();
   void deleteAppointment();
   void searchAppointment();
   void sortCalendar();
   void listCalendar();
   void printAppointment(TAppointment *)

*/
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"

int countAppointments = 0;
int *countAppointp = &countAppointments;
int i;

TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
//   TAppointment apptmnt;
   TDate date;
   TTime time;
   Calendar[countAppointments].Date.Day = -1;
   Calendar[countAppointments].Date.Month = -1;
   Calendar[countAppointments].Date.Year = -1;
   Calendar[countAppointments].Time.Hour = -1;
   Calendar[countAppointments].Time.Minute = -1;
   Calendar[countAppointments].Time.Second = -1;

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
   Calendar[countAppointments].Date.Day = date.Day;
   Calendar[countAppointments].Date.Month = date.Month;
   Calendar[countAppointments].Date.Year = date.Year;

   POSITION(5,0);
   getTime(points[1], &time);
   Calendar[countAppointments].Time.Hour = time.Hour;
   Calendar[countAppointments].Time.Minute = time.Minute;
   Calendar[countAppointments].Time.Second = time.Second;

   //TODO Beschreibung und Ort
   (*countAppointp)++;
   POSITION(7,0);
   CLEAR_LINE;
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
   unsigned char *title = "Termine auflisten";
   CLEAR;
   getSubMenu(title/*, points, 5*/);
   for (i = 0; i < countAppointments; i++)
   {
      printf("\n%d.Termin %d %d.%d.%d  %d:%d:%d", i + 1, Calendar[i].Date.Weekday, Calendar[i].Date.Day, Calendar[i].Date.Month, Calendar[i].Date.Year, Calendar[i].Time.Hour, Calendar[i].Time.Minute, Calendar[i].Time.Second);
   }
}

/* **********************************************
printAppointment gibt einen einzelnen Termin aus.

wird übergeben: TAppointment aus Calendar[]
aufgerufen von: listCalendar
ruft auf: printDate, printTime

************************************************* */
void printAppointment(TAppointment *appoint)
{

}

void freeCalendar()
{

}
