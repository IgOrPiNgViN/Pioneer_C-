/*
===========================================
УРОК 24: ЛУЧШИЕ ПРАКТИКИ И ПРОФЕССИОНАЛЬНАЯ РАЗРАБОТКА
===========================================

ЦЕЛИ УРОКА:
- Изучить лучшие практики программирования
- Понять принципы чистого кода
- Освоить стиль кодирования
- Научиться оптимизировать производительность
- Понять важность документирования
- Понять требования к профессиональным разработчикам
- Изучить карьерные возможности в C++
- Освоить навыки для работы в команде
- Научиться работать с современными инструментами
- Понять важность непрерывного обучения

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

=== ЧАСТЬ 1: ЛУЧШИЕ ПРАКТИКИ ПРОГРАММИРОВАНИЯ ===

Следование лучшим практикам программирования делает код более читаемым,
поддерживаемым и надежным. Это важно как для личных проектов, так и для
работы в команде.

ЗАЧЕМ НУЖНЫ ЛУЧШИЕ ПРАКТИКИ:

1. Читаемость: код легче понимать
2. Поддерживаемость: легче вносить изменения
3. Надежность: меньше ошибок
4. Эффективность: лучшая производительность
5. Совместимость: работа в команде

1. ПРИНЦИПЫ ЧИСТОГО КОДА:

а) ЧИТАЕМОСТЬ КОДА:
   - Понятные имена переменных и функций
   - Логичная структура
   - Правильное форматирование
   - Отсутствие "магических чисел"
   
   Плохо:
   int x = 5;
   if (x > 3) { ... }
   
   Хорошо:
   const int MIN_AGE = 18;
   if (age >= MIN_AGE) { ... }

б) ПРОСТОТА И ЯСНОСТЬ:
   - Простые решения предпочтительнее сложных
   - Один способ делать одно дело
   - Избегайте преждевременной оптимизации
   
   Плохо:
   int result = (a > b) ? ((c > d) ? a : c) : ((e > f) ? b : e);
   
   Хорошо:
   int result = a;
   if (b > result) result = b;
   if (c > result) result = c;

в) ЕДИНСТВЕННАЯ ОТВЕТСТВЕННОСТЬ (Single Responsibility Principle):
   - Класс должен иметь одну причину для изменения
   - Функция должна делать одну вещь
   - Модуль должен решать одну задачу
   
   Плохо:
   class Student {
       void saveToFile();
       void calculateAverage();
       void sendEmail();
   };
   
   Хорошо:
   class Student { ... };
   class FileManager { void save(Student& s); };
   class Calculator { double average(vector<Student>&); };
   class EmailService { void send(Student& s); };

г) DRY (Don't Repeat Yourself):
   - Не повторяйте код
   - Используйте функции и классы
   - Выносите общую логику
   
   Плохо:
   cout << "Студент: " << name1 << ", Оценка: " << grade1 << endl;
   cout << "Студент: " << name2 << ", Оценка: " << grade2 << endl;
   
   Хорошо:
   void printStudent(const string& name, double grade) {
       cout << "Студент: " << name << ", Оценка: " << grade << endl;
   }

2. СТИЛЬ КОДИРОВАНИЯ:

а) ЕДИНООБРАЗНОЕ ИМЕНОВАНИЕ:
   - Выберите стиль и следуйте ему
   - camelCase, snake_case, PascalCase
   - Константы: UPPER_CASE
   - Приватные поля: с префиксом или суффиксом
   
   Примеры:
   int studentAge;           // camelCase
   int student_age;         // snake_case
   int StudentAge;          // PascalCase
   const int MAX_AGE = 100; // константа

б) ПРАВИЛЬНОЕ ФОРМАТИРОВАНИЕ:
   - Единообразные отступы
   - Пробелы вокруг операторов
   - Выравнивание фигурных скобок
   - Длина строк (обычно 80-120 символов)
   
   Пример:
   if (condition) {
       // код
   } else {
       // код
   }

в) КОММЕНТАРИИ И ДОКУМЕНТАЦИЯ:
   - Комментируйте "почему", а не "что"
   - Используйте понятные комментарии
   - Документируйте публичные интерфейсы
   - Избегайте избыточных комментариев
   
   Плохо:
   int x = 5;  // присваиваем 5
   
   Хорошо:
   const int DEFAULT_TIMEOUT = 5;  // время ожидания по умолчанию в секундах

г) СТРУКТУРА ПРОЕКТА:
   - Логичная организация файлов
   - Разделение на модули
   - Заголовочные и исходные файлы
   - Папки для разных компонентов

3. ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ:

а) ПРОФИЛИРОВАНИЕ КОДА:
   - Измеряйте производительность
   - Находите узкие места
   - Оптимизируйте только критичные части
   - Не оптимизируйте преждевременно

б) ЭФФЕКТИВНЫЕ АЛГОРИТМЫ:
   - Выбирайте правильные структуры данных
   - Используйте подходящие алгоритмы
   - Учитывайте сложность O(n)
   - Используйте STL алгоритмы

в) УПРАВЛЕНИЕ ПАМЯТЬЮ:
   - Используйте умные указатели
   - Избегайте утечек памяти
   - Минимизируйте выделение памяти
   - Используйте move semantics

г) КЭШИРОВАНИЕ:
   - Кэшируйте результаты вычислений
   - Используйте мемоизацию
   - Оптимизируйте доступ к данным

4. ОТЛАДКА И ТЕСТИРОВАНИЕ:

а) СИСТЕМАТИЧЕСКИЙ ПОДХОД:
   - Воспроизводите ошибку
   - Изолируйте проблему
   - Используйте отладчик
   - Проверяйте предположения

б) UNIT ТЕСТИРОВАНИЕ:
   - Тестируйте отдельные функции
   - Покрывайте граничные случаи
   - Автоматизируйте тесты
   - Используйте фреймворки (Google Test, Catch2)

в) ИНТЕГРАЦИОННОЕ ТЕСТИРОВАНИЕ:
   - Тестируйте взаимодействие компонентов
   - Проверяйте сценарии использования
   - Тестируйте с реальными данными

г) ОТЛАДКА С ПОМОЩЬЮ ИНСТРУМЕНТОВ:
   - Отладчики (GDB, Visual Studio Debugger)
   - Профилировщики (Valgrind, perf)
   - Статические анализаторы
   - Sanitizers (AddressSanitizer, MemorySanitizer)

5. УПРАВЛЕНИЕ ВЕРСИЯМИ:

а) GIT И СИСТЕМЫ КОНТРОЛЯ ВЕРСИЙ:
   - Отслеживание изменений
   - История разработки
   - Откат изменений
   - Резервное копирование

б) ВЕТВЛЕНИЕ И СЛИЯНИЕ:
   - Работа над разными функциями в ветках
   - Слияние изменений
   - Разрешение конфликтов
   - Code review

в) КОММИТЫ И ТЕГИ:
   - Понятные сообщения коммитов
   - Логичные коммиты (одна задача - один коммит)
   - Теги для версий
   - Changelog

г) СОВМЕСТНАЯ РАБОТА:
   - Согласованные стандарты кодирования
   - Code review процесс
   - Документирование изменений
   - Коммуникация в команде

ДОПОЛНИТЕЛЬНЫЕ РЕКОМЕНДАЦИИ:

1. Используйте const где возможно
2. Избегайте глобальных переменных
3. Инициализируйте переменные
4. Проверяйте границы массивов
5. Обрабатывайте ошибки
6. Используйте исключения для ошибок
7. Избегайте сырых указателей
8. Используйте RAII (Resource Acquisition Is Initialization)
9. Следуйте правилу трех/пяти
10. Документируйте публичные API

=== ЧАСТЬ 2: ПРОФЕССИОНАЛЬНАЯ РАЗРАБОТКА ===

Переход от изучения C++ к профессиональной разработке требует не только
технических знаний, но и понимания процессов разработки, работы в команде
и использования современных инструментов.

ЗАЧЕМ НУЖНА ПОДГОТОВКА:

1. Реальные проекты: работа над большими системами
2. Командная работа: взаимодействие с другими разработчиками
3. Процессы разработки: понимание жизненного цикла проекта
4. Инструменты: эффективное использование инструментов разработки
5. Карьерный рост: развитие профессиональных навыков

1. ТРЕБОВАНИЯ К РАЗРАБОТЧИКАМ:

а) ГЛУБОКОЕ ПОНИМАНИЕ C++:
   - Знание всех основных концепций
   - Понимание работы компилятора
   - Знание стандартной библиотеки
   - Понимание управления памятью
   - Знание шаблонов и метапрограммирования

б) ЗНАНИЕ СОВРЕМЕННЫХ СТАНДАРТОВ:
   - C++11/14/17/20 возможности
   - Лучшие практики
   - Идиомы C++
   - Паттерны проектирования

в) ОПЫТ РАБОТЫ С БИБЛИОТЕКАМИ:
   - STL (Standard Template Library)
   - Boost
   - Специализированные библиотеки
   - Работа с API

г) НАВЫКИ ОТЛАДКИ И ОПТИМИЗАЦИИ:
   - Использование отладчиков
   - Профилирование кода
   - Поиск утечек памяти
   - Оптимизация производительности

д) ПОНИМАНИЕ АРХИТЕКТУРЫ СИСТЕМ:
   - Проектирование систем
   - Масштабируемость
   - Безопасность
   - Производительность

2. КАРЬЕРНЫЕ ВОЗМОЖНОСТИ:

а) СИСТЕМНЫЙ ПРОГРАММИСТ:
   - Разработка операционных систем
   - Драйверы устройств
   - Системные утилиты
   - Низкоуровневое программирование

б) РАЗРАБОТЧИК ИГР:
   - Игровые движки
   - Физика и графика
   - Оптимизация производительности
   - Работа с графическими библиотеками

в) РАЗРАБОТЧИК ВСТРАИВАЕМЫХ СИСТЕМ:
   - Микроконтроллеры
   - IoT устройства
   - Автомобильная электроника
   - Оптимизация ресурсов

г) РАЗРАБОТЧИК ВЫСОКОПРОИЗВОДИТЕЛЬНЫХ ПРИЛОЖЕНИЙ:
   - Финансовые системы
   - Научные вычисления
   - Торговые платформы
   - Базы данных

д) АРХИТЕКТОР ПРОГРАММНОГО ОБЕСПЕЧЕНИЯ:
   - Проектирование архитектуры
   - Техническое руководство
   - Принятие решений
   - Планирование развития

3. НАВЫКИ ДЛЯ РАБОТЫ В КОМАНДЕ:

а) КОММУНИКАЦИЯ С КОЛЛЕГАМИ:
   - Четкое выражение идей
   - Активное слушание
   - Конструктивная обратная связь
   - Разрешение конфликтов

б) РАБОТА С СИСТЕМАМИ КОНТРОЛЯ ВЕРСИЙ:
   - Git workflow
   - Ветвление стратегии
   - Code review процесс
   - Управление конфликтами

в) CODE REVIEW И РЕФАКТОРИНГ:
   - Анализ чужого кода
   - Предложение улучшений
   - Рефакторинг legacy кода
   - Поддержание качества кода

г) ПЛАНИРОВАНИЕ И ОЦЕНКА ЗАДАЧ:
   - Разбиение на подзадачи
   - Оценка времени
   - Приоритизация
   - Отслеживание прогресса

д) ДОКУМЕНТИРОВАНИЕ И ПРЕЗЕНТАЦИЯ:
   - Техническая документация
   - Презентация решений
   - Обучение коллег
   - Документирование API

4. СОВРЕМЕННЫЕ ИНСТРУМЕНТЫ:

а) IDE И РЕДАКТОРЫ КОДА:
   - Visual Studio / Visual Studio Code
   - CLion
   - Qt Creator
   - Vim / Emacs
   
   Возможности:
   - Автодополнение
   - Рефакторинг
   - Отладка
   - Интеграция с Git

б) СИСТЕМЫ СБОРКИ:
   - CMake - кроссплатформенная система сборки
   - Make - традиционная система сборки
   - Ninja - быстрая система сборки
   - Bazel - система сборки от Google
   
   Преимущества:
   - Автоматизация сборки
   - Управление зависимостями
   - Кроссплатформенность

в) СИСТЕМЫ КОНТРОЛЯ ВЕРСИЙ:
   - Git - распределенная система
   - GitHub / GitLab / Bitbucket - хостинг
   - Git workflows (GitFlow, GitHub Flow)
   
   Команды:
   - commit, push, pull
   - branch, merge, rebase
   - checkout, reset

г) ИНСТРУМЕНТЫ ТЕСТИРОВАНИЯ:
   - Google Test - unit тестирование
   - Catch2 - легковесный фреймворк
   - Boost.Test - тестирование
   - Valgrind - проверка памяти

д) ПРОФИЛИРОВЩИКИ И ОТЛАДЧИКИ:
   - GDB - отладчик
   - Valgrind - профилировщик памяти
   - perf - профилировщик Linux
   - AddressSanitizer - обнаружение ошибок памяти

5. НЕПРЕРЫВНОЕ ОБУЧЕНИЕ:

а) ИЗУЧЕНИЕ НОВЫХ СТАНДАРТОВ C++:
   - C++23, C++26 и будущие стандарты
   - Новые возможности языка
   - Лучшие практики
   - Обратная совместимость

б) ОСВОЕНИЕ НОВЫХ ТЕХНОЛОГИЙ:
   - Новые библиотеки и фреймворки
   - Инструменты разработки
   - Методологии разработки
   - Смежные технологии

в) УЧАСТИЕ В СООБЩЕСТВЕ:
   - Форумы и сообщества
   - Конференции и митапы
   - Open source проекты
   - Блоги и статьи

г) ЧТЕНИЕ ТЕХНИЧЕСКОЙ ЛИТЕРАТУРЫ:
   - Книги по C++
   - Стандарты языка
   - Технические статьи
   - Документация

д) ПРАКТИКА НА РЕАЛЬНЫХ ПРОЕКТАХ:
   - Личные проекты
   - Open source вклад
   - Стажировки
   - Фриланс проекты

РЕКОМЕНДАЦИИ ДЛЯ НАЧИНАЮЩИХ:

1. Создайте портфолио проектов
2. Участвуйте в open source
3. Изучайте существующий код
4. Практикуйтесь регулярно
5. Не бойтесь задавать вопросы
6. Читайте код других разработчиков
7. Решайте задачи на платформах (LeetCode, HackerRank)
8. Посещайте конференции и митапы

СИНТАКСИС УРОКА:

1. Именование переменных:
   int studentAge;           // camelCase
   const int MAX_SIZE = 100; // константы UPPER_CASE
   string name_;             // приватные поля с суффиксом _

2. Константность:
   const int& getValue() const { return value; }
   void print(const string& str);  // не изменяет аргумент

3. Умные указатели вместо сырых:
   unique_ptr<MyClass> ptr = make_unique<MyClass>();
   shared_ptr<MyClass> ptr = make_shared<MyClass>();

4. RAII: управление ресурсами в конструкторе/деструкторе
   unique_ptr для владения: make_unique<T>(), ~Destructor освобождает

5. chrono для измерения производительности:
   high_resolution_clock::now(), duration_cast

6. binary_search для отсортированных контейнеров

7. Лямбды с захватом: [&name](const auto& x) { return x == name; }

8. Обработка ошибок:
   if (students.empty()) {
       throw invalid_argument("описание ошибки");
   }

9. Документирование:
   /** @brief Описание функции
    *  @param name Описание параметра
    *  @return Описание возвращаемого значения */

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <chrono>
using namespace std;

