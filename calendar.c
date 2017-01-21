#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructure.h"
#include "tools.h"
#include "calendar.h"
#include "datetime.h"
#include "menu.h"
#include "escapesequenzen.h"
#include "database.h"
#include "sort.h"

/*
calendar

Funktionen:

   void createAppointment()
   void editAppointment()
   void deleteAppointment()
   void searchAppointment()
   void sortCalendar()
   void listCalendar()
   void printAppointment (TAppointment *)
   freeCalendar()
   freeAppointment (TAppointment *)
   compare(int *,int*)
   compare_down(int *,int*)
   swp(int *,int*)
*/

int countAppointments = 0;
int *countAppointp = &countAppointments;
//int i;
const int maxlen_description = 100, maxlen_place = 15;

TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
   TAppointment *App = Calendar + countAppointments; //pointer auf das aktuelle Appointment im globalen Calendar
   App->Description = calloc(101, sizeof(char));
   App->Location = calloc(16, sizeof(char));
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
   printf("%s%s", points[2], App->Description);
   POSITION(7, 0);
   CLEAR_LINE;
   getText(points[3], &App -> Location, maxlen_place, 0);
   UP(1);
   CLEAR_LINE;
   if (App->Location)
   printf("%s%s", points[3], App->Location);
   else
   printf("%s ", points[3]);
   POSITION(8, 0);
   CLEAR_LINE;
   getTime(points[4], App->Duration);
   (*countAppointp)++;
   POSITION(10, 0);
   CLEAR_LINE;
   printf("Termin wurde gespeichert");
   waitForEnter();
}

void editAppointment()
{
   printf("Termin bearbeiten");
   waitForEnter();
}

void deleteAppointment()
{
   printf("Termin löschen");
   waitForEnter();
}

void searchAppointment()
{
   printf("Termin suchen");
   waitForEnter();
}

void sortCalendar()
{
   TAppointment *App = Calendar + countAppointments; //pointer auf das aktuelle Appointment im globalen Calendar
   App->Description = calloc(101, sizeof(char));
   App->Location = calloc(16, sizeof(char));
   App->Duration = calloc(1, sizeof(TTime));
   App->Time.Hour = -1;
   App->Time.Minute = -1;
   App->Time.Second = -1;
   App->Date.Day = -1;
   App->Date.Month = -1;
   App->Date.Year = -1;
   int ch = -1;
   char *menuT = "Termine sortieren";
   char *menuP[5] = { "Sortieren nach Datum und Uhrzeit",
                      "Sortieren nach Beschreibung",
                      "Sortieren nach Ort",
                      "Sortieren nach Dauer",
                      "Zurueck zum Hauptmenue"
                    };
   clearScreen();
   ch = getMenu(menuT, menuP, 5);
   switch (ch)
   {
   case 1: Quicksort(App-countAppointments, countAppointments, cmpDatTim, swp);  break; //der übergebene Pointer zeigt auf das erste Element
   case 2: Quicksort(App-countAppointments, countAppointments, cmpDes, swp);     break;
   case 3: Quicksort(App-countAppointments, countAppointments, cmpLoc, swp);     break;
   case 4: Quicksort(App-countAppointments, countAppointments, cmpDur, swp);     break;
   case 5:                                                                       break;
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
   int fillspace = maxlen_place;
   if (App->Location)
      fillspace= maxlen_place - strlen(App->Location);
   if ((App - 1) -> Date.Day) //if not first Appointment
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
   printf(" - ");
   printTime(addTime(App));
   printf(" -> ");
   if (App->Location)
   printf("%s", App -> Location);
   for (i = 0; i < fillspace; i++)
   {
      printf(" ");
   }
   printf(" | %s\n", App -> Description);
}

void listCalendar()
{
   int i;
   char *title = "Termine auflisten";
   CLEAR;
   getSubMenu(title);
   if (countAppointments == 0)
      printf("\n\nnoch keine Termine vorhanden\n");
   for (i = 0; i < countAppointments; i++)
   {
      printAppointment(Calendar + i);
   }
   waitForEnter();
}

void freeAppointment(TAppointment *App)
{
   free((App)->Duration);
   free((App)->Location);
   free((App)->Description);
}

void freeCalendar()
{
   int i;
   for (i = 0; i < countAppointments; i++)
   {
      freeAppointment(Calendar + i);
   }
}

int cmpDat(TAppointment *A1, TAppointment *A2)
{
   int erg = 0;
   erg = A1->Date.Year - A2->Date.Year;
   if (erg == 0)
      erg = A1->Date.Month - A2->Date.Month;
   if (erg == 0)
      erg = A1->Date.Day - A2->Date.Day;
   return erg;
}

int cmpTim(TAppointment *A1, TAppointment *A2)
{
   int erg = 0;
   erg = A1->Time.Hour - A2->Time.Hour;
   if (erg == 0)
      erg = A1->Time.Minute - A2->Time.Minute;
   if (erg == 0)
      erg = A1->Time.Second - A2->Time.Second;
   return erg;
}

int cmpDatTim(TAppointment *A1, TAppointment *A2)
{
   int erg = 0;
   erg = cmpDat(A1, A2);
   if (erg == 0)
      erg = cmpTim(A1, A2);
   return erg;
}

int cmpDur(TAppointment *A1, TAppointment *A2) /** TODO **/
{
   if (A1 && A2)
      return A1->Duration->Hour - A2->Duration->Hour;
   else return 0;
}

int cmpDes(TAppointment *A1, TAppointment *A2) /** TODO **/
{
   if (A1 && A2)
      return A1->Description - A2->Description;
   else return 0;
}

int cmpLoc(TAppointment *A1, TAppointment *A2) /** TODO **/
{
   if (A1 && A2)
      return A1->Location - A2->Location;
   else return 0;
}

void swp(TAppointment *A1, TAppointment *A2)
{
   TAppointment tmp = *A1;
   *A1 = *A2;
   *A2 = tmp;
}
