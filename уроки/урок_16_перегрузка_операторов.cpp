/*
===========================================
УРОК 16: ПЕРЕГРУЗКА ОПЕРАТОРОВ
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию перегрузки операторов
- Изучить перегрузку арифметических операторов
- Освоить перегрузку операторов ввода/вывода
- Научиться перегружать операторы сравнения
- Понять операторы присваивания

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПЕРЕГРУЗКА ОПЕРАТОРОВ В C++:

Перегрузка операторов позволяет определить поведение операторов для пользовательских типов.
Это делает код более интуитивным и естественным для чтения.

ЗАЧЕМ НУЖНА ПЕРЕГРУЗКА ОПЕРАТОРОВ:

1. Естественность кода: obj1 + obj2 вместо obj1.add(obj2)
2. Интуитивность: код читается как математические выражения
3. Консистентность: операторы работают так же, как для встроенных типов
4. Удобство: меньше кода, больше выразительности

СИНТАКСИС ПЕРЕГРУЗКИ:

Синтаксис:
тип_возврата operator символ_оператора(параметры) {
    // реализация
}

Пример:
class Vector {
public:
    Vector operator+(const Vector& other) {
        // реализация сложения
    }
};

ТИПЫ ОПЕРАТОРОВ:

1. УНАРНЫЕ ОПЕРАТОРЫ (один операнд):
   - Префиксные: ++obj, --obj, -obj, !obj
   - Постфиксные: obj++, obj--
   
2. БИНАРНЫЕ ОПЕРАТОРЫ (два операнда):
   - Арифметические: +, -, *, /, %
   - Сравнения: ==, !=, <, >, <=, >=
   - Логические: &&, ||
   
3. ОПЕРАТОРЫ ПРИСВАИВАНИЯ:
   - =, +=, -=, *=, /=, %=
   
4. ОПЕРАТОРЫ ВВОДА/ВЫВОДА:
   - << (вывод), >> (ввод)
   
5. ОПЕРАТОРЫ ДОСТУПА:
   - [] (индексация), () (вызов функции)

ПЕРЕГРУЗКА КАК МЕТОД КЛАССА:

Когда оператор перегружается как метод класса, левый операнд - это объект класса.

Пример:
class Vector {
public:
    Vector operator+(const Vector& other) {  // метод класса
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};

Использование:
Vector v1, v2, v3;
v3 = v1 + v2;  // эквивалентно v1.operator+(v2)

ПЕРЕГРУЗКА КАК ГЛОБАЛЬНАЯ ФУНКЦИЯ:

Когда оператор перегружается как глобальная функция, оба операнда передаются как параметры.

Пример:
Vector operator+(const Vector& v1, const Vector& v2) {  // глобальная функция
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

Когда использовать:
- Когда левый операнд не является объектом класса
- Для симметричных операций
- Когда нужен доступ к private членам (через friend)

ОПЕРАТОРЫ, КОТОРЫЕ МОЖНО ПЕРЕГРУЖАТЬ:

1. АРИФМЕТИЧЕСКИЕ:
   +, -, *, /, %
   
2. СРАВНЕНИЯ:
   ==, !=, <, >, <=, >=
   
3. ЛОГИЧЕСКИЕ:
   &&, ||, !
   
4. ПРИСВАИВАНИЯ:
   =, +=, -=, *=, /=, %=
   
5. ИНКРЕМЕНТ/ДЕКРЕМЕНТ:
   ++, --
   
6. ВВОДА/ВЫВОДА:
   <<, >>
   
7. ДОСТУПА:
   [], ()
   
8. ДРУГИЕ:
   ->, ->*, new, new[], delete, delete[]

ОПЕРАТОРЫ, КОТОРЫЕ НЕЛЬЗЯ ПЕРЕГРУЖАТЬ:

- . (доступ к члену)
- .* (доступ к члену через указатель)
- :: (область видимости)
- ?: (тернарный оператор)
- sizeof
- typeid
- static_cast, dynamic_cast, const_cast, reinterpret_cast

ПЕРЕГРУЗКА АРИФМЕТИЧЕСКИХ ОПЕРАТОРОВ:

Пример:
class Complex {
private:
    double real, imag;
public:
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }
    
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }
    
    Complex operator*(const Complex& other) {
        return Complex(real * other.real - imag * other.imag,
                      real * other.imag + imag * other.real);
    }
};

ПЕРЕГРУЗКА ОПЕРАТОРОВ СРАВНЕНИЯ:

Пример:
class Person {
private:
    string name;
    int age;
public:
    bool operator==(const Person& other) const {
        return (name == other.name) && (age == other.age);
    }
    
    bool operator!=(const Person& other) const {
        return !(*this == other);  // используем operator==
    }
    
    bool operator<(const Person& other) const {
        if (name != other.name) {
            return name < other.name;
        }
        return age < other.age;
    }
};

ПЕРЕГРУЗКА ОПЕРАТОРОВ ПРИСВАИВАНИЯ:

Оператор присваивания должен возвращать ссылку на объект.

Пример:
class Vector {
public:
    Vector& operator=(const Vector& other) {
        if (this != &other) {  // проверка на самоприсваивание
            x = other.x;
            y = other.y;
        }
        return *this;  // возвращаем ссылку на себя
    }
};

ПЕРЕГРУЗКА ОПЕРАТОРОВ ИНКРЕМЕНТА/ДЕКРЕМЕНТА:

Префиксные и постфиксные версии различаются параметром int.

Пример:
class Counter {
private:
    int value;
public:
    Counter& operator++() {  // префиксный ++
        ++value;
        return *this;
    }
    
    Counter operator++(int) {  // постфиксный ++ (параметр int игнорируется)
        Counter temp = *this;
        ++value;
        return temp;  // возвращаем старое значение
    }
};

ПЕРЕГРУЗКА ОПЕРАТОРОВ ВВОДА/ВЫВОДА:

Операторы << и >> обычно перегружаются как глобальные функции.

Пример:
class Person {
private:
    string name;
    int age;
public:
    friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& is, Person& p);
};

ostream& operator<<(ostream& os, const Person& p) {
    os << "Имя: " << p.name << ", Возраст: " << p.age;
    return os;
}

istream& operator>>(istream& is, Person& p) {
    is >> p.name >> p.age;
    return is;
}

ПЕРЕГРУЗКА ОПЕРАТОРА ИНДЕКСАЦИИ []:

Пример:
class Array {
private:
    int* data;
    int size;
public:
    int& operator[](int index) {  // для изменения
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw out_of_range("Индекс вне границ");
    }
    
    const int& operator[](int index) const {  // для чтения
        if (index >= 0 && index < size) {
            return data[index];
        }
        throw out_of_range("Индекс вне границ");
    }
};

ПЕРЕГРУЗКА ОПЕРАТОРА ВЫЗОВА ФУНКЦИИ ():

Позволяет объекту вести себя как функция (функтор).

Пример:
class Multiplier {
private:
    int factor;
public:
    Multiplier(int f) : factor(f) {}
    
    int operator()(int value) {
        return value * factor;
    }
};

Использование:
Multiplier mult(5);
int result = mult(10);  // result = 50

ПРАВИЛА ПЕРЕГРУЗКИ ОПЕРАТОРОВ:

1. Нельзя изменить приоритет операторов
2. Нельзя изменить ассоциативность
3. Нельзя изменить количество операндов
4. Нельзя создавать новые операторы
5. Некоторые операторы должны быть методами класса (например, =, [], (), ->)
6. Сохраняйте семантику операторов (не делайте + как вычитание!)

РЕКОМЕНДАЦИИ:

1. Перегружайте операторы только когда это имеет смысл
2. Сохраняйте ожидаемое поведение
3. Используйте const где возможно
4. Возвращайте ссылки для операторов присваивания
5. Проверяйте на самоприсваивание в operator=
6. Используйте friend для операторов ввода/вывода

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
using namespace std;

// Класс для работы с комплексными числами
class Complex {
private:
    double real;
    double imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Перегрузка оператора +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    
    // Перегрузка оператора -
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }
    
    // Перегрузка оператора *
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }
    
    // Перегрузка оператора ==
    bool operator==(const Complex& other) const {
        return real == other.real && imag == other.imag;
    }
    
    // Перегрузка оператора !=
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }
    
    // Перегрузка оператора присваивания
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }
    
    // Перегрузка оператора +=
    Complex& operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }
    
    // Перегрузка оператора ++ (префиксный)
    Complex& operator++() {
        real++;
        return *this;
    }
    
    // Перегрузка оператора ++ (постфиксный)
    Complex operator++(int) {
        Complex temp = *this;
        real++;
        return temp;
    }
    
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << (-c.imag) << "i";
        }
        return os;
    }
    
    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Complex& c) {
        cout << "Введите действительную часть: ";
        is >> c.real;
        cout << "Введите мнимую часть: ";
        is >> c.imag;
        return is;
    }
    
    // Методы для получения значений
    double getReal() const { return real; }
    double getImag() const { return imag; }
};

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ ПЕРЕГРУЗКИ ОПЕРАТОРОВ ===" << endl;
    
    // Создание комплексных чисел
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    
    // Арифметические операции
    cout << "\n=== АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ ===" << endl;
    Complex sum = c1 + c2;
    cout << "c1 + c2 = " << sum << endl;
    
    Complex diff = c1 - c2;
    cout << "c1 - c2 = " << diff << endl;
    
    Complex product = c1 * c2;
    cout << "c1 * c2 = " << product << endl;
    
    // Операторы сравнения
    cout << "\n=== ОПЕРАТОРЫ СРАВНЕНИЯ ===" << endl;
    cout << "c1 == c2: " << (c1 == c2) << endl;
    cout << "c1 != c2: " << (c1 != c2) << endl;
    
    // Операторы присваивания
    cout << "\n=== ОПЕРАТОРЫ ПРИСВАИВАНИЯ ===" << endl;
    Complex c3 = c1;
    cout << "c3 = c1: " << c3 << endl;
    
    c3 += c2;
    cout << "c3 += c2: " << c3 << endl;
    
    // Инкремент
    cout << "\n=== ИНКРЕМЕНТ ===" << endl;
    Complex c4(5, 6);
    cout << "c4 = " << c4 << endl;
    cout << "++c4 = " << ++c4 << endl;
    cout << "c4++ = " << c4++ << endl;
    cout << "c4 = " << c4 << endl;
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Перегрузка операторов для класса Vector
Создай класс Vector с перегруженными операторами:
*/

