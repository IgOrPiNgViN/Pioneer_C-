/*
===========================================
УРОК 13: КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ
===========================================

ЦЕЛИ УРОКА:
- Понять назначение конструкторов и деструкторов
- Изучить различные типы конструкторов
- Освоить перегрузку конструкторов
- Научиться использовать списки инициализации
- Понять копирующий конструктор

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ:

КОНСТРУКТОР - специальная функция, которая вызывается при создании объекта
ДЕСТРУКТОР - специальная функция, которая вызывается при уничтожении объекта

ТИПЫ КОНСТРУКТОРОВ:

1. КОНСТРУКТОР ПО УМОЛЧАНИЮ:
   ClassName() { }

2. ПАРАМЕТРИЗОВАННЫЙ КОНСТРУКТОР:
   ClassName(параметры) { }

3. КОПИРУЮЩИЙ КОНСТРУКТОР:
   ClassName(const ClassName& other) { }

4. КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ (C++11):
   ClassName(ClassName&& other) { }

ОСОБЕННОСТИ:
- Имя конструктора совпадает с именем класса
- Конструктор не имеет возвращаемого значения
- Деструктор имеет имя ~ClassName
- Деструктор не имеет параметров
- Деструктор не имеет возвращаемого значения

СПИСОК ИНИЦИАЛИЗАЦИИ:
ClassName(параметры) : поле1(значение1), поле2(значение2) { }

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    double grade;
    
public:
    // Конструктор по умолчанию
    Student() {
        name = "Неизвестно";
        age = 0;
        grade = 0.0;
        cout << "Вызван конструктор по умолчанию" << endl;
    }
    
    // Параметризованный конструктор
    Student(string n, int a, double g) {
        name = n;
        age = a;
        grade = g;
        cout << "Вызван параметризованный конструктор для " << name << endl;
    }
    
    // Конструктор с списком инициализации
    Student(string n) : name(n), age(18), grade(0.0) {
        cout << "Вызван конструктор с списком инициализации для " << name << endl;
    }
    
    // Копирующий конструктор
    Student(const Student& other) {
        name = other.name + " (копия)";
        age = other.age;
        grade = other.grade;
        cout << "Вызван копирующий конструктор для " << name << endl;
    }
    
    // Деструктор
    ~Student() {
        cout << "Вызван деструктор для " << name << endl;
    }
    
    // Методы
    void displayInfo() {
        cout << "Имя: " << name << ", Возраст: " << age << ", Оценка: " << grade << endl;
    }
    
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(double g) { grade = g; }
};

class BankAccount {
private:
    string accountNumber;
    double* balance; // указатель для демонстрации динамической памяти
    
public:
    // Конструктор
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = new double(initialBalance);
        cout << "Создан счет " << accountNumber << " с балансом " << *balance << endl;
    }
    
    // Копирующий конструктор (глубокое копирование)
    BankAccount(const BankAccount& other) {
        accountNumber = other.accountNumber + " (копия)";
        balance = new double(*other.balance);
        cout << "Скопирован счет " << accountNumber << endl;
    }
    
    // Деструктор
    ~BankAccount() {
        cout << "Закрывается счет " << accountNumber << endl;
        delete balance;
    }
    
    // Методы
    void deposit(double amount) {
        *balance += amount;
        cout << "Внесено: " << amount << ", баланс: " << *balance << endl;
    }
    
    void displayInfo() {
        cout << "Счет: " << accountNumber << ", Баланс: " << *balance << endl;
    }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ КОНСТРУКТОРОВ И ДЕСТРУКТОРОВ ===" << endl;
    
    // Создание объектов разными способами
    cout << "\n1. Создание объекта с конструктором по умолчанию:" << endl;
    Student student1;
    student1.displayInfo();
    
    cout << "\n2. Создание объекта с параметризованным конструктором:" << endl;
    Student student2("Анна", 20, 4.5);
    student2.displayInfo();
    
    cout << "\n3. Создание объекта с конструктором с списком инициализации:" << endl;
    Student student3("Петр");
    student3.displayInfo();
    
    cout << "\n4. Создание объекта с копирующим конструктором:" << endl;
    Student student4 = student2;
    student4.displayInfo();
    
    cout << "\n5. Работа с динамической памятью:" << endl;
    BankAccount account1("123456", 1000.0);
    account1.deposit(500.0);
    
    BankAccount account2 = account1;
    account2.deposit(200.0);
    
    cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИИ ===" << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Класс для работы с прямоугольником
Создай класс Rectangle с различными конструкторами:
*/

class Rectangle {
private:
    double width;
    double height;
    
public:
    // Конструктор по умолчанию
    Rectangle() : width(1.0), height(1.0) {
        cout << "Создан прямоугольник по умолчанию" << endl;
    }
    
    // Конструктор с параметрами
    Rectangle(double w, double h) : width(w), height(h) {
        cout << "Создан прямоугольник " << width << "x" << height << endl;
    }
    
    // Конструктор для квадрата
    Rectangle(double side) : width(side), height(side) {
        cout << "Создан квадрат со стороной " << side << endl;
    }
    
    // Копирующий конструктор
    Rectangle(const Rectangle& other) : width(other.width), height(other.height) {
        cout << "Скопирован прямоугольник" << endl;
    }
    
