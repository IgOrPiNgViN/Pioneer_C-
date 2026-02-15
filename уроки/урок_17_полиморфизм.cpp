/*
===========================================
УРОК 17: ПОЛИМОРФИЗМ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию полиморфизма
- Изучить виртуальные функции
- Освоить абстрактные классы
- Научиться работать с чисто виртуальными функциями
- Понять позднее связывание

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПОЛИМОРФИЗМ В C++:

Полиморфизм (polymorphism) - это способность объектов разных типов обрабатываться
через единый интерфейс. Один и тот же код может работать с разными типами объектов.

ЗАЧЕМ НУЖЕН ПОЛИМОРФИЗМ:

1. Гибкость: один код работает с разными типами
2. Расширяемость: легко добавлять новые типы
3. Упрощение: единый интерфейс для разных реализаций
4. Абстракция: работа на уровне интерфейса, а не реализации

ТИПЫ ПОЛИМОРФИЗМА:

1. ВРЕМЕННЫЙ ПОЛИМОРФИЗМ (Compile-time Polymorphism):
   Перегрузка функций и операторов.
   Решение принимается во время компиляции.
   
   Пример:
   int add(int a, int b) { return a + b; }
   double add(double a, double b) { return a + b; }
   
   Компилятор выбирает нужную функцию по типам аргументов.

2. ПАРАМЕТРИЧЕСКИЙ ПОЛИМОРФИЗМ (Parametric Polymorphism):
   Шаблоны (templates).
   Один код для разных типов.
   
   Пример:
   template<typename T>
   T add(T a, T b) { return a + b; }

3. ПОЛИМОРФИЗМ НАСЛЕДОВАНИЯ (Runtime Polymorphism):
   Виртуальные функции.
   Решение принимается во время выполнения.
   
   Пример:
   class Animal {
       virtual void makeSound() { }
   };
   class Dog : public Animal {
       void makeSound() override { }
   };

ВИРТУАЛЬНЫЕ ФУНКЦИИ:

Виртуальные функции - это функции, которые могут быть переопределены в производных классах.
Вызов правильной версии функции происходит во время выполнения (позднее связывание).

1. ОБЪЯВЛЕНИЕ ВИРТУАЛЬНОЙ ФУНКЦИИ:

   Синтаксис: virtual тип имя_функции(параметры);
   
   Пример:
   class Shape {
   public:
       virtual double getArea() {
           return 0.0;
       }
   };
   
   class Circle : public Shape {
   private:
       double radius;
   public:
       double getArea() override {
           return 3.14159 * radius * radius;
       }
   };

2. КАК РАБОТАЮТ ВИРТУАЛЬНЫЕ ФУНКЦИИ:

   а) Без virtual (раннее связывание):
   Shape* shape = new Circle();
   shape->getArea();  // вызовет Shape::getArea() (неправильно!)
   
   б) С virtual (позднее связывание):
   Shape* shape = new Circle();
   shape->getArea();  // вызовет Circle::getArea() (правильно!)
   
   Механизм:
   - Каждый объект с виртуальными функциями имеет таблицу виртуальных функций (vtable)
   - Указатель на vtable хранится в объекте
   - Вызов функции происходит через vtable во время выполнения

3. КЛЮЧЕВОЕ СЛОВО OVERRIDE (C++11):

   override явно указывает, что функция переопределяет виртуальную функцию.
   
   Преимущества:
   - Компилятор проверяет, что функция действительно переопределяет
   - Защита от опечаток в имени или сигнатуре
   - Ясность намерений
   
   Пример:
   class Base {
   public:
       virtual void func() { }
   };
   
   class Derived : public Base {
   public:
       void func() override {  // правильно
           // код
       }
       
       // void func(int x) override;  // ОШИБКА! Не переопределяет
   };

4. КЛЮЧЕВОЕ СЛОВО FINAL (C++11):

   final запрещает дальнейшее переопределение функции или наследование класса.
   
   а) Для функций:
   class Base {
   public:
       virtual void func() final {  // нельзя переопределить
           // код
       }
   };
   
   class Derived : public Base {
   public:
       // void func() { }  // ОШИБКА! Функция final
   };
   
   б) Для классов:
   class Base final {  // нельзя наследовать
       // код
   };
   
   // class Derived : public Base { };  // ОШИБКА! Класс final

РАННЕЕ И ПОЗДНЕЕ СВЯЗЫВАНИЕ:

1. РАННЕЕ СВЯЗЫВАНИЕ (Early Binding, Static Binding):

   Решение о том, какую функцию вызывать, принимается во время компиляции.
   
   Пример:
   class Base {
   public:
       void func() {  // НЕ virtual
           cout << "Base::func()" << endl;
       }
   };
   
   class Derived : public Base {
   public:
       void func() {
           cout << "Derived::func()" << endl;
       }
   };
   
   Base* ptr = new Derived();
   ptr->func();  // вызовет Base::func() (раннее связывание)
   
   Особенности:
   - Быстрее (нет накладных расходов)
   - Решение во время компиляции
   - Для невиртуальных функций

2. ПОЗДНЕЕ СВЯЗЫВАНИЕ (Late Binding, Dynamic Binding):

   Решение о том, какую функцию вызывать, принимается во время выполнения.
   
   Пример:
   class Base {
   public:
       virtual void func() {  // virtual
           cout << "Base::func()" << endl;
       }
   };
   
   class Derived : public Base {
   public:
       void func() override {
           cout << "Derived::func()" << endl;
       }
   };
   
   Base* ptr = new Derived();
   ptr->func();  // вызовет Derived::func() (позднее связывание)
   
   Особенности:
   - Гибкость (полиморфизм)
   - Небольшие накладные расходы (vtable)
   - Для виртуальных функций

АБСТРАКТНЫЕ КЛАССЫ:

Абстрактный класс - это класс, который содержит хотя бы одну чисто виртуальную функцию.
Нельзя создать объект абстрактного класса напрямую.

1. ОБЪЯВЛЕНИЕ АБСТРАКТНОГО КЛАССА:

   Пример:
   class Shape {
   public:
       virtual double getArea() = 0;  // чисто виртуальная функция
       virtual double getPerimeter() = 0;  // чисто виртуальная функция
   };
   
   // Shape shape;  // ОШИБКА! Нельзя создать объект абстрактного класса

2. ИСПОЛЬЗОВАНИЕ АБСТРАКТНЫХ КЛАССОВ:

   Абстрактные классы используются как интерфейсы или базовые классы.
   
   Пример:
   class Circle : public Shape {
   private:
       double radius;
   public:
       double getArea() override {
           return 3.14159 * radius * radius;
       }
       
       double getPerimeter() override {
           return 2 * 3.14159 * radius;
       }
   };
   
   Circle circle;  // можно создать (все чисто виртуальные функции переопределены)

3. ПРЕИМУЩЕСТВА АБСТРАКТНЫХ КЛАССОВ:

   - Определение интерфейса
   - Гарантия реализации методов в производных классах
   - Невозможность создать неполный объект
   - Полиморфизм

ЧИСТО ВИРТУАЛЬНЫЕ ФУНКЦИИ:

Чисто виртуальная функция - это виртуальная функция без реализации.

Синтаксис: virtual тип функция() = 0;

Пример:
class Animal {
public:
    virtual void makeSound() = 0;  // чисто виртуальная функция
    virtual void eat() = 0;        // чисто виртуальная функция
};

Особенности:
- Должна быть переопределена в производных классах
- Если не переопределена, класс остается абстрактным
- Нельзя вызвать напрямую (нет реализации)

Пример реализации:
class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Гав-гав!" << endl;
    }
    
    void eat() override {
        cout << "Собака ест" << endl;
    }
};

ВИРТУАЛЬНЫЙ ДЕСТРУКТОР:

Если класс используется для полиморфизма, деструктор должен быть виртуальным!

Пример:
class Base {
public:
    virtual ~Base() {  // виртуальный деструктор
        cout << "Деструктор Base" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Деструктор Derived" << endl;
    }
};

Использование:
Base* ptr = new Derived();
delete ptr;  // вызовет оба деструктора (правильно)

Без virtual:
Base* ptr = new Derived();
delete ptr;  // вызовет только Base::~Base() (утечка памяти!)

ПРАВИЛО: Если класс имеет виртуальные функции, деструктор должен быть виртуальным!

ПОЛИМОРФИЗМ ЧЕРЕЗ УКАЗАТЕЛИ:

Полиморфизм работает через указатели на базовый класс.

Пример:
vector<Shape*> shapes;
shapes.push_back(new Circle(5.0));
shapes.push_back(new Rectangle(3.0, 4.0));

for (Shape* shape : shapes) {
    cout << "Площадь: " << shape->getArea() << endl;  // вызовет правильную функцию
}

ПОЛИМОРФИЗМ ЧЕРЕЗ ССЫЛКИ:

Полиморфизм также работает через ссылки.

Пример:
void printArea(Shape& shape) {
    cout << "Площадь: " << shape.getArea() << endl;  // вызовет правильную функцию
}

Circle circle(5.0);
printArea(circle);  // передача по ссылке

СРЕЗКА ОБЪЕКТОВ (Object Slicing):

Срезка происходит, когда объект производного класса присваивается объекту базового класса.

Пример:
Circle circle(5.0);
Shape shape = circle;  // срезка! Теряется информация о Circle
shape.getArea();  // вызовет Shape::getArea(), а не Circle::getArea()

Как избежать:
- Используйте указатели: Shape* shape = &circle;
- Используйте ссылки: Shape& shape = circle;
- Не присваивайте объекты напрямую

СИНТАКСИС УРОКА:

1. Виртуальная функция:
   class Base {
   public:
       virtual void method() { }
   };

2. Переопределение (override):
   class Derived : public Base {
   public:
       void method() override { }
   };

3. Чисто виртуальная функция (абстрактный метод):
   virtual void method() = 0;

4. Абстрактный класс:
   class Abstract {
   public:
       virtual void method() = 0;  // нельзя создать объект этого класса
   };

5. Полиморфизм через указатель:
   Base* ptr = new Derived();
   ptr->method();  // вызовется метод Derived
   delete ptr;

6. Виртуальный деструктор:
   virtual ~Base() { }

ИНТЕРФЕЙСЫ:

В C++ интерфейсы реализуются через абстрактные классы с чисто виртуальными функциями.

Пример:
class Drawable {
public:
    virtual void draw() = 0;
    virtual ~Drawable() = default;
};

class Movable {
public:
    virtual void move(int x, int y) = 0;
    virtual ~Movable() = default;
};

class Circle : public Drawable, public Movable {
public:
    void draw() override { }
    void move(int x, int y) override { }
};

ПРЕИМУЩЕСТВА ПОЛИМОРФИЗМА:

1. Гибкость кода
2. Расширяемость (легко добавлять новые типы)
3. Единый интерфейс
4. Упрощение кода
5. Абстракция

НЕДОСТАТКИ:

1. Небольшие накладные расходы (vtable)
2. Сложность отладки
3. Нужно помнить о виртуальных деструкторах

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

void examples() {
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
    
    cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИИ ===" << endl;
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

int main() {
    cout << "=== УРОК 17: ПОЛИМОРФИЗМ ===" << endl;
    
    cout << "\n=== ПРИМЕРЫ ===" << endl;
    examples();
    
    cout << "\n=== УПРАЖНЕНИЕ 1: ПОЛИМОРФИЗМ ЖИВОТНЫХ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ПОЛИМОРФИЗМ ТРАНСПОРТА ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ПОЛИМОРФИЗМ СОТРУДНИКОВ ===" << endl;
    exercise3();
    
    return 0;
}
























