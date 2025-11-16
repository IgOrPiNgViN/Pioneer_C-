/*
===========================================
УРОК 22: ЛУЧШИЕ ПРАКТИКИ ПРОГРАММИРОВАНИЯ
===========================================

ЦЕЛИ УРОКА:
- Изучить лучшие практики программирования
- Понять принципы чистого кода
- Освоить стиль кодирования
- Научиться оптимизировать производительность
- Понять важность документирования

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ЛУЧШИЕ ПРАКТИКИ ПРОГРАММИРОВАНИЯ:

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

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

// Пример хорошего стиля кодирования
class Student {
private:
    string name_;
    int age_;
    double grade_;
    
public:
    // Конструктор с параметрами по умолчанию
    Student(const string& name = "", int age = 0, double grade = 0.0)
        : name_(name), age_(age), grade_(grade) {}
    
    // Геттеры с const
    const string& getName() const { return name_; }
    int getAge() const { return age_; }
    double getGrade() const { return grade_; }
    
    // Сеттеры с проверкой
    void setName(const string& name) {
        if (!name.empty()) {
            name_ = name;
        }
    }
    
    void setAge(int age) {
        if (age >= 0 && age <= 150) {
            age_ = age;
        }
    }
    
    void setGrade(double grade) {
        if (grade >= 0.0 && grade <= 5.0) {
            grade_ = grade;
        }
    }
    
    // Метод для отображения информации
    void displayInfo() const {
        cout << "Студент: " << name_ 
             << ", Возраст: " << age_ 
             << ", Оценка: " << grade_ << endl;
    }
    
    // Оператор сравнения
    bool operator<(const Student& other) const {
        return grade_ < other.grade_;
    }
};

// Пример функции с хорошей документацией
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

// Пример использования умных указателей
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
    
    // Поиск студента по имени
    Student* findStudent(const string& name) const {
        auto it = find_if(students_.begin(), students_.end(),
            [&name](const unique_ptr<Student>& student) {
                return student->getName() == name;
            });
        
        return (it != students_.end()) ? it->get() : nullptr;
    }
};

int main() {
    cout << "=== ЛУЧШИЕ ПРАКТИКИ ПРОГРАММИРОВАНИЯ ===" << endl;
    
    // Создание студентов
    vector<Student> students = {
        Student("Анна", 20, 4.5),
        Student("Петр", 19, 3.8),
        Student("Мария", 21, 4.2),
        Student("Иван", 22, 3.5)
    };
    
    // Отображение информации о студентах
    cout << "\n=== ИНФОРМАЦИЯ О СТУДЕНТАХ ===" << endl;
    for (const auto& student : students) {
        student.displayInfo();
    }
    
    // Вычисление среднего балла
    try {
        double average = calculateAverageGrade(students);
        cout << "\nСредний балл: " << average << endl;
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Сортировка студентов по оценкам
    sort(students.begin(), students.end());
    cout << "\n=== СТУДЕНТЫ ОТСОРТИРОВАННЫЕ ПО ОЦЕНКАМ ===" << endl;
    for (const auto& student : students) {
        student.displayInfo();
    }
    
    // Работа с ResourceManager
    cout << "\n=== РАБОТА С RESOURCE MANAGER ===" << endl;
    ResourceManager manager;
    
    manager.addStudent("Алексей", 23, 4.8);
    manager.addStudent("Елена", 20, 4.1);
    manager.addStudent("Дмитрий", 21, 3.9);
    
    manager.displayAllStudents();
    
    // Поиск студента
    Student* found = manager.findStudent("Елена");
    if (found) {
        cout << "\nНайденный студент: ";
        found->displayInfo();
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Рефакторинг кода
Улучши следующий код, применив лучшие практики:
*/

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: РЕФАКТОРИНГ КОДА ===" << endl;
    
    // Плохой код (для демонстрации)
    vector<int> v = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Хороший код
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Использование алгоритмов STL
    sort(numbers.begin(), numbers.end());
    
    cout << "Отсортированные числа: ";
    for (const auto& num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск с помощью алгоритмов
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Число 5 найдено на позиции " << (it - numbers.begin()) << endl;
    }
    
    // Подсчет с помощью алгоритмов
    int count = count_if(numbers.begin(), numbers.end(),
        [](int n) { return n % 2 == 0; });
    cout << "Количество четных чисел: " << count << endl;
}

