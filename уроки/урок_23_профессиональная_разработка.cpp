/*
===========================================
УРОК 23: ПОДГОТОВКА К ПРОФЕССИОНАЛЬНОЙ РАЗРАБОТКЕ
===========================================

ЦЕЛИ УРОКА:
- Понять требования к профессиональным разработчикам
- Изучить карьерные возможности в C++
- Освоить навыки для работы в команде
- Научиться работать с современными инструментами
- Понять важность непрерывного обучения

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПОДГОТОВКА К ПРОФЕССИОНАЛЬНОЙ РАЗРАБОТКЕ:

1. ТРЕБОВАНИЯ К РАЗРАБОТЧИКАМ:
   - Глубокое понимание C++
   - Знание современных стандартов
   - Опыт работы с библиотеками
   - Навыки отладки и оптимизации
   - Понимание архитектуры систем

2. КАРЬЕРНЫЕ ВОЗМОЖНОСТИ:
   - Системный программист
   - Разработчик игр
   - Разработчик встраиваемых систем
   - Разработчик высокопроизводительных приложений
   - Архитектор программного обеспечения

3. НАВЫКИ ДЛЯ РАБОТЫ В КОМАНДЕ:
   - Коммуникация с коллегами
   - Работа с системами контроля версий
   - Code review и рефакторинг
   - Планирование и оценка задач
   - Документирование и презентация

4. СОВРЕМЕННЫЕ ИНСТРУМЕНТЫ:
   - IDE и редакторы кода
   - Системы сборки (CMake, Make)
   - Системы контроля версий (Git)
   - Инструменты тестирования
   - Профилировщики и отладчики

5. НЕПРЕРЫВНОЕ ОБУЧЕНИЕ:
   - Изучение новых стандартов C++
   - Освоение новых технологий
   - Участие в сообществе
   - Чтение технической литературы
   - Практика на реальных проектах

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <algorithm>
using namespace std;

// Пример профессионального кода
class DatabaseConnection {
private:
    string connectionString_;
    bool isConnected_;
    
public:
    DatabaseConnection(const string& connectionString) 
        : connectionString_(connectionString), isConnected_(false) {}
    
    bool connect() {
        // Симуляция подключения к базе данных
        isConnected_ = true;
        cout << "Подключение к базе данных установлено" << endl;
        return true;
    }
    
    void disconnect() {
        isConnected_ = false;
        cout << "Подключение к базе данных закрыто" << endl;
    }
    
    bool isConnected() const { return isConnected_; }
};

// Пример использования RAII
class DatabaseManager {
private:
    unique_ptr<DatabaseConnection> connection_;
    
public:
    DatabaseManager(const string& connectionString) {
        connection_ = make_unique<DatabaseConnection>(connectionString);
        connection_->connect();
    }
    
    ~DatabaseManager() {
        if (connection_) {
            connection_->disconnect();
        }
    }
    
    DatabaseConnection* getConnection() const {
        return connection_.get();
    }
};

// Пример оптимизированной функции
class PerformanceOptimizer {
public:
    // Оптимизированная сортировка с move semantics
    static void optimizedSort(vector<string>& data) {
        auto start = chrono::high_resolution_clock::now();
        
        sort(data.begin(), data.end());
        
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        
        cout << "Время сортировки: " << duration.count() << " микросекунд" << endl;
    }
    
    // Оптимизированный поиск
    static bool optimizedSearch(const vector<int>& data, int target) {
        return binary_search(data.begin(), data.end(), target);
    }
};

int main() {
    cout << "=== ПОДГОТОВКА К ПРОФЕССИОНАЛЬНОЙ РАЗРАБОТКЕ ===" << endl;
    
    // Демонстрация RAII
    cout << "\n=== ДЕМОНСТРАЦИЯ RAII ===" << endl;
    {
        DatabaseManager dbManager("localhost:3306");
        if (dbManager.getConnection()->isConnected()) {
            cout << "Работаем с базой данных..." << endl;
        }
    } // Автоматическое закрытие подключения
    
    // Демонстрация оптимизации производительности
    cout << "\n=== ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    vector<string> words = {"zebra", "apple", "banana", "cherry", "date"};
    
    cout << "Исходные слова: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    PerformanceOptimizer::optimizedSort(words);
    
    cout << "Отсортированные слова: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Демонстрация оптимизированного поиска
    vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15};
    int target = 7;
    
    if (PerformanceOptimizer::optimizedSearch(numbers, target)) {
        cout << "Число " << target << " найдено в отсортированном массиве" << endl;
    } else {
        cout << "Число " << target << " не найдено" << endl;
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Создание профессионального класса
Создай класс с профессиональными стандартами:
*/

