#ifndef DATASTRUCTURE_H
   #define DATASTRUCTURE_H DATASTRUCTURE_H
   #define MAXAPPOINTMENTS 100
   #define NUMPOINTS 9


typedef enum { NotADay = 0, Mo, Tu, We, Th, Fr, Sa, Su } TDayOfTheWeek;

typedef struct
{
    int Day, Month, Year;
    TDayOfTheWeek Weekday;
} TDate;

typedef struct
{
   int Hour, Minute, Second;
} TTime;

typedef struct
{
   TDate Date;
   TTime Time;
   char *Description;
   char *Place;
   TTime *Duration;
} TAppointment;

extern int countAppointments;
extern int *countAppointp;
extern TAppointment Calendar[];

#endif
