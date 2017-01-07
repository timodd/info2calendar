#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datastructure.h"
#include "calendar.h"
#include "datetime.h"

char filename[] = "calend.xml";
void saveAppointment(FILE *d, int index)
{
   fprintf(d, " <Appointment>\n");
   fprintf(d, "  <Date>%02d.%02d.%04d</Date>\n", Calendar[index].Date.Day, Calendar[index].Date.Month, Calendar[index].Date.Year);
   fprintf(d, "  <Time>%02d:%02d:%02d</Time>\n", Calendar[index].Time.Hour, Calendar[index].Time.Minute, Calendar[index].Time.Second);
   fprintf(d, "  <Description>%s</Description>\n", Calendar[index].Description);
   fprintf(d, "  <Location>%s</Location>\n", Calendar[index].Place);
   fprintf(d, "  <Duration>%02d:%02d:%02d</Duration>\n", Calendar[index].Duration->Hour, Calendar[index].Duration->Minute, Calendar[index].Duration->Second);
   fprintf(d, " </Appointment>\n");
}

void resetAppointment(TAppointment *App)
{
   App->Date.Day   = 0;
   App->Date.Month = 0;
   App->Date.Year  = 0;
   App->Date.Weekday = NotADay;

   App->Description = NULL;
}

void loadAppointment(FILE *d, char l[])
{
   char *pos;
   TAppointment *App = Calendar + countAppointments;

   resetAppointment(App);
   do
   {
      fgets(l, 100, d);
      pos = l;
      while ((*pos == ' ') || (*pos == 9))
      {
         pos++;
      }
      if (strncmp(pos, "<Date>", 6) == 0)
      {
         getDateFromString(pos + 6, &(App->Date));
      }
      else
         if (strncmp(pos, "<Time>", 6) == 0)
         {
            getTimeFromString(pos + 6, &(App->Time));
         }
      else
         if (strncmp(pos, "<Duration>", 10) == 0)
         {
             App->Duration = calloc(1, sizeof(TTime));
            getTimeFromString(pos + 10, App->Duration);
         }

      else
         if (strncmp(pos, "<Description>", 13) == 0)
         {
            pos += 13;
            free(App->Description);
            App->Description = calloc(strlen(pos) + 1, sizeof(char));
            strcpy(App->Description, pos);
         }
           else
         if (strncmp(pos, "<Location>", 10) == 0)
         {
            pos += 10;
            free(App->Place);
            App->Place = calloc(strlen(pos) + 1, sizeof(char));
            if (pos)
               strcpy(App->Place, pos);
         }
      if (feof(d))
         break;
   }while (strncmp(l, " </Appointment>", 15) != 0);
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
      printf("\nDatei konnte nicht erzeugt oder geöffnet werden\n");
      return 0;
   }
   else
   {
      fprintf(dat, "<Calendar>\n");
      for (i = 0; i < c; i++)
      {
         saveAppointment(dat, i);
      }
      fprintf(dat, "</Calendar>\n");
      fclose(dat);
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
         fgets(line, 100, dat);
         if (feof(dat))
            break;
         else
            if (strncmp(line, " <Appointment>", 14) == 0)
            {
//               printf("%s",line);
               loadAppointment(dat, line);
            }
      }while (strncmp(line, "</Calendar>", 11) != 0);
   return 1;
   }
   else
   {
      printf ("\nDatei konnte nicht geöffnet werden");
      return 0;
   }
   fclose(dat);
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
