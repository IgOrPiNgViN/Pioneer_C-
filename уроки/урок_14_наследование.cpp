/*
===========================================
УРОК 14: НАСЛЕДОВАНИЕ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию наследования
- Изучить базовые и производные классы
- Освоить переопределение методов
- Научиться работать с виртуальными функциями
- Понять полиморфизм

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

НАСЛЕДОВАНИЕ В C++:

НАСЛЕДОВАНИЕ - это механизм создания новых классов на основе существующих

БАЗОВЫЙ КЛАСС (родительский) - класс, от которого наследуются другие
ПРОИЗВОДНЫЙ КЛАСС (дочерний) - класс, который наследует от базового

СИНТАКСИС НАСЛЕДОВАНИЯ:
class ПроизводныйКласс : [модификатор] БазовыйКласс {
    // новые члены
};

МОДИФИКАТОРЫ НАСЛЕДОВАНИЯ:
- public - публичное наследование
- protected - защищенное наследование  
- private - приватное наследование

УРОВНИ ДОСТУПА:
- public - доступен везде
- protected - доступен в классе и наследниках
- private - доступен только в классе

ПЕРЕОПРЕДЕЛЕНИЕ МЕТОДОВ:
- Производный класс может переопределить методы базового класса
- Используется ключевое слово virtual для полиморфизма

ВИРТУАЛЬНЫЕ ФУНКЦИИ:
- virtual - указывает, что функция может быть переопределена
- Позволяет вызывать правильную версию функции во время выполнения

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

// Базовый класс
class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Создано животное: " << name << endl;
    }
    
    // Виртуальная функция
    virtual void makeSound() {
        cout << name << " издает звук" << endl;
    }
    
    virtual void displayInfo() {
        cout << "Животное: " << name << ", возраст: " << age << endl;
    }
    
    // Виртуальный деструктор
    virtual ~Animal() {
        cout << "Уничтожено животное: " << name << endl;
    }
};

// Производный класс
class Dog : public Animal {
private:
    string breed;
    
public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Создана собака: " << name << endl;
    }
    
    // Переопределение метода
    void makeSound() override {
        cout << name << " лает: Гав-гав!" << endl;
    }
    
    void displayInfo() override {
        cout << "Собака: " << name << ", возраст: " << age << ", порода: " << breed << endl;
    }
    
    // Новый метод
    void fetch() {
        cout << name << " приносит мяч" << endl;
    }
};

// Еще один производный класс
class Cat : public Animal {
private:
    bool isIndoor;
    
public:
    Cat(string n, int a, bool indoor) : Animal(n, a), isIndoor(indoor) {
        cout << "Создана кошка: " << name << endl;
    }
    
    void makeSound() override {
        cout << name << " мяукает: Мяу-мяу!" << endl;
    }
    
    void displayInfo() override {
        cout << "Кошка: " << name << ", возраст: " << age 
             << ", домашняя: " << (isIndoor ? "Да" : "Нет") << endl;
    }
    
    void climb() {
        cout << name << " лазает по деревьям" << endl;
    }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ НАСЛЕДОВАНИЯ ===" << endl;
    
    // Создание объектов
    Dog dog("Бобик", 3, "Лабрадор");
    Cat cat("Мурка", 2, true);
    
    cout << "\n=== ИНФОРМАЦИЯ О ЖИВОТНЫХ ===" << endl;
    dog.displayInfo();
    cat.displayInfo();
    
    cout << "\n=== ЗВУКИ ЖИВОТНЫХ ===" << endl;
    dog.makeSound();
    cat.makeSound();
    
    cout << "\n=== СПЕЦИАЛЬНЫЕ ДЕЙСТВИЯ ===" << endl;
    dog.fetch();
    cat.climb();
    
    cout << "\n=== ПОЛИМОРФИЗМ ===" << endl;
    Animal* animals[2];
    animals[0] = new Dog("Рекс", 4, "Овчарка");
    animals[1] = new Cat("Васька", 1, false);
    
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->displayInfo();
        cout << endl;
    }
    
    // Освобождение памяти
    for (int i = 0; i < 2; i++) {
        delete animals[i];
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Наследование для геометрических фигур
Создай базовый класс Shape и производные классы:
*/

class Shape {
protected:
    string name;
    
public:
    Shape(string n) : name(n) {
        cout << "Создана фигура: " << name << endl;
    }
    
    virtual double getArea() {
        return 0;
    }
    
    virtual double getPerimeter() {
        return 0;
    }
    
    virtual void displayInfo() {
        cout << "Фигура: " << name << endl;
    }
    
