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
    //Проверка високосности года
    if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            if (day < 1 || day > 29) return false;
        }
        else {
            if (day < 1 || day > 28) return false;
        }
    }
    // Проверка для месяцев с 31 днем
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day < 1 || day > 31) return false;
    }
    // Проверка для месяцев с 30 днями
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day < 1 || day > 30) return false;
    }
    return true;
}


void Menu() {
    char menu[4][50] = { "1. Ввести дату рождения", "2. Вывести Аркан", "3. Вывести логи", "4. Выход" };
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
    system("cls"); // Очищаем консоль
    char input[20];
    time_t start, end;
    double duration; // Переменная для хранения времени выполнения функции
    system("color 14"); // Устанавливаем цвет консоли
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 79);

    switch (choice) {
    case 0: { // Ввод даты рождения
        printf("Введите дату рождения (пример: день.месяц.год): ");
        scanf("%s", input);

        if (sscanf(input, "%d.%d.%d", &day, &month, &year) != 3) {
            printf("Некорректный формат даты.\n");
            _getch();
            break;
        }

        if (!isValidDate(day, month, year)) { // Используем нашу функцию
            printf("Некорректный ввод даты\n");
            _getch();
            break;
        }

        saveToLog(day, month, year);

        /*FILE* logFile = fopen("log.txt", "a"); // Открываем файл log.txt для добавления в него информации
        if (!logFile) { // Если файл не открылся
            printf("Не удалось открыть файл log.txt\n"); // Выводим сообщение об ошибке
            _getch(); // Ожидаем нажатия клавиши
            break; // Прерываем обработку
        }
        fprintf(logFile, "%d.%d.%d\n", day, month, year); // Записываем введенную дату в файл
        fclose(logFile); // Закрываем файл

        realdate = true; // Устанавливаем флаг, что дата была введена
        _getch(); // Ожидаем нажатия клавиши
        break; // Прерываем обработку
        */
    }
    case 1: {
        if (realdate) { // Если дата была введена  
            start = clock(); // Замеряем время начала выполнения
            int arcana = arcan(day, month, year); // Вычисляем номер аркана
            printf("Ваш Аркан: %d\n", arcana); // Выводим номер
            printArcanaDescription(arcana); // Выводим описание
            end = clock(); // Замеряем время окончания
            duration = ((double)(end - start)) / CLOCKS_PER_SEC; // Вычисляем время выполнения
            printf("Время выполнения: %f секунд\n", duration); // Выводим время
            _getch(); // Ожидаем нажатия клавиши
        }
        else { // Если дата не была введена
            printf("Сначала введите дату рождения!\n");
            _getch();
        }
        break;
    }
    case 2: { // Вывод лога
        
        FILE* logFileRead = fopen("log.txt", "r");
        if (logFileRead) {
            char line[256];
            while (fgets(line, sizeof(line), logFileRead)) {
                printf("%s", line);
            }
            fclose(logFileRead);
        }

        /*FILE* logFile = fopen("log.txt", "r"); // Открываем файл log.txt для чтения
        if (!logFile) { // Если файл не открылся
            printf("Не удалось открыть файл log.txt\n");
            _getch();
            break; \
        }

        char line[256]; // Массив для хранения строки из файла
        while (fgets(line, sizeof(line), logFile)) { // Читаем файл построчно
            printf("%s", line); // Выводим строку
        }

        fclose(logFile);
        _getch();
        break; */
    }
    case 3: {
        exit(0); // Завершаем программу
    }
    default: {
        printf("Некорректный ввод.\n"); // Выводим сообщение об ошибке
        _getch();
        break;
    }
    }
}