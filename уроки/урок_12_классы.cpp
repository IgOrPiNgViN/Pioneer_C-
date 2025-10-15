/*
===========================================
УРОК 12: КЛАССЫ И ОБЪЕКТЫ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию объектно-ориентированного программирования
- Изучить классы и объекты
- Освоить инкапсуляцию
- Научиться создавать методы классов
- Понять разницу между классами и структурами

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ:

ООП основано на трех основных принципах:
1. ИНКАПСУЛЯЦИЯ - сокрытие данных и методов
2. НАСЛЕДОВАНИЕ - создание новых классов на основе существующих
3. ПОЛИМОРФИЗМ - возможность объектов вести себя по-разному

КЛАССЫ И ОБЪЕКТЫ:

1. КЛАСС - это шаблон для создания объектов
2. ОБЪЕКТ - это экземпляр класса

ОБЪЯВЛЕНИЕ КЛАССА:
class ИмяКласса {
private:
    // приватные члены (доступны только внутри класса)
    
public:
    // публичные члены (доступны извне)
    
protected:
    // защищенные члены (доступны в наследниках)
};

СОЗДАНИЕ ОБЪЕКТА:
ИмяКласса объект;
ИмяКласса объект(параметры); // с конструктором

ДОСТУП К ЧЛЕНАМ:
объект.член
объект.метод()

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

// Простой класс
class Person {
private:
    string name;
    int age;
    
public:
    // Методы для установки значений
    void setName(string n) {
        name = n;
    }
    
    void setAge(int a) {
        if (a >= 0) {
            age = a;
        }
    }
    
    // Методы для получения значений
    string getName() {
        return name;
    }
    
    int getAge() {
        return age;
    }
    
    // Метод для вывода информации
    void displayInfo() {
        cout << "Имя: " << name << ", Возраст: " << age << endl;
    }
};

// Класс для работы с банковским счетом
class BankAccount {
private:
    string accountNumber;
    double balance;
    
public:
    // Конструктор
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }
    
    // Методы
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено: " << amount << " руб." << endl;
        }
    }
    
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Снято: " << amount << " руб." << endl;
        } else {
            cout << "Недостаточно средств!" << endl;
        }
    }
    
    double getBalance() {
        return balance;
    }
    
    void displayAccount() {
        cout << "Счет: " << accountNumber << ", Баланс: " << balance << " руб." << endl;
    }
};

int main() {
    // Работа с классом Person
    cout << "=== РАБОТА С КЛАССОМ PERSON ===" << endl;
    Person person1;
    person1.setName("Иван");
    person1.setAge(25);
    person1.displayInfo();
    
    Person person2;
    person2.setName("Мария");
    person2.setAge(-5); // не установится из-за проверки
    person2.displayInfo();
    
    // Работа с классом BankAccount
    cout << "\n=== РАБОТА С КЛАССОМ BANKACCOUNT ===" << endl;
    BankAccount account("123456789", 1000.0);
    account.displayAccount();
    
    account.deposit(500.0);
    account.displayAccount();
    
    account.withdraw(200.0);
    account.displayAccount();
    
    account.withdraw(2000.0); // попытка снять больше, чем есть
    account.displayAccount();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Класс для работы с прямоугольником
Создай класс Rectangle с методами для вычисления площади и периметра:
*/

class Rectangle {
private:
    double width;
    double height;
    
public:
    void setDimensions(double w, double h) {
        if (w > 0 && h > 0) {
            width = w;
            height = h;
        }
    }
    
    double getArea() {
        return width * height;
    }
    
    double getPerimeter() {
        return 2 * (width + height);
    }
    
    void displayInfo() {
        cout << "Прямоугольник: " << width << " x " << height << endl;
        cout << "Площадь: " << getArea() << endl;
        cout << "Периметр: " << getPerimeter() << endl;
    }
};

void exercise1() {
    Rectangle rect;
    rect.setDimensions(5.0, 3.0);
    rect.displayInfo();
}

/*
Упражнение 2: Класс для работы с автомобилем
Создай класс Car с методами для управления автомобилем:
*/

class Car {
private:
    string brand;
    string model;
    int year;
    double fuelLevel;
    double maxFuel;
    bool isRunning;
    
public:
    Car(string b, string m, int y, double maxF) {
        brand = b;
        model = m;
        year = y;
        maxFuel = maxF;
        fuelLevel = maxF;
        isRunning = false;
    }
    
