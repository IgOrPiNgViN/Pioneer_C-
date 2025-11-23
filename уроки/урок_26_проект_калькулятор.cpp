/*
===========================================
УРОК 26: ПРОЕКТ "КАЛЬКУЛЯТОР"
===========================================

ЦЕЛИ УРОКА:
- Создать полноценный проект калькулятора
- Применить все изученные концепции C++
- Научиться проектировать архитектуру приложения
- Освоить работу с пользовательским интерфейсом
- Понять процесс разработки реальных программ

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПРОЕКТ "КАЛЬКУЛЯТОР":

Этот урок посвящен созданию полноценного проекта калькулятора, который демонстрирует
применение всех изученных концепций C++. Мы создадим калькулятор с историей операций,
различными математическими операциями и удобным пользовательским интерфейсом.

ОПИСАНИЕ ПРОЕКТА:

Калькулятор - это программа для выполнения математических вычислений. Наш калькулятор
будет поддерживать основные операции (сложение, вычитание, умножение, деление),
сохранять историю операций и предоставлять удобный интерфейс для работы.

АРХИТЕКТУРА ПРОЕКТА:

Проект состоит из нескольких классов, каждый из которых отвечает за свою часть функциональности:

1. КЛАСС Operation (базовый класс для операций):
   
   НАЗНАЧЕНИЕ:
   - Определяет общий интерфейс для всех математических операций
   - Хранит название и символ операции
   - Предоставляет виртуальные методы для вычислений
   
   ЗАЧЕМ НУЖЕН:
   - Единообразный интерфейс для всех операций
   - Возможность легко добавлять новые операции
   - Применение полиморфизма
   
   ФУНКЦИИ:
   - getName() - получение названия операции
   - getSymbol() - получение символа операции
   - calculate() - выполнение вычисления (чисто виртуальная)
   - getDescription() - описание операции

2. КЛАССЫ Addition, Subtraction, Multiplication, Division (производные классы):
   
   НАЗНАЧЕНИЕ:
   - Конкретные реализации математических операций
   - Каждый класс реализует свою операцию
   
   ЗАЧЕМ НУЖНЫ:
   - Инкапсуляция логики каждой операции
   - Легкое добавление новых операций
   - Разделение ответственности
   
   ФУНКЦИИ:
   - calculate() - выполняет конкретную операцию
   - getDescription() - возвращает описание операции
   
   ОСОБЕННОСТИ:
   - Division проверяет деление на ноль и выбрасывает исключение
   - Каждая операция имеет свой символ и название

3. КЛАСС History (история операций):
   
   НАЗНАЧЕНИЕ:
   - Хранение истории всех выполненных операций
   - Отображение истории пользователю
   - Управление историей (очистка)
   
   ЗАЧЕМ НУЖЕН:
   - Пользователь может видеть предыдущие вычисления
   - Возможность повторить операцию
   - Отладка и проверка работы
   
   ФУНКЦИИ:
   - addOperation() - добавление операции в историю
   - displayHistory() - отображение всей истории
   - clearHistory() - очистка истории
   - getSize() - получение количества операций
   
   РЕАЛИЗАЦИЯ:
   - Использует vector<string> для хранения операций
   - Каждая операция хранится как строка

4. КЛАСС Calculator (основной класс калькулятора):
   
   НАЗНАЧЕНИЕ:
   - Управление всеми операциями
   - Координация работы компонентов
   - Выполнение вычислений
   
   ЗАЧЕМ НУЖЕН:
   - Централизованное управление калькулятором
   - Связь между операциями и историей
   - Предоставление единого интерфейса
   
   ФУНКЦИИ:
   - displayMenu() - отображение меню операций
   - performOperation() - выполнение выбранной операции
   - showHistory() - показ истории
   - clearHistory() - очистка истории
   - showOperationDescription() - описание операции
   
   РЕАЛИЗАЦИЯ:
   - Хранит вектор умных указателей на операции (vector<unique_ptr<Operation>>)
   - Имеет объект History для хранения истории
   - Инициализирует все операции в конструкторе

5. КЛАСС Menu (пользовательский интерфейс):
   
   НАЗНАЧЕНИЕ:
   - Взаимодействие с пользователем
   - Обработка пользовательского ввода
   - Управление циклом работы программы
   
   ЗАЧЕМ НУЖЕН:
   - Удобный интерфейс для пользователя
   - Обработка ошибок ввода
   - Организация работы программы
   
   ФУНКЦИИ:
   - run() - главный цикл программы
   - Отображение меню
   - Обработка выбора пользователя
   - Ввод данных для вычислений
   
   РЕАЛИЗАЦИЯ:
   - Содержит объект Calculator
   - Использует цикл while для непрерывной работы
   - Обрабатывает исключения при вычислениях

ПРОЦЕСС СОЗДАНИЯ ПРОЕКТА:

ШАГ 1: ПЛАНИРОВАНИЕ АРХИТЕКТУРЫ

1. Определение требований:
   - Какие операции нужны (+, -, *, /)
   - Нужна ли история операций
   - Какой интерфейс (консольный)
   - Нужна ли валидация данных

2. Проектирование классов:
   - Базовый класс Operation для операций
   - Производные классы для каждой операции
   - Класс History для истории
   - Класс Calculator для управления
   - Класс Menu для интерфейса

3. Определение интерфейсов:
   - Какие методы нужны в каждом классе
   - Какие данные нужно хранить
   - Как классы будут взаимодействовать

ШАГ 2: СОЗДАНИЕ БАЗОВОГО КЛАССА Operation

1. Объявление класса:
   - Защищенные поля: name_, symbol_
   - Виртуальные методы: calculate(), getDescription()
   - Публичные методы: getName(), getSymbol()

2. Назначение:
   - Определяет контракт для всех операций
   - Позволяет использовать полиморфизм
   - Упрощает добавление новых операций

ШАГ 3: СОЗДАНИЕ ПРОИЗВОДНЫХ КЛАССОВ

1. Класс Addition:
   - Наследуется от Operation
   - Реализует calculate() для сложения
   - Возвращает a + b

2. Класс Subtraction:
   - Реализует вычитание
   - Возвращает a - b

3. Класс Multiplication:
   - Реализует умножение
   - Возвращает a * b

4. Класс Division:
   - Реализует деление
   - Проверяет деление на ноль
   - Выбрасывает исключение при ошибке

ШАГ 4: СОЗДАНИЕ КЛАССА History

1. Хранение данных:
   - vector<string> для хранения операций
   - Каждая операция как строка "a + b = result"

2. Функциональность:
   - Добавление операций
   - Отображение истории
   - Очистка истории

ШАГ 5: СОЗДАНИЕ КЛАССА Calculator

1. Инициализация:
   - В конструкторе создаются все операции
   - Сохраняются в vector<unique_ptr<Operation>>

2. Выполнение операций:
   - Получение операции по индексу
   - Вызов метода calculate()
   - Форматирование результата
   - Добавление в историю

3. Управление историей:
   - Делегирование методов History
   - Отображение истории пользователю

ШАГ 6: СОЗДАНИЕ КЛАССА Menu

1. Главный цикл:
   - Отображение меню
   - Ожидание выбора пользователя
   - Выполнение выбранного действия
   - Повтор до выхода

2. Обработка ввода:
   - Ввод чисел для вычислений
   - Валидация данных
   - Обработка ошибок

3. Обработка исключений:
   - Try-catch для вычислений
   - Сообщения об ошибках пользователю

СВЯЗИ МЕЖДУ КОМПОНЕНТАМИ:

1. Operation → Addition, Subtraction, Multiplication, Division:
   - Наследование
   - Полиморфизм через виртуальные функции

2. Calculator → Operation:
   - Хранение операций в векторе
   - Вызов методов через указатели

3. Calculator → History:
   - Композиция (Calculator содержит History)
   - Добавление операций в историю

4. Menu → Calculator:
   - Композиция (Menu содержит Calculator)
   - Использование методов Calculator

ПРЕИМУЩЕСТВА АРХИТЕКТУРЫ:

1. Расширяемость:
   - Легко добавить новую операцию (создать класс, наследовать от Operation)
   - Не нужно изменять существующий код

2. Модульность:
   - Каждый класс отвечает за свою задачу
   - Легко тестировать отдельные компоненты

3. Полиморфизм:
   - Единый интерфейс для всех операций
   - Легко работать с разными операциями одинаково

4. Инкапсуляция:
   - Детали реализации скрыты
   - Публичный интерфейс четко определен

ПРИМЕНЯЕМЫЕ КОНЦЕПЦИИ:

1. ООП:
   - Классы и объекты
   - Инкапсуляция данных
   - Наследование (Operation → конкретные операции)
   - Полиморфизм (виртуальные функции)

2. Умные указатели:
   - unique_ptr для управления операциями
   - Автоматическое управление памятью

3. STL:
   - vector для хранения операций и истории
   - string для работы со строками

4. Исключения:
   - Обработка деления на ноль
   - Валидация пользовательского ввода

5. Работа с файлами (расширение):
   - Сохранение истории в файл
   - Загрузка истории из файла

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <iomanip>
using namespace std;

// Базовый класс для операций
class Operation {
protected:
    string name_;
    string symbol_;
    
public:
    Operation(const string& name, const string& symbol) 
        : name_(name), symbol_(symbol) {}
    
    virtual ~Operation() = default;
    
    virtual double calculate(double a, double b) = 0;
    virtual string getDescription() const = 0;
    
    const string& getName() const { return name_; }
    const string& getSymbol() const { return symbol_; }
};

// Класс для операции сложения
class Addition : public Operation {
public:
    Addition() : Operation("Сложение", "+") {}
    
    double calculate(double a, double b) override {
        return a + b;
    }
    
    string getDescription() const override {
        return "Сложение двух чисел";
    }
};

// Класс для операции вычитания
class Subtraction : public Operation {
public:
    Subtraction() : Operation("Вычитание", "-") {}
    
    double calculate(double a, double b) override {
        return a - b;
    }
    
    string getDescription() const override {
        return "Вычитание второго числа из первого";
    }
};

// Класс для операции умножения
class Multiplication : public Operation {
public:
    Multiplication() : Operation("Умножение", "*") {}
    
    double calculate(double a, double b) override {
        return a * b;
    }
    
    string getDescription() const override {
        return "Умножение двух чисел";
    }
};

// Класс для операции деления
class Division : public Operation {
public:
    Division() : Operation("Деление", "/") {}
    
    double calculate(double a, double b) override {
        if (b == 0) {
            throw runtime_error("Деление на ноль!");
        }
        return a / b;
    }
    
    string getDescription() const override {
        return "Деление первого числа на второе";
    }
};

// Класс для истории операций
class History {
private:
    vector<string> operations_;
    
public:
    void addOperation(const string& operation) {
        operations_.push_back(operation);
    }
    
    void displayHistory() const {
        cout << "\n=== ИСТОРИЯ ОПЕРАЦИЙ ===" << endl;
        if (operations_.empty()) {
            cout << "История пуста" << endl;
            return;
        }
        
        for (size_t i = 0; i < operations_.size(); ++i) {
            cout << (i + 1) << ". " << operations_[i] << endl;
        }
    }
    
    void clearHistory() {
        operations_.clear();
        cout << "История очищена" << endl;
    }
    
    size_t getSize() const {
        return operations_.size();
    }
};

// Основной класс калькулятора
class Calculator {
private:
    vector<unique_ptr<Operation>> operations_;
    History history_;
    
public:
    Calculator() {
        // Инициализация операций
        operations_.push_back(make_unique<Addition>());
        operations_.push_back(make_unique<Subtraction>());
        operations_.push_back(make_unique<Multiplication>());
        operations_.push_back(make_unique<Division>());
    }
    
    void displayMenu() const {
        cout << "\n=== КАЛЬКУЛЯТОР ===" << endl;
        cout << "Доступные операции:" << endl;
        
        for (size_t i = 0; i < operations_.size(); ++i) {
            cout << (i + 1) << ". " << operations_[i]->getName() 
                 << " (" << operations_[i]->getSymbol() << ")" << endl;
        }
        
        cout << "5. Показать историю" << endl;
        cout << "6. Очистить историю" << endl;
        cout << "0. Выход" << endl;
    }
    
    void performOperation(int operationIndex, double a, double b) {
        if (operationIndex < 1 || operationIndex > static_cast<int>(operations_.size())) {
            throw invalid_argument("Неверный номер операции");
        }
        
        Operation* op = operations_[operationIndex - 1].get();
        double result = op->calculate(a, b);
        
        // Форматирование результата
        string operation = to_string(a) + " " + op->getSymbol() + " " + to_string(b) + " = " + to_string(result);
        
        cout << "\nРезультат: " << operation << endl;
        
        // Добавление в историю
        history_.addOperation(operation);
    }
    
    void showHistory() const {
        history_.displayHistory();
    }
    
    void clearHistory() {
        history_.clearHistory();
    }
    
    void showOperationDescription(int operationIndex) const {
        if (operationIndex < 1 || operationIndex > static_cast<int>(operations_.size())) {
            cout << "Неверный номер операции" << endl;
            return;
        }
        
        Operation* op = operations_[operationIndex - 1].get();
        cout << op->getName() << ": " << op->getDescription() << endl;
    }
};

// Класс для пользовательского интерфейса
class Menu {
private:
    Calculator calculator_;
    
public:
    void run() {
        int choice;
        double a, b;
        
        while (true) {
            calculator_.displayMenu();
            cout << "\nВыберите операцию: ";
            cin >> choice;
            
            if (choice == 0) {
                cout << "До свидания!" << endl;
                break;
            }
            
            switch (choice) {
                case 1:
                case 2:
                case 3:
                case 4:
                    try {
                        cout << "Введите первое число: ";
                        cin >> a;
                        cout << "Введите второе число: ";
                        cin >> b;
                        
                        calculator_.performOperation(choice, a, b);
                        
                    } catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                    break;
                    
                case 5:
                    calculator_.showHistory();
                    break;
                    
                case 6:
                    calculator_.clearHistory();
                    break;
                    
                default:
                    cout << "Неверный выбор!" << endl;
                    break;
            }
            
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
    }
};

int main() {
    cout << "=== ПРОЕКТ 'КАЛЬКУЛЯТОР' ===" << endl;
    
    Menu menu;
    menu.run();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Добавление новых операций
Добавь в калькулятор новые операции:
*/