class Vector {
private:
    double x, y, z;
    
public:
    Vector(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    
    // Перегрузка оператора +
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }
    
    // Перегрузка оператора -
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }
    
    // Перегрузка оператора * (скалярное произведение)
    double operator*(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }
    
    // Перегрузка оператора * (умножение на скаляр)
    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }
    
    // Перегрузка оператора ==
    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }
    
    // Перегрузка оператора !=
    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
    
    // Перегрузка оператора присваивания
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
    
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Vector& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
    
    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Vector& v) {
        cout << "Введите x: ";
        is >> v.x;
        cout << "Введите y: ";
        is >> v.y;
        cout << "Введите z: ";
        is >> v.z;
        return is;
    }
    
    // Метод для вычисления длины вектора
    double length() const {
        return sqrt(x*x + y*y + z*z);
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: ВЕКТОРЫ ===" << endl;
    
    Vector v1(1, 2, 3);
    Vector v2(4, 5, 6);
    
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    
    Vector sum = v1 + v2;
    cout << "v1 + v2 = " << sum << endl;
    
    Vector diff = v1 - v2;
    cout << "v1 - v2 = " << diff << endl;
    
    double dotProduct = v1 * v2;
    cout << "v1 * v2 (скалярное произведение) = " << dotProduct << endl;
    
    Vector scaled = v1 * 2.0;
    cout << "v1 * 2 = " << scaled << endl;
    
    cout << "Длина v1 = " << v1.length() << endl;
}

