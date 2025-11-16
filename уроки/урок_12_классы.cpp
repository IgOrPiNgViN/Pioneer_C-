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

ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ (ООП):

ООП - это парадигма программирования, основанная на концепции объектов.
Объекты объединяют данные (поля) и функции (методы), которые работают с этими данными.

ЗАЧЕМ НУЖНО ООП:

1. Модульность: код разбит на логические единицы (классы)
2. Переиспользование: классы можно использовать в разных программах
3. Инкапсуляция: данные защищены от неправильного использования
4. Упрощение сложных программ
5. Близость к реальному миру (объекты моделируют реальные сущности)

ОСНОВНЫЕ ПРИНЦИПЫ ООП:

1. ИНКАПСУЛЯЦИЯ (Encapsulation):
   - Объединение данных и методов в одном классе
   - Сокрытие внутренней реализации
   - Контроль доступа к данным через методы
   - Защита данных от неправильного использования
   
   Пример:
   class BankAccount {
   private:
       double balance;  // скрыто от внешнего доступа
   public:
       void deposit(double amount) {  // контролируемый доступ
           if (amount > 0) {
               balance += amount;
           }
       }
   };

2. НАСЛЕДОВАНИЕ (Inheritance):
   - Создание новых классов на основе существующих
   - Переиспользование кода
   - Расширение функциональности
   - Иерархия классов
   
   Пример:
   class Animal { ... };
   class Dog : public Animal { ... };  // Dog наследует от Animal

3. ПОЛИМОРФИЗМ (Polymorphism):
   - Возможность объектов вести себя по-разному
   - Один интерфейс, разные реализации
   - Виртуальные функции
   - Позднее связывание

КЛАССЫ И ОБЪЕКТЫ:

1. КЛАСС (Class):
   Класс - это шаблон (blueprint) для создания объектов.
   Класс определяет структуру и поведение объектов.
   
   Аналогия: Класс = чертеж дома, Объект = построенный дом
   
   Класс содержит:
   - Поля (данные, переменные-члены)
   - Методы (функции-члены)
   - Конструкторы и деструкторы
   - Уровни доступа

2. ОБЪЕКТ (Object):
   Объект - это конкретный экземпляр класса.
   Каждый объект имеет свои собственные значения полей.
   
   Пример:
   class Person { ... };
   Person person1;  // объект 1
   Person person2;  // объект 2 (другой экземпляр)

ОБЪЯВЛЕНИЕ КЛАССА:

Синтаксис:
class ИмяКласса {
    // члены класса
};

Пример:
class Person {
    // поля и методы
};

УРОВНИ ДОСТУПА (Access Specifiers):

Уровни доступа определяют, кто может обращаться к членам класса.

1. PRIVATE (приватный):
   - Доступны только внутри класса
   - Недоступны извне класса
   - Недоступны в наследниках
   - По умолчанию в классах
   
   Пример:
   class Person {
   private:
       string name;  // только методы класса могут обращаться
       int age;
   };
   
   Использование:
   - Скрытие внутренней реализации
   - Защита данных
   - Инкапсуляция

2. PUBLIC (публичный):
   - Доступны извне класса
   - Доступны везде
   - Доступны в наследниках
   
   Пример:
   class Person {
   public:
       void setName(string n) {  // доступно извне
           name = n;
       }
   };
   
   Использование:
   - Интерфейс класса
   - Методы для работы с данными
   - Публичные поля (не рекомендуется)

3. PROTECTED (защищенный):
   - Доступны внутри класса
   - Доступны в наследниках
   - Недоступны извне
   
   Пример:
   class Person {
   protected:
       string middleName;  // доступно в наследниках
   };
   
   Использование:
   - Для наследования
   - Когда нужно дать доступ наследникам, но не внешнему коду

ПОЛЯ КЛАССА (Data Members):

Поля - это переменные, принадлежащие классу.

Объявление:
class Person {
private:
    string name;      // поле типа string
    int age;          // поле типа int
    double height;    // поле типа double
    bool isStudent;   // поле типа bool
};

Особенности:
- Каждый объект имеет свои собственные копии полей
- Поля могут быть любого типа
- Поля обычно делают private для инкапсуляции

МЕТОДЫ КЛАССА (Member Functions):

Методы - это функции, принадлежащие классу.

Объявление:
class Person {
public:
    void setName(string n) {  // метод для установки имени
        name = n;
    }
    
    string getName() {        // метод для получения имени
        return name;
    }
};

Особенности:
- Методы имеют доступ ко всем полям класса
- Методы могут быть объявлены внутри или вне класса
- Методы могут быть перегружены

Определение методов вне класса:
class Person {
public:
    void setName(string n);  // объявление
    string getName();        // объявление
};

// Определение вне класса:
void Person::setName(string n) {
    name = n;
}

string Person::getName() {
    return name;
}

СОЗДАНИЕ ОБЪЕКТОВ:

