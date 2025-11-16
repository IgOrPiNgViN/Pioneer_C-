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

Наследование - это один из основных принципов ООП, который позволяет создавать
новые классы на основе существующих, переиспользуя и расширяя их функциональность.

ЗАЧЕМ НУЖНО НАСЛЕДОВАНИЕ:

1. Переиспользование кода: не нужно дублировать код базового класса
2. Расширение функциональности: добавление новых возможностей
3. Иерархия классов: логическая организация классов
4. Полиморфизм: единый интерфейс для разных классов
5. Модификация поведения: изменение методов базового класса

ТЕРМИНОЛОГИЯ:

1. БАЗОВЫЙ КЛАСС (Base Class, Parent Class, Superclass):
   - Класс, от которого наследуются другие классы
   - Содержит общую функциональность
   - Также называется родительским или суперклассом
   
2. ПРОИЗВОДНЫЙ КЛАСС (Derived Class, Child Class, Subclass):
   - Класс, который наследует от базового
   - Получает все члены базового класса
   - Может добавлять новые члены
   - Может переопределять методы
   - Также называется дочерним или подклассом

СИНТАКСИС НАСЛЕДОВАНИЯ:

Синтаксис:
class ПроизводныйКласс : [модификатор] БазовыйКласс {
    // новые члены производного класса
};

Пример:
class Animal {
    // базовый класс
};

class Dog : public Animal {
    // производный класс
};

МОДИФИКАТОРЫ НАСЛЕДОВАНИЯ:

Модификатор наследования определяет, как члены базового класса будут доступны
в производном классе.

1. PUBLIC НАСЛЕДОВАНИЕ (public inheritance):

   Синтаксис: class Derived : public Base { };
   
   Правила доступа:
   - public члены Base → public в Derived
   - protected члены Base → protected в Derived
   - private члены Base → недоступны в Derived
   
   Пример:
   class Animal {
   public:
       void eat() { }
   protected:
       void sleep() { }
   private:
       void breathe() { }
   };
   
   class Dog : public Animal {
       // eat() доступен как public
       // sleep() доступен как protected
       // breathe() недоступен
   };
   
   Использование:
   - Рекомендуется в большинстве случаев
   - Сохраняет уровни доступа
   - Реализует отношение "является" (is-a)

2. PROTECTED НАСЛЕДОВАНИЕ (protected inheritance):

   Синтаксис: class Derived : protected Base { };
   
   Правила доступа:
   - public члены Base → protected в Derived
   - protected члены Base → protected в Derived
   - private члены Base → недоступны в Derived
   
   Использование:
   - Редко используется
   - Когда нужно скрыть публичный интерфейс базового класса

3. PRIVATE НАСЛЕДОВАНИЕ (private inheritance):

   Синтаксис: class Derived : private Base { };
   
   Правила доступа:
   - public члены Base → private в Derived
   - protected члены Base → private в Derived
   - private члены Base → недоступны в Derived
   
   Использование:
   - Реализует отношение "реализовано через" (implemented-in-terms-of)
   - Альтернатива композиции
   - Редко используется

Рекомендация: Используйте public наследование в большинстве случаев!

УРОВНИ ДОСТУПА В НАСЛЕДОВАНИИ:

1. PUBLIC (публичный):
   - Доступен везде (в классе, наследниках, извне)
   - Интерфейс класса
   
2. PROTECTED (защищенный):
   - Доступен в классе и наследниках
   - Недоступен извне
   - Используется для наследования
   
3. PRIVATE (приватный):
   - Доступен только в классе
   - Недоступен в наследниках
   - Внутренняя реализация

Таблица доступности при public наследовании:
Член Base    | В Derived        | Извне
-------------|------------------|--------
public       | public           | доступен
protected    | protected        | недоступен
private      | недоступен       | недоступен

ПЕРЕОПРЕДЕЛЕНИЕ МЕТОДОВ (Method Overriding):

Производный класс может переопределить методы базового класса.

Пример:
class Animal {
public:
    void makeSound() {
        cout << "Животное издает звук" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() {  // переопределение метода
        cout << "Гав-гав!" << endl;
    }
};

Использование:
Dog dog;
dog.makeSound();  // выводит "Гав-гав!"

Важно: Без virtual это не полиморфизм! Это скрытие (hiding).

ВИРТУАЛЬНЫЕ ФУНКЦИИ:

Виртуальные функции позволяют реализовать полиморфизм.

1. ОБЪЯВЛЕНИЕ ВИРТУАЛЬНОЙ ФУНКЦИИ:

