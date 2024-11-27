#include <windows.h>
#include "utilits.h"

void SetColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получаем дескриптор консоли
    SetConsoleTextAttribute(hConsole, (WORD)((backgroundColor << 4) | textColor)); // Устанавливаем атрибуты цвета
}