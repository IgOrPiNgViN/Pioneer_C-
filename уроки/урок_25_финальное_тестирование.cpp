/*
===========================================
УРОК 25: ФИНАЛЬНОЕ ТЕСТИРОВАНИЕ
===========================================

ЦЕЛИ УРОКА:
- Проверить знания по всем изученным темам
- Выявить пробелы в понимании
- Оценить уровень подготовки
- Подготовиться к практическому применению
- Получить обратную связь по обучению

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ФИНАЛЬНОЕ ТЕСТИРОВАНИЕ:

Этот урок посвящен проверке знаний по всем изученным темам курса C++.
Тестирование включает в себя:

1. ТЕОРЕТИЧЕСКИЕ ВОПРОСЫ:
   - Основы языка C++
   - Объектно-ориентированное программирование
   - Шаблоны и STL
   - Обработка исключений
   - Современные возможности

2. ПРАКТИЧЕСКИЕ ЗАДАНИЯ:
   - Написание кода
   - Отладка программ
   - Оптимизация производительности
   - Создание архитектуры

3. АНАЛИЗ КОДА:
   - Понимание существующего кода
   - Выявление ошибок
   - Предложение улучшений
   - Рефакторинг

4. ПРОЕКТНЫЕ ЗАДАНИЯ:
   - Создание полноценных программ
   - Применение всех изученных концепций
   - Работа с реальными задачами

ПРИМЕРЫ ТЕСТОВЫХ ЗАДАНИЙ:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;

// ТЕСТОВОЕ ЗАДАНИЕ 1: Создание класса с наследованием
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

// ТЕСТОВОЕ ЗАДАНИЕ 2: Шаблонный класс
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
    
    T top() const {
        if (data_.empty()) {
            throw runtime_error("Стек пуст");
        }
        return data_.back();
    }
    
    bool empty() const {
        return data_.empty();
    }
    
    size_t size() const {
        return data_.size();
    }
};

// ТЕСТОВОЕ ЗАДАНИЕ 3: Работа с STL
class NumberProcessor {
public:
    static vector<int> filterEven(const vector<int>& numbers) {
        vector<int> result;
        copy_if(numbers.begin(), numbers.end(), back_inserter(result),
                [](int n) { return n % 2 == 0; });
        return result;
    }
    
    static int findMax(const vector<int>& numbers) {
        if (numbers.empty()) {
            throw invalid_argument("Вектор пуст");
        }
        return *max_element(numbers.begin(), numbers.end());
    }
    
    static void sortDescending(vector<int>& numbers) {
        sort(numbers.begin(), numbers.end(), greater<int>());
    }
};

int main() {
    cout << "=== ФИНАЛЬНОЕ ТЕСТИРОВАНИЕ ===" << endl;
    
    // Тест 1: Наследование и полиморфизм
    cout << "\n=== ТЕСТ 1: НАСЛЕДОВАНИЕ И ПОЛИМОРФИЗМ ===" << endl;
    vector<unique_ptr<Animal>> animals;
    animals.push_back(make_unique<Dog>("Бобик", 3));
    animals.push_back(make_unique<Cat>("Мурка", 2));
    
    for (const auto& animal : animals) {
        animal->displayInfo();
        animal->makeSound();
    }
    
    // Тест 2: Шаблоны
    cout << "\n=== ТЕСТ 2: ШАБЛОНЫ ===" << endl;
    Stack<int> intStack;
    Stack<string> stringStack;
    
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("C++");
    
    cout << "Целочисленный стек:" << endl;
    while (!intStack.empty()) {
        cout << intStack.pop() << " ";
    }
    cout << endl;
    
    cout << "Строковый стек:" << endl;
    while (!stringStack.empty()) {
        cout << stringStack.pop() << " ";
    }
    cout << endl;
    
    // Тест 3: STL и алгоритмы
    cout << "\n=== ТЕСТ 3: STL И АЛГОРИТМЫ ===" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    cout << "Исходные числа: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Фильтрация четных чисел
    auto evenNumbers = NumberProcessor::filterEven(numbers);
    cout << "Четные числа: ";
    for (int n : evenNumbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Поиск максимума
    try {
        int max = NumberProcessor::findMax(numbers);
        cout << "Максимальное число: " << max << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Сортировка по убыванию
    NumberProcessor::sortDescending(numbers);
    cout << "Отсортированные по убыванию: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Создание системы управления книгами
Создай систему управления книгами с использованием всех изученных концепций:
*/

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
        cout << "\n=== ВСЕ КНИГИ ===" << endl;
        for (const auto& book : books_) {
            book.displayInfo();
        }
    }
    
    void searchByAuthor(const string& author) const {
        cout << "\n=== КНИГИ АВТОРА " << author << " ===" << endl;
        bool found = false;
        for (const auto& book : books_) {
            if (book.getAuthor() == author) {
                book.displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "Книги автора не найдены" << endl;
        }
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: СИСТЕМА УПРАВЛЕНИЯ КНИГАМИ ===" << endl;
    
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

/*
Упражнение 2: Создание калькулятора с историей
Создай калькулятор с историей операций:
*/

class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Деление на ноль");
        }
        return a / b;
    }
};

