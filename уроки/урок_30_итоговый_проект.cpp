/*
===========================================
УРОК 30: ИТОГОВЫЙ ПРОЕКТ И ЗАКЛЮЧЕНИЕ
===========================================

ЦЕЛИ УРОКА:
- Создать итоговый проект, демонстрирующий все изученные концепции
- Подвести итоги обучения
- Оценить достигнутые результаты
- Определить планы на будущее
- Получить обратную связь по курсу

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ИТОГОВЫЙ ПРОЕКТ:

Этот урок посвящен созданию итогового проекта, который демонстрирует применение
всех изученных концепций C++:

1. КЛАССЫ И ОБЪЕКТЫ:
   - Создание сложных иерархий классов
   - Применение принципов ООП
   - Использование инкапсуляции

2. НАСЛЕДОВАНИЕ И ПОЛИМОРФИЗМ:
   - Создание базовых и производных классов
   - Использование виртуальных функций
   - Применение полиморфизма

3. ШАБЛОНЫ:
   - Создание шаблонных классов и функций
   - Применение обобщенного программирования
   - Использование специализации

4. STL:
   - Применение контейнеров
   - Использование алгоритмов
   - Работа с итераторами

5. ОБРАБОТКА ИСКЛЮЧЕНИЙ:
   - Создание пользовательских исключений
   - Обработка ошибок
   - Валидация данных

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
#include <map>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

// Пользовательские исключения
class DatabaseException : public exception {
private:
    string message_;
    
public:
    DatabaseException(const string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

class ValidationException : public exception {
private:
    string message_;
    
public:
    ValidationException(const string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }
};

// Базовый класс для сущностей
class Entity {
protected:
    int id_;
    string name_;
    time_t createdAt_;
    
public:
    Entity(int id = 0, const string& name = "") 
        : id_(id), name_(name), createdAt_(time(0)) {}
    
    virtual ~Entity() = default;
    
    virtual void displayInfo() const = 0;
    virtual string getType() const = 0;
    virtual string serialize() const = 0;
    virtual void deserialize(const string& data) = 0;
    
    int getId() const { return id_; }
    const string& getName() const { return name_; }
    time_t getCreatedAt() const { return createdAt_; }
    
    void setId(int id) { id_ = id; }
    void setName(const string& name) { name_ = name; }
};

// Класс для студента
class Student : public Entity {
private:
    string email_;
    string major_;
    double gpa_;
    int year_;
    set<string> courses_;
    
public:
    Student(int id = 0, const string& name = "", const string& email = "",
            const string& major = "", double gpa = 0.0, int year = 1)
        : Entity(id, name), email_(email), major_(major), gpa_(gpa), year_(year) {}
    
    void displayInfo() const override {
        cout << "Студент ID: " << id_ << endl;
        cout << "  Имя: " << name_ << endl;
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
        return "Student";
    }
    
    string serialize() const override {
        string result = to_string(id_) + "|" + name_ + "|" + email_ + "|" + 
                       major_ + "|" + to_string(gpa_) + "|" + to_string(year_) + "|";
        
        for (const auto& course : courses_) {
            result += course + ",";
        }
        
        return result;
    }
    
    void deserialize(const string& data) override {
        vector<string> parts;
        string current = "";
        
        for (char c : data) {
            if (c == '|') {
                parts.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }
        parts.push_back(current);
        
        if (parts.size() >= 6) {
            id_ = stoi(parts[0]);
            name_ = parts[1];
            email_ = parts[2];
            major_ = parts[3];
            gpa_ = stod(parts[4]);
            year_ = stoi(parts[5]);
            
            courses_.clear();
            if (parts.size() > 6 && !parts[6].empty()) {
                string coursesStr = parts[6];
                string course = "";
                for (char c : coursesStr) {
                    if (c == ',') {
                        if (!course.empty()) {
                            courses_.insert(course);
                            course = "";
                        }
                    } else {
                        course += c;
                    }
                }
                if (!course.empty()) {
                    courses_.insert(course);
                }
            }
        }
    }
    
    const string& getEmail() const { return email_; }
    const string& getMajor() const { return major_; }
    double getGpa() const { return gpa_; }
    int getYear() const { return year_; }
    const set<string>& getCourses() const { return courses_; }
    
    void setEmail(const string& email) { email_ = email; }
    void setMajor(const string& major) { major_ = major; }
    void setGpa(double gpa) { gpa_ = gpa; }
    void setYear(int year) { year_ = year; }
    
    void addCourse(const string& course) {
        courses_.insert(course);
    }
    
    void removeCourse(const string& course) {
        courses_.erase(course);
    }
};

// Класс для преподавателя
class Teacher : public Entity {
private:
    string email_;
    string department_;
    vector<string> subjects_;
    int experience_;
    
public:
    Teacher(int id = 0, const string& name = "", const string& email = "",
            const string& department = "", int experience = 0)
        : Entity(id, name), email_(email), department_(department), experience_(experience) {}
    
    void displayInfo() const override {
        cout << "Преподаватель ID: " << id_ << endl;
        cout << "  Имя: " << name_ << endl;
        cout << "  Email: " << email_ << endl;
        cout << "  Кафедра: " << department_ << endl;
        cout << "  Опыт работы: " << experience_ << " лет" << endl;
        cout << "  Предметы: ";
        for (const auto& subject : subjects_) {
            cout << subject << " ";
        }
        cout << endl;
    }
    
    string getType() const override {
        return "Teacher";
    }
    
    string serialize() const override {
        string result = to_string(id_) + "|" + name_ + "|" + email_ + "|" + 
                       department_ + "|" + to_string(experience_) + "|";
        
        for (const auto& subject : subjects_) {
            result += subject + ",";
        }
        
        return result;
    }
    
    void deserialize(const string& data) override {
        vector<string> parts;
        string current = "";
        
        for (char c : data) {
            if (c == '|') {
                parts.push_back(current);
                current = "";
            } else {
                current += c;
            }
        }
        parts.push_back(current);
        
        if (parts.size() >= 5) {
            id_ = stoi(parts[0]);
            name_ = parts[1];
            email_ = parts[2];
            department_ = parts[3];
            experience_ = stoi(parts[4]);
            
            subjects_.clear();
            if (parts.size() > 5 && !parts[5].empty()) {
                string subjectsStr = parts[5];
                string subject = "";
                for (char c : subjectsStr) {
                    if (c == ',') {
                        if (!subject.empty()) {
                            subjects_.push_back(subject);
                            subject = "";
                        }
                    } else {
                        subject += c;
                    }
                }
                if (!subject.empty()) {
                    subjects_.push_back(subject);
                }
            }
        }
    }
    
    const string& getEmail() const { return email_; }
    const string& getDepartment() const { return department_; }
    int getExperience() const { return experience_; }
    const vector<string>& getSubjects() const { return subjects_; }
    
    void setEmail(const string& email) { email_ = email; }
    void setDepartment(const string& department) { department_ = department; }
    void setExperience(int experience) { experience_ = experience; }
    
    void addSubject(const string& subject) {
        subjects_.push_back(subject);
    }
    
    void removeSubject(const string& subject) {
        auto it = find(subjects_.begin(), subjects_.end(), subject);
        if (it != subjects_.end()) {
            subjects_.erase(it);
        }
    }
};

// Шаблонный класс для управления данными
template<typename T>
class DataManager {
private:
    vector<unique_ptr<T>> data_;
    int nextId_;
    
public:
    DataManager() : nextId_(1) {}
    
    void add(unique_ptr<T> item) {
        if (!item) {
            throw ValidationException("Попытка добавить пустой элемент");
        }
        
        item->setId(nextId_++);
        data_.push_back(move(item));
    }
    
    void remove(int id) {
        auto it = find_if(data_.begin(), data_.end(),
            [id](const unique_ptr<T>& item) { return item->getId() == id; });
        
        if (it != data_.end()) {
            data_.erase(it);
        } else {
            throw DatabaseException("Элемент с ID " + to_string(id) + " не найден");
        }
    }
    
    T* findById(int id) const {
        auto it = find_if(data_.begin(), data_.end(),
            [id](const unique_ptr<T>& item) { return item->getId() == id; });
        
        return (it != data_.end()) ? it->get() : nullptr;
    }
    
    vector<T*> findByName(const string& name) const {
        vector<T*> result;
        for (const auto& item : data_) {
            if (item->getName() == name) {
                result.push_back(item.get());
            }
        }
        return result;
    }
    
    void displayAll() const {
        if (data_.empty()) {
            cout << "Нет данных для отображения" << endl;
            return;
        }
        
        for (const auto& item : data_) {
            item->displayInfo();
            cout << endl;
        }
    }
    
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            throw DatabaseException("Не удалось открыть файл для записи: " + filename);
        }
        
        for (const auto& item : data_) {
            file << item->serialize() << endl;
        }
        
        file.close();
    }
    
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Файл не найден: " << filename << endl;
            return;
        }
        
        data_.clear();
        string line;
        
        while (getline(file, line)) {
            if (!line.empty()) {
                auto item = make_unique<T>();
                item->deserialize(line);
                data_.push_back(move(item));
            }
        }
        
        file.close();
    }
    
    size_t size() const {
        return data_.size();
    }
    
    // Статистика
    void displayStatistics() const {
        if (data_.empty()) {
            cout << "Нет данных для статистики" << endl;
            return;
        }
        
        cout << "Общее количество: " << data_.size() << endl;
        
        // Группировка по типам
        map<string, int> typeCount;
        for (const auto& item : data_) {
            typeCount[item->getType()]++;
        }
        
        cout << "Распределение по типам:" << endl;
        for (const auto& pair : typeCount) {
            cout << "  " << pair.first << ": " << pair.second << endl;
        }
    }
};

// Класс для управления университетом
class UniversityManager {
private:
    DataManager<Student> studentManager_;
    DataManager<Teacher> teacherManager_;
    
public:
    void addStudent(const string& name, const string& email, const string& major, 
                   double gpa, int year) {
        try {
            validateEmail(email);
            validateGpa(gpa);
            validateYear(year);
            
            auto student = make_unique<Student>(0, name, email, major, gpa, year);
            studentManager_.add(move(student));
            
        } catch (const ValidationException& e) {
            cout << "Ошибка валидации: " << e.what() << endl;
        }
    }
    
    void addTeacher(const string& name, const string& email, const string& department, 
                   int experience) {
        try {
            validateEmail(email);
            validateExperience(experience);
            
            auto teacher = make_unique<Teacher>(0, name, email, department, experience);
            teacherManager_.add(move(teacher));
            
        } catch (const ValidationException& e) {
            cout << "Ошибка валидации: " << e.what() << endl;
        }
    }
    
    void displayAllStudents() const {
        cout << "\n=== ВСЕ СТУДЕНТЫ ===" << endl;
        studentManager_.displayAll();
    }
    
    void displayAllTeachers() const {
        cout << "\n=== ВСЕ ПРЕПОДАВАТЕЛИ ===" << endl;
        teacherManager_.displayAll();
    }
    
    void searchStudent(const string& name) const {
        auto students = studentManager_.findByName(name);
        if (students.empty()) {
            cout << "Студенты не найдены" << endl;
        } else {
            cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА СТУДЕНТОВ ===" << endl;
            for (const auto& student : students) {
                student->displayInfo();
                cout << endl;
            }
        }
    }
    
    void searchTeacher(const string& name) const {
        auto teachers = teacherManager_.findByName(name);
        if (teachers.empty()) {
            cout << "Преподаватели не найдены" << endl;
        } else {
            cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ПРЕПОДАВАТЕЛЕЙ ===" << endl;
            for (const auto& teacher : teachers) {
                teacher->displayInfo();
                cout << endl;
            }
        }
    }
    
    void displayStatistics() const {
        cout << "\n=== СТАТИСТИКА УНИВЕРСИТЕТА ===" << endl;
        cout << "Студенты:" << endl;
        studentManager_.displayStatistics();
        cout << "\nПреподаватели:" << endl;
        teacherManager_.displayStatistics();
    }
    
    void saveAllData() const {
        try {
            studentManager_.saveToFile("students.txt");
            teacherManager_.saveToFile("teachers.txt");
            cout << "Все данные сохранены" << endl;
        } catch (const DatabaseException& e) {
            cout << "Ошибка сохранения: " << e.what() << endl;
        }
    }
    
    void loadAllData() {
        studentManager_.loadFromFile("students.txt");
        teacherManager_.loadFromFile("teachers.txt");
        cout << "Все данные загружены" << endl;
    }
    
private:
    void validateEmail(const string& email) {
        if (email.empty()) {
            throw ValidationException("Email не может быть пустым");
        }
        
        if (email.find('@') == string::npos) {
            throw ValidationException("Email должен содержать символ @");
        }
    }
    
    void validateGpa(double gpa) {
        if (gpa < 0.0 || gpa > 4.0) {
            throw ValidationException("GPA должен быть от 0.0 до 4.0");
        }
    }
    
    void validateYear(int year) {
        if (year < 1 || year > 6) {
            throw ValidationException("Курс должен быть от 1 до 6");
        }
    }
    
    void validateExperience(int experience) {
        if (experience < 0) {
            throw ValidationException("Опыт работы не может быть отрицательным");
        }
    }
};

// Класс для пользовательского интерфейса
class UniversitySystemMenu {
private:
    UniversityManager manager_;
    
public:
    UniversitySystemMenu() {
        manager_.loadAllData();
    }
    
    ~UniversitySystemMenu() {
        manager_.saveAllData();
    }
    
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
                    addTeacher();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    searchTeacher();
                    break;
                case 5:
                    manager_.displayAllStudents();
                    break;
                case 6:
                    manager_.displayAllTeachers();
                    break;
                case 7:
                    manager_.displayStatistics();
                    break;
                case 8:
                    manager_.saveAllData();
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
        cout << "\n" << string(70, '=') << endl;
        cout << "           СИСТЕМА УПРАВЛЕНИЯ УНИВЕРСИТЕТОМ" << endl;
        cout << string(70, '=') << endl;
        cout << "1. Добавить студента" << endl;
        cout << "2. Добавить преподавателя" << endl;
        cout << "3. Поиск студента" << endl;
        cout << "4. Поиск преподавателя" << endl;
        cout << "5. Показать всех студентов" << endl;
        cout << "6. Показать всех преподавателей" << endl;
        cout << "7. Статистика" << endl;
        cout << "8. Сохранить данные" << endl;
        cout << "0. Выход" << endl;
    }
    
    void addStudent() {
        string name, email, major;
        double gpa;
        int year;
        
        cout << "\n=== ДОБАВЛЕНИЕ СТУДЕНТА ===" << endl;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Введите email: ";
        getline(cin, email);
        
        cout << "Введите специальность: ";
        getline(cin, major);
        
        cout << "Введите GPA: ";
        cin >> gpa;
        
        cout << "Введите курс: ";
        cin >> year;
        
        manager_.addStudent(name, email, major, gpa, year);
    }
    
    void addTeacher() {
        string name, email, department;
        int experience;
        
        cout << "\n=== ДОБАВЛЕНИЕ ПРЕПОДАВАТЕЛЯ ===" << endl;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        
        cout << "Введите email: ";
        getline(cin, email);
        
        cout << "Введите кафедру: ";
        getline(cin, department);
        
        cout << "Введите опыт работы (лет): ";
        cin >> experience;
        
        manager_.addTeacher(name, email, department, experience);
    }
    
    void searchStudent() {
        string name;
        
        cout << "\n=== ПОИСК СТУДЕНТА ===" << endl;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        
        manager_.searchStudent(name);
    }
    
    void searchTeacher() {
        string name;
        
        cout << "\n=== ПОИСК ПРЕПОДАВАТЕЛЯ ===" << endl;
        cout << "Введите имя: ";
        cin.ignore();
        getline(cin, name);
        
        manager_.searchTeacher(name);
    }
};

int main() {
    cout << "=== ИТОГОВЫЙ ПРОЕКТ: СИСТЕМА УПРАВЛЕНИЯ УНИВЕРСИТЕТОМ ===" << endl;
    
    UniversitySystemMenu menu;
    menu.run();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Расширение функциональности
Расширь систему дополнительными возможностями:
*/

