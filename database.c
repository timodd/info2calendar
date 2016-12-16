#include <stdio.h>
#include <string.h>

void saveCalendar()
{
   char line[101];
FILE *dat = fopen( “calendar.xml”, “rt” ); //declaew
   if (dat)
   {
      do
      {
         fscanf(dat, “%100[^\n]”, line);
      //. . .

         if (feof(dat))
            break;
      } while ( strncmp(line, “</Calendar>”, 9) != 0 );

         fclose(dat);
   }

void saveAppointment()
{

}

void loadCalendar()
{

}

void loadAppointment()
{

}


//<Calendar>
// <Appointment>
//  <Date> </Date>
//  <Time> </Time>
//  <Description> </Description>
//  <Duration> </Duration>
// </Appointment>
//</Calendar>
