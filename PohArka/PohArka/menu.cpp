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
            printf("Некорректный формат даты.\n"); // Выводим сообщение об ошибке
            _getch();
            break; // Прерываем обработку
        }
        if (month < 1 || month > 12) { // Проверяем, корректен ли введенный месяц
            printf("Некорректный ввод. Месяц не должен быть больше 12.\n");
            _getch();
            break;
        }
        if (day < 1 || day > 31) { // Проверяем, корректен ли введенный день
            printf("Некорректный ввод. Дней не должно быть больше 31.\n");
            _getch(); // Ожидаем нажатия клавиши
            break;
        }

        FILE* logFile = fopen("log.txt", "a"); // Открываем файл log.txt для добавления в него информации
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
        FILE* logFile = fopen("log.txt", "r"); // Открываем файл log.txt для чтения
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
        break;
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