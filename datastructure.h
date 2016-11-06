#ifndef DATASTRUCTURE_H
   #define DATASTRUCTURE_H DATASTRUCTURE_H
   #define MAXAPPOINTMENTS 100


typedef enum { NotADay = 0, Mo, Tu, We, Th, Fr, Sa, Su } TDayOfTheWeek;

typedef struct
{
    int Day, Month, Year;
    TDayOfTheWeek weekday;
} TDate;

//typedef struct TDate Date;

typedef struct
{
   int Hour, Minute, Second;
} TTime;

typedef struct
{
   TDate Date;
   TTime Time;
   char *pDescription;
   char *pPlace;
   TTime *duration;
} TAppointment;

extern int countAppointments;
extern TAppointment Calendar[];

#endif
