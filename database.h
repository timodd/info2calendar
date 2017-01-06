#ifndef DATABASE_H
   #define DATABASE_H DATABASE_H

void saveAppointment (FILE *, int);
int loadAppointment (FILE *, char[]);
int saveCalendar (int);
void loadCalendar();

#endif
