#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include "menya.h"
#include "arcana.h"
#include "utilita.h"
#include "core.h"

int core() {

    setlocale(LC_ALL, "RU"); //������������� ������� ���� ��� ������ ������
    while (1) { // ����������� ����
        system("cls"); // ������� �������
        SetColor(7, 4);
        Menu(); // ������� ����
        int choice = _getch(); // ��������� ������� �������
        switch (choice) { // � ����������� �� ������� ������� ��������� ��������������� ��������
        case 72: // ������� �����
            if (pos > 0) {
                pos--;
            }
            break;
        case 80: // ������� ����
            if (pos < 3) {
                pos++;
            }
            break;
        case 13: // Enter
            handleAction(pos); // �������� ������� ��������� ���������� ������ ����
            break;
        default:
            break;
        }
    }
    return 0;
}