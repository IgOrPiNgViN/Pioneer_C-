/*
===========================================
УРОК 14: ИНКАПСУЛЯЦИЯ И МОДИФИКАТОРЫ ДОСТУПА
===========================================

ЦЕЛИ УРОКА:
- Понять принцип инкапсуляции
- Изучить модификаторы доступа (public, private, protected)
- Научиться создавать геттеры и сеттеры
- Освоить сокрытие данных
- Понять преимущества инкапсуляции

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ЧТО ТАКОЕ ИНКАПСУЛЯЦИЯ:

Инкапсуляция - это один из трёх основных принципов ООП (вместе с наследованием и полиморфизмом).

Инкапсуляция означает:
1. Объединение данных и методов в одном классе
2. Сокрытие внутренней реализации от внешнего кода
3. Контроль доступа к данным через методы
4. Защита данных от неправильного использования

Аналогия из реальной жизни:
- Телевизор: мы используем пульт (интерфейс), но не знаем, что внутри
- Автомобиль: мы используем руль и педали, но не трогаем двигатель напрямую
- Банкомат: мы вводим ПИН-код и получаем деньги, но не видим механизм внутри

ЗАЧЕМ НУЖНА ИНКАПСУЛЯЦИЯ:

1. ЗАЩИТА ДАННЫХ:
   - Предотвращение случайного изменения важных данных
   - Контроль допустимых значений
   - Защита от ошибок программиста
   
   Пример без инкапсуляции (ПЛОХО):
   class Person {
   public:
       int age;  // любой может установить отрицательный возраст!
   };
   
   Person p;
   p.age = -100;  // Ошибка! Но компилятор не жалуется
   
   Пример с инкапсуляцией (ХОРОШО):
   class Person {
   private:
       int age;
   public:
       void setAge(int a) {
           if (a >= 0 && a <= 150) {
               age = a;
           }
       }
   };

2. ГИБКОСТЬ ИЗМЕНЕНИЙ:
   - Можно изменить внутреннюю реализацию, не меняя интерфейс
   - Код, использующий класс, не нужно переписывать
   
3. УПРОЩЕНИЕ ИСПОЛЬЗОВАНИЯ:
   - Пользователь класса видит только нужные методы
   - Не нужно знать детали реализации
   
4. ОТЛАДКА И ПОДДЕРЖКА:
   - Легче найти ошибки (данные меняются только через методы)
   - Можно добавить логирование в методы

МОДИФИКАТОРЫ ДОСТУПА:

В C++ есть три модификатора доступа:

1. PRIVATE (приватный):
   - Доступны ТОЛЬКО внутри класса
   - Недоступны извне класса
   - Недоступны в классах-наследниках
   - По умолчанию в классах (class)
   
   class Example {
   private:
       int secretData;  // только методы этого класса могут обращаться
       
       void secretMethod() {  // тоже только для внутреннего использования
           // ...
       }
   };

2. PUBLIC (публичный):
   - Доступны везде: внутри класса, извне, в наследниках
   - Составляют интерфейс класса
   - По умолчанию в структурах (struct)
   
   class Example {
   public:
       void publicMethod() {  // можно вызывать извне
           // ...
       }
   };

3. PROTECTED (защищённый):
   - Доступны внутри класса
   - Доступны в классах-наследниках
   - Недоступны извне
   - Используется для наследования
   
   class Example {
   protected:
       int protectedData;  // доступно наследникам, но не внешнему коду
   };

СРАВНЕНИЕ МОДИФИКАТОРОВ:

╔════════════════╦═══════════╦═════════════╦═══════════╗
║ Модификатор    ║ Свой класс║ Наследники  ║ Извне     ║
╠════════════════╬═══════════╬═════════════╬═══════════╣
║ private        ║    ДА     ║     НЕТ     ║    НЕТ    ║
║ protected      ║    ДА     ║     ДА      ║    НЕТ    ║
║ public         ║    ДА     ║     ДА      ║    ДА     ║
╚════════════════╩═══════════╩═════════════╩═══════════╝

ГЕТТЕРЫ И СЕТТЕРЫ:

Геттеры (getters) - методы для ПОЛУЧЕНИЯ значений приватных полей.
Сеттеры (setters) - методы для УСТАНОВКИ значений приватных полей.

Соглашения по именованию:
- Геттер: getИмяПоля() или просто имяПоля()
- Сеттер: setИмяПоля(значение)

Пример:
class Student {
private:
    string name;
    int age;
    double grade;

public:
    // Геттеры:
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGrade() const { return grade; }
    
    // Сеттеры:
    void setName(const string& n) { name = n; }
    
    void setAge(int a) {
        if (a >= 5 && a <= 100) {  // валидация
            age = a;
        }
    }
    
    void setGrade(double g) {
        if (g >= 0.0 && g <= 5.0) {  // валидация
            grade = g;
        }
    }
};

КОНСТАНТНЫЕ ГЕТТЕРЫ:

Геттеры не должны изменять объект, поэтому их делают const:

string getName() const {  // const означает, что метод не изменяет объект
    return name;
}

Преимущества const методов:
- Можно вызывать на константных объектах
- Компилятор проверит, что метод не изменяет данные
- Документирует намерение программиста

ВАЛИДАЦИЯ ДАННЫХ В СЕТТЕРАХ:

Одно из главных преимуществ инкапсуляции - возможность проверять данные:

class BankAccount {
private:
    double balance;
    
public:
    void setBalance(double b) {
        if (b >= 0) {  // баланс не может быть отрицательным
            balance = b;
        } else {
            cout << "Ошибка: баланс не может быть отрицательным!" << endl;
        }
    }
    
    void deposit(double amount) {
        if (amount > 0) {  // нельзя внести отрицательную сумму
            balance += amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {  // проверка на достаточность средств
            balance -= amount;
            return true;
        }
        return false;
    }
};

ИНКАПСУЛЯЦИЯ И ИНВАРИАНТЫ:

Инвариант класса - это условие, которое всегда должно быть истинным для объекта.

Пример: класс Date (дата)
- Месяц всегда от 1 до 12
- День соответствует месяцу
- Год положительный

class Date {
private:
    int day, month, year;
    
    bool isValidDate(int d, int m, int y) {
        if (y < 1 || m < 1 || m > 12 || d < 1) return false;
        
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Проверка високосного года
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            daysInMonth[1] = 29;
        }
        
        return d <= daysInMonth[m - 1];
    }
    
public:
    bool setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            return true;
        }
        return false;
    }
};

ДРУЗЬЯ КЛАССА (FRIEND):

Иногда нужно дать доступ к приватным членам другому классу или функции.
Для этого используется ключевое слово friend.

class Secret {
private:
    int secretNumber;
    
    friend void showSecret(const Secret& s);  // функция-друг
    friend class SecretViewer;  // класс-друг
};

void showSecret(const Secret& s) {
    cout << s.secretNumber;  // имеет доступ к private членам
}

Важно: friend нарушает инкапсуляцию, используйте осторожно!

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ============================================
// ПРИМЕР 1: Базовая инкапсуляция
// ============================================

class Person {
private:
    string name;
    int age;
    
public:
    // Геттеры
    string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    // Сеттеры с валидацией
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        } else {
            cout << "Ошибка: имя не может быть пустым!" << endl;
        }
    }
    
    void setAge(int a) {
        if (a >= 0 && a <= 150) {
            age = a;
        } else {
            cout << "Ошибка: недопустимый возраст (" << a << ")!" << endl;
        }
    }
    
    // Метод для вывода информации
    void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age << " лет" << endl;
    }
};

void example1() {
    cout << "=== ПРИМЕР 1: Базовая инкапсуляция ===" << endl;
    
    Person person;
    
    // Правильное использование
    person.setName("Иван");
    person.setAge(25);
    person.displayInfo();
    
    // Попытка установить неправильные значения
    person.setAge(-10);  // Ошибка!
    person.setAge(200);  // Ошибка!
    person.setName("");  // Ошибка!
    
    // Значения не изменились
    person.displayInfo();
    
    cout << endl;
}

// ============================================
// ПРИМЕР 2: Банковский счёт с инкапсуляцией
// ============================================

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    double interestRate;  // процентная ставка
    
    // Приватный метод для генерации номера счёта
    string generateAccountNumber() {
        // Простая генерация (в реальности используется более сложная логика)
        return "ACC-" + to_string(rand() % 1000000);
    }
    
public:
    // Конструктор
    BankAccount(const string& owner, double initialDeposit = 0.0) {
        accountNumber = generateAccountNumber();
        ownerName = owner;
        balance = (initialDeposit >= 0) ? initialDeposit : 0;
        interestRate = 0.05;  // 5% годовых
    }
    
    // Геттеры (только для чтения)
    string getAccountNumber() const { return accountNumber; }
    string getOwnerName() const { return ownerName; }
    double getBalance() const { return balance; }
    double getInterestRate() const { return interestRate; }
    
    // Методы для операций со счётом
    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Внесено: " << amount << " руб. Новый баланс: " << balance << " руб." << endl;
            return true;
        }
        cout << "Ошибка: сумма должна быть положительной!" << endl;
        return false;
    }
    
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма должна быть положительной!" << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Ошибка: недостаточно средств! Доступно: " << balance << " руб." << endl;
            return false;
        }
        balance -= amount;
        cout << "Снято: " << amount << " руб. Новый баланс: " << balance << " руб." << endl;
        return true;
    }
    
    void addInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Начислены проценты: " << interest << " руб." << endl;
    }
    
    void displayAccount() const {
        cout << "========================================" << endl;
        cout << "Номер счёта: " << accountNumber << endl;
        cout << "Владелец: " << ownerName << endl;
        cout << "Баланс: " << balance << " руб." << endl;
        cout << "Процентная ставка: " << (interestRate * 100) << "%" << endl;
        cout << "========================================" << endl;
    }
};

void example2() {
    cout << "=== ПРИМЕР 2: Банковский счёт ===" << endl;
    
    BankAccount account("Иван Иванов", 10000.0);
    account.displayAccount();
    
    account.deposit(5000.0);
    account.withdraw(3000.0);
    account.addInterest();
    
    // Попытка снять больше, чем есть
    account.withdraw(100000.0);
    
    // Попытка внести отрицательную сумму
    account.deposit(-500.0);
    
    account.displayAccount();
    
    cout << endl;
}

// ============================================
// ПРИМЕР 3: Класс с разными уровнями доступа
// ============================================

class Employee {
private:
    string name;
    double salary;      // приватно - зарплата конфиденциальна
    string password;    // приватно - пароль секретен
    
protected:
    string department;  // защищённо - доступно наследникам
    int employeeId;     // защищённо - доступно наследникам
    
public:
    string position;    // публично - должность видна всем
    
    Employee(const string& n, const string& pos, double sal) {
        name = n;
        position = pos;
        salary = sal;
        department = "Не указан";
        employeeId = rand() % 10000;
        password = "default123";
    }
    
    // Публичные методы
    string getName() const { return name; }
    
    void setName(const string& n) {
        if (!n.empty()) {
            name = n;
        }
    }
    
    // Метод для изменения зарплаты (только через авторизацию)
    bool changeSalary(double newSalary, const string& adminPassword) {
        if (adminPassword == "admin123") {  // проверка авторизации
            if (newSalary >= 0) {
                salary = newSalary;
                cout << "Зарплата изменена на " << newSalary << " руб." << endl;
                return true;
            }
        }
        cout << "Ошибка: доступ запрещён или неверные данные!" << endl;
        return false;
    }
    
    // Метод для смены пароля
    bool changePassword(const string& oldPass, const string& newPass) {
        if (oldPass == password && newPass.length() >= 6) {
            password = newPass;
            cout << "Пароль успешно изменён!" << endl;
            return true;
        }
        cout << "Ошибка при смене пароля!" << endl;
        return false;
    }
    
    void displayInfo() const {
        cout << "Сотрудник: " << name << endl;
        cout << "Должность: " << position << endl;
        cout << "Отдел: " << department << endl;
        cout << "ID: " << employeeId << endl;
        // salary и password НЕ показываем - они секретные!
    }
};

void example3() {
    cout << "=== ПРИМЕР 3: Разные уровни доступа ===" << endl;
    
    Employee emp("Пётр Петров", "Программист", 100000.0);
    emp.displayInfo();
    
    // Публичное поле можно изменить напрямую
    emp.position = "Старший программист";
    
    // Приватные данные - только через методы
    emp.changeSalary(120000.0, "admin123");  // с правильным паролем
    emp.changeSalary(150000.0, "wrong");     // с неправильным паролем
    
    emp.changePassword("default123", "newpass123");  // смена пароля
    
    cout << endl;
}

// ============================================
// ПРИМЕР 4: Класс Temperature с валидацией
// ============================================

class Temperature {
private:
    double celsius;
    
    // Приватный метод для проверки допустимости температуры
    bool isValidTemperature(double temp) const {
        // Абсолютный ноль: -273.15°C
        return temp >= -273.15;
    }
    
public:
    Temperature(double temp = 0.0) {
        setCelsius(temp);
    }
    
    // Геттеры для разных единиц измерения
    double getCelsius() const {
        return celsius;
    }
    
    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }
    
    double getKelvin() const {
        return celsius + 273.15;
    }
    
    // Сеттеры для разных единиц измерения
    bool setCelsius(double temp) {
        if (isValidTemperature(temp)) {
            celsius = temp;
            return true;
        }
        cout << "Ошибка: температура не может быть ниже абсолютного нуля!" << endl;
        return false;
    }
    
    bool setFahrenheit(double temp) {
        double celsiusTemp = (temp - 32.0) * 5.0 / 9.0;
        return setCelsius(celsiusTemp);
    }
    
    bool setKelvin(double temp) {
        return setCelsius(temp - 273.15);
    }
    
    // Описание температуры
    string getDescription() const {
        if (celsius < -40) return "Экстремальный холод";
        if (celsius < 0) return "Мороз";
        if (celsius < 10) return "Холодно";
        if (celsius < 20) return "Прохладно";
        if (celsius < 25) return "Комфортно";
        if (celsius < 30) return "Тепло";
        if (celsius < 40) return "Жарко";
        return "Экстремальная жара";
    }
    
    void display() const {
        cout << "Температура:" << endl;
        cout << "  Цельсий: " << celsius << "°C" << endl;
        cout << "  Фаренгейт: " << getFahrenheit() << "°F" << endl;
        cout << "  Кельвин: " << getKelvin() << " K" << endl;
        cout << "  Описание: " << getDescription() << endl;
    }
};

void example4() {
    cout << "=== ПРИМЕР 4: Класс Temperature ===" << endl;
    
    Temperature temp(25.0);
    temp.display();
    
    cout << "\nУстановим температуру в Фаренгейтах (100°F):" << endl;
    temp.setFahrenheit(100.0);
    temp.display();
    
    cout << "\nПопытка установить температуру ниже абсолютного нуля:" << endl;
    temp.setCelsius(-300.0);  // Ошибка!
    
    cout << "\nТемпература не изменилась:" << endl;
    temp.display();
    
    cout << endl;
}

// ============================================
// ПРИМЕР 5: Класс Password (пароль)
// ============================================

class Password {
private:
    string password;
    int failedAttempts;
    bool isLocked;
    static const int MAX_ATTEMPTS = 3;
    
    // Приватный метод для проверки сложности пароля
    bool isStrongPassword(const string& pass) const {
        if (pass.length() < 8) return false;
        
        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        
        for (char c : pass) {
            if (isupper(c)) hasUpper = true;
            if (islower(c)) hasLower = true;
            if (isdigit(c)) hasDigit = true;
        }
        
        return hasUpper && hasLower && hasDigit;
    }
    
public:
    Password() {
        password = "";
        failedAttempts = 0;
        isLocked = false;
    }
    
    // Установка нового пароля с проверкой сложности
    bool setPassword(const string& newPass) {
        if (isLocked) {
            cout << "Аккаунт заблокирован!" << endl;
            return false;
        }
        
        if (!isStrongPassword(newPass)) {
            cout << "Слабый пароль! Требования:" << endl;
            cout << "  - Минимум 8 символов" << endl;
            cout << "  - Минимум 1 заглавная буква" << endl;
            cout << "  - Минимум 1 строчная буква" << endl;
            cout << "  - Минимум 1 цифра" << endl;
            return false;
        }
        
        password = newPass;
        cout << "Пароль успешно установлен!" << endl;
        return true;
    }
    
    // Проверка пароля
    bool verify(const string& attempt) {
        if (isLocked) {
            cout << "Аккаунт заблокирован! Обратитесь к администратору." << endl;
            return false;
        }
        
        if (password.empty()) {
            cout << "Пароль не установлен!" << endl;
            return false;
        }
        
        if (attempt == password) {
            failedAttempts = 0;  // сброс счётчика
            cout << "Пароль верный!" << endl;
            return true;
        }
        
        failedAttempts++;
        cout << "Неверный пароль! Осталось попыток: " << (MAX_ATTEMPTS - failedAttempts) << endl;
        
        if (failedAttempts >= MAX_ATTEMPTS) {
            isLocked = true;
            cout << "Аккаунт заблокирован из-за превышения попыток!" << endl;
        }
        
        return false;
    }
    
    // Разблокировка (только для администратора)
    void unlock(const string& adminKey) {
        if (adminKey == "ADMIN_MASTER_KEY") {
            isLocked = false;
            failedAttempts = 0;
            cout << "Аккаунт разблокирован!" << endl;
        }
    }
    
    bool getIsLocked() const { return isLocked; }
};

void example5() {
    cout << "=== ПРИМЕР 5: Класс Password ===" << endl;
    
    Password pwd;
    
    // Попытка установить слабый пароль
    cout << "Попытка установить слабый пароль:" << endl;
    pwd.setPassword("123");
    pwd.setPassword("password");
    pwd.setPassword("PASSWORD123");
    
    // Установка сильного пароля
    cout << "\nУстановка сильного пароля:" << endl;
    pwd.setPassword("MyPassword123");
    
    // Проверка пароля
    cout << "\nПроверка пароля:" << endl;
    pwd.verify("MyPassword123");  // верный
    
    // Неверные попытки
    cout << "\nНеверные попытки:" << endl;
    pwd.verify("wrong1");
    pwd.verify("wrong2");
    pwd.verify("wrong3");  // блокировка
    
    // После блокировки
    pwd.verify("MyPassword123");  // не сработает
    
    // Разблокировка
    cout << "\nРазблокировка администратором:" << endl;
    pwd.unlock("ADMIN_MASTER_KEY");
    pwd.verify("MyPassword123");  // теперь работает
    
    cout << endl;
}

// ============================================
// ГЛАВНАЯ ФУНКЦИЯ
// ============================================

int main() {
    cout << "===========================================\n";
    cout << "УРОК 14: ИНКАПСУЛЯЦИЯ И МОДИФИКАТОРЫ ДОСТУПА\n";
    cout << "===========================================\n\n";
    
    example1();
    example2();
    example3();
    example4();
    example5();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Класс Rectangle (Прямоугольник)
Создай класс Rectangle с приватными полями width и height.
Добавь валидацию: стороны должны быть положительными.
Добавь методы для вычисления площади и периметра.

Упражнение 2: Класс Time (Время)
Создай класс Time с приватными полями hours, minutes, seconds.
Добавь валидацию: часы 0-23, минуты 0-59, секунды 0-59.
Добавь методы для сложения времени и вывода в разных форматах.

Упражнение 3: Класс Student (Студент)
Создай класс Student с приватными полями name, age, grades[].
Добавь методы для добавления оценок, расчёта среднего балла.
Добавь валидацию: оценки от 1 до 5, возраст от 5 до 100.

ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Класс Counter (Счётчик)
- Приватное поле value
- Методы increment(), decrement(), reset()
- Ограничение: значение не может быть отрицательным
- Метод getValue() для получения значения

Задание 2: Класс Circle (Круг)
- Приватное поле radius
- Валидация: радиус должен быть положительным
- Методы: getArea(), getCircumference(), getDiameter()
- Сеттер с проверкой

Задание 3: Класс Product (Товар)
- Приватные поля: name, price, quantity
- Валидация: цена и количество не могут быть отрицательными
- Методы: buy(количество), restock(количество)
- Метод getTotalValue() = price * quantity

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое инкапсуляция?
2. Какие три модификатора доступа есть в C++?
3. Чем private отличается от protected?
4. Что такое геттеры и сеттеры?
5. Зачем делать поля private?
6. Что такое инвариант класса?
7. Как объявить метод, который не изменяет объект?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Наследование классов
- Базовые и производные классы
- Переопределение методов
- Виды наследования

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/