    // Деструктор
    ~Rectangle() {
        cout << "Уничтожен прямоугольник" << endl;
    }
    
    // Методы
    double getArea() {
        return width * height;
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
    
    void displayInfo() {
        cout << "Прямоугольник: " << width << " x " << height << endl;
        cout << "Площадь: " << getArea() << ", Периметр: " << getPerimeter() << endl;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: РАЗЛИЧНЫЕ КОНСТРУКТОРЫ ===" << endl;
    
    Rectangle rect1;
    rect1.displayInfo();
    
    Rectangle rect2(5.0, 3.0);
    rect2.displayInfo();
    
    Rectangle rect3(4.0);
    rect3.displayInfo();
    
    Rectangle rect4 = rect2;
    rect4.displayInfo();
}

/*
Упражнение 2: Класс для работы с динамическими массивами
Создай класс DynamicArray с конструкторами и деструктором:
*/

class DynamicArray {
private:
    int* data;
    int size;
    
public:
    // Конструктор по умолчанию
    DynamicArray() : data(nullptr), size(0) {
        cout << "Создан пустой массив" << endl;
    }
    
    // Конструктор с размером
    DynamicArray(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
        cout << "Создан массив размером " << size << endl;
    }
    
    // Конструктор с массивом
    DynamicArray(int arr[], int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
        cout << "Создан массив из существующего массива" << endl;
    }
    
    // Копирующий конструктор
    DynamicArray(const DynamicArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Скопирован массив" << endl;
    }
    
    // Деструктор
    ~DynamicArray() {
        delete[] data;
        cout << "Уничтожен массив" << endl;
    }
    
    // Методы
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }
    
    int getValue(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return 0;
    }
    
    void displayArray() {
        cout << "Массив: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ДИНАМИЧЕСКИЕ МАССИВЫ ===" << endl;
    
    DynamicArray arr1;
    
    DynamicArray arr2(5);
    arr2.setValue(0, 10);
    arr2.setValue(1, 20);
    arr2.setValue(2, 30);
    arr2.displayArray();
    
    int temp[] = {1, 2, 3, 4, 5};
    DynamicArray arr3(temp, 5);
    arr3.displayArray();
    
    DynamicArray arr4 = arr2;
    arr4.displayArray();
}

/*
Упражнение 3: Класс для работы с книгами
Создай класс Book с различными конструкторами:
*/

class Book {
private:
    string* title;
    string* author;
    int* year;
    
public:
    // Конструктор по умолчанию
    Book() {
        title = new string("Неизвестно");
        author = new string("Неизвестно");
        year = new int(0);
        cout << "Создана книга по умолчанию" << endl;
    }
    
    // Конструктор с параметрами
    Book(string t, string a, int y) {
        title = new string(t);
        author = new string(a);
        year = new int(y);
        cout << "Создана книга: " << *title << endl;
    }
    
    // Конструктор копирования
    Book(const Book& other) {
        title = new string(*other.title);
        author = new string(*other.author);
        year = new int(*other.year);
        cout << "Скопирована книга: " << *title << endl;
    }
    
    // Деструктор
    ~Book() {
        cout << "Уничтожена книга: " << *title << endl;
        delete title;
        delete author;
        delete year;
    }
    
    // Методы
    void displayInfo() {
        cout << "Название: " << *title << ", Автор: " << *author << ", Год: " << *year << endl;
    }
    
    void setTitle(string t) { *title = t; }
    void setAuthor(string a) { *author = a; }
    void setYear(int y) { *year = y; }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: КНИГИ ===" << endl;
    
    Book book1;
    book1.displayInfo();
    
    Book book2("Война и мир", "Лев Толстой", 1869);
    book2.displayInfo();
    
    Book book3 = book2;
    book3.setTitle("Анна Каренина");
    book3.setYear(1877);
    book3.displayInfo();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Класс для работы с матрицами
Создай класс Matrix с конструкторами:
- Конструктор по умолчанию (создает матрицу 2x2)
- Конструктор с размерами
- Конструктор копирования
- Деструктор для освобождения памяти

Задание 2: Класс для работы с банковскими счетами
Создай класс BankAccount с конструкторами:
- Конструктор по умолчанию
- Конструктор с номером счета и начальным балансом
- Конструктор копирования
- Деструктор

Задание 3: Класс для работы с автомобилями
Создай класс Car с конструкторами:
- Конструктор по умолчанию
- Конструктор с маркой и моделью
- Конструктор с полными данными
- Конструктор копирования

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое конструктор?
2. Что такое деструктор?
3. Когда вызывается конструктор?
4. Когда вызывается деструктор?
5. Что такое копирующий конструктор?
6. Что такое список инициализации?
7. Зачем нужен деструктор при работе с динамической памятью?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Наследование
- Базовые и производные классы
- Переопределение методов
- Виртуальные функции
- Абстрактные классы

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
    cout << "=== УРОК 13: КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: РАЗЛИЧНЫЕ КОНСТРУКТОРЫ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ДИНАМИЧЕСКИЕ МАССИВЫ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: КНИГИ ===" << endl;
    exercise3();
    
    return 0;
}





