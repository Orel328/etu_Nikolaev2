#define _CRT_SECURE_NO_WARNINGS
#include </Users/user/source/repos/project5/catch2/catch_amalgamated.hpp>
#include "menya.h"
#include "arcana.h"
#include "stdlib.h"

TEST_CASE("Проверка допустимых значений, поведения при некорректных значениях,граничных значений диапазона") {
    SECTION("Корректные даты") {
        REQUIRE(isValidDate(1, 1, 2023) == true);
        REQUIRE(isValidDate(29, 2, 2024) == true); // Високосный
        REQUIRE(isValidDate(28, 2, 2023) == true);
        REQUIRE(isValidDate(31, 12, 2023) == true);
    }

    SECTION("Некорректные месяцы") {
        REQUIRE(isValidDate(1, 13, 2023) == false);
        REQUIRE(isValidDate(1, 0, 2023) == false);
    }

    SECTION("Некорректные дни") {
        REQUIRE(isValidDate(31, 4, 2023) == false);
        REQUIRE(isValidDate(30, 2, 2023) == false);
        REQUIRE(isValidDate(29, 2, 2023) == false); // не високосный
        REQUIRE(isValidDate(32, 1, 2023) == false);
    }

    SECTION("Високосные года") {
        REQUIRE(isValidDate(29, 2, 2020) == true);
        REQUIRE(isValidDate(29, 2, 2021) == false);
        REQUIRE(isValidDate(29, 2, 2024) == true);
    }

    SECTION("Граничные значения") {
        REQUIRE(isValidDate(1, 1, 2023) == true);
        REQUIRE(isValidDate(31, 12, 2023) == true);
        REQUIRE(isValidDate(1, 3, 2023) == true);
        REQUIRE(isValidDate(28, 2, 2023) == true);
        REQUIRE(isValidDate(1, 1, 1) == true);
    }


}

TEST_CASE("Проверка правильности расчетов") {
    SECTION("Корректные вычисления") {
        REQUIRE(arcan(1, 1, 2000) == 3); // 1 + 1 + 2 = 4, 4-22=-18, -18 + 22 = 4
        REQUIRE(arcan(31, 12, 1999) == 10); // 3+1+1+2+1+9+9+9=35. 35 - 22 = 13
        REQUIRE(arcan(1, 1, 1) == 3);
    }
}


TEST_CASE("Проверка записи в файл") {
    SECTION("Данные записываются и считываются корректно") {
        int day = 26, month = 10, year = 2023;
        saveToLog(day, month, year);

        char* lastLine = getLastLogFromFile();
        char expected[256];
        sprintf(expected, "%d.%d.%d\n", day, month, year);

        REQUIRE(strcmp(lastLine, expected) == 0);
        free(lastLine); //освобождаем память
    }
}