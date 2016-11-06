#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"

int isLeapYear(int year)
{
   if(! 400 % year || (! 4 % year && 100 % year))
      return 1;
   else return 0;
}

int isDateValid(int d, int m, int y)
{
   int isvalid;
   if (m >= 1 && m <=12 && d >= 1 && d <= 28 && y >= 0)
   {
      switch (m)
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12: isvalid = d <= 31 ? 1 : 0;          break;

         case 4:
         case 6:
         case 9:
         case 11: isvalid = d <= 30 ?  1 : 0;         break;

         case 2: if (isLeapYear(y))
                 {
                    isvalid = d <= 29 ? 1 : 0;        break;
                 }
                 else
                 {
                    isvalid = d <= 28 ? 1 : 0;        break;
                 }
         default: printf("hä?");
      }
   }
   return isvalid;
}

int getDateFromString(char date[],TDate *pd)
{
   int i = 0, pos = 0, isval = 0, delim[2];
//   int day, month, year, day1, day2, month1, month2, year1, year2, year3, year4;
   //char day[2], month[2], year[4];
   TDate *pDate = pd; //???
//   pDate -> Day   = 0;
//   pDate -> Month = 0;
//   pDate -> Year  = 0;
   char *pday = NULL;
   char *pmonth = NULL;

   while(date[i])
   {
      if (date[i] == '.')
      {
         switch (pos)
         {
            case 0: *pday = date[i-2]; day[0] = *pday; break;
            case 1: *pmonth = date[i-2]; month[0] = *pmonth; break;
         }

         delim[pos] = i;
         pos++;
      }
      i++;
   }

   isval = isDateValid(day, month, year);




   if (isval)
   {
      pDate -> Day   = day;
      pDate -> Month = month;
      pDate -> Year  = year;
      return 1;
   }
   else
      return 0;
}

int isTimeValid(int h, int m, int s)
{
   if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
      return 1;
   else
      return 0;
}

int getTimeFromString(char time[], TTime *pt)
{
   //TTime *pTime = pt; //makes sense???
   int i = 0;
   int pos = 0;
   int isvalid = -1;
   int hour, minute, second;
   TTime *pTime = pt;
   pTime -> Hour = NULL;
   pTime -> Minute = NULL;
   pTime -> Second = NULL;

   while(time[i] && pos < 3)
   {
      if (time[i] == '.')
         pos++;
      i++;
   }
   isvalid = isTimeValid(hour, minute, second);
   return isvalid;
}