class Power : public Operation {
public:
    Power() : Operation("Возведение в степень", "^") {}
    
    double calculate(double a, double b) override {
        return pow(a, b);
    }
    
    string getDescription() const override {
        return "Возведение первого числа в степень второго";
    }
};

class SquareRoot : public Operation {
public:
    SquareRoot() : Operation("Квадратный корень", "√") {}
    
    double calculate(double a, double b) override {
        if (a < 0) {
            throw runtime_error("Квадратный корень из отрицательного числа!");
        }
        return sqrt(a);
    }
    
    string getDescription() const override {
        return "Квадратный корень из первого числа";
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: НОВЫЕ ОПЕРАЦИИ ===" << endl;
    
    Calculator calc;
    
    // Добавление новых операций
    calc.addOperation(make_unique<Power>());
    calc.addOperation(make_unique<SquareRoot>());
    
    // Тестирование новых операций
    try {
        calc.performOperation(5, 2, 3); // 2^3 = 8
        calc.performOperation(6, 16, 0); // √16 = 4
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

/*
Упражнение 2: Улучшение пользовательского интерфейса
Улучши пользовательский интерфейс калькулятора:
*/

class ImprovedMenu : public Menu {
public:
    void run() override {
        int choice;
        double a, b;
        
        while (true) {
            displayWelcome();
            calculator_.displayMenu();
            cout << "\nВыберите операцию: ";
            
            if (!(cin >> choice)) {
                cout << "Неверный ввод! Пожалуйста, введите число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            if (choice == 0) {
                cout << "До свидания!" << endl;
                break;
            }
            
            if (choice >= 1 && choice <= 4) {
                if (getNumbers(a, b)) {
                    try {
                        calculator_.performOperation(choice, a, b);
                    } catch (const exception& e) {
                        cout << "Ошибка: " << e.what() << endl;
                    }
                }
            } else if (choice == 5) {
                calculator_.showHistory();
            } else if (choice == 6) {
                calculator_.clearHistory();
            } else {
                cout << "Неверный выбор!" << endl;
            }
            
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
    }
    
private:
    void displayWelcome() const {
        cout << "\n" << string(50, '=') << endl;
        cout << "           ДОБРО ПОЖАЛОВАТЬ В КАЛЬКУЛЯТОР" << endl;
        cout << string(50, '=') << endl;
    }
    
    bool getNumbers(double& a, double& b) {
        cout << "Введите первое число: ";
        if (!(cin >> a)) {
            cout << "Неверный ввод первого числа!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        
        cout << "Введите второе число: ";
        if (!(cin >> b)) {
            cout << "Неверный ввод второго числа!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return false;
        }
        
        return true;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    
    ImprovedMenu menu;
    menu.run();
}

/*
Упражнение 3: Добавление функций
Добавь в калькулятор математические функции:
*/

class SinFunction : public Operation {
public:
    SinFunction() : Operation("Синус", "sin") {}
    
    double calculate(double a, double b) override {
        return sin(a * M_PI / 180); // Преобразование в радианы
    }
    
    string getDescription() const override {
        return "Синус первого числа (в градусах)";
    }
};

class CosFunction : public Operation {
public:
    CosFunction() : Operation("Косинус", "cos") {}
    
    double calculate(double a, double b) override {
        return cos(a * M_PI / 180); // Преобразование в радианы
    }
    
    string getDescription() const override {
        return "Косинус первого числа (в градусах)";
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: МАТЕМАТИЧЕСКИЕ ФУНКЦИИ ===" << endl;
    
    Calculator calc;
    
    // Добавление математических функций
    calc.addOperation(make_unique<SinFunction>());
    calc.addOperation(make_unique<CosFunction>());
    
    // Тестирование функций
    try {
        calc.performOperation(7, 30, 0); // sin(30°) = 0.5
        calc.performOperation(8, 60, 0); // cos(60°) = 0.5
    } catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Расширение функциональности
Расширь калькулятор дополнительными возможностями:
- Поддержка констант (π, e)
- Работа с памятью (M+, M-, MR, MC)
- Поддержка скобок
- Работа с дробями

Задание 2: Графический интерфейс
Создай версию калькулятора с графическим интерфейсом:
- Использование библиотек GUI
- Кнопки для операций
- Поле для ввода и вывода
- История операций

Задание 3: Научный калькулятор
Создай научный калькулятор с расширенными функциями:
- Логарифмы
- Тригонометрические функции
- Статистические функции
- Конвертация единиц измерения

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Как применить ООП в проекте калькулятора?
2. Какие паттерны проектирования использованы?
3. Как обрабатывать ошибки в калькуляторе?
4. Как организовать пользовательский интерфейс?
5. Как расширить функциональность калькулятора?
6. Какие тесты нужны для калькулятора?
7. Как оптимизировать производительность?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Проект "Игра Угадай число"
- Создание игрового приложения
- Работа с случайными числами
- Пользовательский интерфейс игры
- Сохранение результатов

ВРЕМЯ ИЗУЧЕНИЯ: 60-90 минут
ВРЕМЯ ПРАКТИКИ: 60-90 минут
ОБЩЕЕ ВРЕМЯ: 2-3 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 26: ПРОЕКТ 'КАЛЬКУЛЯТОР' ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: НОВЫЕ ОПЕРАЦИИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: МАТЕМАТИЧЕСКИЕ ФУНКЦИИ ===" << endl;
    exercise3();
    
    return 0;
}
