// === Примеры из части 1: Лучшие практики ===

// Пример хорошего стиля кодирования
class Student {
private:
    string name_;
    int age_;
    double grade_;
    
public:
    Student(const string& name = "", int age = 0, double grade = 0.0)
        : name_(name), age_(age), grade_(grade) {}
    
    const string& getName() const { return name_; }
    int getAge() const { return age_; }
    double getGrade() const { return grade_; }
    
    void setName(const string& name) {
        if (!name.empty()) name_ = name;
    }
    
    void setAge(int age) {
        if (age >= 0 && age <= 150) age_ = age;
    }
    
    void setGrade(double grade) {
        if (grade >= 0.0 && grade <= 5.0) grade_ = grade;
    }
    
    void displayInfo() const {
        cout << "Студент: " << name_ << ", Возраст: " << age_ << ", Оценка: " << grade_ << endl;
    }
    
    bool operator<(const Student& other) const {
        return grade_ < other.grade_;
    }
};

/**
 * @brief Вычисляет средний балл студентов
 * @param students Вектор студентов
 * @return Средний балл
 * @throws std::invalid_argument Если вектор пуст
 */
double calculateAverageGrade(const vector<Student>& students) {
    if (students.empty()) {
        throw invalid_argument("Вектор студентов не может быть пустым");
    }
    double sum = 0.0;
    for (const auto& student : students) {
        sum += student.getGrade();
    }
    return sum / students.size();
}

