/*
===========================================
УРОК 11: РАБОТА С ФАЙЛАМИ
===========================================

ЦЕЛИ УРОКА:
- Понять основы работы с файлами
- Изучить чтение из файла
- Освоить запись в файл
- Научиться обрабатывать ошибки
- Понять различные режимы открытия файлов

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

РАБОТА С ФАЙЛАМИ В C++:

1. ПОДКЛЮЧЕНИЕ БИБЛИОТЕКИ:
   #include <fstream>

2. ОБЪЯВЛЕНИЕ ФАЙЛОВЫХ ПОТОКОВ:
   ifstream inputFile;  // для чтения
   ofstream outputFile; // для записи
   fstream file;        // для чтения и записи

3. ОТКРЫТИЕ ФАЙЛА:
   file.open("имя_файла", режим);

4. РЕЖИМЫ ОТКРЫТИЯ:
   ios::in     - для чтения
   ios::out    - для записи
   ios::app    - добавление в конец
   ios::trunc  - очистка файла
   ios::binary - бинарный режим

5. ПРОВЕРКА ОТКРЫТИЯ:
   if (file.is_open()) {
       // файл открыт успешно
   }

6. ЗАКРЫТИЕ ФАЙЛА:
   file.close();

ОСНОВНЫЕ ОПЕРАЦИИ:
- Чтение: file >> переменная или getline(file, строка)
- Запись: file << данные
- Проверка конца файла: file.eof()
- Проверка ошибок: file.fail()

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Запись в файл
    cout << "=== ЗАПИСЬ В ФАЙЛ ===" << endl;
    ofstream outputFile("example.txt");
    
    if (outputFile.is_open()) {
        outputFile << "Привет, мир!" << endl;
        outputFile << "Это пример записи в файл" << endl;
        outputFile << "Число: " << 42 << endl;
        outputFile.close();
        cout << "Данные записаны в файл example.txt" << endl;
    } else {
        cout << "Ошибка открытия файла для записи!" << endl;
    }
    
    // Чтение из файла
    cout << "\n=== ЧТЕНИЕ ИЗ ФАЙЛА ===" << endl;
    ifstream inputFile("example.txt");
    
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "Ошибка открытия файла для чтения!" << endl;
    }
    
    // Работа с числами
    cout << "\n=== РАБОТА С ЧИСЛАМИ ===" << endl;
    ofstream numbersFile("numbers.txt");
    if (numbersFile.is_open()) {
        for (int i = 1; i <= 10; i++) {
            numbersFile << i << " ";
        }
        numbersFile << endl;
        numbersFile.close();
    }
    
    ifstream readNumbers("numbers.txt");
    if (readNumbers.is_open()) {
        int num;
        cout << "Числа из файла: ";
        while (readNumbers >> num) {
            cout << num << " ";
        }
        cout << endl;
        readNumbers.close();
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Создание файла с данными студентов
Создай программу для записи данных студентов в файл:
*/

void exercise1() {
    ofstream studentFile("students.txt");
    
    if (studentFile.is_open()) {
        studentFile << "Иван Петров 18 4.5" << endl;
        studentFile << "Мария Сидорова 17 4.8" << endl;
        studentFile << "Петр Иванов 19 3.2" << endl;
        studentFile << "Анна Козлова 18 4.0" << endl;
        studentFile.close();
        cout << "Данные студентов записаны в файл students.txt" << endl;
    } else {
        cout << "Ошибка создания файла!" << endl;
    }
}

/*
Упражнение 2: Чтение и обработка данных студентов
Создай программу для чтения данных студентов из файла:
*/

void exercise2() {
    ifstream studentFile("students.txt");
    
    if (studentFile.is_open()) {
        string name, surname;
        int age;
        double grade;
        
        cout << "=== СПИСОК СТУДЕНТОВ ===" << endl;
        while (studentFile >> name >> surname >> age >> grade) {
            cout << name << " " << surname << " - " << age << " лет, оценка: " << grade << endl;
        }
        studentFile.close();
    } else {
        cout << "Файл students.txt не найден!" << endl;
    }
}

