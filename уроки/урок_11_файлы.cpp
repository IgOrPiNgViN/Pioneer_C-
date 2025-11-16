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

Работа с файлами позволяет программе сохранять данные на диск и читать их обратно.
Это необходимо для создания программ, которые работают с данными между запусками.

ЗАЧЕМ НУЖНА РАБОТА С ФАЙЛАМИ:

1. Сохранение данных между запусками программы
2. Обработка больших объемов данных
3. Обмен данными между программами
4. Создание логов и отчетов
5. Работа с конфигурационными файлами

1. ПОДКЛЮЧЕНИЕ БИБЛИОТЕКИ:

   Для работы с файлами нужно подключить библиотеку <fstream>:
   #include <fstream>
   
   Также могут понадобиться:
   #include <iostream>  // для cout, cin
   #include <string>     // для работы со строками

2. ФАЙЛОВЫЕ ПОТОКИ:

   В C++ работа с файлами осуществляется через потоки (streams).
   
   а) ifstream (input file stream) - для чтения из файла:
      ifstream inputFile;
      // или с инициализацией:
      ifstream inputFile("filename.txt");
   
   б) ofstream (output file stream) - для записи в файл:
      ofstream outputFile;
      // или с инициализацией:
      ofstream outputFile("filename.txt");
   
   в) fstream (file stream) - для чтения и записи:
      fstream file;
      // или с инициализацией:
      fstream file("filename.txt", ios::in | ios::out);
   
   Разница:
   - ifstream: только чтение
   - ofstream: только запись
   - fstream: чтение и запись

3. ОТКРЫТИЕ ФАЙЛА:

   а) При создании объекта:
   ofstream file("data.txt");  // файл открывается автоматически
   
   б) Явное открытие:
   ofstream file;
   file.open("data.txt");
   
   в) С указанием режима:
   fstream file;
   file.open("data.txt", ios::in | ios::out);
   
   Путь к файлу:
   - Относительный путь: "data.txt" (в текущей папке)
   - Абсолютный путь: "C:\\Users\\Name\\data.txt" (Windows)
   - Абсолютный путь: "/home/user/data.txt" (Linux/Mac)
   
   Важно: В Windows используйте двойные обратные слеши \\ или одинарные прямые /

4. РЕЖИМЫ ОТКРЫТИЯ ФАЙЛА:

   Режимы определяют, как будет открыт файл.
   
   а) ios::in - открытие для чтения:
      ifstream file("data.txt", ios::in);
      // или просто:
      ifstream file("data.txt");  // ios::in по умолчанию
   
   б) ios::out - открытие для записи (перезаписывает файл):
      ofstream file("data.txt", ios::out);
      // или просто:
      ofstream file("data.txt");  // ios::out по умолчанию
   
   в) ios::app - добавление в конец файла (append):
      ofstream file("data.txt", ios::app);
      // Новые данные добавляются в конец, старые не удаляются
   
   г) ios::trunc - очистка файла перед записью:
      ofstream file("data.txt", ios::trunc);
      // Содержимое файла удаляется (по умолчанию для ios::out)
   
   д) ios::binary - бинарный режим:
      fstream file("data.bin", ios::binary);
      // Для работы с бинарными данными (не текстовыми)
   
   е) Комбинация режимов (через |):
      fstream file("data.txt", ios::in | ios::out);
      fstream file("data.txt", ios::in | ios::out | ios::app);
   
   Таблица режимов:
   Режим      | Описание
   ----------|----------------------------------------
   ios::in   | Открытие для чтения
   ios::out  | Открытие для записи (перезапись)
   ios::app  | Добавление в конец файла
   ios::ate  | Открытие с позицией в конце
   ios::trunc| Очистка файла перед записью
   ios::binary| Бинарный режим

5. ПРОВЕРКА ОТКРЫТИЯ ФАЙЛА:

   Всегда проверяйте, успешно ли открыт файл!
   
   а) Метод is_open():
   ifstream file("data.txt");
   if (file.is_open()) {
       // файл открыт успешно
       // работа с файлом
   } else {
       // ошибка открытия файла
       cout << "Не удалось открыть файл!" << endl;
   }
   
   б) Проверка через оператор !:
   ifstream file("data.txt");
   if (!file) {
       cout << "Ошибка открытия файла!" << endl;
       return;
   }
   
   в) Проверка через метод fail():
   ifstream file("data.txt");
   if (file.fail()) {
       cout << "Ошибка открытия файла!" << endl;
       return;
   }
   
   Причины ошибок открытия:
   - Файл не существует (для чтения)
   - Нет прав доступа
   - Неправильный путь
   - Файл используется другой программой

6. ЗАКРЫТИЕ ФАЙЛА:

   Файл закрывается автоматически при уничтожении объекта, но лучше закрывать явно.
   
   Синтаксис: file.close();
   
   Пример:
   ofstream file("data.txt");
   if (file.is_open()) {
       file << "Данные" << endl;
       file.close();  // явное закрытие
   }
   
   Зачем закрывать явно:
   - Освобождение ресурсов
   - Гарантия записи данных на диск
   - Возможность открыть файл снова
   
   Автоматическое закрытие:
   Файл закрывается автоматически, когда объект выходит из области видимости.

