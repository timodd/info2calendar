#ifndef DATABASE_H
   #define DATABASE_H DATABASE_H

int saveCalendar(int);
void saveAppointment(FILE *, int);
void loadCalendar();
int loadAppointment();

#endif