1. Создание без параметров:
   ClassName object;
   Person person1;
   
2. Создание с параметрами (через конструктор):
   ClassName object(параметры);
   Person person2("Иван", 25);
   
3. Создание в динамической памяти:
   ClassName* object = new ClassName();
   Person* person3 = new Person("Мария", 20);
   delete person3;  // не забудьте освободить память!

ДОСТУП К ЧЛЕНАМ КЛАССА:

1. Доступ к полям и методам (через объект):
   объект.поле
   объект.метод()
   
   Пример:
   Person person;
   person.setName("Иван");     // вызов метода
   string name = person.getName();  // получение значения
   
   Важно: Доступ к private полям напрямую невозможен!
   // person.name = "Иван";  // ОШИБКА! name - private

2. Доступ через указатель:
   объект->поле
   объект->метод()
   
   Пример:
   Person* person = new Person();
   person->setName("Иван");
   string name = person->getName();
   delete person;

РАЗНИЦА МЕЖДУ КЛАССАМИ И СТРУКТУРАМИ:

В C++ классы и структуры почти идентичны, но есть важные различия:

1. Уровень доступа по умолчанию:
   - class: private по умолчанию
   - struct: public по умолчанию
   
   Пример:
   class MyClass {
       int x;  // private по умолчанию
   };
   
   struct MyStruct {
       int x;  // public по умолчанию
   };

2. Использование:
   - class: для объектов с поведением (методы)
   - struct: для простых структур данных (поля)
   
   Рекомендация:
   - Используйте class для ООП
   - Используйте struct для простых данных (как в C)

ИНКАПСУЛЯЦИЯ:

Инкапсуляция - это сокрытие внутренней реализации и предоставление интерфейса.

Принципы:
1. Данные делаются private
2. Доступ через публичные методы (getters/setters)
3. Валидация данных в методах
4. Сокрытие сложности

Пример правильной инкапсуляции:
class BankAccount {
private:
    double balance;  // скрыто
    
public:
    void deposit(double amount) {  // контролируемый доступ
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Неверная сумма!" << endl;
        }
    }
    
    double getBalance() {  // только чтение
        return balance;
    }
};

GETTERS И SETTERS:

Getters (геттеры) - методы для получения значений полей.
Setters (сеттеры) - методы для установки значений полей.

Пример:
class Person {
private:
    string name;
    int age;
    
public:
    // Getters (получение значений):
    string getName() {
        return name;
    }
    
    int getAge() {
        return age;
    }
    
    // Setters (установка значений):
    void setName(string n) {
        name = n;
    }
    
    void setAge(int a) {
        if (a >= 0 && a <= 150) {  // валидация
            age = a;
        } else {
            cout << "Неверный возраст!" << endl;
        }
    }
};

Преимущества:
- Контроль доступа к данным
- Валидация данных
- Возможность добавить логику при изменении
- Гибкость в изменении реализации

КОНСТАНТНЫЕ МЕТОДЫ:

Методы, которые не изменяют состояние объекта, должны быть const.

Синтаксис:
тип имя_метода() const {
    // код
}

Пример:
class Person {
private:
    string name;
    int age;
    
public:
    string getName() const {  // не изменяет объект
        return name;
    }
    
    int getAge() const {  // не изменяет объект
        return age;
    }
    
    void setName(string n) {  // изменяет объект (не const)
        name = n;
    }
};

Преимущества:
- Ясность намерений
- Возможность вызывать на const объектах
- Оптимизация компилятором

СТАТИЧЕСКИЕ ЧЛЕНЫ:

Статические члены принадлежат классу, а не объекту.

1. Статические поля:
   class Counter {
   private:
       static int count;  // общее для всех объектов
   public:
       Counter() { count++; }
       static int getCount() { return count; }
   };
   
   int Counter::count = 0;  // определение вне класса

2. Статические методы:
   class Math {
   public:
       static double pi() { return 3.14159; }
       static int max(int a, int b) { return (a > b) ? a : b; }
   };
   
   Использование:
   double p = Math::pi();  // вызов без объекта
   int m = Math::max(5, 3);

ВЛОЖЕННЫЕ КЛАССЫ:

Классы могут содержать другие классы.

Пример:
class Outer {
public:
    class Inner {
    public:
        void display() {
            cout << "Вложенный класс" << endl;
        }
    };
};

Использование:
Outer::Inner obj;
obj.display();

УКАЗАТЕЛИ НА ОБЪЕКТЫ:

Можно создавать указатели на объекты.

Пример:
Person* person = new Person("Иван", 25);
person->setName("Петр");
person->displayInfo();
delete person;  // не забудьте освободить память!

Массивы объектов:
Person people[10];  // массив из 10 объектов
people[0].setName("Иван");

Вектор объектов:
#include <vector>
vector<Person> people;
people.push_back(Person("Иван", 25));

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


















