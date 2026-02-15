/*
===========================================
УРОК 25: ИТОГОВОЕ ПОВТОРЕНИЕ И ТЕСТИРОВАНИЕ
===========================================

ЦЕЛИ УРОКА:
- Повторить все изученные концепции C++
- Проверить понимание материала и знания по всем темам
- Закрепить знания на практике
- Выявить пробелы в понимании
- Оценить уровень подготовки
- Подготовиться к практическому применению
- Понять связи между различными темами
- Получить обратную связь по обучению

===========================================
ЧАСТЬ 1: ИТОГОВОЕ ПОВТОРЕНИЕ
===========================================

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ЗАЧЕМ НУЖНО ПОВТОРЕНИЕ:

1. Закрепление знаний: повторение помогает запомнить материал
2. Понимание связей: видеть, как концепции связаны между собой
3. Выявление пробелов: найти темы, которые нужно повторить
4. Подготовка к практике: уверенность в использовании знаний
5. Систематизация: упорядочивание изученного материала

1. ОСНОВЫ ЯЗЫКА:

а) ПЕРЕМЕННЫЕ И ТИПЫ ДАННЫХ:
   - Базовые типы (int, float, double, char, bool)
   - Модификаторы (const, static, volatile)
   - Инициализация переменных
   - Область видимости

б) ОПЕРАТОРЫ И ВЫРАЖЕНИЯ:
   - Арифметические, сравнения, логические операторы
   - Инкремент/декремент (++, --)

в) УСЛОВНЫЕ ОПЕРАТОРЫ И ЦИКЛЫ:
   - if, else if, else, switch
   - for, while, do-while
   - Range-based for (C++11)

г) ФУНКЦИИ:
   - Параметры (по значению, по ссылке, по указателю)
   - Перегрузка, рекурсия

2. СТРУКТУРЫ ДАННЫХ:

а) МАССИВЫ И СТРОКИ:
   - Одномерные и многомерные массивы
   - std::string вместо C-строк

б) УКАЗАТЕЛИ И ССЫЛКИ:
   - nullptr, умные указатели (C++11)

в) СТРУКТУРЫ:
   - Группировка данных

г) ДИНАМИЧЕСКАЯ ПАМЯТЬ:
   - new/delete, умные указатели

3. ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ:

а) КЛАССЫ И ОБЪЕКТЫ:
   - Инкапсуляция, getters и setters

б) НАСЛЕДОВАНИЕ:
   - public наследование, виртуальный деструктор

в) ПОЛИМОРФИЗМ:
   - Виртуальные функции, override, final

г) КОНСТРУКТОРЫ И ДЕСТРУКТОРЫ:
   - Правило трех/пяти

4. ПРОДВИНУТЫЕ ВОЗМОЖНОСТИ:

а) ПЕРЕГРУЗКА ОПЕРАТОРОВ
б) ШАБЛОНЫ ФУНКЦИЙ И КЛАССОВ
в) STL (vector, list, map, set, алгоритмы)
г) ОБРАБОТКА ИСКЛЮЧЕНИЙ

5. СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ:

а) ЛЯМБДА-ВЫРАЖЕНИЯ
б) auto и decltype
в) УМНЫЕ УКАЗАТЕЛИ (unique_ptr, shared_ptr)
г) MOVE SEMANTICS

СВЯЗИ МЕЖДУ КОНЦЕПЦИЯМИ:

1. Классы используют указатели для динамической памяти
2. Наследование использует виртуальные функции для полиморфизма
3. Шаблоны работают с STL контейнерами
4. Исключения обрабатывают ошибки в классах
5. Умные указатели управляют памятью в классах

===========================================
ЧАСТЬ 2: ТЕСТИРОВАНИЕ
===========================================

ФИНАЛЬНОЕ ТЕСТИРОВАНИЕ включает:

1. ТЕОРЕТИЧЕСКИЕ ВОПРОСЫ
2. ПРАКТИЧЕСКИЕ ЗАДАНИЯ (написание кода, отладка)
3. АНАЛИЗ КОДА (понимание, выявление ошибок)
4. ПРОЕКТНЫЕ ЗАДАНИЯ

СИНТАКСИС УРОКА (ключевые конструкции курса):

- Шаблоны классов: template<typename T> class SmartVector
- Перегрузка операторов: operator[], operator+=, operator<<
- Наследование и полиморфизм: virtual void makeSound() = 0; override
- Шаблонный класс: template<typename T> class Stack
- unique_ptr с полиморфизмом: vector<unique_ptr<Animal>>
- STL с лямбдами: sort(begin, end, [](a,b){ return a.length() < b.length(); })
- STL алгоритмы: copy_if, max_element, sort с greater<int>()
- Обработка исключений: try/catch, throw out_of_range, throw runtime_error
- function<bool(T,T)> для компараторов в методах

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

// ========== ЧАСТЬ 1: ПОВТОРЕНИЕ - Комплексный класс SmartVector ==========
template<typename T>
class SmartVector {
private:
    vector<T> data_;
    string name_;

public:
    SmartVector(const string& name = "SmartVector") : name_(name) {}
    SmartVector(const vector<T>& data, const string& name = "SmartVector")
        : data_(data), name_(name) {}

    ~SmartVector() {
        cout << "SmartVector '" << name_ << "' уничтожен" << endl;
    }

    void add(const T& value) {
        data_.push_back(value);
    }

    void remove(const T& value) {
        auto it = std::find(data_.begin(), data_.end(), value);
        if (it != data_.end()) {
            data_.erase(it);
        }
    }

    SmartVector& operator+=(const SmartVector& other) {
        for (const auto& value : other.data_) {
            data_.push_back(value);
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index >= data_.size()) {
            throw out_of_range("Индекс вне диапазона");
        }
        return data_[index];
    }

    const T& operator[](size_t index) const {
        if (index >= data_.size()) {
            throw out_of_range("Индекс вне диапазона");
        }
        return data_[index];
    }

    void display() const {
        cout << name_ << ": ";
        for (const auto& value : data_) {
            cout << value << " ";
        }
        cout << endl;
    }

    size_t size() const { return data_.size(); }
    bool empty() const { return data_.empty(); }
    const string& getName() const { return name_; }

    void sort() {
        std::sort(data_.begin(), data_.end());
    }

    void sort(function<bool(const T&, const T&)> comparator) {
        std::sort(data_.begin(), data_.end(), comparator);
    }

    bool contains(const T& value) const {
        return std::find(data_.begin(), data_.end(), value) != data_.end();
    }

    size_t findIndex(const T& value) const {
        auto it = std::find(data_.begin(), data_.end(), value);
        return (it != data_.end()) ? static_cast<size_t>(it - data_.begin()) : static_cast<size_t>(-1);
    }
};

void repetitionExamples() {
    cout << "=== ЧАСТЬ 1: ИТОГОВОЕ ПОВТОРЕНИЕ ===" << endl;

    cout << "\n--- SmartVector (шаблоны, операторы, исключения) ---" << endl;
    SmartVector<int> intVector("Целочисленный вектор");
    intVector.add(5);
    intVector.add(2);
    intVector.add(8);
    intVector.add(1);
    intVector.add(9);
    intVector.display();
    intVector.sort();
    cout << "После сортировки: ";
    intVector.display();
    if (intVector.contains(5)) {
        cout << "Элемент 5 найден на позиции " << intVector.findIndex(5) << endl;
    }
    try {
        cout << "Элемент с индексом 2: " << intVector[2] << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    cout << "\n--- SmartVector со строками (лямбды) ---" << endl;
    SmartVector<string> stringVector("Строковый вектор");
    stringVector.add("Hello");
    stringVector.add("World");
    stringVector.add("C++");
    stringVector.sort([](const string& a, const string& b) {
        return a.length() < b.length();
    });
    cout << "После сортировки по длине: ";
    stringVector.display();
}

// ========== ЧАСТЬ 2: ТЕСТИРОВАНИЕ - Наследование и полиморфизм ==========
class Animal {
protected:
    string name_;
    int age_;

public:
    Animal(const string& name, int age) : name_(name), age_(age) {}
    virtual ~Animal() = default;
    virtual void makeSound() = 0;
    virtual void displayInfo() const {
        cout << "Животное: " << name_ << ", возраст: " << age_ << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string& name, int age) : Animal(name, age) {}
    void makeSound() override {
        cout << name_ << " лает: Гав-гав!" << endl;
    }
    void displayInfo() const override {
        cout << "Собака: " << name_ << ", возраст: " << age_ << endl;
    }
};

class Cat : public Animal {
public:
    Cat(const string& name, int age) : Animal(name, age) {}
    void makeSound() override {
        cout << name_ << " мяукает: Мяу-мяу!" << endl;
    }
    void displayInfo() const override {
        cout << "Кошка: " << name_ << ", возраст: " << age_ << endl;
    }
};

// Шаблонный класс Stack
template<typename T>
class Stack {
private:
    vector<T> data_;

public:
    void push(const T& value) {
        data_.push_back(value);
    }
    T pop() {
        if (data_.empty()) {
            throw runtime_error("Стек пуст");
        }
        T value = data_.back();
        data_.pop_back();
        return value;
    }
    bool empty() const { return data_.empty(); }
    size_t size() const { return data_.size(); }
};

void testingExamples() {
    cout << "\n=== ЧАСТЬ 2: ТЕСТИРОВАНИЕ ===" << endl;

    cout << "\n--- Наследование и полиморфизм (unique_ptr) ---" << endl;
    vector<unique_ptr<Animal>> animals;
    animals.push_back(make_unique<Dog>("Бобик", 3));
    animals.push_back(make_unique<Cat>("Мурка", 2));
    for (const auto& animal : animals) {
        animal->displayInfo();
        animal->makeSound();
    }

    cout << "\n--- Шаблонный класс Stack ---" << endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    while (!intStack.empty()) {
        cout << intStack.pop() << " ";
    }
    cout << endl;

    cout << "\n--- STL алгоритмы (copy_if, max_element, sort) ---" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    vector<int> evenNumbers;
    copy_if(numbers.begin(), numbers.end(), back_inserter(evenNumbers),
            [](int n) { return n % 2 == 0; });
    cout << "Четные: ";
    for (int n : evenNumbers) cout << n << " ";
    cout << endl;
    cout << "Максимум: " << *max_element(numbers.begin(), numbers.end()) << endl;
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "По убыванию: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;
}

// ========== УПРАЖНЕНИЕ 1: Комплексные числа (перегрузка операторов) ==========
class ComplexNumber {
private:
    double real_;
    double imag_;

public:
    ComplexNumber(double real = 0, double imag = 0) : real_(real), imag_(imag) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real_ + other.real_, imag_ + other.imag_);
    }
    ComplexNumber operator-(const ComplexNumber& other) const {
        return ComplexNumber(real_ - other.real_, imag_ - other.imag_);
    }
    ComplexNumber operator*(const ComplexNumber& other) const {
        return ComplexNumber(real_ * other.real_ - imag_ * other.imag_,
                            real_ * other.imag_ + imag_ * other.real_);
    }

    friend ostream& operator<<(ostream& os, const ComplexNumber& c) {
        os << c.real_;
        if (c.imag_ >= 0) os << " + " << c.imag_ << "i";
        else os << " - " << (-c.imag_) << "i";
        return os;
    }

    double getMagnitude() const {
        return sqrt(real_ * real_ + imag_ * imag_);
    }
};

void exercise1() {
    cout << "\n=== УПРАЖНЕНИЕ 1: КОМПЛЕКСНЫЕ ЧИСЛА ===" << endl;
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);
    cout << "c1 = " << c1 << ", c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "Модуль c1: " << c1.getMagnitude() << endl;
}

// ========== УПРАЖНЕНИЕ 2: Система управления книгами (классы, STL) ==========
class Book {
private:
    string title_;
    string author_;
    int year_;
    bool isAvailable_;

public:
    Book(const string& title, const string& author, int year)
        : title_(title), author_(author), year_(year), isAvailable_(true) {}

    const string& getTitle() const { return title_; }
    const string& getAuthor() const { return author_; }
    int getYear() const { return year_; }
    bool isAvailable() const { return isAvailable_; }
    void setAvailable(bool available) { isAvailable_ = available; }

    void displayInfo() const {
        cout << "Книга: " << title_ << ", Автор: " << author_
             << ", Год: " << year_ << ", Доступна: " << (isAvailable_ ? "Да" : "Нет") << endl;
    }
};

class Library {
private:
    vector<Book> books_;

public:
    void addBook(const Book& book) {
        books_.push_back(book);
    }
    void removeBook(const string& title) {
        auto it = find_if(books_.begin(), books_.end(),
            [&title](const Book& book) { return book.getTitle() == title; });
        if (it != books_.end()) {
            books_.erase(it);
            cout << "Книга '" << title << "' удалена" << endl;
        } else {
            cout << "Книга '" << title << "' не найдена" << endl;
        }
    }
    void displayAllBooks() const {
        cout << "--- Все книги ---" << endl;
        for (const auto& book : books_) {
            book.displayInfo();
        }
    }
    void searchByAuthor(const string& author) const {
        cout << "--- Книги автора " << author << " ---" << endl;
        for (const auto& book : books_) {
            if (book.getAuthor() == author) book.displayInfo();
        }
    }
};

void exercise2() {
    cout << "\n=== УПРАЖНЕНИЕ 2: СИСТЕМА УПРАВЛЕНИЯ КНИГАМИ ===" << endl;
    Library library;
    library.addBook(Book("Война и мир", "Лев Толстой", 1869));
    library.addBook(Book("Евгений Онегин", "Александр Пушкин", 1833));
    library.addBook(Book("Мастер и Маргарита", "Михаил Булгаков", 1967));
    library.addBook(Book("Анна Каренина", "Лев Толстой", 1877));
    library.displayAllBooks();
    library.searchByAuthor("Лев Толстой");
    library.removeBook("Евгений Онегин");
    library.displayAllBooks();
}

// ========== УПРАЖНЕНИЕ 3: Обработка исключений ==========
void exercise3() {
    cout << "\n=== УПРАЖНЕНИЕ 3: ОБРАБОТКА ИСКЛЮЧЕНИЙ ===" << endl;
    try {
        vector<int> numbers = {1, 2, 3, 4, 5};
        int value = numbers.at(10);
        cout << "Значение: " << value << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка доступа: " << e.what() << endl;
        try {
            vector<int> numbers = {1, 2, 3, 4, 5};
            cout << "Элемент с индексом 2: " << numbers.at(2) << endl;
        } catch (const out_of_range& e2) {
            cout << "Ошибка: " << e2.what() << endl;
        }
    }
}

// ========== УПРАЖНЕНИЕ 4: Калькулятор с историей (исключения) ==========
class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) throw runtime_error("Деление на ноль");
        return a / b;
    }
};

class History {
private:
    vector<string> operations_;

public:
    void addOperation(const string& op) { operations_.push_back(op); }
    void displayHistory() const {
        cout << "--- История операций ---" << endl;
        for (const auto& op : operations_) cout << op << endl;
    }
};

void exercise4() {
    cout << "\n=== УПРАЖНЕНИЕ 4: КАЛЬКУЛЯТОР С ИСТОРИЕЙ ===" << endl;
    History history;
    try {
        double a = 10, b = 5;
        double result = Calculator::add(a, b);
        history.addOperation(to_string(a) + " + " + to_string(b) + " = " + to_string(result));
        result = Calculator::multiply(a, b);
        history.addOperation(to_string(a) + " * " + to_string(b) + " = " + to_string(result));
        result = Calculator::divide(a, b);
        history.addOperation(to_string(a) + " / " + to_string(b) + " = " + to_string(result));
        history.displayHistory();
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание итогового проекта
- Классы, наследование, полиморфизм
- Шаблоны, STL, обработка исключений

Задание 2: Написание тестов
- Unit тесты, интеграционные тесты
- Тесты на граничные случаи

Задание 3: Документирование кода
- Описание классов и методов
- Примеры использования

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Какие основные концепции C++ вы изучили?
2. Как связаны между собой различные темы?
3. Что было самым сложным для понимания?
4. Как вы планируете применять полученные знания?

ВРЕМЯ ИЗУЧЕНИЯ: 60-90 минут
ВРЕМЯ ПРАКТИКИ: 60-90 минут
ОБЩЕЕ ВРЕМЯ: 2-3 часа

===========================================
*/

int main() {
    cout << "=== УРОК 25: ИТОГОВОЕ ПОВТОРЕНИЕ И ТЕСТИРОВАНИЕ ===" << endl;

    repetitionExamples();
    testingExamples();

    exercise1();
    exercise2();
    exercise3();
    exercise4();

    return 0;
}
