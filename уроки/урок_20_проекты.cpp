/*
===========================================
УРОК 20: ПРАКТИЧЕСКИЕ ПРОЕКТЫ
===========================================

ЦЕЛИ УРОКА:
- Применить все изученные концепции C++
- Создать полноценные программы
- Научиться проектировать архитектуру приложений
- Освоить работу с файлами и данными
- Понять процесс разработки программ

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПРАКТИЧЕСКИЕ ПРОЕКТЫ:

В этом уроке мы создадим несколько полноценных проектов, используя все изученные концепции C++:
- Классы и объекты
- Наследование и полиморфизм
- Шаблоны
- STL
- Обработка исключений
- Работа с файлами

ПРОЕКТ 1: СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ
- Класс Student с данными о студенте
- Класс StudentManager для управления студентами
- Сохранение и загрузка данных
- Поиск и сортировка студентов

ПРОЕКТ 2: КАЛЬКУЛЯТОР С ИСТОРИЕЙ
- Класс Calculator для вычислений
- Класс History для хранения истории
- Различные типы операций
- Сохранение истории в файл

ПРОЕКТ 3: ИГРА "УГАДАЙ ЧИСЛО"
- Класс Game для управления игрой
- Класс Player для игрока
- Статистика игр
- Различные уровни сложности

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// ПРОЕКТ 1: СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ
class Student {
private:
    string name;
    int age;
    double grade;
    string major;
    
public:
    Student(string n = "", int a = 0, double g = 0.0, string m = "") 
        : name(n), age(a), grade(g), major(m) {}
    
    // Геттеры
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGrade() const { return grade; }
    string getMajor() const { return major; }
    
    // Сеттеры
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setGrade(double g) { grade = g; }
    void setMajor(string m) { major = m; }
    
    // Методы
    void displayInfo() const {
        cout << "Имя: " << name << ", Возраст: " << age 
             << ", Оценка: " << grade << ", Специальность: " << major << endl;
    }
    
    // Оператор для записи в файл
    friend ostream& operator<<(ostream& os, const Student& s) {
        os << s.name << " " << s.age << " " << s.grade << " " << s.major;
        return os;
    }
    
    // Оператор для чтения из файла
    friend istream& operator>>(istream& is, Student& s) {
        is >> s.name >> s.age >> s.grade >> s.major;
        return is;
    }
};

class StudentManager {
private:
    vector<Student> students;
    string filename;
    
public:
    StudentManager(string fname = "students.txt") : filename(fname) {}
    
    void addStudent(const Student& student) {
        students.push_back(student);
        cout << "Студент добавлен!" << endl;
    }
    
    void removeStudent(const string& name) {
        auto it = find_if(students.begin(), students.end(),
            [&name](const Student& s) { return s.getName() == name; });
        
        if (it != students.end()) {
            students.erase(it);
            cout << "Студент удален!" << endl;
        } else {
            cout << "Студент не найден!" << endl;
        }
    }
    
    void displayAllStudents() const {
        cout << "\n=== СПИСОК СТУДЕНТОВ ===" << endl;
        for (const Student& student : students) {
            student.displayInfo();
        }
    }
    
    void searchStudent(const string& name) const {
        auto it = find_if(students.begin(), students.end(),
            [&name](const Student& s) { return s.getName() == name; });
        
        if (it != students.end()) {
            cout << "Студент найден:" << endl;
            it->displayInfo();
        } else {
            cout << "Студент не найден!" << endl;
        }
    }
    
    void sortByGrade() {
        sort(students.begin(), students.end(),
            [](const Student& a, const Student& b) {
                return a.getGrade() > b.getGrade();
            });
        cout << "Студенты отсортированы по оценкам!" << endl;
    }
    
    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const Student& student : students) {
                file << student << endl;
            }
            file.close();
            cout << "Данные сохранены в файл!" << endl;
        } else {
            cout << "Ошибка сохранения файла!" << endl;
        }
    }
    
    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            students.clear();
            Student student;
            while (file >> student) {
                students.push_back(student);
            }
            file.close();
            cout << "Данные загружены из файла!" << endl;
        } else {
            cout << "Файл не найден!" << endl;
        }
    }
};

// ПРОЕКТ 2: КАЛЬКУЛЯТОР С ИСТОРИЕЙ
class Calculator {
public:
    static double add(double a, double b) { return a + b; }
    static double subtract(double a, double b) { return a - b; }
    static double multiply(double a, double b) { return a * b; }
    static double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Деление на ноль!");
        }
        return a / b;
    }
};

class History {
private:
    vector<string> operations;
    string filename;
    
public:
    History(string fname = "history.txt") : filename(fname) {}
    
    void addOperation(const string& operation) {
        operations.push_back(operation);
    }
    
    void displayHistory() const {
        cout << "\n=== ИСТОРИЯ ОПЕРАЦИЙ ===" << endl;
        for (const string& op : operations) {
            cout << op << endl;
        }
    }
    
    void saveToFile() {
        ofstream file(filename);
        if (file.is_open()) {
            for (const string& op : operations) {
                file << op << endl;
            }
            file.close();
            cout << "История сохранена!" << endl;
        }
    }
    
    void loadFromFile() {
        ifstream file(filename);
        if (file.is_open()) {
            operations.clear();
            string line;
            while (getline(file, line)) {
                operations.push_back(line);
            }
            file.close();
            cout << "История загружена!" << endl;
        }
    }
};

// ПРОЕКТ 3: ИГРА "УГАДАЙ ЧИСЛО"
class Player {
private:
    string name;
    int gamesPlayed;
    int gamesWon;
    
public:
    Player(string n = "Игрок") : name(n), gamesPlayed(0), gamesWon(0) {}
    
    string getName() const { return name; }
    int getGamesPlayed() const { return gamesPlayed; }
    int getGamesWon() const { return gamesWon; }
    
    void playGame() { gamesPlayed++; }
    void winGame() { gamesWon++; }
    
    double getWinRate() const {
        return gamesPlayed > 0 ? (double)gamesWon / gamesPlayed * 100 : 0;
    }
    
    void displayStats() const {
        cout << "Игрок: " << name << endl;
        cout << "Игр сыграно: " << gamesPlayed << endl;
        cout << "Игр выиграно: " << gamesWon << endl;
        cout << "Процент побед: " << getWinRate() << "%" << endl;
    }
};

class Game {
private:
    int secretNumber;
    int maxAttempts;
    int attempts;
    Player* player;
    
public:
    Game(Player* p = nullptr) : player(p), attempts(0), maxAttempts(7) {
        srand(time(0));
    }
    
    void startNewGame() {
        secretNumber = rand() % 100 + 1;
        attempts = 0;
        cout << "Новая игра! Угадайте число от 1 до 100" << endl;
        cout << "У вас " << maxAttempts << " попыток" << endl;
    }
    
    bool makeGuess(int guess) {
        attempts++;
        
        if (guess == secretNumber) {
            cout << "Поздравляем! Вы угадали число " << secretNumber << " за " << attempts << " попыток!" << endl;
            if (player) {
                player->playGame();
                player->winGame();
            }
            return true;
        } else if (guess < secretNumber) {
            cout << "Загаданное число больше!" << endl;
        } else {
            cout << "Загаданное число меньше!" << endl;
        }
        
        if (attempts >= maxAttempts) {
            cout << "Игра окончена! Загаданное число было " << secretNumber << endl;
            if (player) {
                player->playGame();
            }
        }
        
        return false;
    }
    
    int getAttempts() const { return attempts; }
    int getMaxAttempts() const { return maxAttempts; }
};

int main() {
    cout << "=== ПРАКТИЧЕСКИЕ ПРОЕКТЫ ===" << endl;
    
    // Демонстрация проекта 1: Система управления студентами
    cout << "\n=== ПРОЕКТ 1: СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ ===" << endl;
    StudentManager manager;
    
    // Добавление студентов
    manager.addStudent(Student("Анна", 20, 4.5, "Информатика"));
    manager.addStudent(Student("Петр", 19, 3.8, "Математика"));
    manager.addStudent(Student("Мария", 21, 4.2, "Физика"));
    
    // Отображение всех студентов
    manager.displayAllStudents();
    
    // Поиск студента
    manager.searchStudent("Анна");
    
    // Сортировка по оценкам
    manager.sortByGrade();
    manager.displayAllStudents();
    
    // Сохранение в файл
    manager.saveToFile();
    
    // Демонстрация проекта 2: Калькулятор с историей
    cout << "\n=== ПРОЕКТ 2: КАЛЬКУЛЯТОР С ИСТОРИЕЙ ===" << endl;
    History history;
    
    try {
        double a = 10, b = 5;
        
        double result = Calculator::add(a, b);
        string operation = to_string(a) + " + " + to_string(b) + " = " + to_string(result);
        history.addOperation(operation);
        
        result = Calculator::multiply(a, b);
        operation = to_string(a) + " * " + to_string(b) + " = " + to_string(result);
        history.addOperation(operation);
        
        result = Calculator::divide(a, b);
        operation = to_string(a) + " / " + to_string(b) + " = " + to_string(result);
        history.addOperation(operation);
        
        history.displayHistory();
        history.saveToFile();
        
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    // Демонстрация проекта 3: Игра "Угадай число"
    cout << "\n=== ПРОЕКТ 3: ИГРА 'УГАДАЙ ЧИСЛО' ===" << endl;
    Player player("Тестовый игрок");
    Game game(&player);
    
    game.startNewGame();
    
    // Симуляция игры
    vector<int> guesses = {50, 75, 63, 69, 66, 67, 68};
    for (int guess : guesses) {
        cout << "Попытка " << game.getAttempts() + 1 << ": " << guess << endl;
        if (game.makeGuess(guess)) {
            break;
        }
    }
    
    player.displayStats();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Расширение системы управления студентами
Добавь в систему управления студентами:
- Поиск студентов по специальности
- Фильтрация по возрасту
- Статистика по оценкам
- Экспорт в различные форматы

Упражнение 2: Улучшение калькулятора
Добавь в калькулятор:
- Поддержку скобок
- Функции (sin, cos, sqrt)
- Константы (pi, e)
- Графический интерфейс (консольный)

Упражнение 3: Развитие игры
Добавь в игру:
- Различные уровни сложности
- Мультиплеер
- Турниры
- Рейтинговая система

ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Система управления библиотекой
Создай систему управления библиотекой:
- Класс Book для книг
- Класс Library для управления библиотекой
- Система выдачи и возврата книг
- Поиск и сортировка книг

Задание 2: Система управления задачами
Создай систему управления задачами:
- Класс Task для задач
- Класс TaskManager для управления
- Приоритеты и статусы задач
- Фильтрация и группировка

Задание 3: Система управления финансами
Создай систему управления финансами:
- Класс Transaction для транзакций
- Класс FinanceManager для управления
- Категории доходов и расходов
- Отчеты и аналитика

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Как применить ООП в реальных проектах?
2. Какие принципы проектирования использовать?
3. Как организовать работу с файлами?
4. Как обрабатывать ошибки в проектах?
5. Как тестировать программы?
6. Как оптимизировать производительность?
7. Как документировать код?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Дополнительные возможности C++
- Продвинутые темы
- Современные стандарты C++
- Лучшие практики программирования
- Подготовка к профессиональной разработке

ВРЕМЯ ИЗУЧЕНИЯ: 60-90 минут
ВРЕМЯ ПРАКТИКИ: 60-90 минут
ОБЩЕЕ ВРЕМЯ: 2-3 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 20: ПРАКТИЧЕСКИЕ ПРОЕКТЫ ===" << endl;
    
    return 0;
}





