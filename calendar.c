/*
calendar
*/
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include "tools.h"
#include "menu.h"
#include "calendar.h"

int AppointmentCount = 0;

void createAppointment()
{
   printf("Termin erzeugen\n");
   waitForEnter();
}

void editAppointment()
{
   printf("Termin bearbeiten\n");
   waitForEnter();
}

void deleteAppointment()
{
   printf("Termin löschen\n");
   waitForEnter();
}

void searchAppointment()
{
   printf("Termin suchen\n");
   waitForEnter();
}

void sortCalendar()
{
   printf("Kalender sortieren\n");
   waitForEnter();
}

void listCalendar()
{
   printf("Kalender auflisten\n");
   waitForEnter();
}
