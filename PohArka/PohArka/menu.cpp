#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"
#include "arcan.h"
#include "utilits.h"
#include "main.h"
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
            printf("������������ ������ ����.\n"); // ������� ��������� �� ������
            _getch();
            break; // ��������� ���������
        }
        if (month < 1 || month > 12) { // ���������, ��������� �� ��������� �����
            printf("������������ ����. ����� �� ������ ���� ������ 12.\n");
            _getch();
            break;
        }
        if (day < 1 || day > 31) { // ���������, ��������� �� ��������� ����
            printf("������������ ����. ���� �� ������ ���� ������ 31.\n");
            _getch(); // ������� ������� �������
            break;
        }

        FILE* logFile = fopen("log.txt", "a"); // ��������� ���� log.txt ��� ���������� � ���� ����������
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
        FILE* logFile = fopen("log.txt", "r"); // ��������� ���� log.txt ��� ������
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
        break;
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