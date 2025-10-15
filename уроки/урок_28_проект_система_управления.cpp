/*
===========================================
УРОК 28: ПРОЕКТ "СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ"
===========================================

ЦЕЛИ УРОКА:
- Создать полноценную систему управления студентами
- Применить все изученные концепции C++
- Научиться работать с файлами и данными
- Освоить создание систем управления
- Понять принципы разработки приложений

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПРОЕКТ "СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ":

Этот урок посвящен созданию полноценной системы управления студентами, которая демонстрирует
применение всех изученных концепций C++:

1. КЛАССЫ И ОБЪЕКТЫ:
   - Класс Student для представления студента
   - Класс StudentManager для управления студентами
   - Класс FileManager для работы с файлами

2. НАСЛЕДОВАНИЕ И ПОЛИМОРФИЗМ:
   - Базовый класс Person
   - Производный класс Student
   - Виртуальные функции для отображения информации

3. ШАБЛОНЫ:
   - Шаблонный класс для хранения данных
   - Шаблонные функции для обработки

4. STL:
   - Контейнеры для хранения данных
   - Алгоритмы для поиска и сортировки

5. ОБРАБОТКА ИСКЛЮЧЕНИЙ:
   - Обработка ошибок файлов
   - Валидация данных
   - Обработка неверных операций

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

// Базовый класс для персон
class Person {
protected:
    string name_;
    int age_;
    string email_;
    
public:
    Person(const string& name = "", int age = 0, const string& email = "")
        : name_(name), age_(age), email_(email) {}
    
    virtual ~Person() = default;
    
    virtual void displayInfo() const = 0;
    virtual string getType() const = 0;
    
    const string& getName() const { return name_; }
    int getAge() const { return age_; }
    const string& getEmail() const { return email_; }
    
    void setName(const string& name) { name_ = name; }
    void setAge(int age) { age_ = age; }
    void setEmail(const string& email) { email_ = email; }
};

// Класс для студента
class Student : public Person {
private:
    string studentId_;
    string major_;
    double gpa_;
    int year_;
    vector<string> courses_;
    
public:
    Student(const string& name = "", int age = 0, const string& email = "",
            const string& studentId = "", const string& major = "", 
            double gpa = 0.0, int year = 1)
        : Person(name, age, email), studentId_(studentId), major_(major), gpa_(gpa), year_(year) {}
    
    void displayInfo() const override {
        cout << "Студент: " << name_ << endl;
        cout << "  ID: " << studentId_ << endl;
        cout << "  Возраст: " << age_ << endl;
        cout << "  Email: " << email_ << endl;
        cout << "  Специальность: " << major_ << endl;
        cout << "  GPA: " << fixed << setprecision(2) << gpa_ << endl;
        cout << "  Курс: " << year_ << endl;
        cout << "  Предметы: ";
        for (const auto& course : courses_) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    string getType() const override {
        return "Студент";
    }
    
    const string& getStudentId() const { return studentId_; }
    const string& getMajor() const { return major_; }
    double getGpa() const { return gpa_; }
    int getYear() const { return year_; }
    const vector<string>& getCourses() const { return courses_; }
    
    void setStudentId(const string& studentId) { studentId_ = studentId; }
    void setMajor(const string& major) { major_ = major; }
    void setGpa(double gpa) { gpa_ = gpa; }
    void setYear(int year) { year_ = year; }
    
    void addCourse(const string& course) {
        courses_.push_back(course);
    }
    
    void removeCourse(const string& course) {
        auto it = find(courses_.begin(), courses_.end(), course);
        if (it != courses_.end()) {
            courses_.erase(it);
        }
    }
    
    // Операторы для работы с файлами
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.name_ << " " << student.age_ << " " << student.email_ << " "
           << student.studentId_ << " " << student.major_ << " " << student.gpa_ << " "
           << student.year_ << " " << student.courses_.size();
        for (const auto& course : student.courses_) {
            os << " " << course;
        }
        return os;
    }
    
    friend istream& operator>>(istream& is, Student& student) {
        is >> student.name_ >> student.age_ >> student.email_ >>
              student.studentId_ >> student.major_ >> student.gpa_ >> student.year_;
        
        int courseCount;
        is >> courseCount;
        student.courses_.clear();
        for (int i = 0; i < courseCount; ++i) {
            string course;
            is >> course;
            student.courses_.push_back(course);
        }
        return is;
    }
};

// Класс для работы с файлами
class FileManager {
public:
    static void saveStudents(const vector<Student>& students, const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            throw runtime_error("Не удалось открыть файл для записи: " + filename);
        }
        
        for (const auto& student : students) {
            file << student << endl;
        }
        
        file.close();
        cout << "Данные студентов сохранены в файл " << filename << endl;
    }
    
    static vector<Student> loadStudents(const string& filename) {
        vector<Student> students;
        ifstream file(filename);
        
        if (!file.is_open()) {
            cout << "Файл не найден: " << filename << endl;
            return students;
        }
        
        Student student;
        while (file >> student) {
            students.push_back(student);
        }
        
        file.close();
        cout << "Загружено " << students.size() << " студентов из файла " << filename << endl;
        return students;
    }
};

// Основной класс для управления студентами
class StudentManager {
private:
    vector<Student> students_;
    string filename_;
    
public:
    StudentManager(const string& filename = "students.txt") : filename_(filename) {
        loadFromFile();
    }
    
    ~StudentManager() {
        saveToFile();
    }
    
    void addStudent(const Student& student) {
        // Проверка на дубликаты
        if (findStudentById(student.getStudentId()) != nullptr) {
            throw invalid_argument("Студент с таким ID уже существует!");
        }
        
        students_.push_back(student);
        cout << "Студент добавлен!" << endl;
    }
    
    void removeStudent(const string& studentId) {
        auto it = find_if(students_.begin(), students_.end(),
            [&studentId](const Student& s) { return s.getStudentId() == studentId; });
        
        if (it != students_.end()) {
            students_.erase(it);
            cout << "Студент удален!" << endl;
        } else {
            cout << "Студент не найден!" << endl;
        }
    }
    
    Student* findStudentById(const string& studentId) {
        auto it = find_if(students_.begin(), students_.end(),
            [&studentId](const Student& s) { return s.getStudentId() == studentId; });
        
        return (it != students_.end()) ? &(*it) : nullptr;
    }
    
    vector<Student> findStudentsByName(const string& name) const {
        vector<Student> result;
        copy_if(students_.begin(), students_.end(), back_inserter(result),
            [&name](const Student& s) { return s.getName() == name; });
        return result;
    }
    
    vector<Student> findStudentsByMajor(const string& major) const {
        vector<Student> result;
        copy_if(students_.begin(), students_.end(), back_inserter(result),
            [&major](const Student& s) { return s.getMajor() == major; });
        return result;
    }
    
    void displayAllStudents() const {
        cout << "\n=== ВСЕ СТУДЕНТЫ ===" << endl;
        if (students_.empty()) {
            cout << "Нет студентов для отображения" << endl;
            return;
        }
        
        for (const auto& student : students_) {
            student.displayInfo();
            cout << endl;
        }
    }
    
    void sortByGpa() {
        sort(students_.begin(), students_.end(),
            [](const Student& a, const Student& b) { return a.getGpa() > b.getGpa(); });
        cout << "Студенты отсортированы по GPA" << endl;
    }
    
    void sortByName() {
        sort(students_.begin(), students_.end(),
            [](const Student& a, const Student& b) { return a.getName() < b.getName(); });
        cout << "Студенты отсортированы по имени" << endl;
    }
    
    void displayStatistics() const {
        if (students_.empty()) {
            cout << "Нет данных для статистики" << endl;
            return;
        }
        
        cout << "\n=== СТАТИСТИКА ===" << endl;
        cout << "Общее количество студентов: " << students_.size() << endl;
        
        // Статистика по курсам
        map<int, int> yearCount;
        for (const auto& student : students_) {
            yearCount[student.getYear()]++;
        }
        
        cout << "Распределение по курсам:" << endl;
        for (const auto& pair : yearCount) {
            cout << "  " << pair.first << " курс: " << pair.second << " студентов" << endl;
        }
        
        // Статистика по специальностям
        map<string, int> majorCount;
        for (const auto& student : students_) {
            majorCount[student.getMajor()]++;
        }
        
        cout << "Распределение по специальностям:" << endl;
        for (const auto& pair : majorCount) {
            cout << "  " << pair.first << ": " << pair.second << " студентов" << endl;
        }
        
        // Средний GPA
        double totalGpa = 0;
        for (const auto& student : students_) {
            totalGpa += student.getGpa();
        }
        double averageGpa = totalGpa / students_.size();
        cout << "Средний GPA: " << fixed << setprecision(2) << averageGpa << endl;
    }
    
    void saveToFile() {
        try {
            FileManager::saveStudents(students_, filename_);
        } catch (const exception& e) {
            cout << "Ошибка сохранения: " << e.what() << endl;
        }
    }
    
    void loadFromFile() {
        try {
            students_ = FileManager::loadStudents(filename_);
        } catch (const exception& e) {
            cout << "Ошибка загрузки: " << e.what() << endl;
        }
    }
    
    size_t getStudentCount() const {
        return students_.size();
    }
};

// Класс для пользовательского интерфейса
class StudentSystemMenu {
private:
    StudentManager manager_;
    
public:
    StudentSystemMenu() : manager_("students.txt") {}
    
    void run() {
        int choice;
        
        while (true) {
            displayMainMenu();
            cout << "Выберите действие: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    removeStudent();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    manager_.displayAllStudents();
                    break;
                case 5:
                    sortStudents();
                    break;
                case 6:
                    manager_.displayStatistics();
                    break;
                case 7:
                    manager_.saveToFile();
                    break;
                case 0:
                    cout << "До свидания!" << endl;
                    return;
                default:
                    cout << "Неверный выбор!" << endl;
                    break;
            }
            
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
    }
    
private:
    void displayMainMenu() {
        cout << "\n" << string(60, '=') << endl;
        cout << "           СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ" << endl;
        cout << string(60, '=') << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Удалить студента" << endl;
        cout << "3. Поиск студента" << endl;
        cout << "4. Показать всех студентов" << endl;
        cout << "5. Сортировка студентов" << endl;
        cout << "6. Статистика" << endl;
        cout << "7. Сохранить данные" << endl;
        cout << "0. Выход" << endl;
    }
    
    void addStudent() {
        string name, email, studentId, major;
        int age, year;
        double gpa;
        
        cout << "\n=== ДОБАВЛЕНИЕ СТУДЕНТА ===" << endl;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Введите возраст: ";
        cin >> age;
        
        cout << "Введите email: ";
        cin.ignore();
        getline(cin, email);
        
        cout << "Введите ID студента: ";
        getline(cin, studentId);
        
        cout << "Введите специальность: ";
        getline(cin, major);
        
        cout << "Введите GPA: ";
        cin >> gpa;
        
        cout << "Введите курс: ";
        cin >> year;
        
        try {
            Student student(name, age, email, studentId, major, gpa, year);
            manager_.addStudent(student);
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
    
    void removeStudent() {
        string studentId;
        
        cout << "\n=== УДАЛЕНИЕ СТУДЕНТА ===" << endl;
        cout << "Введите ID студента: ";
        cin.ignore();
        getline(cin, studentId);
        
        manager_.removeStudent(studentId);
    }
    
    void searchStudent() {
        int searchChoice;
        string searchTerm;
        
        cout << "\n=== ПОИСК СТУДЕНТА ===" << endl;
        cout << "1. По ID" << endl;
        cout << "2. По имени" << endl;
        cout << "3. По специальности" << endl;
        cout << "Выберите тип поиска: ";
        cin >> searchChoice;
        
        cout << "Введите поисковый запрос: ";
        cin.ignore();
        getline(cin, searchTerm);
        
        switch (searchChoice) {
            case 1: {
                Student* student = manager_.findStudentById(searchTerm);
                if (student) {
                    student->displayInfo();
                } else {
                    cout << "Студент не найден!" << endl;
                }
                break;
            }
            case 2: {
                auto students = manager_.findStudentsByName(searchTerm);
                if (students.empty()) {
                    cout << "Студенты не найдены!" << endl;
                } else {
                    for (const auto& student : students) {
                        student.displayInfo();
                        cout << endl;
                    }
                }
                break;
            }
            case 3: {
                auto students = manager_.findStudentsByMajor(searchTerm);
                if (students.empty()) {
                    cout << "Студенты не найдены!" << endl;
                } else {
                    for (const auto& student : students) {
                        student.displayInfo();
                        cout << endl;
                    }
                }
                break;
            }
            default:
                cout << "Неверный выбор!" << endl;
                break;
        }
    }
    
    void sortStudents() {
        int sortChoice;
        
        cout << "\n=== СОРТИРОВКА СТУДЕНТОВ ===" << endl;
        cout << "1. По имени" << endl;
        cout << "2. По GPA" << endl;
        cout << "Выберите тип сортировки: ";
        cin >> sortChoice;
        
        switch (sortChoice) {
            case 1:
                manager_.sortByName();
                break;
            case 2:
                manager_.sortByGpa();
                break;
            default:
                cout << "Неверный выбор!" << endl;
                break;
        }
    }
};

int main() {
    cout << "=== ПРОЕКТ 'СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ' ===" << endl;
    
    StudentSystemMenu menu;
    menu.run();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Добавление новых функций
Добавь в систему новые функции:
*/

