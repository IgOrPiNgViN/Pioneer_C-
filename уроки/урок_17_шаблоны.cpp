/*
===========================================
УРОК 17: ШАБЛОНЫ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию шаблонов
- Изучить шаблоны функций
- Освоить шаблоны классов
- Научиться работать с параметрами шаблонов
- Понять специализацию шаблонов

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ШАБЛОНЫ В C++:

ШАБЛОНЫ - это механизм для создания универсального кода, который может работать с различными типами данных

ТИПЫ ШАБЛОНОВ:
1. ШАБЛОНЫ ФУНКЦИЙ - функции, которые могут работать с разными типами
2. ШАБЛОНЫ КЛАССОВ - классы, которые могут работать с разными типами

СИНТАКСИС ШАБЛОНОВ:
template <typename T> // или template <class T>
// определение функции или класса

ПАРАМЕТРЫ ШАБЛОНОВ:
- typename T - параметр типа
- int N - параметр значения
- template <typename U> - параметр шаблона

ОСОБЕННОСТИ:
- Компилятор генерирует код для каждого используемого типа
- Шаблоны компилируются только при использовании
- Можно использовать несколько параметров
- Можно задавать значения по умолчанию

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

// Шаблон функции для поиска максимума
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Шаблон функции для обмена значений
template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Шаблон функции для поиска элемента в массиве
template <typename T>
int findElement(T arr[], int size, T target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Шаблон функции для сортировки массива
template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swapValues(arr[j], arr[j + 1]);
            }
        }
    }
}

// Шаблон функции для вывода массива
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ ШАБЛОНОВ ФУНКЦИЙ ===" << endl;
    
    // Работа с целыми числами
    cout << "\n=== РАБОТА С ЦЕЛЫМИ ЧИСЛАМИ ===" << endl;
    int a = 10, b = 20;
    cout << "Максимум из " << a << " и " << b << ": " << findMax(a, b) << endl;
    
    cout << "До обмена: a = " << a << ", b = " << b << endl;
    swapValues(a, b);
    cout << "После обмена: a = " << a << ", b = " << b << endl;
    
    // Работа с числами с плавающей точкой
    cout << "\n=== РАБОТА С ЧИСЛАМИ С ПЛАВАЮЩЕЙ ТОЧКОЙ ===" << endl;
    double x = 3.14, y = 2.71;
    cout << "Максимум из " << x << " и " << y << ": " << findMax(x, y) << endl;
    
    // Работа со строками
    cout << "\n=== РАБОТА СО СТРОКАМИ ===" << endl;
    string s1 = "Hello", s2 = "World";
    cout << "Максимум из '" << s1 << "' и '" << s2 << "': " << findMax(s1, s2) << endl;
    
    // Работа с массивами
    cout << "\n=== РАБОТА С МАССИВАМИ ===" << endl;
    int intArr[] = {5, 2, 8, 1, 9};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    
    cout << "Исходный массив: ";
    printArray(intArr, intSize);
    
    bubbleSort(intArr, intSize);
    cout << "Отсортированный массив: ";
    printArray(intArr, intSize);
    
    int target = 8;
    int index = findElement(intArr, intSize, target);
    if (index != -1) {
        cout << "Элемент " << target << " найден на позиции " << index << endl;
    } else {
        cout << "Элемент " << target << " не найден" << endl;
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Шаблон класса для работы с парами
Создай шаблон класса Pair для работы с парами значений:
*/

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
    
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    
    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; }
    
    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ШАБЛОН КЛАССА PAIR ===" << endl;
    
    Pair<int, string> pair1(1, "Hello");
    Pair<double, char> pair2(3.14, 'A');
    Pair<string, int> pair3("World", 42);
    
    cout << "pair1: ";
    pair1.display();
    
    cout << "pair2: ";
    pair2.display();
    
    cout << "pair3: ";
    pair3.display();
    
    pair1.setFirst(10);
    pair1.setSecond("Updated");
    cout << "Обновленная pair1: ";
    pair1.display();
}

/*
Упражнение 2: Шаблон класса для работы со стеком
Создай шаблон класса Stack для работы со стеком:
*/

template <typename T>
class Stack {
private:
    T* data;
    int top;
    int capacity;
    
public:
    Stack(int cap = 10) : capacity(cap), top(-1) {
        data = new T[capacity];
    }
    
    ~Stack() {
        delete[] data;
    }
    
