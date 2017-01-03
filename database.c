#include <stdio.h>
#include <string.h>
#include "datastructure.h"
#include "calendar.h"

char filename[] = "calend.xml";
void saveAppointment(FILE *d, int index)
{
   fprintf(d, " <Appointment>\n");
   fprintf(d, "  <Date>%02d.%02d.%04d</Date>\n", Calendar[index].Date.Day, Calendar[index].Date.Month, Calendar[index].Date.Year);
   fprintf(d, "  <Time>%02d.%02d.%02d</Time>\n", Calendar[index].Time.Hour, Calendar[index].Time.Minute, Calendar[index].Time.Second);
   fprintf(d, "  <Description>%s</Description>\n",Calendar[index].Description);
   fprintf(d, "  <Location>%s</Location>\n",Calendar[index].Place);
   fprintf(d, "  <Duration>%02d.%02d.%02d</Duration>\n", Calendar[index].Duration.Hour, Calendar[index].Duration.Minute, Calendar[index].Duration.Second);
   fprintf(d, " </Appointment>\n");
}

int saveCalendar(int c)
{
   int i;
   FILE *dat = fopen (filename,"wt");
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
int loadCalendar() //TODO**************
{
   char line[101];
   FILE *dat = fopen (filename,"rt");
   if (dat)
   {
      do
      {
         fscanf (dat, "%100[^\n]",line);
      //. . .

         if (feof(dat))
            break;
      } while (strncmp(line, "</Calendar>", 9) != 0);

         fclose(dat);
         return 1;
   }
   else
   {
      printf ("\nDatei konnte nicht geöffnet werden");
      return 0;
   }
}

void loadAppointment()
{

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