class AdvancedUniversityManager : public UniversityManager {
public:
    void assignCourseToStudent(int studentId, const string& course) {
        // Реализация назначения курса студенту
        cout << "Курс " << course << " назначен студенту ID " << studentId << endl;
    }
    
    void assignSubjectToTeacher(int teacherId, const string& subject) {
        // Реализация назначения предмета преподавателю
        cout << "Предмет " << subject << " назначен преподавателю ID " << teacherId << endl;
    }
    
    void generateReport() const {
        cout << "\n=== ОТЧЕТ УНИВЕРСИТЕТА ===" << endl;
        cout << "Дата создания отчета: " << ctime(&time(0)) << endl;
        
        // Детальная статистика
        cout << "Детальная статистика:" << endl;
        displayStatistics();
        
        // Рекомендации
        cout << "\nРекомендации:" << endl;
        cout << "1. Увеличить количество преподавателей" << endl;
        cout << "2. Улучшить качество образования" << endl;
        cout << "3. Расширить программы обучения" << endl;
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: РАСШИРЕНИЕ ФУНКЦИОНАЛЬНОСТИ ===" << endl;
    
    AdvancedUniversityManager manager;
    
    // Добавление тестовых данных
    manager.addStudent("Иван Петров", "ivan@university.edu", "Информатика", 4.2, 3);
    manager.addTeacher("Мария Сидорова", "maria@university.edu", "Кафедра информатики", 10);
    
    // Назначение курсов и предметов
    manager.assignCourseToStudent(1, "Программирование");
    manager.assignSubjectToTeacher(1, "Алгоритмы");
    
    // Генерация отчета
    manager.generateReport();
}

/*
Упражнение 2: Создание тестов
Создай тесты для всех классов:
*/

class TestSuite {
public:
    static void runAllTests() {
        cout << "\n=== ЗАПУСК ТЕСТОВ ===" << endl;
        
        testStudentCreation();
        testTeacherCreation();
        testDataManager();
        testValidation();
        testSerialization();
        
        cout << "\nВсе тесты завершены!" << endl;
    }
    
private:
    static void testStudentCreation() {
        cout << "Тест создания студента..." << endl;
        
        try {
            Student student(1, "Тест Студент", "test@email.com", "Тест", 3.5, 2);
            
            if (student.getId() == 1 && student.getName() == "Тест Студент") {
                cout << "✓ Тест создания студента пройден" << endl;
            } else {
                cout << "✗ Тест создания студента не пройден" << endl;
            }
        } catch (const exception& e) {
            cout << "✗ Ошибка в тесте создания студента: " << e.what() << endl;
        }
    }
    
