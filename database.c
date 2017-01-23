#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "datetime.h"

char filename[] = "calend.xml";
void saveAppointment(FILE *d, TAppointment *App)
{
   fprintf (d, " <Appointment>\n");
   fprintf (d, "  <Date>%02d.%02d.%04d</Date>\n", App->Date.Day, App->Date.Month, App->Date.Year);
   fprintf (d, "  <Time>%02d:%02d:%02d</Time>\n", App->Time.Hour, App->Time.Minute, App->Time.Second);
   fprintf (d, "  <Description>%s</Description>\n", App->Description);
   if (App->Location)
      fprintf (d, "  <Location>%s</Location>\n", App->Location);
   if (App->Duration && (App->Duration->Hour||App->Duration->Minute||App->Duration->Second))
      fprintf (d, "  <Duration>%02d:%02d:%02d</Duration>\n", App->Duration->Hour, App->Duration->Minute, App->Duration->Second);
   fprintf (d, " </Appointment>\n");
}

void resetAppointment(TAppointment *App)
{
   App->Date.Day   = 0;
   App->Date.Month = 0;
   App->Date.Year  = 0;
   App->Date.Weekday = NotADay;
   App->Description = NULL;
   App->Location = NULL;
   App->Duration = NULL;
}

void loadAppointment(FILE *d, char l[])
{
   int len = 0;
   char *pos;
   TAppointment *App = Calendar + countAppointments;

   resetAppointment(App);
   do
   {
      fgets (l, 100, d);
      pos = l;
      while ((*pos == ' ') || (*pos == 9))
      {
         pos++;
      }
      if(strncmp (pos, "<Date>", 6) == 0)
      {
         getDateFromString (pos + 6, &(App->Date));
      }
      else if(strncmp (pos, "<Time>", 6) == 0)
      {
         getTimeFromString (pos + 6, &(App->Time));
      }
      else if (strncmp (pos, "<Duration>", 10) == 0)
      {
         free (App->Duration);
         App->Duration = calloc (1, sizeof(TTime));
         if (App->Duration)
            getTimeFromString (pos + 10, App->Duration);
      }

      else if (strncmp (pos, "<Description>", 13) == 0)
      {
         free (App->Description);
         len = strlen(pos + 13) - 15;
         if (strncmp (pos + 13 + len, "</Description>", 14) == 0)
         {
            App->Description = calloc(len + 1, sizeof(char));
            if (App->Description)
               strncpy(App->Description, pos + 13, len);
         }
      }
      else if (strncmp (pos, "<Location>", 10) == 0)
      {
         free (App->Location);
         len = strlen(pos + 10) - 12;
         if (strncmp (pos + 10 + len, "</Location>", 11) == 0)
         {
            App->Location = calloc(len + 1, sizeof(char));
            if (App->Location)
               strncpy(App->Location, pos + 10, len);
         }
      }
      if(feof (d))
         break;
   }
   while(strncmp (l, " </Appointment>", 15) != 0);
   (*countAppointp)++;
}
int saveCalendar()
{
   int i;
   FILE *dat = fopen (filename, "wt");
   if (dat == NULL)
   {
      printf ("\nDatei konnte nicht erzeugt oder geöffnet werden\n");
      return 0;
   }
   else
   {
      printf ("\nTermine gespeichert \n");
      fprintf (dat, "<Calendar>\n");
      for (i = 0; i < countAppointments; i++)
      {
         saveAppointment (dat, Calendar + i);
      }
      fprintf (dat, "</Calendar>\n");
      fclose (dat);
      return 1;
   }
}
int loadCalendar()
{
   char line[101];
   char *pos;

   FILE *dat = fopen (filename, "rt");
   if (dat)
   {
      do
      {
         fgets (line, 100, dat);
         pos = line;
         while ((*pos == ' ') || (*pos == 9))
         {
            pos++;
         }
         if (feof (dat) )
            break;
         else if (strncmp (pos, "<Appointment>", 13) == 0)
         {
            loadAppointment (dat, line);
         }
      }
      while (strncmp (line, "</Calendar>", 11) != 0);
      printf("\n\nTermine geladen\n");
      return 1;
   }
   else
   {
      printf ("\nDatei konnte nicht geöffnet werden");
      return 0;
   }
   fclose (dat);
}