    void start() {
        if (fuelLevel > 0) {
            isRunning = true;
            cout << "Автомобиль заведен" << endl;
        } else {
            cout << "Нет топлива!" << endl;
        }
    }
    
    void stop() {
        isRunning = false;
        cout << "Автомобиль заглушен" << endl;
    }
    
    void refuel(double amount) {
        if (amount > 0) {
            fuelLevel = min(fuelLevel + amount, maxFuel);
            cout << "Заправлено: " << amount << " л" << endl;
        }
    }
    
    void drive(double distance) {
        if (isRunning && fuelLevel > 0) {
            double fuelUsed = distance * 0.1; // 0.1 л на км
            if (fuelUsed <= fuelLevel) {
                fuelLevel -= fuelUsed;
                cout << "Проехали: " << distance << " км" << endl;
            } else {
                cout << "Недостаточно топлива!" << endl;
            }
        } else {
            cout << "Автомобиль не заведен!" << endl;
        }
    }
    
    void displayInfo() {
        cout << brand << " " << model << " (" << year << ")" << endl;
        cout << "Топливо: " << fuelLevel << "/" << maxFuel << " л" << endl;
        cout << "Состояние: " << (isRunning ? "Заведен" : "Заглушен") << endl;
    }
};

void exercise2() {
    Car myCar("Toyota", "Camry", 2020, 60.0);
    myCar.displayInfo();
    
    myCar.start();
    myCar.drive(50.0);
    myCar.displayInfo();
    
    myCar.refuel(20.0);
    myCar.displayInfo();
}

/*
Упражнение 3: Класс для работы с библиотекой
Создай класс Book для работы с книгами:
*/

class Book {
private:
    string title;
    string author;
    int year;
    bool isAvailable;
    
public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
        isAvailable = true;
    }
    
    void borrow() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Книга '" << title << "' взята в аренду" << endl;
        } else {
            cout << "Книга '" << title << "' уже взята" << endl;
        }
    }
    
    void returnBook() {
        if (!isAvailable) {
            isAvailable = true;
            cout << "Книга '" << title << "' возвращена" << endl;
        } else {
            cout << "Книга '" << title << "' уже в библиотеке" << endl;
        }
    }
    
    void displayInfo() {
        cout << "Название: " << title << endl;
        cout << "Автор: " << author << endl;
        cout << "Год: " << year << endl;
        cout << "Статус: " << (isAvailable ? "Доступна" : "Взята") << endl;
    }
};

void exercise3() {
    Book book1("Война и мир", "Лев Толстой", 1869);
    Book book2("Евгений Онегин", "Александр Пушкин", 1833);
    
    book1.displayInfo();
    book1.borrow();
    book1.displayInfo();
    
    book2.borrow();
    book2.returnBook();
    book2.displayInfo();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Класс для работы с дробями
Создай класс Fraction для работы с дробями:
- Поля: числитель и знаменатель
- Методы: сложение, вычитание, умножение, деление
- Метод для упрощения дроби
- Метод для вывода дроби

Задание 2: Класс для работы с временем
Создай класс Time для работы с временем:
- Поля: часы, минуты, секунды
- Методы: установка времени, получение времени
- Методы: добавление времени, сравнение времени
- Метод для вывода времени в формате ЧЧ:ММ:СС

Задание 3: Класс для работы с магазином
Создай класс Store для работы с магазином:
- Поля: название, адрес, количество товаров
- Методы: добавление товара, продажа товара
- Методы: проверка наличия, получение информации о магазине

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое класс и объект?
2. В чем разница между классами и структурами?
3. Что такое инкапсуляция?
4. Какие уровни доступа есть в C++?
5. Что такое методы класса?
6. Как создать объект класса?
7. Как получить доступ к членам класса?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Конструкторы и деструкторы
- Перегрузка конструкторов
- Список инициализации
- Копирующий конструктор
- Оператор присваивания

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 12: КЛАССЫ И ОБЪЕКТЫ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: КЛАСС ПРЯМОУГОЛЬНИК ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: КЛАСС АВТОМОБИЛЬ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: КЛАСС КНИГА ===" << endl;
    exercise3();
    
    return 0;
}





