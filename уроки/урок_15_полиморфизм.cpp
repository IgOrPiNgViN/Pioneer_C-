/*
===========================================
УРОК 15: ПОЛИМОРФИЗМ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию полиморфизма
- Изучить виртуальные функции
- Освоить абстрактные классы
- Научиться работать с чисто виртуальными функциями
- Понять позднее связывание

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПОЛИМОРФИЗМ В C++:

ПОЛИМОРФИЗМ - это способность объектов вести себя по-разному в зависимости от их типа

ТИПЫ ПОЛИМОРФИЗМА:
1. ВРЕМЕННЫЙ ПОЛИМОРФИЗМ (перегрузка функций)
2. ПАРАМЕТРИЧЕСКИЙ ПОЛИМОРФИЗМ (шаблоны)
3. ПОЛИМОРФИЗМ НАСЛЕДОВАНИЯ (виртуальные функции)

ВИРТУАЛЬНЫЕ ФУНКЦИИ:
- virtual - ключевое слово для объявления виртуальной функции
- override - ключевое слово для переопределения (C++11)
- Позволяют вызывать правильную версию функции во время выполнения

РАННЕЕ И ПОЗДНЕЕ СВЯЗЫВАНИЕ:
- Раннее связывание - решение о том, какую функцию вызывать, принимается во время компиляции
- Позднее связывание - решение принимается во время выполнения

АБСТРАКТНЫЕ КЛАССЫ:
- Класс с чисто виртуальными функциями
- Нельзя создать объект абстрактного класса
- Используется как интерфейс

ЧИСТО ВИРТУАЛЬНЫЕ ФУНКЦИИ:
- virtual функция() = 0;
- Должны быть переопределены в производных классах

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Абстрактный базовый класс
class Shape {
protected:
    string name;
    
public:
    Shape(string n) : name(n) {
        cout << "Создана фигура: " << name << endl;
    }
    
    // Чисто виртуальные функции
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual void draw() = 0;
    
    // Обычная виртуальная функция
    virtual void displayInfo() {
        cout << "Фигура: " << name << endl;
    }
    
    // Виртуальный деструктор
    virtual ~Shape() {
        cout << "Уничтожена фигура: " << name << endl;
    }
};

// Конкретный класс
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
    
    void draw() override {
        cout << "Рисую прямоугольник " << width << "x" << height << endl;
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
    
    void draw() override {
        cout << "Рисую круг радиусом " << radius << endl;
    }
    
    void displayInfo() override {
        cout << "Круг: радиус " << radius << endl;
        cout << "Площадь: " << getArea() << ", Периметр: " << getPerimeter() << endl;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
    
public:
    Triangle(double b, double h) : Shape("Треугольник"), base(b), height(h) {}
    
    double getArea() override {
        return 0.5 * base * height;
    }
    
    double getPerimeter() override {
        // Упрощенный расчет для равнобедренного треугольника
        double side = sqrt((base/2)*(base/2) + height*height);
        return base + 2 * side;
    }
    
    void draw() override {
        cout << "Рисую треугольник с основанием " << base << " и высотой " << height << endl;
    }
    
    void displayInfo() override {
        cout << "Треугольник: основание " << base << ", высота " << height << endl;
        cout << "Площадь: " << getArea() << ", Периметр: " << getPerimeter() << endl;
    }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА ===" << endl;
    
    // Создание объектов
    Rectangle rect(5.0, 3.0);
    Circle circle(4.0);
    Triangle triangle(6.0, 4.0);
    
    cout << "\n=== ИНФОРМАЦИЯ О ФИГУРАХ ===" << endl;
    rect.displayInfo();
    circle.displayInfo();
    triangle.displayInfo();
    
    cout << "\n=== РИСОВАНИЕ ФИГУР ===" << endl;
    rect.draw();
    circle.draw();
    triangle.draw();
    
    cout << "\n=== ПОЛИМОРФИЗМ ЧЕРЕЗ УКАЗАТЕЛИ ===" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Rectangle(6.0, 4.0));
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Triangle(8.0, 6.0));
    
    double totalArea = 0;
    for (Shape* shape : shapes) {
        shape->draw();
        totalArea += shape->getArea();
    }
    
    cout << "\nОбщая площадь всех фигур: " << totalArea << endl;
    
    // Освобождение памяти
    for (Shape* shape : shapes) {
        delete shape;
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Полиморфизм для животных
Создай абстрактный класс Animal и конкретные классы:
*/