    static void testTeacherCreation() {
        cout << "Тест создания преподавателя..." << endl;
        
        try {
            Teacher teacher(1, "Тест Преподаватель", "test@email.com", "Тест", 5);
            
            if (teacher.getId() == 1 && teacher.getName() == "Тест Преподаватель") {
                cout << "✓ Тест создания преподавателя пройден" << endl;
            } else {
                cout << "✗ Тест создания преподавателя не пройден" << endl;
            }
        } catch (const exception& e) {
            cout << "✗ Ошибка в тесте создания преподавателя: " << e.what() << endl;
        }
    }
    
    static void testDataManager() {
        cout << "Тест менеджера данных..." << endl;
        
        try {
            DataManager<Student> manager;
            auto student = make_unique<Student>(0, "Тест", "test@email.com", "Тест", 3.0, 1);
            manager.add(move(student));
            
            if (manager.size() == 1) {
                cout << "✓ Тест менеджера данных пройден" << endl;
            } else {
                cout << "✗ Тест менеджера данных не пройден" << endl;
            }
        } catch (const exception& e) {
            cout << "✗ Ошибка в тесте менеджера данных: " << e.what() << endl;
        }
    }
    
    static void testValidation() {
        cout << "Тест валидации..." << endl;
        
        try {
            UniversityManager manager;
            manager.addStudent("Тест", "invalid-email", "Тест", 5.0, 7); // Неверные данные
            
            cout << "✗ Тест валидации не пройден (должна была быть ошибка)" << endl;
        } catch (const ValidationException& e) {
            cout << "✓ Тест валидации пройден: " << e.what() << endl;
        } catch (const exception& e) {
            cout << "✗ Неожиданная ошибка в тесте валидации: " << e.what() << endl;
        }
    }
    