/*
Упражнение 2: Оптимизация производительности
Создай оптимизированную версию программы:
*/

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    
    // Резервирование памяти для вектора
    vector<int> numbers;
    numbers.reserve(1000); // Резервируем память заранее
    
    // Заполнение вектора
    for (int i = 0; i < 1000; ++i) {
        numbers.push_back(i);
    }
    
    cout << "Размер вектора: " << numbers.size() << endl;
    cout << "Емкость вектора: " << numbers.capacity() << endl;
    
    // Использование move semantics
    vector<int> movedNumbers = move(numbers);
    cout << "После move - размер исходного: " << numbers.size() << endl;
    cout << "После move - размер целевого: " << movedNumbers.size() << endl;
    
    // Эффективный поиск в отсортированном векторе
    sort(movedNumbers.begin(), movedNumbers.end());
    
    auto it = lower_bound(movedNumbers.begin(), movedNumbers.end(), 500);
    if (it != movedNumbers.end()) {
        cout << "Первое число >= 500: " << *it << endl;
    }
}

/*
Упражнение 3: Документирование кода
Создай хорошо документированный код:
*/

/**
 * @brief Класс для работы с геометрическими фигурами
 */
class Shape {
protected:
    string name_;
    
public:
    Shape(const string& name) : name_(name) {}
    virtual ~Shape() = default;
    
    /**
     * @brief Вычисляет площадь фигуры
     * @return Площадь фигуры
     */
    virtual double getArea() const = 0;
    
    /**
     * @brief Вычисляет периметр фигуры
     * @return Периметр фигуры
     */
    virtual double getPerimeter() const = 0;
    
    /**
     * @brief Возвращает название фигуры
     * @return Название фигуры
     */
    const string& getName() const { return name_; }
};

/**
 * @brief Класс для работы с прямоугольниками
 */
class Rectangle : public Shape {
private:
    double width_;
    double height_;
    
public:
    /**
     * @brief Конструктор прямоугольника
     * @param width Ширина
     * @param height Высота
     */
    Rectangle(double width, double height) 
        : Shape("Прямоугольник"), width_(width), height_(height) {}
    
    double getArea() const override {
        return width_ * height_;
    }
    
    double getPerimeter() const override {
        return 2 * (width_ + height_);
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ДОКУМЕНТИРОВАНИЕ КОДА ===" << endl;
    
    Rectangle rect(5.0, 3.0);
    
    cout << "Фигура: " << rect.getName() << endl;
    cout << "Площадь: " << rect.getArea() << endl;
    cout << "Периметр: " << rect.getPerimeter() << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание библиотеки классов
Создай библиотеку классов с хорошей документацией:
- Четкие интерфейсы
- Подробные комментарии
- Примеры использования
- Тесты для каждого класса

Задание 2: Оптимизация существующего кода
Возьми существующий код и оптимизируй его:
- Улучши производительность
- Сделай код более читаемым
- Добавь обработку ошибок
- Напиши тесты

Задание 3: Создание проекта с нуля
Создай новый проект, применяя все лучшие практики:
- Правильная архитектура
- Чистый код
- Документация
- Тестирование
- Управление версиями

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое чистый код?
2. Какие принципы программирования важны?
3. Как оптимизировать производительность?
4. Зачем нужна документация?
5. Как правильно тестировать код?
6. Что такое рефакторинг?
7. Как работать с версиями кода?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Подготовка к профессиональной разработке
- Карьерные возможности
- Дальнейшее обучение
- Сообщество разработчиков
- Ресурсы для изучения

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 22: ЛУЧШИЕ ПРАКТИКИ ПРОГРАММИРОВАНИЯ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: РЕФАКТОРИНГ КОДА ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ДОКУМЕНТИРОВАНИЕ КОДА ===" << endl;
    exercise3();
    
    return 0;
}


















