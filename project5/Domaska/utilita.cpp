#include <windows.h>
#include "utilita.h"

void SetColor(int textColor, int backgroundColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // �������� ���������� �������
    SetConsoleTextAttribute(hConsole, (WORD)((backgroundColor << 4) | textColor)); // ������������� �������� �����
}