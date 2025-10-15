/*
===========================================
УРОК 18: СТАНДАРТНАЯ БИБЛИОТЕКА ШАБЛОНОВ (STL)
===========================================

ЦЕЛИ УРОКА:
- Понять концепцию STL
- Изучить основные контейнеры
- Освоить итераторы
- Научиться работать с алгоритмами
- Понять функциональные объекты

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

STL (STANDARD TEMPLATE LIBRARY):

STL - это набор шаблонов классов и функций для работы с данными

ОСНОВНЫЕ КОМПОНЕНТЫ STL:
1. КОНТЕЙНЕРЫ - структуры данных для хранения объектов
2. ИТЕРАТОРЫ - объекты для доступа к элементам контейнеров
3. АЛГОРИТМЫ - функции для работы с данными
4. ФУНКЦИОНАЛЬНЫЕ ОБЪЕКТЫ - объекты, которые ведут себя как функции

КОНТЕЙНЕРЫ STL:

ПОСЛЕДОВАТЕЛЬНЫЕ КОНТЕЙНЕРЫ:
- vector - динамический массив
- list - двусвязный список
- deque - двусторонняя очередь
- array - статический массив

АССОЦИАТИВНЫЕ КОНТЕЙНЕРЫ:
- set - множество уникальных элементов
- multiset - множество с дубликатами
- map - ассоциативный массив
- multimap - ассоциативный массив с дубликатами

ИТЕРАТОРЫ:
- begin() - итератор на начало
- end() - итератор на конец
- ++, -- - переход к следующему/предыдущему элементу
- * - разыменование итератора

АЛГОРИТМЫ:
- sort - сортировка
- find - поиск элемента
- count - подсчет элементов
- transform - преобразование элементов

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    cout << "=== ДЕМОНСТРАЦИЯ STL ===" << endl;
    
    // Работа с vector
    cout << "\n=== РАБОТА С VECTOR ===" << endl;
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    cout << "Исходный вектор: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Сортировка
    sort(numbers.begin(), numbers.end());
    cout << "Отсортированный вектор: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск элемента
    auto it = find(numbers.begin(), numbers.end(), 5);
    if (it != numbers.end()) {
        cout << "Элемент 5 найден на позиции " << (it - numbers.begin()) << endl;
    }
    
    // Работа с list
    cout << "\n=== РАБОТА С LIST ===" << endl;
    list<string> words = {"Hello", "World", "C++", "STL"};
    
    cout << "Список слов: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Добавление элемента в начало
    words.push_front("Start");
    cout << "После добавления в начало: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Работа с set
    cout << "\n=== РАБОТА С SET ===" << endl;
    set<int> uniqueNumbers = {5, 2, 8, 1, 9, 3, 5, 2, 8};
    
    cout << "Множество уникальных чисел: ";
    for (int num : uniqueNumbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Проверка наличия элемента
    if (uniqueNumbers.find(5) != uniqueNumbers.end()) {
        cout << "Элемент 5 найден в множестве" << endl;
    }
    
    // Работа с map
    cout << "\n=== РАБОТА С MAP ===" << endl;
    map<string, int> ages;
    ages["Анна"] = 25;
    ages["Петр"] = 30;
    ages["Мария"] = 28;
    
    cout << "Возрасты:" << endl;
    for (const auto& pair : ages) {
        cout << pair.first << ": " << pair.second << " лет" << endl;
    }
    
    // Поиск в map
    if (ages.find("Анна") != ages.end()) {
        cout << "Возраст Анны: " << ages["Анна"] << " лет" << endl;
    }
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Работа с vector и алгоритмами
Создай программу для работы с вектором чисел:
*/

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: VECTOR И АЛГОРИТМЫ ===" << endl;
    
    vector<int> numbers = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    cout << "Исходный вектор: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Сортировка по возрастанию
    sort(numbers.begin(), numbers.end());
    cout << "Отсортированный по возрастанию: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Сортировка по убыванию
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "Отсортированный по убыванию: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск максимального и минимального элементов
    auto maxIt = max_element(numbers.begin(), numbers.end());
    auto minIt = min_element(numbers.begin(), numbers.end());
    cout << "Максимальный элемент: " << *maxIt << endl;
    cout << "Минимальный элемент: " << *minIt << endl;
    
    // Подсчет четных чисел
    int evenCount = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;
    });
    cout << "Количество четных чисел: " << evenCount << endl;
    
    // Удаление дубликатов
    sort(numbers.begin(), numbers.end());
    auto uniqueEnd = unique(numbers.begin(), numbers.end());
    numbers.erase(uniqueEnd, numbers.end());
    cout << "Вектор без дубликатов: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Упражнение 2: Работа с map для подсчета слов
