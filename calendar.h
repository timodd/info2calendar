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
//void printAppointment(TAppointment *); /**TODO**/
void freeCalendar();
//void freeAppointment(TAppointment *);
int compare(int *, int *);
int compare_down(int *, int *);
void swp(int *, int *);
#endif
