/*
===========================================
УРОК 24: ИТОГОВОЕ ПОВТОРЕНИЕ
===========================================

ЦЕЛИ УРОКА:
- Повторить все изученные концепции C++
- Проверить понимание материала
- Закрепить знания на практике
- Подготовиться к финальному тестированию
- Понять связи между различными темами

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ИТОГОВОЕ ПОВТОРЕНИЕ КУРСА C++:

1. ОСНОВЫ ЯЗЫКА:
   - Переменные и типы данных
   - Операторы и выражения
   - Условные операторы и циклы
   - Функции и области видимости

2. СТРУКТУРЫ ДАННЫХ:
   - Массивы и строки
   - Указатели и ссылки
   - Структуры и объединения
   - Динамическая память

3. ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ:
   - Классы и объекты
   - Инкапсуляция и наследование
   - Полиморфизм и виртуальные функции
   - Конструкторы и деструкторы

4. ПРОДВИНУТЫЕ ВОЗМОЖНОСТИ:
   - Перегрузка операторов
   - Шаблоны функций и классов
   - Стандартная библиотека шаблонов (STL)
   - Обработка исключений

5. СОВРЕМЕННЫЕ ВОЗМОЖНОСТИ:
   - Лямбда-выражения
   - Автоматическое выведение типов
   - Умные указатели
   - Move semantics

6. ЛУЧШИЕ ПРАКТИКИ:
   - Чистый код
   - Оптимизация производительности
   - Тестирование и отладка
   - Документирование

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Пример комплексного класса, демонстрирующий все изученные концепции
template<typename T>
class SmartVector {
private:
    vector<T> data_;
    string name_;
    
public:
    // Конструкторы
    SmartVector(const string& name = "SmartVector") : name_(name) {}
    SmartVector(const vector<T>& data, const string& name = "SmartVector") 
        : data_(data), name_(name) {}
    
    // Деструктор
    ~SmartVector() {
        cout << "SmartVector '" << name_ << "' уничтожен" << endl;
    }
    
    // Методы для работы с данными
    void add(const T& value) {
        data_.push_back(value);
    }
    
    void remove(const T& value) {
        auto it = find(data_.begin(), data_.end(), value);
        if (it != data_.end()) {
            data_.erase(it);
        }
    }
    
    // Перегрузка операторов
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
    
    // Методы для отображения
    void display() const {
        cout << name_ << ": ";
        for (const auto& value : data_) {
            cout << value << " ";
        }
        cout << endl;
    }
    
    // Методы для получения информации
    size_t size() const { return data_.size(); }
    bool empty() const { return data_.empty(); }
    const string& getName() const { return name_; }
    
    // Методы для сортировки
    void sort() {
        std::sort(data_.begin(), data_.end());
    }
    
    void sort(function<bool(const T&, const T&)> comparator) {
        std::sort(data_.begin(), data_.end(), comparator);
    }
    
    // Методы для поиска
    bool contains(const T& value) const {
        return find(data_.begin(), data_.end(), value) != data_.end();
    }
    
    size_t find(const T& value) const {
        auto it = find(data_.begin(), data_.end(), value);
        return (it != data_.end()) ? (it - data_.begin()) : string::npos;
    }
};

// Пример использования всех возможностей
int main() {
    cout << "=== ИТОГОВОЕ ПОВТОРЕНИЕ КУРСА C++ ===" << endl;
    
    // Демонстрация работы с целочисленным вектором
    cout << "\n=== РАБОТА С ЦЕЛОЧИСЛЕННЫМ ВЕКТОРОМ ===" << endl;
    SmartVector<int> intVector("Целочисленный вектор");
    
    intVector.add(5);
    intVector.add(2);
    intVector.add(8);
    intVector.add(1);
    intVector.add(9);
    
    intVector.display();
    cout << "Размер: " << intVector.size() << endl;
    
    // Сортировка
    intVector.sort();
    cout << "После сортировки: ";
    intVector.display();
    
    // Поиск
    if (intVector.contains(5)) {
        cout << "Элемент 5 найден на позиции " << intVector.find(5) << endl;
    }
    
    // Доступ по индексу
    try {
        cout << "Элемент с индексом 2: " << intVector[2] << endl;
    } catch (const out_of_range& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Демонстрация работы со строковым вектором
    cout << "\n=== РАБОТА СО СТРОКОВЫМ ВЕКТОРОМ ===" << endl;
    SmartVector<string> stringVector("Строковый вектор");
    
    stringVector.add("Hello");
    stringVector.add("World");
    stringVector.add("C++");
    stringVector.add("Programming");
    
    stringVector.display();
    
    // Сортировка по длине строк
    stringVector.sort([](const string& a, const string& b) {
        return a.length() < b.length();
    });
    
    cout << "После сортировки по длине: ";
    stringVector.display();
    
    // Демонстрация объединения векторов
    cout << "\n=== ОБЪЕДИНЕНИЕ ВЕКТОРОВ ===" << endl;
    SmartVector<int> vector1("Вектор 1");
    SmartVector<int> vector2("Вектор 2");
    
    vector1.add(1);
    vector1.add(2);
    vector1.add(3);
    
    vector2.add(4);
    vector2.add(5);
    vector2.add(6);
    
    cout << "До объединения:" << endl;
    vector1.display();
    vector2.display();
    
    vector1 += vector2;
    cout << "После объединения:" << endl;
    vector1.display();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Создание комплексного класса
Создай класс, демонстрирующий все изученные концепции:
*/

