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
применение всех изученных концепций C++:

1. КЛАССЫ И ОБЪЕКТЫ:
   - Класс Calculator для вычислений
   - Класс History для истории операций
   - Класс Menu для пользовательского интерфейса

2. НАСЛЕДОВАНИЕ И ПОЛИМОРФИЗМ:
   - Базовый класс Operation
   - Производные классы для различных операций
   - Виртуальные функции для вычислений

3. ШАБЛОНЫ:
   - Шаблонные функции для различных типов данных
   - Шаблонный класс для хранения истории

4. STL:
   - Контейнеры для хранения данных
   - Алгоритмы для обработки

5. ОБРАБОТКА ИСКЛЮЧЕНИЙ:
   - Обработка ошибок деления на ноль
   - Валидация пользовательского ввода
   - Обработка неверных операций

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





