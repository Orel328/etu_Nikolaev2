#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "arcan.h"
#include "main.h"

int day, month, year; // ���������� ��� �������� ���� ��������
bool realDate = false;

int arcan(int day, int month, int year) {
    int sum = 0; // ����� ���� ���� ��������
    sum += (day / 10) + (day % 10); // ��������� ����� ���
    sum += (month / 10) + (month % 10); // ��������� ����� ������
    sum += (year / 1000) + ((year / 100) % 10) + ((year / 10) % 10) + (year % 10); // ��������� ����� ����

    while (sum > 22) { // ���� ����� ������ 22, �������� 22
        sum -= 22;
    }

    return sum; // ���������� ����� ������
}

void printArcanaDescription(int arcana) {
    FILE* infoFile = fopen("info.txt", "r");
    setlocale(LC_ALL, "RU");
    if (infoFile == NULL) { // ���� ���� �� ��������
        fprintf(stderr, "�� ������� ������� ���� info.txt\n");
        return;
    }

    char line[256]; // ������ ��� �������� ������ �� �����
    int currentLine = 1; // ������� ����� ������
    while (fgets(line, sizeof(line), infoFile)) { // ������ ���� ���������
        if (currentLine == arcana) {
            setlocale(LC_ALL, "RU");
            printf("�������� ������: %s\n", line); // ������� �������� ������
            break;
        }
        currentLine++; // ����������� ������� �����
    }

    fclose(infoFile); // ��������� ����
}