/*
===========================================
УРОК 21: ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ C++
===========================================

ЦЕЛИ УРОКА:
- Изучить дополнительные возможности C++
- Понять современные стандарты C++
- Освоить продвинутые темы
- Научиться использовать новые возможности
- Понять лучшие практики программирования

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ C++:

1. ЛЯМБДА-ВЫРАЖЕНИЯ (C++11)
2. АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ ТИПОВ (auto)
3. УМНЫЕ УКАЗАТЕЛИ (smart pointers)
4. RANGE-BASED FOR LOOPS
5. INITIALIZER LISTS
6. MOVE SEMANTICS
7. CONSTEXPR
8. VARIADIC TEMPLATES

ЛЯМБДА-ВЫРАЖЕНИЯ:
[захват](параметры) -> тип_возврата { тело }

АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ ТИПОВ:
auto variable = value;

УМНЫЕ УКАЗАТЕЛИ:
- unique_ptr - единоличное владение
- shared_ptr - разделяемое владение
- weak_ptr - слабая ссылка

RANGE-BASED FOR LOOPS:
for (auto element : container) { ... }

INITIALIZER LISTS:
vector<int> v = {1, 2, 3, 4, 5};

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cout << "=== ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ C++ ===" << endl;
    
    // Лямбда-выражения
    cout << "\n=== ЛЯМБДА-ВЫРАЖЕНИЯ ===" << endl;
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Подсчет четных чисел с помощью лямбды
    int evenCount = count_if(numbers.begin(), numbers.end(),
        [](int n) { return n % 2 == 0; });
    cout << "Количество четных чисел: " << evenCount << endl;
    
    // Умножение каждого элемента на 2
    transform(numbers.begin(), numbers.end(), numbers.begin(),
        [](int n) { return n * 2; });
    
    cout << "Числа умноженные на 2: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Автоматическое выведение типов
    cout << "\n=== АВТОМАТИЧЕСКОЕ ВЫВЕДЕНИЕ ТИПОВ ===" << endl;
    auto name = string("Иван");
    auto age = 25;
    auto height = 1.75;
    auto isStudent = true;
    
    cout << "Имя: " << name << ", тип: " << typeid(name).name() << endl;
    cout << "Возраст: " << age << ", тип: " << typeid(age).name() << endl;
    cout << "Рост: " << height << ", тип: " << typeid(height).name() << endl;
    cout << "Студент: " << isStudent << ", тип: " << typeid(isStudent).name() << endl;
    
    // Range-based for loops
    cout << "\n=== RANGE-BASED FOR LOOPS ===" << endl;
    vector<string> words = {"Hello", "World", "C++", "Programming"};
    
    cout << "Слова: ";
    for (const auto& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Initializer lists
    cout << "\n=== INITIALIZER LISTS ===" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Вектор: ";
    for (int n : v) {
        cout << n << " ";
    }
    cout << endl;
    
    // Умные указатели
    cout << "\n=== УМНЫЕ УКАЗАТЕЛИ ===" << endl;
    unique_ptr<int> ptr1 = make_unique<int>(42);
    cout << "Значение через unique_ptr: " << *ptr1 << endl;
    
    shared_ptr<int> ptr2 = make_shared<int>(100);
    shared_ptr<int> ptr3 = ptr2;
    cout << "Значение через shared_ptr: " << *ptr2 << endl;
    cout << "Количество ссылок: " << ptr2.use_count() << endl;
    
    // Move semantics
    cout << "\n=== MOVE SEMANTICS ===" << endl;
    vector<int> source = {1, 2, 3, 4, 5};
    vector<int> destination = move(source);
    
    cout << "Исходный вектор (после move): ";
    for (int n : source) {
        cout << n << " ";
    }
    cout << endl;
    
    cout << "Целевой вектор: ";
    for (int n : destination) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Использование лямбда-выражений
Создай программу с различными лямбда-выражениями:
*/

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ЛЯМБДА-ВЫРАЖЕНИЯ ===" << endl;
    
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // Сортировка по четности
    sort(numbers.begin(), numbers.end(),
        [](int a, int b) {
            if (a % 2 == b % 2) {
                return a < b;
            }
            return a % 2 < b % 2;
        });
    
    cout << "Отсортированные числа (четные сначала): ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Поиск чисел больше 5
    auto it = find_if(numbers.begin(), numbers.end(),
        [](int n) { return n > 5; });
    
    if (it != numbers.end()) {
        cout << "Первое число больше 5: " << *it << endl;
    }
    
    // Подсчет чисел в диапазоне
    int count = count_if(numbers.begin(), numbers.end(),
        [](int n) { return n >= 3 && n <= 7; });
    
    cout << "Количество чисел от 3 до 7: " << count << endl;
}