    virtual ~Shape() {
        cout << "Уничтожена фигура: " << name << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : Shape("Прямоугольник"), width(w), height(h) {}
    
    double getArea() override {
        return width * height;
    }
    
    double getPerimeter() override {
        return 2 * (width + height);
    }
    
    void displayInfo() override {
        cout << "Прямоугольник: " << width << " x " << height << endl;
        cout << "Площадь: " << getArea() << ", Периметр: " << getPerimeter() << endl;
    }
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("Круг"), radius(r) {}
    
    double getArea() override {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() override {
        return 2 * 3.14159 * radius;
    }
    
    void displayInfo() override {
        cout << "Круг: радиус " << radius << endl;
        cout << "Площадь: " << getArea() << ", Периметр: " << getPerimeter() << endl;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ГЕОМЕТРИЧЕСКИЕ ФИГУРЫ ===" << endl;
    
    Rectangle rect(5.0, 3.0);
    Circle circle(4.0);
    
    rect.displayInfo();
    circle.displayInfo();
    
    // Полиморфизм
    Shape* shapes[2];
    shapes[0] = new Rectangle(6.0, 4.0);
    shapes[1] = new Circle(5.0);
    
    cout << "\n=== ПОЛИМОРФИЗМ ===" << endl;
    for (int i = 0; i < 2; i++) {
        shapes[i]->displayInfo();
        cout << endl;
    }
    
    for (int i = 0; i < 2; i++) {
        delete shapes[i];
    }
}

/*
Упражнение 2: Наследование для транспортных средств
Создай базовый класс Vehicle и производные классы:
*/

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    double fuelLevel;
    
public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y), fuelLevel(100.0) {
        cout << "Создано транспортное средство: " << brand << " " << model << endl;
    }
    
    virtual void start() {
        cout << brand << " " << model << " заведен" << endl;
    }
    
    virtual void stop() {
        cout << brand << " " << model << " заглушен" << endl;
    }
    
    virtual void displayInfo() {
        cout << brand << " " << model << " (" << year << ")" << endl;
    }
    
    virtual ~Vehicle() {
        cout << "Уничтожено транспортное средство: " << brand << " " << model << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(string b, string m, int y, int d) : Vehicle(b, m, y), doors(d) {}
    
    void start() override {
        cout << "Автомобиль " << brand << " " << model << " заведен" << endl;
    }
    
    void displayInfo() override {
        cout << "Автомобиль: " << brand << " " << model << " (" << year << "), дверей: " << doors << endl;
    }
    
    void honk() {
        cout << brand << " " << model << " сигналит: Би-би!" << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasWindshield;
    
public:
    Motorcycle(string b, string m, int y, bool w) : Vehicle(b, m, y), hasWindshield(w) {}
    
    void start() override {
        cout << "Мотоцикл " << brand << " " << model << " заведен" << endl;
    }
    
    void displayInfo() override {
        cout << "Мотоцикл: " << brand << " " << model << " (" << year 
             << "), ветровое стекло: " << (hasWindshield ? "Да" : "Нет") << endl;
    }
    
    void wheelie() {
        cout << brand << " " << model << " делает вилли!" << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ТРАНСПОРТНЫЕ СРЕДСТВА ===" << endl;
    
    Car car("Toyota", "Camry", 2020, 4);
    Motorcycle bike("Honda", "CBR", 2021, true);
    
    car.displayInfo();
    bike.displayInfo();
    
    car.start();
    bike.start();
    
    car.honk();
    bike.wheelie();
}

/*
Упражнение 3: Наследование для сотрудников
Создай базовый класс Employee и производные классы:
*/

class Employee {
protected:
    string name;
    int id;
    double salary;
    
public:
    Employee(string n, int i, double s) : name(n), id(i), salary(s) {
        cout << "Создан сотрудник: " << name << endl;
    }
    
    virtual void work() {
        cout << name << " работает" << endl;
    }
    
    virtual void displayInfo() {
        cout << "Сотрудник: " << name << ", ID: " << id << ", Зарплата: " << salary << endl;
    }
    
    virtual ~Employee() {
        cout << "Уволен сотрудник: " << name << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;
    
public:
    Manager(string n, int i, double s, int ts) : Employee(n, i, s), teamSize(ts) {}
    
    void work() override {
        cout << name << " управляет командой из " << teamSize << " человек" << endl;
    }
    
    void displayInfo() override {
        cout << "Менеджер: " << name << ", ID: " << id << ", Зарплата: " << salary 
             << ", Размер команды: " << teamSize << endl;
    }
    
    void holdMeeting() {
        cout << name << " проводит совещание" << endl;
    }
};

class Developer : public Employee {
private:
    string programmingLanguage;
    
public:
    Developer(string n, int i, double s, string lang) : Employee(n, i, s), programmingLanguage(lang) {}
    
    void work() override {
        cout << name << " программирует на " << programmingLanguage << endl;
    }
    
    void displayInfo() override {
        cout << "Разработчик: " << name << ", ID: " << id << ", Зарплата: " << salary 
             << ", Язык программирования: " << programmingLanguage << endl;
    }
    
    void debug() {
        cout << name << " отлаживает код" << endl;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: СОТРУДНИКИ ===" << endl;
    
    Manager manager("Анна", 1, 80000, 5);
    Developer developer("Петр", 2, 60000, "C++");
    
    manager.displayInfo();
    developer.displayInfo();
    
    manager.work();
    developer.work();
    
    manager.holdMeeting();
    developer.debug();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Наследование для банковских счетов
Создай базовый класс Account и производные классы:
- SavingsAccount (сберегательный счет)
- CheckingAccount (текущий счет)
- CreditAccount (кредитный счет)

Задание 2: Наследование для игровых персонажей
Создай базовый класс Character и производные классы:
- Warrior (воин)
- Mage (маг)
- Archer (лучник)

Задание 3: Наследование для музыкальных инструментов
Создай базовый класс Instrument и производные классы:
- Guitar (гитара)
- Piano (пианино)
- Drums (барабаны)

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое наследование?
2. В чем разница между базовым и производным классом?
3. Что такое переопределение методов?
4. Что такое виртуальные функции?
5. Что такое полиморфизм?
6. Зачем нужен виртуальный деструктор?
7. Какие модификаторы наследования существуют?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Полиморфизм
- Виртуальные функции
- Абстрактные классы
- Чисто виртуальные функции
- Позднее связывание

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
    cout << "=== УРОК 14: НАСЛЕДОВАНИЕ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ГЕОМЕТРИЧЕСКИЕ ФИГУРЫ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ТРАНСПОРТНЫЕ СРЕДСТВА ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: СОТРУДНИКИ ===" << endl;
    exercise3();
    
    return 0;
}





