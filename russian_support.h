/*
===========================================
ПОДДЕРЖКА РУССКОГО ЯЗЫКА ДЛЯ C++
===========================================

Этот заголовочный файл настраивает консоль Windows
для корректного отображения русских символов.

ИСПОЛЬЗОВАНИЕ:
Просто добавьте в начало вашей программы:
    #include "russian_support.h"

И затем в начале функции main() вызовите:
    setupRussian();
*/

#ifndef RUSSIAN_SUPPORT_H
#define RUSSIAN_SUPPORT_H

#ifdef _WIN32
    #include <windows.h>      // для функций Windows API
#endif
#include <iostream>
#include <locale>             // для setlocale

// Функция для настройки русского языка в Windows
// ВАЖНО: Вызовите эту функцию в самом начале main()
void setupRussian() {
#ifdef _WIN32
    // Устанавливаем кодировку консоли в UTF-8 (65001)
    SetConsoleOutputCP(65001);  // UTF-8 для вывода
    SetConsoleCP(65001);        // UTF-8 для ввода
    
    // Устанавливаем локаль для русской локализации
    setlocale(LC_ALL, "Russian");
#else
    // Для Linux и других систем
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
}

#endif // RUSSIAN_SUPPORT_H

