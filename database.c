#include <stdio.h>
#include <string.h>
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
   fprintf(d, "  <Duration>%02d:%02d:%02d</Duration>\n", Calendar[index].Duration.Hour, Calendar[index].Duration.Minute, Calendar[index].Duration.Second);
   fprintf(d, " </Appointment>\n");
}
void loadAppointment(FILE *d, char l[])
{
   do
   {
      fgets(l, 100, d);
      if (strstr(l, "<Date>"))
      {
//         printf("%s",l);
         getDateFromString(l, &Calendar[countAppointments].Date);
      }
      else
         if (strstr(l, "<Time>"))
         {
//            printf("%s",l);
            getTimeFromString(l, &Calendar[countAppointments].Time);
         }
      else
         if (strncmp(l, "  <Description>", 15) == 0)
         {
//            printf("%s",l);
//            Calendar[countAppointments].Description);
         }
           else
         if (strncmp(l, "  <Location>", 15) == 0)
         {
//            printf("%s",l);
//            Calendar[countAppointments].Place);
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
