#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include "menya.h"
#include "arcana.h"
#include "utilita.h"
#include "core.h"
#include <stdio.h> 
#include <locale.h> 
#include <ctype.h>
#include <time.h>
#include <string.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <windows.h>

int pos = 0;
bool realdate = false;

bool isValidDate(int day, int month, int year) {
    if (month < 1 || month > 12) return false;
    //�������� ������������ ����
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (day < 1 || day > 29) return false;
        }
        else {
            if (day < 1 || day > 28) return false;
        }
    }
    // �������� ��� ������� � 31 ����
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31) return false;
    }
    // �������� ��� ������� � 30 �����
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) return false;
    }
    return true;
}


void Menu() {
    char menu[4][50] = { "1. ������ ���� ��������", "2. ������� �����", "3. ������� ����", "4. �����" };
    char marker[5] = "<-";
    for (int i = 0; i < 4; ++i) {
        printf("%s", menu[i]);
        if (i == pos) {
            printf(" %s", marker);
        }
        printf("\n");
    }
}

void saveToLog(int day, int month, int year) {
    FILE* logFile = fopen("log.txt", "a");
    if (!logFile) {
        return;
    }
    fprintf(logFile, "%d.%d.%d\n", day, month, year);
    fclose(logFile);
}

char* getLastLogFromFile() {
    FILE* logFile = fopen("log.txt", "r");
    if (!logFile) {
        return nullptr;
    }

    char* lastLine = new char[256];
     char line[256];
    while (fgets(line, sizeof(line), logFile)) {
        strcpy(lastLine, line);
    }
    fclose(logFile);
    return lastLine;
}

void handleAction(int choice) {
    system("cls"); // ������� �������
    char input[20];
    time_t start, end;
    double duration; // ���������� ��� �������� ������� ���������� �������
    system("color 14"); // ������������� ���� �������
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 79);

    switch (choice) {
    case 0: { // ���� ���� ��������
        printf("������� ���� �������� (������: ����.�����.���): ");
        scanf("%s", input);

        if (sscanf(input, "%d.%d.%d", &day, &month, &year) != 3) {
            printf("������������ ������ ����.\n");
            _getch();
            break;
        }

        if (!isValidDate(day, month, year)) { // ���������� ���� �������
            printf("������������ ���� ����\n");
            _getch();
            break;
        }

        saveToLog(day, month, year);

        /*FILE* logFile = fopen("log.txt", "a"); // ��������� ���� log.txt ��� ���������� � ���� ����������
        if (!logFile) { // ���� ���� �� ��������
            printf("�� ������� ������� ���� log.txt\n"); // ������� ��������� �� ������
            _getch(); // ������� ������� �������
            break; // ��������� ���������
        }
        fprintf(logFile, "%d.%d.%d\n", day, month, year); // ���������� ��������� ���� � ����
        fclose(logFile); // ��������� ����

        realdate = true; // ������������� ����, ��� ���� ���� �������
        _getch(); // ������� ������� �������
        break; // ��������� ���������
        */
    }
    case 1: {
        if (realdate) { // ���� ���� ���� �������  
            start = clock(); // �������� ����� ������ ����������
            int arcana = arcan(day, month, year); // ��������� ����� ������
            printf("��� �����: %d\n", arcana); // ������� �����
            printArcanaDescription(arcana); // ������� ��������
            end = clock(); // �������� ����� ���������
            duration = ((double)(end - start)) / CLOCKS_PER_SEC; // ��������� ����� ����������
            printf("����� ����������: %f ������\n", duration); // ������� �����
            _getch(); // ������� ������� �������
        }
        else { // ���� ���� �� ���� �������
            printf("������� ������� ���� ��������!\n");
            _getch();
        }
        break;
    }
    case 2: { // ����� ����
        
        FILE* logFileRead = fopen("log.txt", "r");
        if (logFileRead) {
            char line[256];
            while (fgets(line, sizeof(line), logFileRead)) {
                printf("%s", line);
            }
            fclose(logFileRead);
        }

        /*FILE* logFile = fopen("log.txt", "r"); // ��������� ���� log.txt ��� ������
        if (!logFile) { // ���� ���� �� ��������
            printf("�� ������� ������� ���� log.txt\n");
            _getch();
            break; \
        }

        char line[256]; // ������ ��� �������� ������ �� �����
        while (fgets(line, sizeof(line), logFile)) { // ������ ���� ���������
            printf("%s", line); // ������� ������
        }

        fclose(logFile);
        _getch();
        break; */
    }
    case 3: {
        exit(0); // ��������� ���������
    }
    default: {
        printf("������������ ����.\n"); // ������� ��������� �� ������
        _getch();
        break;
    }
    }
}