class History {
private:
    vector<string> operations_;
    
public:
    void addOperation(const string& operation) {
        operations_.push_back(operation);
    }
    
    void displayHistory() const {
        cout << "\n=== ИСТОРИЯ ОПЕРАЦИЙ ===" << endl;
        for (const auto& op : operations_) {
            cout << op << endl;
        }
    }
    
    void clearHistory() {
        operations_.clear();
        cout << "История очищена" << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: КАЛЬКУЛЯТОР С ИСТОРИЕЙ ===" << endl;
    
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
Упражнение 3: Создание игры "Угадай число"
Создай игру "Угадай число" с использованием всех изученных концепций:
*/

class Game {
private:
    int secretNumber_;
    int maxAttempts_;
    int attempts_;
    bool isGameOver_;
    
public:
    Game(int maxAttempts = 7) : maxAttempts_(maxAttempts), attempts_(0), isGameOver_(false) {
        srand(time(0));
    }
    
    void startNewGame() {
        secretNumber_ = rand() % 100 + 1;
        attempts_ = 0;
        isGameOver_ = false;
        cout << "Новая игра! Угадайте число от 1 до 100" << endl;
        cout << "У вас " << maxAttempts_ << " попыток" << endl;
    }
    
    bool makeGuess(int guess) {
        if (isGameOver_) {
            cout << "Игра уже окончена!" << endl;
            return false;
        }
        
        attempts_++;
        
        if (guess == secretNumber_) {
            cout << "Поздравляем! Вы угадали число " << secretNumber_ << " за " << attempts_ << " попыток!" << endl;
            isGameOver_ = true;
            return true;
        } else if (guess < secretNumber_) {
            cout << "Загаданное число больше!" << endl;
        } else {
            cout << "Загаданное число меньше!" << endl;
        }
        
        if (attempts_ >= maxAttempts_) {
            cout << "Игра окончена! Загаданное число было " << secretNumber_ << endl;
            isGameOver_ = true;
        }
        
        return false;
    }
    
    bool isGameOver() const { return isGameOver_; }
    int getAttempts() const { return attempts_; }
    int getMaxAttempts() const { return maxAttempts_; }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ИГРА 'УГАДАЙ ЧИСЛО' ===" << endl;
    
    Game game(5);
    game.startNewGame();
    
    // Симуляция игры
    vector<int> guesses = {50, 75, 63, 69, 66};
    for (int guess : guesses) {
        cout << "Попытка " << game.getAttempts() + 1 << ": " << guess << endl;
        if (game.makeGuess(guess)) {
            break;
        }
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание итогового проекта
Создай итоговый проект, демонстрирующий все изученные концепции:
- Классы и объекты
- Наследование и полиморфизм
- Шаблоны
- STL
- Обработка исключений

Задание 2: Написание тестов
Напиши тесты для всех созданных классов:
- Unit тесты
- Интеграционные тесты
- Тесты производительности
- Тесты на граничные случаи

Задание 3: Документирование кода
Создай документацию для всех классов:
- Описание классов и методов
- Примеры использования
- Диаграммы архитектуры
- Руководство пользователя

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Какие основные концепции C++ вы изучили?
2. Как связаны между собой различные темы?
3. Какие навыки вы приобрели?
4. Что было самым сложным для понимания?
5. Какие темы требуют дополнительного изучения?
6. Как вы планируете применять полученные знания?
7. Что вы хотели бы изучить дополнительно?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Оценка результатов обучения
- Планы на будущее
- Дополнительные ресурсы
- Заключение курса
- Поздравления с завершением

ВРЕМЯ ИЗУЧЕНИЯ: 60-90 минут
ВРЕМЯ ПРАКТИКИ: 60-90 минут
ОБЩЕЕ ВРЕМЯ: 2-3 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 25: ФИНАЛЬНОЕ ТЕСТИРОВАНИЕ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: СИСТЕМА УПРАВЛЕНИЯ КНИГАМИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: КАЛЬКУЛЯТОР С ИСТОРИЕЙ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ИГРА 'УГАДАЙ ЧИСЛО' ===" << endl;
    exercise3();
    
    return 0;
}
























