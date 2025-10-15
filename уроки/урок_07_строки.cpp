/*
===========================================
УРОК 7: СТРОКИ
===========================================

ЦЕЛИ УРОКА:
- Изучить C-строки (char[])
- Понять std::string
- Научиться работать с основными операциями строк
- Освоить поиск и замену в строках
- Изучить функции для работы со строками

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

СТРОКИ В C++:

1. C-СТРОКИ (char[]):
   char str[100] = "Hello";
   char str[] = "Hello"; // автоматический размер

2. STD::STRING:
   #include <string>
   string str = "Hello";
   string str("Hello");

ОСНОВНЫЕ ОПЕРАЦИИ СО СТРОКАМИ:

C-СТРОКИ:
- strlen() - длина строки
- strcpy() - копирование
- strcat() - конкатенация
- strcmp() - сравнение

STD::STRING:
- length() или size() - длина
- = - присваивание
- + - конкатенация
- == - сравнение
- [] - доступ к символу

ФУНКЦИИ STD::STRING:
- find() - поиск подстроки
- substr() - извлечение подстроки
- replace() - замена
- insert() - вставка
- erase() - удаление

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
#include <cstring> // для C-строк
using namespace std;

int main() {
    // C-строки
    cout << "=== C-СТРОКИ ===" << endl;
    char cstr[50] = "Hello";
    char cstr2[] = "World";
    
    cout << "C-строка 1: " << cstr << endl;
    cout << "C-строка 2: " << cstr2 << endl;
    cout << "Длина cstr: " << strlen(cstr) << endl;
    
    // Конкатенация C-строк
    strcat(cstr, " ");
    strcat(cstr, cstr2);
    cout << "После конкатенации: " << cstr << endl;
    
    // std::string
    cout << "\n=== STD::STRING ===" << endl;
    string str1 = "Hello";
    string str2 = "World";
    
    cout << "string 1: " << str1 << endl;
    cout << "string 2: " << str2 << endl;
    cout << "Длина str1: " << str1.length() << endl;
    
    // Конкатенация std::string
    string result = str1 + " " + str2;
    cout << "После конкатенации: " << result << endl;
    
    // Сравнение строк
    cout << "\n=== СРАВНЕНИЕ СТРОК ===" << endl;
    if (str1 == str2) {
        cout << "Строки равны" << endl;
    } else {
        cout << "Строки не равны" << endl;
    }
    
    // Доступ к символам
    cout << "\n=== ДОСТУП К СИМВОЛАМ ===" << endl;
    cout << "Первый символ str1: " << str1[0] << endl;
    cout << "Последний символ str1: " << str1[str1.length() - 1] << endl;
    
    // Поиск в строке
    cout << "\n=== ПОИСК В СТРОКЕ ===" << endl;
    string text = "Hello World";
    size_t pos = text.find("World");
    if (pos != string::npos) {
        cout << "Подстрока 'World' найдена на позиции " << pos << endl;
    } else {
        cout << "Подстрока не найдена" << endl;
    }
    
    // Извлечение подстроки
    cout << "\n=== ИЗВЛЕЧЕНИЕ ПОДСТРОКИ ===" << endl;
    string substr = text.substr(6, 5); // начиная с позиции 6, длина 5
    cout << "Подстрока: " << substr << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Подсчет символов в строке
Создай программу для подсчета различных символов в строке:
*/

void exercise1() {
    string text;
    cout << "Введите строку: ";
    getline(cin, text);
    
    int letters = 0, digits = 0, spaces = 0, others = 0;
    
    for (char c : text) {
        if (isalpha(c)) {
            letters++;
        } else if (isdigit(c)) {
            digits++;
        } else if (isspace(c)) {
            spaces++;
        } else {
            others++;
        }
    }
    
    cout << "\n=== СТАТИСТИКА СИМВОЛОВ ===" << endl;
    cout << "Буквы: " << letters << endl;
    cout << "Цифры: " << digits << endl;
    cout << "Пробелы: " << spaces << endl;
    cout << "Другие символы: " << others << endl;
}