/*
Упражнение 2: Работа с умными указателями
Создай программу для демонстрации умных указателей:
*/

class Resource {
private:
    string name;
    
public:
    Resource(string n) : name(n) {
        cout << "Ресурс '" << name << "' создан" << endl;
    }
    
    ~Resource() {
        cout << "Ресурс '" << name << "' уничтожен" << endl;
    }
    
    string getName() const { return name; }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: УМНЫЕ УКАЗАТЕЛИ ===" << endl;
    
    // unique_ptr
    {
        unique_ptr<Resource> ptr1 = make_unique<Resource>("Ресурс 1");
        cout << "Используем: " << ptr1->getName() << endl;
        
        // Передача владения
        unique_ptr<Resource> ptr2 = move(ptr1);
        cout << "После move: " << ptr2->getName() << endl;
    } // ptr2 автоматически уничтожается
    
    // shared_ptr
    {
        shared_ptr<Resource> ptr1 = make_shared<Resource>("Ресурс 2");
        cout << "Количество ссылок: " << ptr1.use_count() << endl;
        
        shared_ptr<Resource> ptr2 = ptr1;
        cout << "После копирования: " << ptr1.use_count() << endl;
        
        shared_ptr<Resource> ptr3 = ptr1;
        cout << "После еще одного копирования: " << ptr1.use_count() << endl;
    } // Все ссылки автоматически уничтожаются
}

/*
Упражнение 3: Современные возможности C++
Создай программу с использованием современных возможностей:
*/

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ ===" << endl;
    
    // Initializer lists
    vector<string> fruits = {"яблоко", "банан", "апельсин", "груша"};
    
    // Range-based for с auto
    cout << "Фрукты: ";
    for (const auto& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;
    
    // Лямбда с захватом
    string prefix = "Свежий ";
    transform(fruits.begin(), fruits.end(), fruits.begin(),
        [&prefix](const string& fruit) {
            return prefix + fruit;
        });
    
    cout << "Обновленные фрукты: ";
    for (const auto& fruit : fruits) {
        cout << fruit << " ";
    }
    cout << endl;
    
    // Автоматическое выведение типов
    auto numbers = {1, 2, 3, 4, 5};
    auto sum = 0;
    
    for (const auto& num : numbers) {
        sum += num;
    }
    
    cout << "Сумма чисел: " << sum << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Современный калькулятор
Создай калькулятор с использованием современных возможностей C++:
- Лямбда-выражения для операций
- Автоматическое выведение типов
- Умные указатели для управления памятью
- Range-based for для обработки данных

Задание 2: Система управления ресурсами
Создай систему управления ресурсами с умными указателями:
- unique_ptr для уникальных ресурсов
- shared_ptr для разделяемых ресурсов
- weak_ptr для слабых ссылок
- Автоматическое управление памятью

Задание 3: Функциональное программирование
Создай программу с элементами функционального программирования:
- Лямбда-выражения
- Функции высшего порядка
- Неизменяемые данные
- Чистые функции

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое лямбда-выражения?
2. Как работает автоматическое выведение типов?
3. В чем разница между умными указателями?
4. Что такое move semantics?
5. Как работают initializer lists?
6. Что такое range-based for loops?
7. Зачем нужны современные возможности C++?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Лучшие практики программирования
- Стиль кодирования
- Оптимизация производительности
- Отладка и тестирование
- Документирование кода

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 21: ДОПОЛНИТЕЛЬНЫЕ ВОЗМОЖНОСТИ C++ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ЛЯМБДА-ВЫРАЖЕНИЯ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: УМНЫЕ УКАЗАТЕЛИ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ ===" << endl;
    exercise3();
    
    return 0;
}