ОСНОВНЫЕ ОПЕРАЦИИ С ФАЙЛАМИ:

1. ЗАПИСЬ В ФАЙЛ:

   Запись работает так же, как вывод в консоль (cout).
   
   а) Запись через оператор <<:
   ofstream file("data.txt");
   file << "Текст" << endl;
   file << 42 << endl;
   file << 3.14 << endl;
   
   б) Запись переменных:
   int age = 18;
   string name = "Иван";
   ofstream file("data.txt");
   file << "Имя: " << name << ", Возраст: " << age << endl;
   
   в) Запись в цикле:
   ofstream file("numbers.txt");
   for (int i = 1; i <= 10; i++) {
       file << i << " ";
   }
   file << endl;
   
   г) Запись структур:
   struct Student {
       string name;
       int age;
   };
   
   Student s = {"Иван", 18};
   ofstream file("students.txt");
   file << s.name << " " << s.age << endl;

2. ЧТЕНИЕ ИЗ ФАЙЛА:

   а) Чтение через оператор >> (до пробела):
   ifstream file("data.txt");
   string word;
   int number;
   file >> word;      // читает одно слово
   file >> number;    // читает одно число
   
   б) Чтение строки целиком (getline):
   ifstream file("data.txt");
   string line;
   getline(file, line);  // читает всю строку до \n
   
   в) Чтение всех строк:
   ifstream file("data.txt");
   string line;
   while (getline(file, line)) {
       cout << line << endl;
   }
   
   г) Чтение до конца файла:
   ifstream file("data.txt");
   string word;
   while (file >> word) {
       cout << word << " ";
   }
   
   д) Чтение чисел:
   ifstream file("numbers.txt");
   int num;
   while (file >> num) {
       cout << num << " ";
   }

3. ПРОВЕРКА КОНЦА ФАЙЛА:

   а) Метод eof() (end of file):
   ifstream file("data.txt");
   string line;
   while (!file.eof()) {
       getline(file, line);
       cout << line << endl;
   }
   
   б) Проверка в условии цикла (рекомендуется):
   ifstream file("data.txt");
   string line;
   while (getline(file, line)) {  // автоматически проверяет конец файла
       cout << line << endl;
   }
   
   Важно: eof() возвращает true только ПОСЛЕ попытки чтения за концом файла!

4. ПРОВЕРКА ОШИБОК:

   а) Метод fail():
   ifstream file("data.txt");
   int number;
   file >> number;
   if (file.fail()) {
       cout << "Ошибка чтения!" << endl;
   }
   
   б) Метод good():
   ifstream file("data.txt");
   if (file.good()) {
       // файл в хорошем состоянии
   }
   
   в) Метод bad():
   ifstream file("data.txt");
   if (file.bad()) {
       // критическая ошибка
   }
   
   г) Очистка флагов ошибок:
   file.clear();  // сбрасывает флаги ошибок

5. ПОЗИЦИОНИРОВАНИЕ В ФАЙЛЕ:

   а) Получение текущей позиции:
   ifstream file("data.txt");
   streampos pos = file.tellg();  // позиция для чтения
   ofstream file2("data.txt");
   streampos pos2 = file2.tellp(); // позиция для записи
   
   б) Установка позиции:
   file.seekg(0);           // в начало файла
   file.seekg(0, ios::end); // в конец файла
   file.seekg(10);          // на позицию 10
   
   в) Относительное позиционирование:
   file.seekg(10, ios::cur);  // на 10 байт вперед от текущей позиции
   file.seekg(-5, ios::cur);  // на 5 байт назад

РАБОТА С БИНАРНЫМИ ФАЙЛАМИ:

Бинарные файлы используются для хранения данных в их исходном виде (без преобразования).

1. Открытие в бинарном режиме:
   ofstream file("data.bin", ios::binary);
   ifstream file("data.bin", ios::binary);

2. Запись бинарных данных:
   int number = 42;
   file.write((char*)&number, sizeof(number));

3. Чтение бинарных данных:
   int number;
   file.read((char*)&number, sizeof(number));

Преимущества бинарных файлов:
- Быстрее работа
- Меньше размер
- Точное сохранение данных

Недостатки:
- Не читаются как текст
- Зависимость от платформы

РАБОТА С ПУТЯМИ:

1. Относительные пути:
   "data.txt"              // в текущей папке
   "folder/data.txt"       // в подпапке
   "../data.txt"           // в родительской папке

2. Абсолютные пути:
   Windows: "C:\\Users\\Name\\data.txt"
   Linux: "/home/user/data.txt"

3. Проверка существования файла:
   #include <fstream>
   bool fileExists(const string& filename) {
       ifstream file(filename);
       return file.good();
   }

ОБРАБОТКА ОШИБОК:

Всегда обрабатывайте возможные ошибки при работе с файлами!

Пример безопасной работы:
ifstream file("data.txt");
if (!file.is_open()) {
    cout << "Ошибка: не удалось открыть файл!" << endl;
    return;
}

string line;
while (getline(file, line)) {
    if (file.fail() && !file.eof()) {
        cout << "Ошибка чтения файла!" << endl;
        break;
    }
    cout << line << endl;
}

file.close();

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


















