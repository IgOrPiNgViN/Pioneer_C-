/*
===========================================
УРОК 9: СТРУКТУРЫ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию структур
- Изучить объявление и использование структур
- Научиться работать с массивами структур
- Освоить указатели на структуры
- Понять вложенные структуры

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

СТРУКТУРЫ В C++:

1. ОБЪЯВЛЕНИЕ СТРУКТУРЫ:
   struct ИмяСтруктуры {
       тип поле1;
       тип поле2;
       // ...
   };

2. СОЗДАНИЕ ПЕРЕМЕННОЙ СТРУКТУРЫ:
   ИмяСтруктуры переменная;
   ИмяСтруктуры переменная = {значение1, значение2};

3. ДОСТУП К ПОЛЯМ:
   переменная.поле
   указатель->поле

4. ИНИЦИАЛИЗАЦИЯ:
   struct Point p = {10, 20};
   struct Point p = {.x = 10, .y = 20}; // C++20

ОСОБЕННОСТИ СТРУКТУР:
- Группировка связанных данных
- Каждое поле имеет свой тип
- Поля доступны по имени
- Можно создавать массивы структур
- Можно использовать указатели на структуры

ВЛОЖЕННЫЕ СТРУКТУРЫ:
- Структуры могут содержать другие структуры
- Доступ к полям через точку
- Инициализация вложенных структур

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

// Объявление структуры
struct Point {
    int x;
    int y;
};

struct Student {
    string name;
    int age;
    double grade;
    bool isScholarship;
};

struct Rectangle {
    Point topLeft;
    Point bottomRight;
};

int main() {
    // Создание и инициализация структуры
    cout << "=== ОСНОВЫ СТРУКТУР ===" << endl;
    Point p1 = {10, 20};
    Point p2 = {.x = 30, .y = 40};
    
    cout << "Точка p1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "Точка p2: (" << p2.x << ", " << p2.y << ")" << endl;
    
    // Изменение полей
    p1.x = 100;
    p1.y = 200;
    cout << "После изменения p1: (" << p1.x << ", " << p1.y << ")" << endl;
    
    // Структура Student
    cout << "\n=== СТРУКТУРА STUDENT ===" << endl;
    Student student1 = {"Иван", 18, 4.5, true};
    
    cout << "Имя: " << student1.name << endl;
    cout << "Возраст: " << student1.age << endl;
    cout << "Оценка: " << student1.grade << endl;
    cout << "Стипендия: " << (student1.isScholarship ? "Да" : "Нет") << endl;
    
    // Вложенные структуры
    cout << "\n=== ВЛОЖЕННЫЕ СТРУКТУРЫ ===" << endl;
    Rectangle rect = {{0, 0}, {10, 10}};
    
    cout << "Прямоугольник:" << endl;
    cout << "Верхний левый угол: (" << rect.topLeft.x << ", " << rect.topLeft.y << ")" << endl;
    cout << "Нижний правый угол: (" << rect.bottomRight.x << ", " << rect.bottomRight.y << ")" << endl;
    
    // Указатели на структуры
    cout << "\n=== УКАЗАТЕЛИ НА СТРУКТУРЫ ===" << endl;
    Point *ptr = &p1;
    cout << "Через указатель: (" << ptr->x << ", " << ptr->y << ")" << endl;
    cout << "Альтернативный синтаксис: (" << (*ptr).x << ", " << (*ptr).y << ")" << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Структура для работы с датой
Создай структуру для работы с датой:
*/

struct Date {
    int day;
    int month;
    int year;
};

void printDate(const Date &date) {
    cout << date.day << "." << date.month << "." << date.year << endl;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

void exercise1() {
    Date today = {15, 12, 2024};
    
    cout << "Сегодняшняя дата: ";
    printDate(today);
    
    cout << "Дней в месяце: " << daysInMonth(today.month, today.year) << endl;
    cout << "Високосный год: " << (isLeapYear(today.year) ? "Да" : "Нет") << endl;
}

/*
Упражнение 2: Массив структур студентов
Создай программу для работы с массивом студентов:
*/

void exercise2() {
    Student students[3] = {
        {"Анна", 17, 4.8, true},
        {"Петр", 18, 3.2, false},
        {"Мария", 17, 4.5, true}
    };
    
    cout << "=== СПИСОК СТУДЕНТОВ ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Студент " << (i + 1) << ":" << endl;
        cout << "  Имя: " << students[i].name << endl;
        cout << "  Возраст: " << students[i].age << endl;
        cout << "  Оценка: " << students[i].grade << endl;
        cout << "  Стипендия: " << (students[i].isScholarship ? "Да" : "Нет") << endl;
        cout << endl;
    }
    
    // Поиск студента с лучшей оценкой
    int bestStudent = 0;
    for (int i = 1; i < 3; i++) {
        if (students[i].grade > students[bestStudent].grade) {
            bestStudent = i;
        }
    }
    
    cout << "Лучший студент: " << students[bestStudent].name 
         << " с оценкой " << students[bestStudent].grade << endl;
}

