#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"

int isLeapYear(int year)
{
   if(((4 % year == 0) && (100 % year != 0)) || (400 % year == 0))
      return 1;
   else
      return 0;
}

int isDateValid(TDate date)
{
   int isvalid = 0;
   if (date.Month>= 1 && date.Month <=12 && date.Day >= 1 && date.Day <= 28 && date.Year >= 0)
   {
      switch (date.Month)
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12: isvalid = date.Day <= 31 ? 1 : 0;          break;

         case 4:
         case 6:
         case 9:
         case 11: isvalid = date.Day <= 30 ?  1 : 0;         break;

         case 2: if (isLeapYear(date.Year))
                 {
                    isvalid = date.Day <= 29 ? 1 : 0;        break;
                 }
                 else
                 {
                    isvalid = date.Day <= 28 ? 1 : 0;        break;
                 }
         default: printf("hä?");
      }
   }
   return isvalid;
}

int getDateFromString(char input[], TDate *Date)
{

    if(sscanf(input,"%d.%d.%d",&Date->Day,&Date->Month,&Date->Year) && isDateValid(*Date))
      return 1;
   return 0;
}
//int getDateFromString(char date[],TDate *pd)
//{
//   int i = 0, pos = 0, isval = 0, delim[2];
////   int day, month, year, day1, day2, month1, month2, year1, year2, year3, year4;
//   //char day[2], month[2], year[4];
//   TDate *pDate = pd; //???
////   pDate -> Day   = 0;
////   pDate -> Month = 0;
////   pDate -> Year  = 0;
//   char *pday = NULL;
//   char *pmonth = NULL;
//
//   while(date[i])
//   {
//      if (date[i] == '.')
//      {
//         switch (pos)
//         {
//            case 0: *pday = date[i-2]; day[0] = *pday; break;
//            case 1: *pmonth = date[i-2]; month[0] = *pmonth; break;
//         }
//
//         delim[pos] = i;
//         pos++;
//      }
//      i++;
//   }
//
//   isval = isDateValid(day, month, year);
//
//
//
//
//   if (isval)
//   {
//      pDate -> Day   = day;
//      pDate -> Month = month;
//      pDate -> Year  = year;
//      return 1;
//   }
//   return 0;
//}

int isTimeValid(int h, int m, int s)
{
   if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59)
      return 1;
   else
      return 0;
}

int getTimeFromString(char time[], TTime *pt)
{
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

