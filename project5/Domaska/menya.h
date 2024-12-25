#ifndef MENYA_H
#define MENYA_H

extern int pos;

bool isValidDate(int day, int month, int year);
void Menu();
void saveToLog(int day, int month, int year);
char* getLastLogFromFile();
void handleAction(int choice);

#endif // MENYA_H
