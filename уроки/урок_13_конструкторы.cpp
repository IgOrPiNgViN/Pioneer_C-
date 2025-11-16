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

Конструкторы и деструкторы - это специальные функции класса, которые управляют
жизненным циклом объектов.

КОНСТРУКТОР (Constructor):

Конструктор - это специальная функция, которая вызывается автоматически при создании объекта.
Она инициализирует объект и подготавливает его к использованию.

Особенности конструкторов:
- Имя совпадает с именем класса
- Не имеет возвращаемого значения (даже void)
- Вызывается автоматически при создании объекта
- Может быть перегружен (несколько конструкторов)
- Может иметь параметры

ДЕСТРУКТОР (Destructor):

Деструктор - это специальная функция, которая вызывается автоматически при уничтожении объекта.
Она освобождает ресурсы, выделенные объектом.

Особенности деструкторов:
- Имя: ~ИмяКласса
- Не имеет параметров
- Не имеет возвращаемого значения
- Вызывается автоматически
- В классе может быть только один деструктор

ТИПЫ КОНСТРУКТОРОВ:

1. КОНСТРУКТОР ПО УМОЛЧАНИЮ (Default Constructor):

   Конструктор без параметров или с параметрами по умолчанию.
   
   Синтаксис:
   ClassName() {
       // инициализация
   }
   
   Пример:
   class Person {
   private:
       string name;
       int age;
   public:
       Person() {  // конструктор по умолчанию
           name = "Неизвестно";
           age = 0;
       }
   };
   
   Использование:
   Person person;  // вызывается конструктор по умолчанию
   
   Если конструктор не определен:
   - Компилятор создает конструктор по умолчанию автоматически
   - Но только если нет других конструкторов!
   
   Пример с параметрами по умолчанию:
   Person(string n = "Неизвестно", int a = 0) {
       name = n;
       age = a;
   }

2. ПАРАМЕТРИЗОВАННЫЙ КОНСТРУКТОР (Parameterized Constructor):

   Конструктор с параметрами для инициализации объекта.
   
   Синтаксис:
   ClassName(тип1 параметр1, тип2 параметр2, ...) {
       // инициализация полей
   }
   
   Пример:
   class Person {
   private:
       string name;
       int age;
   public:
       Person(string n, int a) {  // параметризованный конструктор
           name = n;
           age = a;
       }
   };
   
   Использование:
   Person person("Иван", 25);  // вызов с параметрами
   
   Преимущества:
   - Гарантированная инициализация
   - Удобство создания объектов
   - Невозможность создать неинициализированный объект

3. КОПИРУЮЩИЙ КОНСТРУКТОР (Copy Constructor):

   Конструктор, который создает объект как копию другого объекта.
   
   Синтаксис:
   ClassName(const ClassName& other) {
       // копирование полей
   }
   
   Пример:
   class Person {
   private:
       string name;
       int age;
   public:
       Person(const Person& other) {  // копирующий конструктор
           name = other.name;
           age = other.age;
       }
   };
   
   Использование:
   Person person1("Иван", 25);
   Person person2(person1);  // копирование через конструктор
   Person person3 = person1; // тоже копирование
   
   Когда вызывается:
   - При инициализации копией
   - При передаче объекта в функцию по значению
   - При возврате объекта из функции по значению
   
   Если не определен:
   - Компилятор создает копирующий конструктор автоматически
   - Просто копирует все поля (поверхностное копирование)

4. КОНСТРУКТОР ПЕРЕМЕЩЕНИЯ (Move Constructor, C++11):

   Конструктор, который "перемещает" ресурсы из одного объекта в другой.
   
   Синтаксис:
   ClassName(ClassName&& other) {
       // перемещение ресурсов
   }
   
   Пример:
   class Person {
   private:
       string name;
       int age;
   public:
       Person(Person&& other) {  // конструктор перемещения
           name = move(other.name);  // перемещение, а не копирование
           age = other.age;
       }
   };
   
   Использование:
   Person person1("Иван", 25);
   Person person2(move(person1));  // перемещение
   
   Преимущества:
   - Эффективность (избегает копирования)
   - Для больших объектов

СПИСОК ИНИЦИАЛИЗАЦИИ (Initializer List):

Список инициализации позволяет инициализировать поля напрямую, без присваивания.

Синтаксис:
ClassName(параметры) : поле1(значение1), поле2(значение2) {
    // тело конструктора
}

Пример:
class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {
        // поля уже инициализированы
    }
};

