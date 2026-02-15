/*
===========================================
УРОК 21: ОБРАБОТКА ИСКЛЮЧЕНИЙ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию исключений
- Изучить блоки try-catch
- Освоить создание собственных исключений
- Научиться обрабатывать различные типы ошибок
- Понять лучшие практики обработки ошибок

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ИСКЛЮЧЕНИЯ В C++:

Исключение (exception) - это механизм обработки ошибок, который позволяет
передавать информацию об ошибке из места возникновения в место обработки.

ЗАЧЕМ НУЖНЫ ИСКЛЮЧЕНИЯ:

1. Разделение нормального кода и обработки ошибок
2. Передача ошибок через уровни вызовов функций
3. Автоматическая очистка ресурсов (RAII)
4. Типобезопасная обработка ошибок

МЕХАНИЗМ ОБРАБОТКИ ИСКЛЮЧЕНИЙ:

1. TRY - блок кода, в котором могут возникнуть исключения:
   try {
       // код, который может вызвать исключение
   }

2. THROW - оператор для генерации исключения:
   throw исключение;

3. CATCH - блок кода для обработки исключений:
   catch (тип_исключения переменная) {
       // обработка исключения
   }

ПОЛНЫЙ СИНТАКСИС:

try {
    // код, который может вызвать исключение
    if (условие_ошибки) {
        throw исключение;
    }
} catch (тип_исключения переменная) {
    // обработка исключения
}

СТАНДАРТНЫЕ ИСКЛЮЧЕНИЯ:

1. std::exception - базовый класс для всех исключений
2. std::runtime_error - ошибки времени выполнения
3. std::logic_error - логические ошибки
4. std::invalid_argument - неверные аргументы
5. std::out_of_range - выход за границы
6. std::bad_alloc - ошибка выделения памяти

ОСОБЕННОСТИ:

1. Можно обрабатывать несколько типов исключений
2. Можно использовать catch(...) для всех исключений
3. Исключения могут быть вложенными
4. Можно перебрасывать исключения (rethrow)

СИНТАКСИС УРОКА:

1. Блок try-catch:
   try {
       // код, который может вызвать ошибку
   } catch (тип_исключения& e) {
       // обработка ошибки
   }

2. Выброс исключения:
   throw runtime_error("сообщение");
   throw invalid_argument("сообщение");

3. Несколько catch:
   try { ... }
   catch (runtime_error& e) { ... }
   catch (exception& e) { ... }
   catch (...) { /* любое исключение */ }

4. Пользовательское исключение:
   class MyError : public exception {
   public:
       const char* what() const noexcept override {
           return "описание ошибки";
       }
   };

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

// Функция для деления с проверкой
double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Деление на ноль!");
    }
    return a / b;
}

// Функция для доступа к элементу массива
int getElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс вне диапазона!");
    }
    return arr[index];
}

