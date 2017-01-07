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
#include "database.h"

int countAppointments = 0;
int *countAppointp = &countAppointments;
int i;
const int maxlen_description = 100, maxlen_place = 15;

TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
   TAppointment *apptmnt = Calendar + countAppointments;
//   TDate date;
//   TTime time;
//   char describ[maxlen_description];
//   char place[maxlen_place];
   apptmnt->Description = calloc(101, sizeof(char));
   apptmnt->Place = calloc(16, sizeof(char));
   apptmnt->Duration = calloc(11, sizeof(char));

   Calendar[countAppointments].Time.Minute = -1;
   Calendar[countAppointments].Time.Second = -1;
   Calendar[countAppointments].Description = calloc(100, sizeof(char));
   Calendar[countAppointments].Place = calloc(15, sizeof(char));


   char *title = "Erfassung eines neuen Termins";
   char *points[5] = {  "Datum        : ",
                     "Uhrzeit      : ",
                     "Beschreibung : ",
                     "Ort          : ",
                     "Dauer        : "
                     };

   getSubMenu(title);

   POSITION(4,0);
   getDate(points[0], &Calendar[countAppointments].Date);
//   Calendar[countAppointments].Date.Day = date.Day;
//   Calendar[countAppointments].Date.Month = date.Month;
//   Calendar[countAppointments].Date.Year = date.Year;
//   Calendar[countAppointments].Date.Weekday = date.Weekday;

   POSITION(5,0);
   CLEAR_LINE;
   getTime(points[1], &Calendar[countAppointments].Time);
//   Calendar[countAppointments].Time.Hour = time.Hour;
//   Calendar[countAppointments].Time.Minute = time.Minute;
//   Calendar[countAppointments].Time.Second = time.Second;

   POSITION(6,0);
   CLEAR_LINE;
   getText(points[2], &apptmnt -> Description, maxlen_description, 1);
   *strcpy(Calendar[countAppointments].Description, apptmnt -> Description);
   UP(1);
   CLEAR_LINE;
   printf("%s%s",points[2],Calendar[countAppointments].Description);
   POSITION(7,0);
   CLEAR_LINE;
   getText(points[3], &apptmnt -> Place, maxlen_place, 0);
   *strcpy(Calendar[countAppointments].Place, apptmnt -> Place);
   UP(1);
   CLEAR_LINE;
   printf("%s%s",points[3],Calendar[countAppointments].Place);
   POSITION(8,0);
   CLEAR_LINE;
   getTime(points[4], Calendar[countAppointments].Duration);
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
   getSubMenu(title);
   for (i = 0; i < countAppointments; i++)
   {
      printAppointment(Calendar + i);
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
   char *wday[7] = {"So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"};
   int index = appoint -> Date.Weekday;
   if ((appoint - 1) -> Date.Day)
   {
      TDate tmp = (appoint - 1) -> Date;
      if (tmp.Day != appoint -> Date.Day || tmp.Month != appoint -> Date.Month || tmp.Year != appoint -> Date.Year) //if new date
      {
         printf("\n");
         printLine('=', 80);
         printf("%s, ", wday[index]);
         printDate(appoint -> Date);
      }
   }
   else // if first date
      {
         printf("\n");
         printLine('=', 80);
         printf("%s, ", wday[index]);
         printDate(appoint -> Date);
      }
      printTime(appoint -> Time);
      printf("%s  %s", appoint -> Place, appoint -> Description);
      printf("\n");
}

void freeCalendar()
{

}