class ResourceManager {
private:
    vector<unique_ptr<Student>> students_;
    
public:
    void addStudent(const string& name, int age, double grade) {
        students_.push_back(make_unique<Student>(name, age, grade));
    }
    
    void displayAllStudents() const {
        for (const auto& student : students_) {
            student->displayInfo();
        }
    }
    
    Student* findStudent(const string& name) const {
        auto it = find_if(students_.begin(), students_.end(),
            [&name](const unique_ptr<Student>& student) {
                return student->getName() == name;
            });
        return (it != students_.end()) ? it->get() : nullptr;
    }
};

// === Примеры из части 2: Профессиональная разработка ===

class DatabaseConnection {
private:
    string connectionString_;
    bool isConnected_;
    
public:
    DatabaseConnection(const string& connectionString) 
        : connectionString_(connectionString), isConnected_(false) {}
    
    bool connect() {
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

class DatabaseManager {
private:
    unique_ptr<DatabaseConnection> connection_;
    
public:
    DatabaseManager(const string& connectionString) {
        connection_ = make_unique<DatabaseConnection>(connectionString);
        connection_->connect();
    }
    
    ~DatabaseManager() {
        if (connection_) connection_->disconnect();
    }
    
    DatabaseConnection* getConnection() const {
        return connection_.get();
    }
};

class PerformanceOptimizer {
public:
    static void optimizedSort(vector<string>& data) {
        auto start = chrono::high_resolution_clock::now();
        sort(data.begin(), data.end());
        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
        cout << "Время сортировки: " << duration.count() << " микросекунд" << endl;
    }
    
    static bool optimizedSearch(const vector<int>& data, int target) {
        return binary_search(data.begin(), data.end(), target);
    }
};

void examples() {
    cout << "=== ЛУЧШИЕ ПРАКТИКИ И ПРОФЕССИОНАЛЬНАЯ РАЗРАБОТКА ===" << endl;
    
    // Часть 1: Лучшие практики
    cout << "\n=== ИНФОРМАЦИЯ О СТУДЕНТАХ ===" << endl;
    vector<Student> students = {
        Student("Анна", 20, 4.5),
        Student("Петр", 19, 3.8),
        Student("Мария", 21, 4.2),
        Student("Иван", 22, 3.5)
    };
    
    for (const auto& student : students) {
        student.displayInfo();
    }
    
    try {
        double average = calculateAverageGrade(students);
        cout << "\nСредний балл: " << average << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    sort(students.begin(), students.end());
    cout << "\n=== СТУДЕНТЫ ОТСОРТИРОВАННЫЕ ПО ОЦЕНКАМ ===" << endl;
    for (const auto& student : students) {
        student.displayInfo();
    }
    
    cout << "\n=== РАБОТА С RESOURCE MANAGER ===" << endl;
    ResourceManager manager;
    manager.addStudent("Алексей", 23, 4.8);
    manager.addStudent("Елена", 20, 4.1);
    manager.displayAllStudents();
    
    Student* found = manager.findStudent("Елена");
    if (found) {
        cout << "Найденный студент: ";
        found->displayInfo();
    }
    
    // Часть 2: Профессиональная разработка (RAII)
    cout << "\n=== ДЕМОНСТРАЦИЯ RAII ===" << endl;
    {
        DatabaseManager dbManager("localhost:3306");
        if (dbManager.getConnection()->isConnected()) {
            cout << "Работаем с базой данных..." << endl;
        }
    }
    
    cout << "\n=== ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    vector<string> words = {"zebra", "apple", "banana", "cherry", "date"};
    PerformanceOptimizer::optimizedSort(words);
    cout << "Отсортированные слова: ";
    for (const auto& word : words) cout << word << " ";
    cout << endl;
    
    vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15};
    if (PerformanceOptimizer::optimizedSearch(numbers, 7)) {
        cout << "Число 7 найдено в отсортированном массиве" << endl;
    }
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:
*/

// Упражнение 1: Рефакторинг кода
void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: РЕФАКТОРИНГ КОДА ===" << endl;
    
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    sort(numbers.begin(), numbers.end());
    
    cout << "Отсортированные числа: ";
    for (const auto& num : numbers) cout << num << " ";
    cout << endl;
    
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Число 5 найдено на позиции " << (it - numbers.begin()) << endl;
    }
    
    int count = count_if(numbers.begin(), numbers.end(),
        [](int n) { return n % 2 == 0; });
    cout << "Количество четных чисел: " << count << endl;
}

// Упражнение 2: Оптимизация производительности
void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    
    vector<int> numbers;
    numbers.reserve(1000);
    