/*
Упражнение 2: Перегрузка операторов для класса Matrix
Создай класс Matrix с перегруженными операторами:
*/

class Matrix {
private:
    double data[2][2];
    
public:
    Matrix(double a = 0, double b = 0, double c = 0, double d = 0) {
        data[0][0] = a; data[0][1] = b;
        data[1][0] = c; data[1][1] = d;
    }
    
    // Перегрузка оператора +
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
    
    // Перегрузка оператора -
    Matrix operator-(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
    
    // Перегрузка оператора * (умножение матриц)
    Matrix operator*(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    
    // Перегрузка оператора ==
    bool operator==(const Matrix& other) const {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Перегрузка оператора !=
    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
    
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Matrix& m) {
        os << "[" << m.data[0][0] << " " << m.data[0][1] << "]" << endl;
        os << "[" << m.data[1][0] << " " << m.data[1][1] << "]";
        return os;
    }
    
    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Matrix& m) {
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout << "Элемент [" << i << "][" << j << "]: ";
                is >> m.data[i][j];
            }
        }
        return is;
    }
    
    // Метод для вычисления определителя
    double determinant() const {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: МАТРИЦЫ ===" << endl;
    
    Matrix m1(1, 2, 3, 4);
    Matrix m2(5, 6, 7, 8);
    
    cout << "m1:" << endl << m1 << endl << endl;
    cout << "m2:" << endl << m2 << endl << endl;
    
    Matrix sum = m1 + m2;
    cout << "m1 + m2:" << endl << sum << endl << endl;
    
    Matrix diff = m1 - m2;
    cout << "m1 - m2:" << endl << diff << endl << endl;
    
    Matrix product = m1 * m2;
    cout << "m1 * m2:" << endl << product << endl << endl;
    
    cout << "Определитель m1: " << m1.determinant() << endl;
}

