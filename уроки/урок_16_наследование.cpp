/*
===========================================
УРОК 16: НАСЛЕДОВАНИЕ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию наследования (отношение «является»)
- Изучить базовые и производные классы
- Освоить public / protected / private наследование
- Научиться переопределять методы и использовать protected
- Кратко познакомиться с virtual (подробно — урок 17)

ВАЖНО ПРО ПОРЯДОК:
Этот урок — про иерархию классов и переиспользование кода.
В примерах и ДЗ — обычное наследование без virtual и без Base*.
Полиморфизм, virtual, абстрактные классы (= 0) — урок 17.

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

НАСЛЕДОВАНИЕ В C++:

Наследование - это один из основных принципов ООП, который позволяет создавать
новые классы на основе существующих, переиспользуя и расширяя их функциональность.

ЗАЧЕМ НУЖНО НАСЛЕДОВАНИЕ:

1. Переиспользование кода: не нужно дублировать код базового класса
2. Расширение функциональности: добавление новых возможностей
3. Иерархия классов: логическая организация классов
4. Полиморфизм: единый интерфейс для разных классов (подробно — урок 17)
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

VIRTUAL — КРАТКИЙ АНОНС (подробно — урок 17):

Если писать Animal* p = new Dog(); и вызывать p->makeSound(),
без virtual вызовется версия Animal, а не Dog.
Чтобы работал «настоящий» полиморфизм, в базовом классе пишут:
   virtual void makeSound();
а в производном часто добавляют override.
Виртуальный деструктор, abstract (= 0), массивы Base* — урок 17.
На этом уроке в ДЗ достаточно обычного наследования без Base*.

МНОЖЕСТВЕННОЕ НАСЛЕДОВАНИЕ — кратко:
Класс может наследоваться от нескольких баз (сложная тема).
Для курса достаточно одного public-наследования.

СИНТАКСИС УРОКА:

1. Наследование:
   class Потомок : public Базовый {
       // новые поля и методы
   };

2. Вызов конструктора базового класса:
   Потомок(параметры) : Базовый(параметры) { }

3. Переопределение метода:
   class Base {
   public:
       void method() { cout << "Base"; }
   };
   class Derived : public Base {
   public:
       void method() { cout << "Derived"; }  // переопределение
   };

4. Доступ к методу базового класса:
   Base::method();

5. Виды наследования:
   class A : public Base { };     // public наследование
   class B : protected Base { };  // protected наследование
   class C : private Base { };    // private наследование

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
    
    void makeSound() {
        cout << name << " издает звук" << endl;
    }
    
    void displayInfo() {
        cout << "Животное: " << name << ", возраст: " << age << endl;
    }
    
    ~Animal() {
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
    void makeSound() {
        cout << name << " лает: Гав-гав!" << endl;
    }
    
    void displayInfo() {
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
    
    void makeSound() {
        cout << name << " мяукает: Мяу-мяу!" << endl;
    }
    
    void displayInfo() {
        cout << "Кошка: " << name << ", возраст: " << age 
             << ", домашняя: " << (isIndoor ? "Да" : "Нет") << endl;
    }
    
    void climb() {
        cout << name << " лазает по деревьям" << endl;
    }
};

void examples() {
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
    
    cout << "\n=== ПЕРЕОПРЕДЕЛЕНИЕ МЕТОДОВ ===" << endl;
    // Вызов переопределённых методов напрямую у объектов Dog и Cat
    Dog rex("Рекс", 4, "Овчарка");
    Cat vasya("Васька", 1, false);
    
    rex.makeSound();   // версия Dog
    rex.displayInfo();
    cout << endl;
    
    vasya.makeSound(); // версия Cat
    vasya.displayInfo();
    
    cout << "\n=== КОНЕЦ ДЕМОНСТРАЦИИ ===" << endl;
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
    
    double getArea() {
        return 0;
    }
    
    double getPerimeter() {
        return 0;
    }
    
    void displayInfo() {
        cout << "Фигура: " << name << endl;
    }
    
    ~Shape() {
        cout << "Уничтожена фигура: " << name << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : Shape("Прямоугольник"), width(w), height(h) {}
    
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

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : Shape("Круг"), radius(r) {}
    
    double getArea() {
        return 3.14159 * radius * radius;
    }
    
    double getPerimeter() {
        return 2 * 3.14159 * radius;
    }
    
    void displayInfo() {
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
    
    cout << "\n=== ЕЩЁ ФИГУРЫ (ПРЯМОЙ ВЫЗОВ) ===" << endl;
    Rectangle rect2(6.0, 4.0);
    Circle circle2(5.0);
    
    rect2.displayInfo();
    cout << endl;
    circle2.displayInfo();
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
    
    void start() {
        cout << brand << " " << model << " заведен" << endl;
    }
    
    void stop() {
        cout << brand << " " << model << " заглушен" << endl;
    }
    
    void displayInfo() {
        cout << brand << " " << model << " (" << year << ")" << endl;
    }
    
    ~Vehicle() {
        cout << "Уничтожено транспортное средство: " << brand << " " << model << endl;
    }
};

class Car : public Vehicle {
private:
    int doors;
    
public:
    Car(string b, string m, int y, int d) : Vehicle(b, m, y), doors(d) {}
    
    void start() {
        cout << "Автомобиль " << brand << " " << model << " заведен" << endl;
    }
    
    void displayInfo() {
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
    
    void start() {
        cout << "Мотоцикл " << brand << " " << model << " заведен" << endl;
    }
    
    void displayInfo() {
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
    
    void work() {
        cout << name << " работает" << endl;
    }
    
    void displayInfo() {
        cout << "Сотрудник: " << name << ", ID: " << id << ", Зарплата: " << salary << endl;
    }
    
    ~Employee() {
        cout << "Уволен сотрудник: " << name << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;
    
public:
    Manager(string n, int i, double s, int ts) : Employee(n, i, s), teamSize(ts) {}
    
    void work() {
        cout << name << " управляет командой из " << teamSize << " человек" << endl;
    }
    
    void displayInfo() {
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
    
    void work() {
        cout << name << " программирует на " << programmingLanguage << endl;
    }
    
    void displayInfo() {
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
(Без абстрактных классов и без массивов Base*. Это будет в уроке 17.)

Задание 1: Банковские счета (иерархия)
Базовый класс Account (номер, владелец, баланс) и производные:
- SavingsAccount — метод addInterest()
- CheckingAccount — метод withdrawWithFee()
Создай объекты каждого типа отдельно и вызови их методы.

Задание 2: Транспорт
Базовый класс Vehicle (марка, скорость) и производные:
- Car — число дверей
- Bike — есть ли корзина
У каждого — свой метод displayInfo() (можно переопределить).

Задание 3: Фигуры без полиморфного массива
Базовый Shape с полями и метод area() в производных:
- Rectangle, Circle
Посчитай площади, создавая объекты по отдельности (не через Shape*).

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое наследование?
2. В чем разница между базовым и производным классом?
3. Что такое переопределение методов?
4. Зачем нужен protected?
5. Чем public-наследование отличается от private?
6. Что означает отношение «является» (is-a)?
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

int main() {
    cout << "=== УРОК 16: НАСЛЕДОВАНИЕ ===" << endl;
    
    cout << "\n=== ПРИМЕРЫ ===" << endl;
    examples();
    
    cout << "\n=== УПРАЖНЕНИЕ 1: ГЕОМЕТРИЧЕСКИЕ ФИГУРЫ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ТРАНСПОРТНЫЕ СРЕДСТВА ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: СОТРУДНИКИ ===" << endl;
    exercise3();
    
    return 0;
}
