    for (int i = 0; i < 1000; ++i) {
        numbers.push_back(i);
    }
    
    cout << "Размер вектора: " << numbers.size() << endl;
    cout << "Емкость вектора: " << numbers.capacity() << endl;
    
    vector<int> movedNumbers = move(numbers);
    cout << "После move - размер исходного: " << numbers.size() << endl;
    cout << "После move - размер целевого: " << movedNumbers.size() << endl;
    
    sort(movedNumbers.begin(), movedNumbers.end());
    auto it = lower_bound(movedNumbers.begin(), movedNumbers.end(), 500);
    if (it != movedNumbers.end()) {
        cout << "Первое число >= 500: " << *it << endl;
    }
}

// Упражнение 3: Профессиональный логгер
class ProfessionalLogger {
private:
    string logFile_;
    bool isEnabled_;
    
public:
    ProfessionalLogger(const string& logFile) 
        : logFile_(logFile), isEnabled_(true) {}
    
    void log(const string& message) {
        if (isEnabled_) cout << "[LOG] " << message << endl;
    }
    
    void setEnabled(bool enabled) { isEnabled_ = enabled; }
    bool isEnabled() const { return isEnabled_; }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ПРОФЕССИОНАЛЬНЫЙ ЛОГГЕР ===" << endl;
    
