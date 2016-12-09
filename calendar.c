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
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"
#include "escapesequenzen.h"

int countAppointments = 0;
int *countAppointp = &countAppointments;
int i;
const int maxlen_description = 100, maxlen_place = 15;

TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
   TAppointment *apptmnt = Calendar + countAppointments;
   TDate date;
   TTime time;
//   char describ[maxlen_description];
//   char place[maxlen_place];
   apptmnt->pDescription = calloc(100, sizeof(char));
   apptmnt->pPlace = calloc(15, sizeof(char));

//
//   Calendar[countAppointments].Date.Day = -1;
//   Calendar[countAppointments].Date.Month = -1;
//   Calendar[countAppointments].Date.Year = -1;
//   Calendar[countAppointments].Time.Hour = -1;
//   Calendar[countAppointments].Time.Minute = -1;
//   Calendar[countAppointments].Time.Second = -1;
   Calendar[countAppointments].pDescription = calloc(100, sizeof(char));
   Calendar[countAppointments].pPlace = calloc(15, sizeof(char));


   char *title = "Erfassung eines neuen Termins";
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
   Calendar[countAppointments].Date.Weekday = date.Weekday;

   POSITION(5,0);
   CLEAR_LINE;
   getTime(points[1], &time);
   Calendar[countAppointments].Time.Hour = time.Hour;
   Calendar[countAppointments].Time.Minute = time.Minute;
   Calendar[countAppointments].Time.Second = time.Second;

   POSITION(6,0);
   CLEAR_LINE;
   getText(points[2], &apptmnt -> pDescription, maxlen_description, 1);
   *strcpy(Calendar[countAppointments].pDescription, apptmnt -> pDescription);
   POSITION(7,0);
   CLEAR_LINE;
   getText(points[3], &apptmnt -> pPlace, maxlen_place, 0);
   *strcpy(Calendar[countAppointments].pPlace, apptmnt -> pPlace);
   POSITION(8,0);
   CLEAR_LINE;
   getTime(points[4], &time);
   Calendar[countAppointments].Duration.Hour = time.Hour;
   Calendar[countAppointments].Duration.Minute = time.Minute;
   Calendar[countAppointments].Duration.Second = time.Second;

   (*countAppointp)++;
   POSITION(10,0);
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
   char *title = "Termine auflisten";
   CLEAR;
   getSubMenu(title/*, points, 5*/);
   for (i = 0; i < countAppointments; i++)
   {
      printf("\n%d.Termin %d %02d.%02d.%04d  %02d:%02d:%02d\n%s             %s Dauer: %02d:%02d:%02d", i + 1, Calendar[i].Date.Weekday, Calendar[i].Date.Day, Calendar[i].Date.Month, Calendar[i].Date.Year, Calendar[i].Time.Hour, Calendar[i].Time.Minute, Calendar[i].Time.Second, Calendar[i].pPlace, Calendar[i].pDescription, Calendar[i].Duration.Hour, Calendar[i].Duration.Minute, Calendar[i].Duration.Second);
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