Создай программу для подсчета частоты слов в тексте:
*/

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: ПОДСЧЕТ СЛОВ ===" << endl;
    
    vector<string> words = {"hello", "world", "hello", "c++", "world", "hello", "stl"};
    
    cout << "Исходные слова: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Подсчет частоты слов
    map<string, int> wordCount;
    for (const string& word : words) {
        wordCount[word]++;
    }
    
    cout << "\nЧастота слов:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << " раз" << endl;
    }
    
    // Поиск самого частого слова
    auto maxPair = max_element(wordCount.begin(), wordCount.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second;
        });
    
    cout << "\nСамое частое слово: " << maxPair->first 
         << " (" << maxPair->second << " раз)" << endl;
}

/*
Упражнение 3: Работа с set для поиска пересечений
Создай программу для поиска пересечений множеств:
*/

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: ПЕРЕСЕЧЕНИЯ МНОЖЕСТВ ===" << endl;
    
    set<int> set1 = {1, 2, 3, 4, 5, 6};
    set<int> set2 = {4, 5, 6, 7, 8, 9};
    
    cout << "Множество 1: ";
    for (int num : set1) {
        cout << num << " ";
    }
    cout << endl;
    
    cout << "Множество 2: ";
    for (int num : set2) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск пересечения
    set<int> intersection;
    set_intersection(set1.begin(), set1.end(),
                     set2.begin(), set2.end(),
                     inserter(intersection, intersection.begin()));
    
    cout << "Пересечение: ";
    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск объединения
    set<int> unionSet;
    set_union(set1.begin(), set1.end(),
              set2.begin(), set2.end(),
              inserter(unionSet, unionSet.begin()));
    
    cout << "Объединение: ";
    for (int num : unionSet) {
        cout << num << " ";
    }
    cout << endl;
    
    // Поиск разности
    set<int> difference;
    set_difference(set1.begin(), set1.end(),
                   set2.begin(), set2.end(),
                   inserter(difference, difference.begin()));
    
    cout << "Разность (set1 - set2): ";
    for (int num : difference) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Упражнение 4: Работа с list и итераторами
Создай программу для работы со списком и итераторами:
*/

void exercise4() {
    cout << "=== УПРАЖНЕНИЕ 4: LIST И ИТЕРАТОРЫ ===" << endl;
    
    list<string> words = {"Hello", "World", "C++", "STL", "Templates"};
    
    cout << "Исходный список: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Поиск элемента с помощью итератора
    auto it = find(words.begin(), words.end(), "C++");
    if (it != words.end()) {
        cout << "Элемент 'C++' найден" << endl;
        
        // Вставка элемента после найденного
        words.insert(++it, "Programming");
        cout << "После вставки 'Programming': ";
        for (const string& word : words) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    // Удаление элементов по условию
    words.remove_if([](const string& word) {
        return word.length() <= 3;
    });
    
    cout << "После удаления коротких слов: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
    
    // Сортировка списка
    words.sort();
    cout << "Отсортированный список: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Система управления студентами
Создай программу для управления студентами с использованием STL:
- Хранение информации о студентах в map
- Поиск студентов по имени
- Сортировка по оценкам
- Подсчет среднего балла

Задание 2: Анализатор текста
Создай программу для анализа текста с использованием STL:
- Подсчет частоты слов
- Поиск самых длинных слов
- Удаление стоп-слов
- Сортировка по частоте

Задание 3: Система управления задачами
Создай программу для управления задачами с использованием STL:
- Хранение задач в vector
- Сортировка по приоритету
- Поиск задач по статусу
- Фильтрация по дате

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Что такое STL?
2. Какие основные компоненты STL?
3. В чем разница между vector и list?
4. Что такое итераторы?
5. Как работают алгоритмы STL?
6. В чем разница между set и map?
7. Зачем нужны функциональные объекты?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Обработка исключений
- Блоки try-catch
- Создание собственных исключений
- Обработка различных типов ошибок
- Лучшие практики обработки ошибок

ВРЕМЯ ИЗУЧЕНИЯ: 50-60 минут
ВРЕМЯ ПРАКТИКИ: 40-50 минут
ОБЩЕЕ ВРЕМЯ: 1.5-2 часа

===========================================
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 18: СТАНДАРТНАЯ БИБЛИОТЕКА ШАБЛОНОВ (STL) ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: VECTOR И АЛГОРИТМЫ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: ПОДСЧЕТ СЛОВ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: ПЕРЕСЕЧЕНИЯ МНОЖЕСТВ ===" << endl;
    exercise3();
    
    cout << "\n=== УПРАЖНЕНИЕ 4: LIST И ИТЕРАТОРЫ ===" << endl;
    exercise4();
    
    return 0;
}