/*
Упражнение 2: Поиск слова в тексте
Создай программу для поиска слова в тексте:
*/

void exercise2() {
    string text, word;
    cout << "Введите текст: ";
    getline(cin, text);
    cout << "Введите слово для поиска: ";
    cin >> word;
    
    size_t pos = 0;
    int count = 0;
    
    while ((pos = text.find(word, pos)) != string::npos) {
        count++;
        cout << "Слово найдено на позиции " << pos << endl;
        pos += word.length();
    }
    
    cout << "\nВсего найдено: " << count << " раз" << endl;
}

/*
Упражнение 3: Проверка палиндрома
Создай программу для проверки, является ли строка палиндромом:
*/

void exercise3() {
    string text;
    cout << "Введите строку для проверки палиндрома: ";
    getline(cin, text);
    
    // Удаляем пробелы и приводим к нижнему регистру
    string cleaned = "";
    for (char c : text) {
        if (isalpha(c)) {
            cleaned += tolower(c);
        }
    }
    
    bool isPalindrome = true;
    int len = cleaned.length();
    
    for (int i = 0; i < len / 2; i++) {
        if (cleaned[i] != cleaned[len - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }
    
    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
    if (isPalindrome) {
        cout << "Строка является палиндромом!" << endl;
    } else {
        cout << "Строка не является палиндромом" << endl;
    }
}

/*
Упражнение 4: Замена символов
Создай программу для замены символов в строке:
*/

void exercise4() {
    string text;
    char oldChar, newChar;
    
    cout << "Введите строку: ";
    getline(cin, text);
    cout << "Введите символ для замены: ";
    cin >> oldChar;
    cout << "Введите новый символ: ";
    cin >> newChar;
    
    cout << "\nИсходная строка: " << text << endl;
    
    // Замена символов
    for (char &c : text) {
        if (c == oldChar) {
            c = newChar;
        }
    }
    
    cout << "Измененная строка: " << text << endl;
}

/*
Упражнение 5: Подсчет слов
Создай программу для подсчета слов в тексте:
*/

void exercise5() {
    string text;
    cout << "Введите текст: ";
    getline(cin, text);
    
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : text) {
        if (isalpha(c)) {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    
    cout << "\n=== РЕЗУЛЬТАТ ===" << endl;
    cout << "Количество слов: " << wordCount << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Шифрование текста
Создай программу для простого шифрования:
- Сдвиг символов на определенное количество позиций
- Ввод текста и ключа шифрования
- Вывод зашифрованного текста

Задание 2: Проверка корректности email
Создай программу для проверки корректности email адреса:
- Наличие символа @
- Наличие точки после @
- Проверка допустимых символов

Задание 3: Удаление лишних пробелов
Создай программу для очистки текста:
- Удаление лишних пробелов
- Удаление пробелов в начале и конце
- Замена множественных пробелов одним

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. В чем разница между C-строками и std::string?
2. Как найти длину строки?
3. Как скопировать строку?
4. Как объединить две строки?
5. Как найти подстроку в строке?
6. Как извлечь часть строки?
7. Как заменить символы в строке?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Указатели и ссылки
- Работа с памятью
- Указатели на массивы
- Динамическое выделение памяти

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 7: СТРОКИ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ПОДСЧЕТ СИМВОЛОВ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ПОИСК СЛОВА ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ПРОВЕРКА ПАЛИНДРОМА ===" << endl;
    exercise3();
    
    cout << "\n=== УПРАЖНЕНИЕ 4: ЗАМЕНА СИМВОЛОВ ===" << endl;
    exercise4();
    
    cout << "\n=== УПРАЖНЕНИЕ 5: ПОДСЧЕТ СЛОВ ===" << endl;
    exercise5();
    
    return 0;
}