class ComplexNumber {
private:
    double real_;
    double imag_;
    
public:
    ComplexNumber(double real = 0, double imag = 0) : real_(real), imag_(imag) {}
    
    // Перегрузка операторов
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
    
    // Оператор вывода
    friend ostream& operator<<(ostream& os, const ComplexNumber& c) {
        os << c.real_;
        if (c.imag_ >= 0) {
            os << " + " << c.imag_ << "i";
        } else {
            os << " - " << (-c.imag_) << "i";
        }
        return os;
    }
    
    // Методы
    double getReal() const { return real_; }
    double getImag() const { return imag_; }
    double getMagnitude() const {
        return sqrt(real_ * real_ + imag_ * imag_);
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: КОМПЛЕКСНЫЕ ЧИСЛА ===" << endl;
    
    ComplexNumber c1(3, 4);
    ComplexNumber c2(1, 2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << (c1 + c2) << endl;
    cout << "c1 - c2 = " << (c1 - c2) << endl;
    cout << "c1 * c2 = " << (c1 * c2) << endl;
    cout << "Модуль c1: " << c1.getMagnitude() << endl;
}

/*
Упражнение 2: Работа с STL и алгоритмами
Создай программу с использованием STL:
*/

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: STL И АЛГОРИТМЫ ===" << endl;
    
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    cout << "Исходные числа: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Сортировка
    sort(numbers.begin(), numbers.end());
    cout << "Отсортированные: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;
    
    // Поиск
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Число 5 найдено на позиции " << (it - numbers.begin()) << endl;
    }
    
    // Подсчет
    int evenCount = count_if(numbers.begin(), numbers.end(),
        [](int n) { return n % 2 == 0; });
    cout << "Количество четных чисел: " << evenCount << endl;
}

/*
Упражнение 3: Обработка исключений
Создай программу с обработкой исключений:
*/

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ОБРАБОТКА ИСКЛЮЧЕНИЙ ===" << endl;
    
    try {
        vector<int> numbers = {1, 2, 3, 4, 5};
        
        // Попытка доступа к несуществующему элементу
        int value = numbers.at(10);
        cout << "Значение: " << value << endl;
        
    } catch (const out_of_range& e) {
        cout << "Ошибка доступа к элементу: " << e.what() << endl;
        
        // Попытка доступа к существующему элементу
        try {
            vector<int> numbers = {1, 2, 3, 4, 5};
            int value = numbers.at(2);
            cout << "Значение элемента с индексом 2: " << value << endl;
            
        } catch (const out_of_range& e) {
            cout << "Ошибка доступа к существующему элементу: " << e.what() << endl;
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
- Финальное тестирование
- Проверка знаний
- Оценка результатов
- Планы на будущее
- Заключение курса

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
#include <functional>
#include <cmath>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 24: ИТОГОВОЕ ПОВТОРЕНИЕ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: КОМПЛЕКСНЫЕ ЧИСЛА ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: STL И АЛГОРИТМЫ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ОБРАБОТКА ИСКЛЮЧЕНИЙ ===" << endl;
    exercise3();
    
    return 0;
}