   Синтаксис: virtual тип имя_функции(параметры);
   
   Пример:
   class Animal {
   public:
       virtual void makeSound() {  // виртуальная функция
           cout << "Животное издает звук" << endl;
       }
   };
   
   class Dog : public Animal {
   public:
       void makeSound() override {  // переопределение (C++11)
           cout << "Гав-гав!" << endl;
       }
   };

2. КЛЮЧЕВОЕ СЛОВО OVERRIDE (C++11):

   override указывает, что функция переопределяет виртуальную функцию базового класса.
   
   Преимущества:
   - Проверка компилятором (ошибка, если функция не переопределяет)
   - Ясность намерений
   - Защита от опечаток
   
   Пример:
   class Dog : public Animal {
   public:
       void makeSound() override {  // правильно
           // код
       }
       
       // void makeSound() override;  // ОШИБКА! Нет виртуальной функции для переопределения
   };

3. КЛЮЧЕВОЕ СЛОВО FINAL (C++11):

   final запрещает дальнейшее переопределение функции.
   
   Пример:
   class Animal {
   public:
       virtual void makeSound() final {  // нельзя переопределить
           // код
       }
   };
   
   class Dog : public Animal {
   public:
       // void makeSound() { }  // ОШИБКА! Функция final
   };

ПОЛИМОРФИЗМ ЧЕРЕЗ УКАЗАТЕЛИ И ССЫЛКИ:

Полиморфизм работает только через указатели и ссылки!

Пример:
Animal* animal = new Dog();
animal->makeSound();  // вызовет Dog::makeSound() (если virtual)

Animal animal2 = Dog();  // НЕ полиморфизм! Это срезка (slicing)
animal2.makeSound();     // вызовет Animal::makeSound()

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

Без virtual деструктора:
Base* ptr = new Derived();
delete ptr;  // вызовет только деструктор Base (утечка памяти!)

ПРАВИЛО: Если класс имеет виртуальные функции, деструктор должен быть виртуальным!

МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ:

Класс может наследоваться от нескольких базовых классов.

Синтаксис:
class Derived : public Base1, public Base2 {
    // код
};

Пример:
class Animal {
    // код
};

class Pet {
    // код
};

class Dog : public Animal, public Pet {
    // наследует от обоих классов
};

Особенности:
- Может быть сложным
- Проблема ромба (diamond problem)
- Используйте виртуальное наследование при необходимости

ВИРТУАЛЬНОЕ НАСЛЕДОВАНИЕ:

Решает проблему множественного наследования одного базового класса.

Синтаксис:
class Derived : public virtual Base {
    // код
};

Пример:
class Animal {
    // код
};

class Mammal : public virtual Animal { };
class Pet : public virtual Animal { };

class Dog : public Mammal, public Pet {
    // Animal наследуется только один раз
};

ДОСТУП К ЧЛЕНАМ БАЗОВОГО КЛАССА:

1. Доступ к переопределенным методам:
   class Base {
   public:
       void func() { }
   };
   
   class Derived : public Base {
   public:
       void func() {
           Base::func();  // вызов метода базового класса
           // дополнительный код
       }
   };

2. Доступ к полям базового класса:
   class Base {
   protected:
       int value;
   };
   
   class Derived : public Base {
   public:
       void setValue(int v) {
           value = v;  // доступ к protected полю
       }
   };

КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ В НАСЛЕДОВАНИИ:

1. Порядок вызова конструкторов:
   - Сначала конструктор базового класса
   - Потом конструктор производного класса
   
2. Порядок вызова деструкторов:
   - Сначала деструктор производного класса
   - Потом деструктор базового класса

3. Явный вызов конструктора базового класса:
   class Derived : public Base {
   public:
       Derived(int x) : Base(x) {  // вызов конструктора Base
           // код
       }
   };

СООТНОШЕНИЕ "ЯВЛЯЕТСЯ" (IS-A):

Наследование реализует отношение "является":
- Dog является Animal
- Car является Vehicle
- Student является Person

Если отношение "является" не выполняется, используйте композицию вместо наследования!

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


