Преимущества списка инициализации:
1. Эффективность:
   - Поля инициализируются напрямую (без присваивания)
   - Для константных полей это единственный способ
   
2. Для константных полей:
   class Person {
   private:
       const int id;  // константное поле
       string name;
   public:
       Person(int i, string n) : id(i), name(n) {
           // id можно инициализировать только в списке!
       }
   };
   
3. Для ссылок:
   class Person {
   private:
       const string& nameRef;  // ссылка
   public:
       Person(const string& n) : nameRef(n) {
           // ссылку можно инициализировать только в списке!
       }
   };
   
4. Для объектов без конструктора по умолчанию:
   class Person {
   private:
       Date birthDate;  // если Date не имеет конструктора по умолчанию
   public:
       Person(Date d) : birthDate(d) {
           // инициализация через список
       }
   };

Порядок инициализации:
- Поля инициализируются в порядке ОБЪЯВЛЕНИЯ, а не в порядке списка!
- Рекомендация: Следуйте порядку объявления в списке инициализации

ПЕРЕГРУЗКА КОНСТРУКТОРОВ:

Можно иметь несколько конструкторов с разными параметрами.

Пример:
class Person {
private:
    string name;
    int age;
public:
    Person() {  // конструктор по умолчанию
        name = "Неизвестно";
        age = 0;
    }
    
    Person(string n) {  // конструктор с одним параметром
        name = n;
        age = 0;
    }
    
    Person(string n, int a) {  // конструктор с двумя параметрами
        name = n;
        age = a;
    }
};

Использование:
Person p1;              // вызов первого конструктора
Person p2("Иван");     // вызов второго конструктора
Person p3("Иван", 25); // вызов третьего конструктора

ДЕЛЕГИРУЮЩИЙ КОНСТРУКТОР (C++11):

Один конструктор может вызывать другой конструктор того же класса.

Синтаксис:
ClassName(параметры) : ClassName(другие_параметры) {
    // дополнительный код
}

Пример:
class Person {
private:
    string name;
    int age;
public:
    Person() : Person("Неизвестно", 0) {  // делегирует другому конструктору
        // дополнительный код
    }
    
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

ДЕСТРУКТОР:

Деструктор вызывается автоматически при уничтожении объекта.

Синтаксис:
~ClassName() {
    // освобождение ресурсов
}

Пример:
class Person {
private:
    string name;
    int* data;  // динамическая память
public:
    Person(string n) {
        name = n;
        data = new int[100];  // выделение памяти
    }
    
    ~Person() {  // деструктор
        delete[] data;  // освобождение памяти
        cout << "Объект уничтожен" << endl;
    }
};

Когда вызывается деструктор:
1. При выходе объекта из области видимости
2. При вызове delete для указателя
3. При завершении программы (для глобальных объектов)

Порядок вызова:
- Деструкторы вызываются в обратном порядке создания
- Сначала деструктор объекта, потом деструкторы полей

ПРАВИЛО ТРЕХ (Rule of Three):

Если класс управляет ресурсами, нужно определить:
1. Деструктор
2. Копирующий конструктор
3. Оператор присваивания

Пример:
class Resource {
private:
    int* data;
public:
    Resource() {
        data = new int[100];
    }
    
    ~Resource() {  // 1. Деструктор
        delete[] data;
    }
    
    Resource(const Resource& other) {  // 2. Копирующий конструктор
        data = new int[100];
        for (int i = 0; i < 100; i++) {
            data[i] = other.data[i];
        }
    }
    
    Resource& operator=(const Resource& other) {  // 3. Оператор присваивания
        if (this != &other) {
            delete[] data;
            data = new int[100];
            for (int i = 0; i < 100; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};

ПРАВИЛО ПЯТИ (C++11):

Добавляется к правилу трех:
4. Конструктор перемещения
5. Оператор перемещающего присваивания

КОНСТРУКТОРЫ И НАСЛЕДОВАНИЕ:

В производных классах конструкторы базового класса вызываются автоматически.

Пример:
class Base {
public:
    Base() {
        cout << "Конструктор Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Конструктор Derived" << endl;
    }
};

Порядок вызова:
1. Конструктор базового класса
2. Конструктор производного класса

Деструкторы вызываются в обратном порядке:
1. Деструктор производного класса
2. Деструктор базового класса

ЯВНЫЙ ВЫЗОВ КОНСТРУКТОРА БАЗОВОГО КЛАССА:
class Derived : public Base {
public:
    Derived() : Base() {  // явный вызов
        // код
    }
};

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


