    void push(T value) {
        if (top < capacity - 1) {
            data[++top] = value;
            cout << "Добавлен элемент: " << value << endl;
        } else {
            cout << "Стек переполнен!" << endl;
        }
    }
    
    T pop() {
        if (top >= 0) {
            T value = data[top--];
            cout << "Удален элемент: " << value << endl;
            return value;
        } else {
            cout << "Стек пуст!" << endl;
            return T();
        }
    }
    
    T peek() {
        if (top >= 0) {
            return data[top];
        } else {
            cout << "Стек пуст!" << endl;
            return T();
        }
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    void display() {
        cout << "Стек: ";
        for (int i = 0; i <= top; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ШАБЛОН КЛАССА STACK ===" << endl;
    
    Stack<int> intStack(5);
    
    cout << "Работа с целочисленным стеком:" << endl;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    
    cout << "Верхний элемент: " << intStack.peek() << endl;
    intStack.pop();
    intStack.display();
    
    Stack<string> stringStack(3);
    
    cout << "\nРабота со строковым стеком:" << endl;
    stringStack.push("Hello");
    stringStack.push("World");
    stringStack.push("C++");
    stringStack.display();
    
    cout << "Верхний элемент: " << stringStack.peek() << endl;
    stringStack.pop();
    stringStack.display();
}

/*
Упражнение 3: Шаблон класса для работы с векторами
Создай шаблон класса Vector для работы с векторами:
*/

template <typename T>
class Vector {
private:
    T* data;
    int size;
    int capacity;
    
public:
    Vector(int cap = 10) : capacity(cap), size(0) {
        data = new T[capacity];
    }
    
    ~Vector() {
        delete[] data;
    }
    
    void push_back(T value) {
        if (size < capacity) {
            data[size++] = value;
        } else {
            cout << "Вектор переполнен!" << endl;
        }
    }
    
    T at(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            cout << "Индекс вне диапазона!" << endl;
            return T();
        }
    }
    
    void set(int index, T value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            cout << "Индекс вне диапазона!" << endl;
        }
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void display() {
        cout << "Вектор: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    
    // Перегрузка оператора []
    T& operator[](int index) {
        return data[index];
    }
    
    // Перегрузка оператора =
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ШАБЛОН КЛАССА VECTOR ===" << endl;
    
    Vector<int> intVector(5);
    
    cout << "Работа с целочисленным вектором:" << endl;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.push_back(30);
    intVector.display();
    
    cout << "Элемент с индексом 1: " << intVector.at(1) << endl;
    intVector.set(1, 25);
    intVector.display();
    
    cout << "Элемент с индексом 0: " << intVector[0] << endl;
    intVector[0] = 15;
    intVector.display();
    
    Vector<string> stringVector(3);
    
    cout << "\nРабота со строковым вектором:" << endl;
    stringVector.push_back("Hello");
    stringVector.push_back("World");
    stringVector.push_back("C++");
    stringVector.display();
    
    cout << "Элемент с индексом 2: " << stringVector.at(2) << endl;
    stringVector.set(2, "Templates");
    stringVector.display();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Шаблон класса для работы с очередью
Создай шаблон класса Queue с методами:
- enqueue (добавление в конец)
- dequeue (удаление из начала)
- front (получение первого элемента)
- isEmpty, isFull
- display

Задание 2: Шаблон класса для работы с матрицами
Создай шаблон класса Matrix с методами:
- Конструктор с размерами
- Операторы +, -, *
- Оператор []
- Методы для получения размеров
- Метод для транспонирования

Задание 3: Шаблон класса для работы с множествами
Создай шаблон класса Set с методами:
- insert (добавление элемента)
- remove (удаление элемента)
- contains (проверка наличия)
- union (объединение)
- intersection (пересечение)
- difference (разность)

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое шаблоны?
2. В чем разница между шаблонами функций и классов?
3. Что такое параметры шаблонов?
4. Когда компилируются шаблоны?
5. Можно ли использовать несколько параметров в шаблоне?
6. Что такое специализация шаблонов?
7. Зачем нужны шаблоны?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Стандартная библиотека шаблонов (STL)
- Контейнеры STL
- Итераторы
- Алгоритмы STL
- Функциональные объекты

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 17: ШАБЛОНЫ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ШАБЛОН КЛАССА PAIR ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ШАБЛОН КЛАССА STACK ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ШАБЛОН КЛАССА VECTOR ===" << endl;
    exercise3();
    
    return 0;
}





