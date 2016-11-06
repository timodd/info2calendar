#ifndef DATETIME_H
   #define DATETIME_H DATETIME_H

   int isLeapYear(int);

   int isDateValid(TDate);

   int getDateFromString(char [], TDate *);

   int isTimeValid(int, int, int);

   int getTimeFromString(char [], TTime *);


#endif // DATETIME_H_INCLUDED