class Animal {
protected:
    string name;
    int age;
    
public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Создано животное: " << name << endl;
    }
    
    // Чисто виртуальные функции
    virtual void makeSound() = 0;
    virtual void move() = 0;
    virtual void eat() = 0;
    
    // Обычная виртуальная функция
    virtual void displayInfo() {
        cout << "Животное: " << name << ", возраст: " << age << endl;
    }
    
    virtual ~Animal() {
        cout << "Уничтожено животное: " << name << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}
    
    void makeSound() override {
        cout << name << " лает: Гав-гав!" << endl;
    }
    
    void move() override {
        cout << name << " бегает" << endl;
    }
    
    void eat() override {
        cout << name << " ест корм" << endl;
    }
    
    void displayInfo() override {
        cout << "Собака: " << name << ", возраст: " << age << endl;
    }
};

class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}
    
    void makeSound() override {
        cout << name << " поет: Чирик-чирик!" << endl;
    }
    
    void move() override {
        cout << name << " летает" << endl;
    }
    
    void eat() override {
        cout << name << " клюет зерно" << endl;
    }
    
    void displayInfo() override {
        cout << "Птица: " << name << ", возраст: " << age << endl;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ПОЛИМОРФИЗМ ЖИВОТНЫХ ===" << endl;
    
    vector<Animal*> animals;
    animals.push_back(new Dog("Бобик", 3));
    animals.push_back(new Bird("Кеша", 2));
    animals.push_back(new Dog("Рекс", 5));
    
    for (Animal* animal : animals) {
        animal->displayInfo();
        animal->makeSound();
        animal->move();
        animal->eat();
        cout << endl;
    }
    
    for (Animal* animal : animals) {
        delete animal;
    }
}

/*
Упражнение 2: Полиморфизм для транспортных средств
Создай абстрактный класс Vehicle и конкретные классы:
*/

class Vehicle {
protected:
    string brand;
    string model;
    int year;
    
public:
    Vehicle(string b, string m, int y) : brand(b), model(m), year(y) {
        cout << "Создано транспортное средство: " << brand << " " << model << endl;
    }
    
    // Чисто виртуальные функции
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate() = 0;
    
    // Обычная виртуальная функция
    virtual void displayInfo() {
        cout << brand << " " << model << " (" << year << ")" << endl;
    }
    
    virtual ~Vehicle() {
        cout << "Уничтожено транспортное средство: " << brand << " " << model << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string b, string m, int y) : Vehicle(b, m, y) {}
    
    void start() override {
        cout << "Автомобиль " << brand << " " << model << " заведен ключом" << endl;
    }
    
    void stop() override {
        cout << "Автомобиль " << brand << " " << model << " заглушен" << endl;
    }
    
