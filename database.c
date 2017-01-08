#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "datetime.h"

char filename[] = "calend.xml";
void saveAppointment(FILE *d, int index)
{
   fprintf (d, " <Appointment>\n");
   fprintf (d, "  <Date>%02d.%02d.%04d</Date>\n", Calendar[index].Date.Day, Calendar[index].Date.Month, Calendar[index].Date.Year);
   fprintf (d, "  <Time>%02d:%02d:%02d</Time>\n", Calendar[index].Time.Hour, Calendar[index].Time.Minute, Calendar[index].Time.Second);
   fprintf (d, "  <Description>%s</Description>\n", Calendar[index].Description);
   fprintf (d, "  <Location>%s</Location>\n", Calendar[index].Place);
   fprintf (d, "  <Duration>%02d:%02d:%02d</Duration>\n", Calendar[index].Duration->Hour, Calendar[index].Duration->Minute, Calendar[index].Duration->Second);
   fprintf (d, " </Appointment>\n");
}

void resetAppointment(TAppointment *App)
{
   App->Date.Day   = 0;
   App->Date.Month = 0;
   App->Date.Year  = 0;
   App->Date.Weekday = NotADay;
   App->Description = NULL;
   App->Place = NULL;
   App->Duration = NULL;
}

//void extrStr(TAppointment *App, char* pos, char tag) // TODO************************************************
//{
//   int len;
//   len = strlen (*pos + strlen (tag)) - strlen (tag) - 1;
//   if(strncmp (pos, "</Description>", 14) == 0)
//   {
//      App->Description = calloc (strlen (pos) + 1, sizeof (char));
//      if (pos)
//         strncpy(App->Description, pos + strlen (tag), len);
//   }
//   else if(strncmp (pos, "</Location>", 12) == 0)
//   {
//      App->Place = calloc (strlen (pos) + 1, sizeof (char));
//      if (pos)
//         strncpy(App->Place, pos + strlen (tag), len);
//   }
//}

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
         free (App->Place);
         len = strlen(pos + 10) - 12;
         if (strncmp (pos + 10 + len, "</Location>", 11) == 0)
         {
            App->Place = calloc(len + 1, sizeof(char));
            if (App->Place)
               strncpy(App->Place, pos + 10, len);
         }
      }
      if(feof (d))
         break;
   }
   while(strncmp (l, " </Appointment>", 15) != 0);
   (*countAppointp)++;
//   while ((*bol == ' ') || (*bol == 9))
//      bol++;


   //. . .

}
int saveCalendar(int c)
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
      fprintf (dat, "<Calendar>\n");
      for (i = 0; i < c; i++)
      {
         saveAppointment (dat, i);
      }
      fprintf (dat, "</Calendar>\n");
      fclose (dat);
      return 1;
   }
}
int loadCalendar()
{
   char line[101];
   FILE *dat = fopen (filename, "rt");
   if (dat)
   {
      do
      {
         fgets (line, 100, dat);
         if (feof (dat) )
            break;
         else if (strncmp (line, " <Appointment>", 14) == 0)
         {
//               printf("%s",line);
            loadAppointment (dat, line);
         }
      }
      while (strncmp (line, "</Calendar>", 11) != 0);
      return 1;
   }
   else
   {
      printf ("\nDatei konnte nicht geöffnet werden");
      return 0;
   }
   fclose (dat);
}



//<Calendar>
// <Appointment>
//  <Date> </Date>
//  <Time> </Time>
//  <Description> </Description>
//  <Location> </Location>
//  <Duration> </Duration>
// </Appointment>
//</Calendar>