/*
Упражнение 3: Структура для работы с комплексными числами
Создай структуру для работы с комплексными числами:
*/

struct Complex {
    double real;
    double imag;
};

Complex addComplex(const Complex &a, const Complex &b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex multiplyComplex(const Complex &a, const Complex &b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

void printComplex(const Complex &c) {
    cout << c.real;
    if (c.imag >= 0) {
        cout << " + " << c.imag << "i";
    } else {
        cout << " - " << (-c.imag) << "i";
    }
}

void exercise3() {
    Complex c1 = {3, 4};
    Complex c2 = {1, 2};
    
    cout << "Комплексное число 1: ";
    printComplex(c1);
    cout << endl;
    
    cout << "Комплексное число 2: ";
    printComplex(c2);
    cout << endl;
    
    Complex sum = addComplex(c1, c2);
    cout << "Сумма: ";
    printComplex(sum);
    cout << endl;
    
    Complex product = multiplyComplex(c1, c2);
    cout << "Произведение: ";
    printComplex(product);
    cout << endl;
}

/*
Упражнение 4: Структура для работы с книгами
Создай структуру для работы с книгами:
*/

struct Book {
    string title;
    string author;
    int year;
    int pages;
    double price;
};

void exercise4() {
    Book books[3] = {
        {"Война и мир", "Лев Толстой", 1869, 1274, 1500.0},
        {"Евгений Онегин", "Александр Пушкин", 1833, 352, 800.0},
        {"Мастер и Маргарита", "Михаил Булгаков", 1967, 448, 1200.0}
    };
    
    cout << "=== КАТАЛОГ КНИГ ===" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Книга " << (i + 1) << ":" << endl;
        cout << "  Название: " << books[i].title << endl;
        cout << "  Автор: " << books[i].author << endl;
        cout << "  Год: " << books[i].year << endl;
        cout << "  Страниц: " << books[i].pages << endl;
        cout << "  Цена: " << books[i].price << " руб." << endl;
        cout << endl;
    }
    
    // Поиск самой дорогой книги
    int expensiveBook = 0;
    for (int i = 1; i < 3; i++) {
        if (books[i].price > books[expensiveBook].price) {
            expensiveBook = i;
        }
    }
    
    cout << "Самая дорогая книга: " << books[expensiveBook].title 
         << " за " << books[expensiveBook].price << " руб." << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Структура для работы с банковским счетом
Создай структуру для банковского счета:
- Номер счета
- Имя владельца
- Баланс
- Процентная ставка
- Функции для пополнения и снятия денег

Задание 2: Структура для работы с геометрическими фигурами
Создай структуры для различных фигур:
- Точка
- Круг (центр + радиус)
- Прямоугольник (две точки)
- Функции для вычисления площади и периметра

Задание 3: Структура для работы с автомобилями
Создай структуру для автомобиля:
- Марка и модель
- Год выпуска
- Пробег
- Цена
- Функции для поиска автомобилей по критериям

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое структура?
2. Как объявить структуру?
3. Как создать переменную структуры?
4. Как получить доступ к полям структуры?
5. Можно ли создавать массивы структур?
6. Как работать с указателями на структуры?
7. Что такое вложенные структуры?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Функции
- Объявление и определение функций
- Параметры и возвращаемые значения
- Перегрузка функций
- Рекурсивные функции

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 9: СТРУКТУРЫ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: РАБОТА С ДАТОЙ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: МАССИВ СТУДЕНТОВ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: КОМПЛЕКСНЫЕ ЧИСЛА ===" << endl;
    exercise3();
    
    cout << "\n=== УПРАЖНЕНИЕ 4: КАТАЛОГ КНИГ ===" << endl;
    exercise4();
    
    return 0;
}





