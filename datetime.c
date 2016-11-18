#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include <string.h>
#include "escapesequenzen.h"

// TODO getDateFromString mit Wochentagberechnung erweitern

// Benutzereingabe eines Datums und Umwandlung in ein TDate (Funtionalität aus der main.c von Uebung1)
void getDate(char prompt[], TDate *dat)
{

   char Input[20];
   printf("%s",prompt);
   do
   {
      *Input = '\0';
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
      {
         if (getDateFromString(Input, dat))
         {
           printf("ok");
         }
         else
         {
             DOWN(2);
            printf("Das eingegebene Datum %s ist ungueltig!", Input);
            UP(3);
         }
      }
      else
      {
         DOWN(2);
         printf("Sie haben nichts eingegeben!");
         UP(3);
      }
   } while (!*Input);

}

/* Benutzereingabe einer Uhrzeit (auch ohne Sekunden) und Umwandlung in ein TTime (Funtionalität aus der main.c von Uebung1)
   Es muss zusätzlich Speicher für die Termindauer reserviert werden
*/
void getTime(char prompt[], TTime *tim)
{
      char Input[20];
      *Input = '\0';
      printf("%s",prompt);
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
      {
         if (getTimeFromString(Input, &Time))
      {
            printf("ok");
      }
         else
            DOWN(2);
            printf("Die eingegebene Uhrzeit ist ungueltig!\n");
            UP(3);
      }
      else
         DOWN(2);
         printf("Sie haben nichts eingegeben!");
         UP(3);
}

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
   if (date.Month>= 1 && date.Month <=12 && date.Day >= 1 && date.Day <= 31 && date.Year >= 0)
   {
      switch (date.Month)
      {
         case 1:
         case 3:
         case 5:
         case 7:
         case 8:
         case 10:
         case 12: isvalid = 1;                               break;

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

int getDateFromString(char input[], TDate *date)
{
    char *p;
    int i;

    p = strtok(input, ".");

    for(i = 0; (p != NULL); i++){
        if(i == 0){
            (*date).Day = atoi(p);
        }else if(i == 1){
            (*date).Month = atoi(p);
        }else if(i == 2){
            (*date).Year = atoi(p);
        }
        p = strtok(NULL, ".");
    }

    return isDateValid((*date));
}


//int getDateFromString(char input[], TDate *Date)
//{
//
//    if(sscanf(input,"%d.%d.%d",&Date->Day,&Date->Month,&Date->Year) && isDateValid(*Date))
//      return 1;
//   return 0;
//}


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

int isTimeValid(TTime time)
{
      return 0;
}

int getTimeFromString(char input[], TTime *time)
{
   int i = 0;
   int pos = 0;
   int isvalid = -1;

   time -> Hour = NULL;
   time -> Minute = NULL;
   time -> Second = NULL;

   while(input[i] && pos < 3)
   {
      if (input[i] == ':') //TODO
         pos++;
      i++;
   }
   isvalid = isTimeValid(*time);
   return isvalid;
}

