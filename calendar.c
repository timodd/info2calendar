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
   TAppointment *App = Calendar + countAppointments; //pointer auf das aktuelle Appointment im globalen Calendar
   App->Description = calloc(101, sizeof(char));
   App->Place = calloc(16, sizeof(char));
   App->Duration = calloc(1, sizeof(TTime));
   App->Time.Hour = -1;
   App->Time.Minute = -1;
   App->Time.Second = -1;
   App->Date.Day = -1;
   App->Date.Month = -1;
   App->Date.Year = -1;

   char *title = "Erfassung eines neuen Termins";
   char *points[5] = {  "Datum        : ",
                        "Uhrzeit      : ",
                        "Beschreibung : ",
                        "Ort          : ",
                        "Dauer        : "
                     };
   getSubMenu(title);

   POSITION(4, 0);
   getDate(points[0], &App->Date);

   POSITION(5, 0);
   CLEAR_LINE;
   getTime(points[1], &App->Time);

   POSITION(6, 0);
   CLEAR_LINE;
   getText(points[2], &App -> Description, maxlen_description, 1);
   UP(1);
   CLEAR_LINE;
   printf("%s%s", points[2], Calendar[countAppointments].Description);
   POSITION(7, 0);
   CLEAR_LINE;
   getText(points[3], &App -> Place, maxlen_place, 0);
   UP(1);
   CLEAR_LINE;
   printf("%s%s", points[3], Calendar[countAppointments].Place);
   POSITION(8, 0);
   CLEAR_LINE;
   getTime(points[4], App->Duration);
   (*countAppointp)++;
   POSITION(10, 0);
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
   if (countAppointments == 0)
      printf("\n\nnoch keine Termine vorhanden\n");
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
void printAppointment(TAppointment *App)
{
   char *wday[7] = {"So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"};
   int i, index = App -> Date.Weekday;
   int fillspace = maxlen_place - strlen(App->Place);
   if ((App - 1) -> Date.Day)
   {
      TDate tmp = (App - 1) -> Date;
      if (tmp.Day != App -> Date.Day || tmp.Month != App -> Date.Month || tmp.Year != App -> Date.Year) //if new date
      {
         printf("\n");
         printLine('=', 80);
         printf("%s, ", wday[index]);
         printDate(App -> Date);
      }
   }
   else // if first date
   {
      printf("\n");
      printLine('=', 80);
      printf("%s, ", wday[index]);
      printDate(App -> Date);
   }
   printTime(App -> Time);
   printf("%s", App -> Place);
   for (i = 0; i < fillspace; i++)
   {
      printf(" ");
   }
   printf(" | %s\n", App -> Description);
}

void freeCalendar()
{
   int i;
   for (i = 0; i < countAppointments; i++)
   {
      freeAppointment(Calendar + i);
   }
}
void freeAppointment(TAppointment *App)
{
   free((App)->Duration);
   free((App)->Place);
   free((App)->Description);
}
