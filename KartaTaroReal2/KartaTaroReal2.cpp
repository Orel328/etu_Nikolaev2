#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>



int main() {
    setlocale(LC_ALL, "RU");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    printf("This text is blue");
    SetConsoleTextAttribute(hConsole, 7);

    char birthDate[11];
    int sum = 0;

    printf("Введите дату рождения в формате дд.мм.гггг: ");

    for (int i = 0; i < 10; i++) {
        char c = _getch();

        if (c == '\r') {
            birthDate[i] = '\0';
            break;
        }

        if (i == 2 || i == 5) {
            printf(".");
            if (c == '0') {
                printf("0");
                birthDate[i] = '0';
                birthDate[i + 1] = c;
                i++;
                continue;
            }
        }
        else if (i == 3 || i == 6) {
            if (c == '0') {
                printf(".");
                printf("0");
                birthDate[i] = c;
                i++;
            }
        }

        birthDate[i] = c;
        printf("%c", c);
    }

    int day = (birthDate[0]) * 10 + (birthDate[1] - '0');
    int month = (birthDate[3] - '0') * 10 + (birthDate[4] - '0');
    int year = (birthDate[6] - '0') * 1000 + (birthDate[7] - '0') * 100 + (birthDate[8] - '0') * 10 + (birthDate[9] - '0');

    sum = day + month + year;

    if (sum > 44) {
        sum -= 44;
    }
    else if (sum > 22) {
        sum -= 22;
    }

    printf("\nСумма цифр даты рождения: %d\n", sum);

    return 0;
}