// Функция для вычисления факториала
long long factorial(int n) {
    if (n < 0) {
        throw invalid_argument("Факториал отрицательного числа не определен!");
    }
    if (n > 20) {
        throw overflow_error("Слишком большое число для факториала!");
    }
    
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

void examples() {
    cout << "=== ДЕМОНСТРАЦИЯ ОБРАБОТКИ ИСКЛЮЧЕНИЙ ===" << endl;
    
    // Обработка деления на ноль
    cout << "\n=== ОБРАБОТКА ДЕЛЕНИЯ НА НОЛЬ ===" << endl;
    try {
        double result = divide(10, 0);
        cout << "Результат: " << result << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Обработка выхода за границы массива
    cout << "\n=== ОБРАБОТКА ВЫХОДА ЗА ГРАНИЦЫ ===" << endl;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    try {
        int value = getElement(arr, size, 10);
        cout << "Значение: " << value << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Обработка факториала
    cout << "\n=== ОБРАБОТКА ФАКТОРИАЛА ===" << endl;
    try {
        long long result = factorial(-5);
        cout << "Факториал: " << result << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    try {
        long long result = factorial(25);
        cout << "Факториал: " << result << endl;
    } catch (const overflow_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Обработка нескольких типов исключений
    cout << "\n=== ОБРАБОТКА НЕСКОЛЬКИХ ТИПОВ ===" << endl;
    try {
        double result = divide(10, 2);
        cout << "Результат деления: " << result << endl;
        
        int value = getElement(arr, size, 2);
        cout << "Значение элемента: " << value << endl;
        
        long long fact = factorial(5);
        cout << "Факториал: " << fact << endl;
    } catch (const runtime_error& e) {
        cout << "Ошибка времени выполнения: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка диапазона: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка аргумента: " << e.what() << endl;
    } catch (const overflow_error& e) {
        cout << "Ошибка переполнения: " << e.what() << endl;
    } catch (...) {
        cout << "Неизвестная ошибка!" << endl;
    }
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Создание собственного класса исключения
Создай собственный класс исключения для работы с банковским счетом:
*/

class InsufficientFundsException : public exception {
private:
    double balance;
    double amount;
    
public:
    InsufficientFundsException(double bal, double amt) : balance(bal), amount(amt) {}
    
    const char* what() const noexcept override {
        static string message = "Недостаточно средств! Баланс: " + 
                               to_string(balance) + ", Попытка снять: " + 
                               to_string(amount);
        return message.c_str();
    }
};

class BankAccount {
private:
    double balance;
    
public:
    BankAccount(double initialBalance) : balance(initialBalance) {}
    
    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Сумма должна быть положительной!");
        }
        if (amount > balance) {
            throw InsufficientFundsException(balance, amount);
        }
        balance -= amount;
        cout << "Снято: " << amount << ", Баланс: " << balance << endl;
    }
    
    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Сумма должна быть положительной!");
        }
        balance += amount;
        cout << "Внесено: " << amount << ", Баланс: " << balance << endl;
    }
    
    double getBalance() const {
        return balance;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: БАНКОВСКИЙ СЧЕТ ===" << endl;
    
    BankAccount account(1000.0);
    
    try {
        account.deposit(500.0);
        account.withdraw(200.0);
        account.withdraw(2000.0); // Это вызовет исключение
    } catch (const InsufficientFundsException& e) {
        cout << "Ошибка: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

/*
Упражнение 2: Обработка исключений при работе с файлами
Создай программу для работы с файлами с обработкой исключений:
*/

#include <fstream>

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: РАБОТА С ФАЙЛАМИ ===" << endl;
    
    try {
        // Попытка открыть несуществующий файл
        ifstream file("nonexistent.txt");
        if (!file.is_open()) {
            throw runtime_error("Не удалось открыть файл!");
        }
        
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
        
        // Попытка создать новый файл
        try {
            ofstream newFile("test.txt");
            if (!newFile.is_open()) {
                throw runtime_error("Не удалось создать файл!");
            }
            
            newFile << "Это тестовый файл" << endl;
            newFile << "Создан для демонстрации" << endl;
            newFile.close();
            
            cout << "Файл test.txt создан успешно!" << endl;
            
        } catch (const runtime_error& e) {
            cout << "Ошибка создания файла: " << e.what() << endl;
        }
    }
}

/*
Упражнение 3: Обработка исключений при работе с динамической памятью
Создай программу для работы с динамической памятью с обработкой исключений:
*/

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ДИНАМИЧЕСКАЯ ПАМЯТЬ ===" << endl;
    
    try {
        // Попытка выделить очень большой блок памяти
        size_t size = 1000000000000ULL; // 1 терабайт
        int* largeArray = new int[size];
        
        cout << "Память выделена успешно!" << endl;
        delete[] largeArray;
        
    } catch (const bad_alloc& e) {
        cout << "Ошибка выделения памяти: " << e.what() << endl;
        
        // Попытка выделить меньший блок
        try {
            size_t smallerSize = 1000000; // 1 мегабайт
            int* smallerArray = new int[smallerSize];
            
            cout << "Меньший блок памяти выделен успешно!" << endl;
            delete[] smallerArray;
            
        } catch (const bad_alloc& e) {
            cout << "Ошибка выделения меньшего блока: " << e.what() << endl;
        }
    }
}

/*
Упражнение 4: Обработка исключений при работе с контейнерами
Создай программу для работы с контейнерами STL с обработкой исключений:
*/

void exercise4() {
    cout << "=== УПРАЖНЕНИЕ 4: КОНТЕЙНЕРЫ STL ===" << endl;
    
    vector<int> numbers = {1, 2, 3, 4, 5};
    
    try {
        // Попытка доступа к несуществующему элементу
        int value = numbers.at(10);
        cout << "Значение: " << value << endl;
        
    } catch (const out_of_range& e) {
        cout << "Ошибка доступа к элементу: " << e.what() << endl;
        
        // Попытка доступа к существующему элементу
        try {
            int value = numbers.at(2);
            cout << "Значение элемента с индексом 2: " << value << endl;
            
        } catch (const out_of_range& e) {
            cout << "Ошибка доступа к существующему элементу: " << e.what() << endl;
        }
    }
    
    // Обработка исключений при работе с пустым контейнером
    try {
        vector<int> emptyVector;
        int firstElement = emptyVector.front();
        cout << "Первый элемент: " << firstElement << endl;
        
    } catch (const runtime_error& e) {
        cout << "Ошибка доступа к пустому контейнеру: " << e.what() << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Система управления студентами с обработкой исключений
Создай программу для управления студентами с обработкой исключений:
- Проверка корректности данных
- Обработка ошибок при работе с файлами
- Валидация оценок и возрастов

Задание 2: Калькулятор с обработкой исключений
Создай калькулятор с обработкой исключений:
- Деление на ноль
- Неверные операции
- Переполнение при вычислениях
- Неверный формат ввода

Задание 3: Система управления задачами с обработкой исключений
Создай систему управления задачами с обработкой исключений:
- Проверка корректности дат
- Обработка ошибок при сохранении
- Валидация приоритетов и статусов

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое исключение?
2. Как работает механизм try-catch?
3. Что такое оператор throw?
4. Какие стандартные исключения есть в C++?
5. Как создать собственное исключение?
6. Что такое catch(...)?
7. Зачем нужна обработка исключений?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Практические проекты
- Создание полноценных программ
- Применение всех изученных концепций
- Разработка реальных приложений
- Тестирование и отладка

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

int main() {
    cout << "=== УРОК 21: ОБРАБОТКА ИСКЛЮЧЕНИЙ ===" << endl;
    
    examples();
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: БАНКОВСКИЙ СЧЕТ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: РАБОТА С ФАЙЛАМИ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ДИНАМИЧЕСКАЯ ПАМЯТЬ ===" << endl;
    exercise3();
    
    cout << "\n=== УПРАЖНЕНИЕ 4: КОНТЕЙНЕРЫ STL ===" << endl;
    exercise4();
    
    return 0;
}
























