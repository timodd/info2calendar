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
int countAppointments = 0;
TAppointment Calendar[MAXAPPOINTMENTS];

void createAppointment()
{
   printf("neuen Termin anlegen");
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