    void accelerate() override {
        cout << "Автомобиль " << brand << " " << model << " разгоняется" << endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(string b, string m, int y) : Vehicle(b, m, y) {}
    
    void start() override {
        cout << "Мотоцикл " << brand << " " << model << " заведен кнопкой" << endl;
    }
    
    void stop() override {
        cout << "Мотоцикл " << brand << " " << model << " заглушен" << endl;
    }
    
    void accelerate() override {
        cout << "Мотоцикл " << brand << " " << model << " быстро разгоняется" << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ПОЛИМОРФИЗМ ТРАНСПОРТА ===" << endl;
    
    vector<Vehicle*> vehicles;
    vehicles.push_back(new Car("Toyota", "Camry", 2020));
    vehicles.push_back(new Motorcycle("Honda", "CBR", 2021));
    vehicles.push_back(new Car("BMW", "X5", 2019));
    
    for (Vehicle* vehicle : vehicles) {
        vehicle->displayInfo();
        vehicle->start();
        vehicle->accelerate();
        vehicle->stop();
        cout << endl;
    }
    
    for (Vehicle* vehicle : vehicles) {
        delete vehicle;
    }
}

/*
Упражнение 3: Полиморфизм для сотрудников
Создай абстрактный класс Employee и конкретные классы:
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
    
    // Чисто виртуальные функции
    virtual void work() = 0;
    virtual void takeBreak() = 0;
    virtual void attendMeeting() = 0;
    
    // Обычная виртуальная функция
    virtual void displayInfo() {
        cout << "Сотрудник: " << name << ", ID: " << id << ", Зарплата: " << salary << endl;
    }
    
    virtual ~Employee() {
        cout << "Уволен сотрудник: " << name << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int i, double s) : Employee(n, i, s) {}
    
    void work() override {
        cout << name << " планирует работу команды" << endl;
    }
    
    void takeBreak() override {
        cout << name << " отдыхает в своем кабинете" << endl;
    }
    
    void attendMeeting() override {
        cout << name << " проводит совещание" << endl;
    }
    
    void displayInfo() override {
        cout << "Менеджер: " << name << ", ID: " << id << ", Зарплата: " << salary << endl;
    }
};

class Developer : public Employee {
public:
    Developer(string n, int i, double s) : Employee(n, i, s) {}
    
    void work() override {
        cout << name << " пишет код" << endl;
    }
    
    void takeBreak() override {
        cout << name << " играет в пинг-понг" << endl;
    }
    
    void attendMeeting() override {
        cout << name << " участвует в планировании спринта" << endl;
    }
    
    void displayInfo() override {
        cout << "Разработчик: " << name << ", ID: " << id << ", Зарплата: " << salary << endl;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ПОЛИМОРФИЗМ СОТРУДНИКОВ ===" << endl;
    
    vector<Employee*> employees;
    employees.push_back(new Manager("Анна", 1, 80000));
    employees.push_back(new Developer("Петр", 2, 60000));
    employees.push_back(new Manager("Иван", 3, 75000));
    
    for (Employee* employee : employees) {
        employee->displayInfo();
        employee->work();
        employee->takeBreak();
        employee->attendMeeting();
        cout << endl;
    }
    
    for (Employee* employee : employees) {
        delete employee;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Полиморфизм для банковских счетов
Создай абстрактный класс Account и конкретные классы:
- SavingsAccount (сберегательный счет)
- CheckingAccount (текущий счет)
- CreditAccount (кредитный счет)

Задание 2: Полиморфизм для игровых персонажей
Создай абстрактный класс Character и конкретные классы:
- Warrior (воин)
- Mage (маг)
- Archer (лучник)

Задание 3: Полиморфизм для музыкальных инструментов
Создай абстрактный класс Instrument и конкретные классы:
- Guitar (гитара)
- Piano (пианино)
- Drums (барабаны)

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое полиморфизм?
2. В чем разница между ранним и поздним связыванием?
3. Что такое виртуальная функция?
4. Что такое абстрактный класс?
5. Что такое чисто виртуальная функция?
6. Можно ли создать объект абстрактного класса?
7. Зачем нужен виртуальный деструктор?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Перегрузка операторов
- Операторы ввода/вывода
- Операторы арифметики
- Операторы сравнения
- Операторы присваивания

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 15: ПОЛИМОРФИЗМ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ПОЛИМОРФИЗМ ЖИВОТНЫХ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ПОЛИМОРФИЗМ ТРАНСПОРТА ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ПОЛИМОРФИЗМ СОТРУДНИКОВ ===" << endl;
    exercise3();
    
    return 0;
}





