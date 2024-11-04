#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[9] = "SSSSSSSS";
    char dig = 0;

    for (int i = 0; i < 8; ++i) {
        char dig = _getch();

        if (isdigit(dig)) {
            str[i] = dig;

        }

        else {
            if ((int)dig == 27) {
                exit(0);

            }

            else if ((int)dig == 8) {

                if (i == 0) {
                    i == 0;
                }

                else {
                    str[i] = 'S';
                    --i;
                }
            }

            else {
                if (i == 0) {
                    i == 0;
                }

                else {
                    --i;
                }
            }

        }
    }

    printf("%s", str);
    return 0;
}



/*#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>*\


/*int main()
{
    setlocale(LC_ALL, "RU"); //русский язык
    
    system("color 14");
    HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 79); //цвет триколор

    int i = 0;

    do {
         printf("\nВведите дату рождения дд.мм.гггг:");
        
        int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8 = 0;
        int arcan = 0;
        int vixod = 0;

        dig1 = _getch();
        

        if (dig1 > 47 && dig1 < 52) {

            printf("%c", (char)dig1);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig1 = _getch();
            } while (!(dig1 > 47 && dig1 < 52));

            printf("%c", (char)dig1);
        }

        dig2 = _getch();

        if ((dig1 == 48 && dig2 > 48 && dig2 < 58) || \
            (dig1 > 48 && dig1 < 51 && dig2 > 47 && dig2 < 58) || \
            (dig1 == 51 && dig2 > 47 && dig2 < 50)) {

            printf("%c. ", (char)dig2);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig2 = _getch();
            } while (!((dig1 == 48 && dig2 > 48 && dig2 < 58) || \
                (dig1 > 48 && dig1 < 51 && dig2 > 47 && dig2 < 58) || \
                (dig1 == 51 && dig2 > 47 && dig2 < 50)));

            printf("%c. ", (char)dig2);
        }

        dig3 = _getch();

        if (dig3 > 47 && dig3 < 50) {
            printf("%c", (char)dig3);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig3 = _getch();
            } while (!(dig3 > 47 && dig3 < 50));

            printf("%c", (char)dig3);
        }

        dig4 = _getch();

        if ((dig3 == 48 && dig4 > 48 && dig4 < 58) || \
            (dig3 == 49 && dig4 > 47 && dig4 < 51)) {
            printf("%c. ", (char)dig4);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig4 = _getch();
            } while (!((dig3 == 48 && dig4 > 48 && dig4 < 58) || \
                (dig3 == 49 && dig4 > 47 && dig4 < 51)));
            printf("%c. ", (char)dig4);
        }

        dig5 = _getch();

        if (dig5 > 48 && dig5 < 51) {
            printf("%c", (char)dig5);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig5 = _getch();
            } while (!(dig5 > 48 && dig5 < 51));

            printf("%c", (char)dig5);
        }

        dig6 = _getch();

        if ((dig5 == 49 && dig6 == 57) || \
            (dig5 == 50 && dig6 == 48)) {
            printf("%c", (char)dig6);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig6 = _getch();
            } while (!((dig5 == 49 && dig6 == 57) || \
                (dig5 == 50 && dig6 == 48)));

            printf("%c", (char)dig6);
        }

        dig7 = _getch();

        if ((dig5 == 49 && dig7 > 55 && dig7 < 58) || \
            (dig5 == 50 && dig7 > 47 && dig7 < 51)) {
            printf("%c", (char)dig7);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig7 = _getch();
            } while (!((dig5 == 49 && dig7 > 55 && dig7 < 58) || \
                (dig5 == 50 && dig7 > 47 && dig7 < 51)));

            printf("%c", (char)dig7);
        }

        dig8 = _getch();

        if (dig8 > 47 && dig8 < 58) {

            printf("%c", (char)dig8);
        }

        else if (dig1 == 27) {
            i += 10;
        }

        else {
            do {
                dig8 = _getch();
            } while (!(dig8 > 47 && dig8 < 58));

            printf("%c", (char)dig8);
        }

        switch (dig1) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig2) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig3) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig4) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig5) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig6) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig7) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        switch (dig8) {
        case 48: arcan += 0;
            break;
        case 49: arcan += 1;
            break;
        case 50: arcan += 2;
            break;
        case 51: arcan += 3;
            break;
        case 52: arcan += 4;
            break;
        case 53: arcan += 5;
            break;
        case 54: arcan += 6;
            break;
        case 55: arcan += 7;
            break;
        case 56: arcan += 8;
            break;
        case 57: arcan += 9;
            break;
        default: printf("невозможно такое");
            break;
        }

        if (arcan <= 22) {
            printf("\nВаш старший аркан равен: %d", arcan);
        }

        else if (arcan > 44) {
            arcan -= 44;
            printf("\nВаш старший аркан равен: %d", arcan);
        }

        else {
            arcan -= 22;
            printf("\nВаш старший аркан равен: %d", arcan);
        }
    }while (!(i >= 10));
     return 0;
}*/