class AdvancedStudentManager : public StudentManager {
public:
    AdvancedStudentManager(const string& filename = "students.txt") : StudentManager(filename) {}
    
    void addCourseToStudent(const string& studentId, const string& course) {
        Student* student = findStudentById(studentId);
        if (student) {
            student->addCourse(course);
            cout << "Предмет добавлен студенту " << student->getName() << endl;
        } else {
            cout << "Студент не найден!" << endl;
        }
    }
    
    void removeCourseFromStudent(const string& studentId, const string& course) {
        Student* student = findStudentById(studentId);
        if (student) {
            student->removeCourse(course);
            cout << "Предмет удален у студента " << student->getName() << endl;
        } else {
            cout << "Студент не найден!" << endl;
        }
    }
    
    void displayStudentsByYear(int year) const {
        cout << "\n=== СТУДЕНТЫ " << year << " КУРСА ===" << endl;
        bool found = false;
        for (const auto& student : students_) {
            if (student.getYear() == year) {
                student.displayInfo();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Студенты не найдены!" << endl;
        }
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: НОВЫЕ ФУНКЦИИ ===" << endl;
    
    AdvancedStudentManager manager;
    
    // Добавление тестовых данных
    Student student1("Иван Петров", 20, "ivan@email.com", "S001", "Информатика", 4.5, 2);
    Student student2("Мария Сидорова", 19, "maria@email.com", "S002", "Математика", 4.2, 1);
    
    manager.addStudent(student1);
    manager.addStudent(student2);
    
    // Добавление предметов
    manager.addCourseToStudent("S001", "Программирование");
    manager.addCourseToStudent("S001", "Алгоритмы");
    manager.addCourseToStudent("S002", "Математический анализ");
    
    // Отображение студентов по курсу
    manager.displayStudentsByYear(2);
}

/*
Упражнение 2: Улучшение пользовательского интерфейса
Улучши пользовательский интерфейс системы:
*/

class ImprovedStudentSystemMenu : public StudentSystemMenu {
public:
    void run() override {
        int choice;
        
        while (true) {
            displayWelcome();
            displayMainMenu();
            cout << "Выберите действие: ";
            
            if (!(cin >> choice)) {
                cout << "Неверный ввод! Пожалуйста, введите число." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            switch (choice) {
                case 1:
                    addStudent();
                    break;
                case 2:
                    removeStudent();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    manager_.displayAllStudents();
                    break;
                case 5:
                    sortStudents();
                    break;
                case 6:
                    manager_.displayStatistics();
                    break;
                case 7:
                    manager_.saveToFile();
                    break;
                case 0:
                    cout << "До свидания!" << endl;
                    return;
                default:
                    cout << "Неверный выбор!" << endl;
                    break;
            }
            
            cout << "\nНажмите Enter для продолжения...";
            cin.ignore();
            cin.get();
        }
    }
    
private:
    void displayWelcome() const {
        cout << "\n" << string(70, '=') << endl;
        cout << "           ДОБРО ПОЖАЛОВАТЬ В СИСТЕМУ УПРАВЛЕНИЯ СТУДЕНТАМИ" << endl;
        cout << string(70, '=') << endl;
        cout << "Текущее количество студентов: " << manager_.getStudentCount() << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    
    ImprovedStudentSystemMenu menu;
    menu.run();
}

/*
Упражнение 3: Добавление новых возможностей
Добавь в систему новые возможности:
*/

class StudentSystemFeatures {
public:
    static void displayHelp() {
        cout << "\n=== СПРАВКА ===" << endl;
        cout << "1. Добавление студента - создание новой записи о студенте" << endl;
        cout << "2. Удаление студента - удаление записи по ID" << endl;
        cout << "3. Поиск студента - поиск по различным критериям" << endl;
        cout << "4. Отображение студентов - показ всех записей" << endl;
        cout << "5. Сортировка - упорядочивание по различным полям" << endl;
        cout << "6. Статистика - анализ данных студентов" << endl;
        cout << "7. Сохранение - запись данных в файл" << endl;
    }
    
    static void displaySystemInfo() {
        cout << "\n=== ИНФОРМАЦИЯ О СИСТЕМЕ ===" << endl;
        cout << "Версия: 1.0" << endl;
        cout << "Разработчик: Курс C++" << endl;
        cout << "Дата создания: 2024" << endl;
        cout << "Поддерживаемые форматы: TXT" << endl;
    }
    
    static void displayKeyboardShortcuts() {
        cout << "\n=== ГОРЯЧИЕ КЛАВИШИ ===" << endl;
        cout << "Ctrl+C - Выход из программы" << endl;
        cout << "Enter - Продолжить" << endl;
        cout << "Esc - Отмена операции" << endl;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: НОВЫЕ ВОЗМОЖНОСТИ ===" << endl;
    
    StudentSystemFeatures::displayHelp();
    StudentSystemFeatures::displaySystemInfo();
    StudentSystemFeatures::displayKeyboardShortcuts();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Расширение функциональности
Расширь систему дополнительными возможностями:
- Поддержка групп студентов
- Система оценок и зачетов
- Планировщик занятий
- Уведомления и напоминания

Задание 2: Графический интерфейс
Создай версию системы с графическим интерфейсом:
- Использование библиотек GUI
- Визуальные элементы интерфейса
- Диаграммы и графики
- Экспорт в различные форматы

Задание 3: Сетевая система
Создай сетевую версию системы:
- Многопользовательский доступ
- Сетевое взаимодействие
- Синхронизация данных
- Удаленное управление

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Как применить ООП в системе управления данными?
2. Какие паттерны проектирования использованы?
3. Как организовать работу с файлами?
4. Как обрабатывать ошибки в системе?
5. Как расширить функциональность системы?
6. Какие тесты нужны для системы?
7. Как оптимизировать производительность?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Проект "Крестики-нолики"
- Создание игрового приложения
- Работа с игровой логикой
- Пользовательский интерфейс игры
- Искусственный интеллект

ВРЕМЯ ИЗУЧЕНИЯ: 60-90 минут
ВРЕМЯ ПРАКТИКИ: 60-90 минут
ОБЩЕЕ ВРЕМЯ: 2-3 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <limits>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 28: ПРОЕКТ 'СИСТЕМА УПРАВЛЕНИЯ СТУДЕНТАМИ' ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: НОВЫЕ ФУНКЦИИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: НОВЫЕ ВОЗМОЖНОСТИ ===" << endl;
    exercise3();
    
    return 0;
}