    static void testSerialization() {
        cout << "Тест сериализации..." << endl;
        
        try {
            Student student(1, "Тест", "test@email.com", "Тест", 3.0, 1);
            string serialized = student.serialize();
            
            Student deserialized;
            deserialized.deserialize(serialized);
            
            if (deserialized.getId() == student.getId() && deserialized.getName() == student.getName()) {
                cout << "✓ Тест сериализации пройден" << endl;
            } else {
                cout << "✗ Тест сериализации не пройден" << endl;
            }
        } catch (const exception& e) {
            cout << "✗ Ошибка в тесте сериализации: " << e.what() << endl;
        }
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: СОЗДАНИЕ ТЕСТОВ ===" << endl;
    
    TestSuite::runAllTests();
}

/*
Упражнение 3: Оптимизация производительности
Оптимизируй производительность системы:
*/

class PerformanceOptimizer {
public:
    static void optimizeDataManager() {
        cout << "\n=== ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
        
        // Измерение времени выполнения
        clock_t start = clock();
        
        DataManager<Student> manager;
        
        // Добавление большого количества данных
        for (int i = 0; i < 1000; ++i) {
            auto student = make_unique<Student>(0, "Студент " + to_string(i), 
                                              "student" + to_string(i) + "@email.com", 
                                              "Специальность", 3.0, 1);
            manager.add(move(student));
        }
        
        clock_t end = clock();
        double timeSpent = double(end - start) / CLOCKS_PER_SEC;
        
        cout << "Время добавления 1000 студентов: " << timeSpent << " секунд" << endl;
        cout << "Среднее время на студента: " << (timeSpent / 1000) * 1000 << " миллисекунд" << endl;
        
        // Тест поиска
        start = clock();
        auto found = manager.findByName("Студент 500");
        end = clock();
        timeSpent = double(end - start) / CLOCKS_PER_SEC;
        
        cout << "Время поиска студента: " << timeSpent << " секунд" << endl;
        
        // Рекомендации по оптимизации
        cout << "\nРекомендации по оптимизации:" << endl;
        cout << "1. Использовать индексы для быстрого поиска" << endl;
        cout << "2. Применить кэширование часто используемых данных" << endl;
        cout << "3. Использовать многопоточность для параллельной обработки" << endl;
        cout << "4. Оптимизировать структуры данных" << endl;
    }
    