class ProfessionalLogger {
private:
    string logFile_;
    bool isEnabled_;
    
public:
    ProfessionalLogger(const string& logFile) 
        : logFile_(logFile), isEnabled_(true) {}
    
    void log(const string& message) {
        if (isEnabled_) {
            cout << "[LOG] " << message << endl;
        }
    }
    
    void setEnabled(bool enabled) {
        isEnabled_ = enabled;
    }
    
    bool isEnabled() const {
        return isEnabled_;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ПРОФЕССИОНАЛЬНЫЙ ЛОГГЕР ===" << endl;
    
    ProfessionalLogger logger("app.log");
    
    logger.log("Приложение запущено");
    logger.log("Пользователь вошел в систему");
    logger.log("Выполняется операция");
    
    logger.setEnabled(false);
    logger.log("Это сообщение не будет показано");
    
    logger.setEnabled(true);
    logger.log("Логирование возобновлено");
}

/*
Упражнение 2: Работа с современными возможностями C++
Создай код с использованием современных возможностей:
*/

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ C++ ===" << endl;
    
    // Использование auto и range-based for
    vector<string> technologies = {"C++", "STL", "Templates", "RAII", "Smart Pointers"};
    
    cout << "Технологии C++:" << endl;
    for (const auto& tech : technologies) {
        cout << "- " << tech << endl;
    }
    
    // Использование лямбда-выражений
    auto isLongWord = [](const string& word) {
        return word.length() > 5;
    };
    
    auto longWords = count_if(technologies.begin(), technologies.end(), isLongWord);
    cout << "\nКоличество длинных слов: " << longWords << endl;
    
    // Использование умных указателей
    auto ptr = make_unique<string>("Динамическая строка");
    cout << "Содержимое умного указателя: " << *ptr << endl;
}

/*
Упражнение 3: Создание тестового кода
Создай код с тестированием:
*/

class Calculator {
public:
    static double add(double a, double b) {
        return a + b;
    }
    
    static double multiply(double a, double b) {
        return a * b;
    }
    
    static double divide(double a, double b) {
        if (b == 0) {
            throw invalid_argument("Деление на ноль");
        }
        return a / b;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ТЕСТИРОВАНИЕ КОДА ===" << endl;
    
    // Простые тесты
    cout << "Тестирование сложения:" << endl;
    cout << "2 + 3 = " << Calculator::add(2, 3) << " (ожидается 5)" << endl;
    
    cout << "Тестирование умножения:" << endl;
    cout << "4 * 5 = " << Calculator::multiply(4, 5) << " (ожидается 20)" << endl;
    
    cout << "Тестирование деления:" << endl;
    cout << "10 / 2 = " << Calculator::divide(10, 2) << " (ожидается 5)" << endl;
    
    cout << "Тестирование деления на ноль:" << endl;
    try {
        Calculator::divide(10, 0);
    } catch (const invalid_argument& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание портфолио
Создай портфолио с примерами кода:
- Различные проекты на C++
- Документация к коду
- Примеры тестирования
- Описание архитектуры

Задание 2: Изучение современных стандартов
Изучи новые возможности C++17 и C++20:
- Новые алгоритмы
- Улучшения в STL
- Новые возможности языка
- Практическое применение

Задание 3: Участие в сообществе
Присоединись к сообществу разработчиков C++:
- Форумы и чаты
- Open source проекты
- Конференции и встречи
- Обмен опытом

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Какие навыки нужны профессиональному разработчику?
2. Какие карьерные возможности есть в C++?
3. Как работать в команде разработчиков?
4. Какие инструменты используются в разработке?
5. Как продолжать обучение?
6. Что такое RAII?
7. Зачем нужны тесты?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Итоговое повторение
- Проверка знаний
- Планы на будущее
- Дополнительные ресурсы
- Заключение курса

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <chrono>
#include <algorithm>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 23: ПОДГОТОВКА К ПРОФЕССИОНАЛЬНОЙ РАЗРАБОТКЕ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ПРОФЕССИОНАЛЬНЫЙ ЛОГГЕР ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ C++ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ТЕСТИРОВАНИЕ КОДА ===" << endl;
    exercise3();
    
    return 0;
}