/*
Упражнение 3: Перегрузка операторов для класса String
Создай класс String с перегруженными операторами:
*/

class String {
private:
    char* data;
    int length;
    
public:
    // Конструктор
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    
    // Конструктор копирования
    String(const String& other) {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }
    
    // Деструктор
    ~String() {
        delete[] data;
    }
    
    // Перегрузка оператора присваивания
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }
    
    // Перегрузка оператора +
    String operator+(const String& other) const {
        String result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }
    
    // Перегрузка оператора +=
    String& operator+=(const String& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        delete[] data;
        data = temp;
        length += other.length;
        return *this;
    }
    
    // Перегрузка оператора ==
    bool operator==(const String& other) const {
        return strcmp(data, other.data) == 0;
    }
    
    // Перегрузка оператора !=
    bool operator!=(const String& other) const {
        return !(*this == other);
    }
    
    // Перегрузка оператора <
    bool operator<(const String& other) const {
        return strcmp(data, other.data) < 0;
    }
    
    // Перегрузка оператора >
    bool operator>(const String& other) const {
        return strcmp(data, other.data) > 0;
    }
    
    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const String& s) {
        os << s.data;
        return os;
    }
    
    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, String& s) {
        char buffer[1000];
        is >> buffer;
        s = String(buffer);
        return is;
    }
    
    // Метод для получения длины
    int getLength() const {
        return length;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: СТРОКИ ===" << endl;
    
    String s1("Hello");
    String s2("World");
    
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    
    String s3 = s1 + s2;
    cout << "s1 + s2 = " << s3 << endl;
    
    s1 += s2;
    cout << "s1 += s2: " << s1 << endl;
    
    cout << "s1 == s2: " << (s1 == s2) << endl;
    cout << "s1 != s2: " << (s1 != s2) << endl;
    cout << "s1 < s2: " << (s1 < s2) << endl;
    cout << "s1 > s2: " << (s1 > s2) << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Перегрузка операторов для класса Fraction
Создай класс Fraction с перегруженными операторами:
- Арифметические: +, -, *, /
- Сравнения: ==, !=, <, >, <=, >=
- Присваивания: =, +=, -=, *=, /=
- Ввода/вывода: <<, >>

Задание 2: Перегрузка операторов для класса Point
Создай класс Point с перегруженными операторами:
- Арифметические: +, -, *
- Сравнения: ==, !=
- Присваивания: =, +=, -=
- Ввода/вывода: <<, >>

Задание 3: Перегрузка операторов для класса Set
Создай класс Set с перегруженными операторами:
- Объединение: +
- Пересечение: *
- Разность: -
- Сравнения: ==, !=
- Присваивания: =, +=, -=, *=

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое перегрузка операторов?
2. Какие операторы можно перегружать?
3. Какие операторы нельзя перегружать?
4. В чем разница между унарными и бинарными операторами?
5. Что такое friend функции?
6. Как перегрузить операторы ввода/вывода?
7. Зачем нужна перегрузка операторов?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Шаблоны функций
- Шаблоны классов
- Параметры шаблонов
- Специализация шаблонов
- Применение шаблонов

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 16: ПЕРЕГРУЗКА ОПЕРАТОРОВ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ВЕКТОРЫ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: МАТРИЦЫ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: СТРОКИ ===" << endl;
    exercise3();
    
    return 0;
}


