    static void analyzeMemoryUsage() {
        cout << "\n=== АНАЛИЗ ИСПОЛЬЗОВАНИЯ ПАМЯТИ ===" << endl;
        
        DataManager<Student> manager;
        
        // Добавление данных
        for (int i = 0; i < 100; ++i) {
            auto student = make_unique<Student>(0, "Студент " + to_string(i), 
                                              "student" + to_string(i) + "@email.com", 
                                              "Специальность", 3.0, 1);
            manager.add(move(student));
        }
        
        cout << "Количество студентов: " << manager.size() << endl;
        cout << "Примерный размер в памяти: " << (manager.size() * sizeof(Student)) << " байт" << endl;
        
        // Рекомендации по памяти
        cout << "\nРекомендации по памяти:" << endl;
        cout << "1. Использовать умные указатели для управления памятью" << endl;
        cout << "2. Применять пулы объектов для часто создаваемых объектов" << endl;
        cout << "3. Использовать сжатие данных для экономии места" << endl;
        cout << "4. Реализовать ленивую загрузку данных" << endl;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    
    PerformanceOptimizer::optimizeDataManager();
    PerformanceOptimizer::analyzeMemoryUsage();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Создание итогового проекта
Создай итоговый проект, демонстрирующий все изученные концепции:
- Сложная иерархия классов
- Применение всех принципов ООП
- Использование шаблонов и STL
- Обработка исключений
- Работа с файлами

Задание 2: Написание документации
Создай документацию для итогового проекта:
- Описание архитектуры
- Руководство пользователя
- API документация
- Примеры использования

Задание 3: Создание презентации
Создай презентацию итогового проекта:
- Описание проекта
- Демонстрация возможностей
- Технические детали
- Планы развития

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Какие основные концепции C++ вы изучили?
2. Как применить ООП в реальных проектах?
3. Какие паттерны проектирования использованы?
4. Как организовать архитектуру приложения?
5. Как обрабатывать ошибки в системе?
6. Как расширить функциональность системы?
7. Какие тесты нужны для системы?
8. Как оптимизировать производительность?

ЗАКЛЮЧЕНИЕ КУРСА:

Поздравляем с завершением курса C++! Вы изучили:

1. ОСНОВЫ ЯЗЫКА:
   - Синтаксис и семантика
   - Типы данных и переменные
   - Операторы и выражения
   - Управляющие конструкции

2. ОБЪЕКТНО-ОРИЕНТИРОВАННОЕ ПРОГРАММИРОВАНИЕ:
   - Классы и объекты
   - Наследование и полиморфизм
   - Инкапсуляция
   - Абстракция

3. ПРОДВИНУТЫЕ ВОЗМОЖНОСТИ:
   - Шаблоны
   - STL
   - Обработка исключений
   - Работа с файлами

4. ПРАКТИЧЕСКИЕ ПРОЕКТЫ:
   - Калькулятор
   - Игра "Угадай число"
   - Система управления студентами
   - Крестики-нолики
   - Итоговый проект

ПЛАНЫ НА БУДУЩЕЕ:

1. ПРОДОЛЖЕНИЕ ОБУЧЕНИЯ:
   - Изучение дополнительных библиотек
   - Освоение новых технологий
   - Участие в проектах

2. ПРАКТИЧЕСКОЕ ПРИМЕНЕНИЕ:
   - Создание собственных проектов
   - Участие в конкурсах
   - Разработка приложений

3. РАЗВИТИЕ НАВЫКОВ:
   - Изучение других языков программирования
   - Освоение алгоритмов и структур данных
   - Изучение архитектуры программного обеспечения

СПАСИБО ЗА ОБУЧЕНИЕ!

Желаем успехов в дальнейшем изучении программирования!

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
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 30: ИТОГОВЫЙ ПРОЕКТ И ЗАКЛЮЧЕНИЕ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: РАСШИРЕНИЕ ФУНКЦИОНАЛЬНОСТИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: СОЗДАНИЕ ТЕСТОВ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ОПТИМИЗАЦИЯ ПРОИЗВОДИТЕЛЬНОСТИ ===" << endl;
    exercise3();
    
    // Заключение
    cout << "\n" << string(70, '=') << endl;
    cout << "           ПОЗДРАВЛЯЕМ С ЗАВЕРШЕНИЕМ КУРСА C++!" << endl;
    cout << string(70, '=') << endl;
    cout << "Вы успешно изучили все основные концепции языка C++" << endl;
    cout << "и создали несколько практических проектов." << endl;
    cout << "\nЖелаем успехов в дальнейшем изучении программирования!" << endl;
    
    return 0;
}





