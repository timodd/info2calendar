#include <stdlib.h>
#include <stdio.h>
#include "datastructure.h"
#include "datetime.h"
#include <string.h>
#include "escapesequenzen.h"
#include "tools.h"

// TODO getDateFromString mit Wochentagberechnung erweitern

// Benutzereingabe eines Datums und Umwandlung in ein TDate (Funtionalität aus der main.c von Uebung1)
void getDate(char prompt[], TDate *d)
{
   int t;
   char Input[20];
   do
   {
      *Input = '\0';
      STORE_POS;
      CLEAR_LINE;
      printf("%s",prompt);
      scanf("%19[^\n]", Input);
      clearBuffer();
      if (*Input)
      {
         t = getDateFromString(Input, d);
         if (!t)
         {
            DOWN(2);
            printf("Das eingegebene Datum ist ungueltig!");
            RESTORE_POS;
         }
      }
      else
      {
         DOWN(2);
         printf("Sie haben nichts eingegeben!");
         RESTORE_POS;
      }
   } while (!t);
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

int getDateFromString(char input[], TDate *d)
{
    char *p;
    int i;

    p = strtok(input, ".");

    for(i = 0; (p != NULL); i++){
        if(i == 0){
            (*d).Day = atoi(p);
        }else if(i == 1){
            (*d).Month = atoi(p);
        }else if(i == 2){
            (*d).Year = atoi(p);
        }
        p = strtok(NULL, ".");
    }

    return isDateValid((*d));
}


//int getDateFromString(char input[], TDate *Date)
//{
//
//    if(sscanf(input,"%d.%d.%d",&Date->Day,&Date->Month,&Date->Year) && isDateValid(*Date))
//      return 1;
//   return 0;
//}



int isTimeValid(TTime Time)
{
    if (Time.Hour >= 0 && Time.Hour <= 23)

        if (Time.Minute >= 0 && Time.Minute <= 59)

            if (Time.Second >= 0 && Time.Second <= 59)
                return 1;

    return 0;
}

int getTimeFromString(char input[], TTime *Time)
{
    char *p;
    int i;

    p = strtok(input, ":");

    for(i = 0; (p != NULL); i++){
        if(i == 0){
            (*Time).Hour = atoi(p);
        }else if(i == 1){
            (*Time).Minute = atoi(p);
        }else if(i == 2){
            (*Time).Second = atoi(p);
        }
        p = strtok(NULL, ":");
    }

    return isTimeValid((*Time));
}