    ProfessionalLogger logger("app.log");
    logger.log("Приложение запущено");
    logger.log("Пользователь вошел в систему");
    
    logger.setEnabled(false);
    logger.log("Это сообщение не будет показано");
    
    logger.setEnabled(true);
    logger.log("Логирование возобновлено");
}

// Упражнение 4: Тестирование кода
class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) throw invalid_argument("Деление на ноль");
        return a / b;
    }
};

void exercise4() {
    cout << "=== УПРАЖНЕНИЕ 4: ТЕСТИРОВАНИЕ КОДА ===" << endl;
    
    cout << "2 + 3 = " << Calculator::add(2, 3) << " (ожидается 5)" << endl;
    cout << "4 * 5 = " << Calculator::multiply(4, 5) << " (ожидается 20)" << endl;
    cout << "10 / 2 = " << Calculator::divide(10, 2) << " (ожидается 5)" << endl;
    
    try {
        Calculator::divide(10, 0);
    } catch (const invalid_argument& e) {
        cout << "Деление на ноль - поймано исключение: " << e.what() << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание библиотеки классов
Создай библиотеку классов с хорошей документацией, четкими интерфейсами,
подробными комментариями, примерами использования и тестами.

Задание 2: Оптимизация и портфолио
Возьми существующий код, оптимизируй его и добавь в портфолио с документацией
и описанием архитектуры.

Задание 3: Проект с нуля
Создай новый проект, применяя все лучшие практики: правильная архитектура,
чистый код, документация, тестирование, управление версиями.

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое чистый код?
2. Какие принципы программирования важны?
3. Как оптимизировать производительность?
4. Зачем нужна документация?
5. Как правильно тестировать код?
6. Какие навыки нужны профессиональному разработчику?
7. Какие карьерные возможности есть в C++?
8. Что такое RAII?
9. Какие инструменты используются в разработке?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим итоговое повторение, проверку знаний,
планы на будущее и заключение курса.

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

int main() {
    cout << "=== УРОК 24: ЛУЧШИЕ ПРАКТИКИ И ПРОФЕССИОНАЛЬНАЯ РАЗРАБОТКА ===" << endl;
    
    examples();
    
    cout << endl;
    exercise1();
    
    cout << endl;
    exercise2();
    
    cout << endl;
    exercise3();
    
    cout << endl;
    exercise4();
    
    return 0;
}
