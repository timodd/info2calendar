/*
calendar
*/

#ifndef CALENDAR_H
   #define CALENDAR_H CALENDAR_H

void createAppointment();
void editAppointment();
void deleteAppointment();
void searchAppointment();
void sortCalendar();
void listCalendar();
void printAppointment(TAppointment *);
void freeCalendar();
void freeAppointment(TAppointment *);
int cmpDat(TAppointment *, TAppointment *);
int cmpDur(TAppointment *, TAppointment *);
int cmpDes(TAppointment *, TAppointment *);
int cmpLoc(TAppointment *, TAppointment *);
void swp(TAppointment *, TAppointment *);
#endif