/*
Упражнение 3: Подсчет слов в файле
Создай программу для подсчета слов в текстовом файле:
*/

void exercise3() {
    // Создаем тестовый файл
    ofstream testFile("test.txt");
    if (testFile.is_open()) {
        testFile << "Это тестовый файл для подсчета слов." << endl;
        testFile << "В нем содержится несколько строк текста." << endl;
        testFile << "Каждая строка содержит разное количество слов." << endl;
        testFile.close();
    }
    
    // Подсчитываем слова
    ifstream inputFile("test.txt");
    if (inputFile.is_open()) {
        int wordCount = 0;
        string word;
        
        while (inputFile >> word) {
            wordCount++;
        }
        
        cout << "Количество слов в файле: " << wordCount << endl;
        inputFile.close();
    }
}

/*
Упражнение 4: Копирование файла
Создай программу для копирования содержимого одного файла в другой:
*/

void exercise4() {
    // Создаем исходный файл
    ofstream sourceFile("source.txt");
    if (sourceFile.is_open()) {
        sourceFile << "Это исходный файл." << endl;
        sourceFile << "Его содержимое будет скопировано." << endl;
        sourceFile.close();
    }
    
    // Копируем файл
    ifstream source("source.txt");
    ofstream destination("destination.txt");
    
    if (source.is_open() && destination.is_open()) {
        string line;
        while (getline(source, line)) {
            destination << line << endl;
        }
        
        source.close();
        destination.close();
        cout << "Файл успешно скопирован!" << endl;
    } else {
        cout << "Ошибка при копировании файла!" << endl;
    }
}

/*
Упражнение 5: Поиск строки в файле
Создай программу для поиска определенной строки в файле:
*/

void exercise5() {
    string searchString;
    cout << "Введите строку для поиска: ";
    cin.ignore(); // очищаем буфер
    getline(cin, searchString);
    
    ifstream file("test.txt");
    if (file.is_open()) {
        string line;
        int lineNumber = 0;
        bool found = false;
        
        cout << "\n=== РЕЗУЛЬТАТЫ ПОИСКА ===" << endl;
        while (getline(file, line)) {
            lineNumber++;
            if (line.find(searchString) != string::npos) {
                cout << "Строка " << lineNumber << ": " << line << endl;
                found = true;
            }
        }
        
        if (!found) {
            cout << "Строка не найдена!" << endl;
        }
        
        file.close();
    } else {
        cout << "Файл test.txt не найден!" << endl;
    }
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Система логирования
Создай программу для записи логов в файл:
- Функция для записи сообщения с временной меткой
- Различные уровни логирования (INFO, WARNING, ERROR)
- Автоматическое создание файла логов

Задание 2: Резервное копирование
Создай программу для создания резервных копий файлов:
- Копирование файла с добавлением даты к имени
- Проверка существования файла
- Создание папки для резервных копий

Задание 3: Анализатор текста
Создай программу для анализа текстового файла:
- Подсчет количества строк, слов, символов
- Поиск самого длинного и короткого слова
- Статистика по символам

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Какие библиотеки нужны для работы с файлами?
2. В чем разница между ifstream и ofstream?
3. Как проверить, открыт ли файл?
4. Что такое режимы открытия файла?
5. Как читать строки из файла?
6. Как обрабатывать ошибки при работе с файлами?
7. Обязательно ли закрывать файл?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Основы объектно-ориентированного программирования
- Классы и объекты
- Инкапсуляция
- Конструкторы и деструкторы
- Методы классов

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 11: РАБОТА С ФАЙЛАМИ ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: ЗАПИСЬ ДАННЫХ СТУДЕНТОВ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ЧТЕНИЕ ДАННЫХ СТУДЕНТОВ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ПОДСЧЕТ СЛОВ В ФАЙЛЕ ===" << endl;
    exercise3();
    
    cout << "\n=== УПРАЖНЕНИЕ 4: КОПИРОВАНИЕ ФАЙЛА ===" << endl;
    exercise4();
    
    cout << "\n=== УПРАЖНЕНИЕ 5: ПОИСК СТРОКИ В ФАЙЛЕ ===" << endl;
    exercise5();
    
    return 0;
}





