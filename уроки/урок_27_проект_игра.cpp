/*
===========================================
УРОК 27: ПРОЕКТ "ИГРА УГАДАЙ ЧИСЛО"
===========================================

ЦЕЛИ УРОКА:
- Создать полноценную игру "Угадай число"
- Применить все изученные концепции C++
- Научиться работать с пользовательским интерфейсом
- Освоить создание игровых приложений
- Понять принципы разработки игр

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПРОЕКТ "ИГРА УГАДАЙ ЧИСЛО":

Этот урок посвящен созданию полноценной игры "Угадай число", которая демонстрирует
применение всех изученных концепций C++:

1. КЛАССЫ И ОБЪЕКТЫ:
   - Класс Game для управления игрой
   - Класс Player для игрока
   - Класс Statistics для статистики

2. НАСЛЕДОВАНИЕ И ПОЛИМОРФИЗМ:
   - Базовый класс Difficulty
   - Производные классы для различных уровней сложности
   - Виртуальные функции для настройки игры

3. ШАБЛОНЫ:
   - Шаблонный класс для хранения статистики
   - Шаблонные функции для обработки данных

4. STL:
   - Контейнеры для хранения данных
   - Алгоритмы для обработки

5. ОБРАБОТКА ИСКЛЮЧЕНИЙ:
   - Обработка ошибок ввода
   - Валидация пользовательского ввода
   - Обработка неверных данных

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
using namespace std;

// Базовый класс для уровней сложности
class Difficulty {
protected:
    string name_;
    int maxNumber_;
    int maxAttempts_;
    
public:
    Difficulty(const string& name, int maxNumber, int maxAttempts)
        : name_(name), maxNumber_(maxNumber), maxAttempts_(maxAttempts) {}
    
    virtual ~Difficulty() = default;
    
    virtual int generateNumber() const {
        return rand() % maxNumber_ + 1;
    }
    
    virtual string getHint(int guess, int secretNumber) const {
        if (guess < secretNumber) {
            return "Загаданное число больше!";
        } else if (guess > secretNumber) {
            return "Загаданное число меньше!";
        } else {
            return "Поздравляем! Вы угадали!";
        }
    }
    
    const string& getName() const { return name_; }
    int getMaxNumber() const { return maxNumber_; }
    int getMaxAttempts() const { return maxAttempts_; }
};

// Класс для легкого уровня
class EasyDifficulty : public Difficulty {
public:
    EasyDifficulty() : Difficulty("Легкий", 50, 10) {}
    
    string getHint(int guess, int secretNumber) const override {
        int difference = abs(guess - secretNumber);
        string baseHint = Difficulty::getHint(guess, secretNumber);
        
        if (difference <= 5) {
            return baseHint + " (Очень близко!)";
        } else if (difference <= 15) {
            return baseHint + " (Близко)";
        } else {
            return baseHint + " (Далеко)";
        }
    }
};

// Класс для среднего уровня
class MediumDifficulty : public Difficulty {
public:
    MediumDifficulty() : Difficulty("Средний", 100, 7) {}
};

// Класс для сложного уровня
class HardDifficulty : public Difficulty {
public:
    HardDifficulty() : Difficulty("Сложный", 200, 5) {}
    
    string getHint(int guess, int secretNumber) const override {
        return Difficulty::getHint(guess, secretNumber);
    }
};

// Класс для игрока
class Player {
private:
    string name_;
    int gamesPlayed_;
    int gamesWon_;
    int totalAttempts_;
    int bestScore_;
    
public:
    Player(const string& name = "Игрок") 
        : name_(name), gamesPlayed_(0), gamesWon_(0), totalAttempts_(0), bestScore_(INT_MAX) {}
    
    void playGame() { gamesPlayed_++; }
    void winGame() { gamesWon_++; }
    void addAttempts(int attempts) { totalAttempts_ += attempts; }
    
    void updateBestScore(int attempts) {
        if (attempts < bestScore_) {
            bestScore_ = attempts;
        }
    }
    
    const string& getName() const { return name_; }
    int getGamesPlayed() const { return gamesPlayed_; }
    int getGamesWon() const { return gamesWon_; }
    int getTotalAttempts() const { return totalAttempts_; }
    int getBestScore() const { return bestScore_; }
    
    double getWinRate() const {
        return gamesPlayed_ > 0 ? (double)gamesWon_ / gamesPlayed_ * 100 : 0;
    }
    
    double getAverageAttempts() const {
        return gamesPlayed_ > 0 ? (double)totalAttempts_ / gamesPlayed_ : 0;
    }
    
    void displayStats() const {
        cout << "\n=== СТАТИСТИКА ИГРОКА ===" << endl;
        cout << "Имя: " << name_ << endl;
        cout << "Игр сыграно: " << gamesPlayed_ << endl;
        cout << "Игр выиграно: " << gamesWon_ << endl;
        cout << "Процент побед: " << fixed << setprecision(1) << getWinRate() << "%" << endl;
        cout << "Среднее количество попыток: " << fixed << setprecision(1) << getAverageAttempts() << endl;
        cout << "Лучший результат: " << bestScore_ << " попыток" << endl;
    }
};

// Класс для статистики
class Statistics {
private:
    vector<Player> players_;
    
public:
    void addPlayer(const Player& player) {
        players_.push_back(player);
    }
    
    void displayLeaderboard() const {
        cout << "\n=== ТАБЛИЦА ЛИДЕРОВ ===" << endl;
        
        if (players_.empty()) {
            cout << "Нет данных для отображения" << endl;
            return;
        }
        
        // Сортировка по проценту побед
        vector<Player> sortedPlayers = players_;
        sort(sortedPlayers.begin(), sortedPlayers.end(),
            [](const Player& a, const Player& b) {
                return a.getWinRate() > b.getWinRate();
            });
        
        cout << "Место | Имя | Побед | Попыток | Лучший результат" << endl;
        cout << "------|-----|-------|---------|------------------" << endl;
        
        for (size_t i = 0; i < sortedPlayers.size(); ++i) {
            const Player& player = sortedPlayers[i];
            cout << setw(5) << (i + 1) << " | "
                 << setw(3) << player.getName() << " | "
                 << setw(5) << player.getGamesWon() << " | "
                 << setw(7) << fixed << setprecision(1) << player.getAverageAttempts() << " | "
                 << setw(16) << player.getBestScore() << endl;
        }
    }
    
    void saveToFile(const string& filename) const {
        ofstream file(filename);
        if (file.is_open()) {
            for (const auto& player : players_) {
                file << player.getName() << " " << player.getGamesPlayed() << " "
                     << player.getGamesWon() << " " << player.getTotalAttempts() << " "
                     << player.getBestScore() << endl;
            }
            file.close();
            cout << "Статистика сохранена в файл " << filename << endl;
        } else {
            cout << "Ошибка сохранения файла!" << endl;
        }
    }
    
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (file.is_open()) {
            players_.clear();
            string name;
            int gamesPlayed, gamesWon, totalAttempts, bestScore;
            
            while (file >> name >> gamesPlayed >> gamesWon >> totalAttempts >> bestScore) {
                Player player(name);
                // Установка статистики (упрощенная версия)
                players_.push_back(player);
            }
            file.close();
            cout << "Статистика загружена из файла " << filename << endl;
        } else {
            cout << "Файл не найден!" << endl;
        }
    }
};

// Основной класс игры
class Game {
private:
    unique_ptr<Difficulty> difficulty_;
    Player* player_;
    int secretNumber_;
    int attempts_;
    bool isGameOver_;
    
public:
    Game(Player* player = nullptr) 
        : player_(player), attempts_(0), isGameOver_(false) {
        srand(time(0));
    }
    
    void setDifficulty(unique_ptr<Difficulty> diff) {
        difficulty_ = move(diff);
    }
    
    void startNewGame() {
        if (!difficulty_) {
            throw runtime_error("Уровень сложности не установлен!");
        }
        
        secretNumber_ = difficulty_->generateNumber();
        attempts_ = 0;
        isGameOver_ = false;
        
        cout << "\n=== НОВАЯ ИГРА ===" << endl;
        cout << "Уровень сложности: " << difficulty_->getName() << endl;
        cout << "Диапазон чисел: 1 - " << difficulty_->getMaxNumber() << endl;
        cout << "Максимум попыток: " << difficulty_->getMaxAttempts() << endl;
        cout << "Угадайте загаданное число!" << endl;
    }
    
    bool makeGuess(int guess) {
        if (isGameOver_) {
            cout << "Игра уже окончена!" << endl;
            return false;
        }
        
        attempts_++;
        
        if (guess == secretNumber_) {
            cout << "Поздравляем! Вы угадали число " << secretNumber_ 
                 << " за " << attempts_ << " попыток!" << endl;
            
            if (player_) {
                player_->playGame();
                player_->winGame();
                player_->addAttempts(attempts_);
                player_->updateBestScore(attempts_);
            }
            
            isGameOver_ = true;
            return true;
        }
        
        cout << difficulty_->getHint(guess, secretNumber_) << endl;
        
        if (attempts_ >= difficulty_->getMaxAttempts()) {
            cout << "Игра окончена! Загаданное число было " << secretNumber_ << endl;
            
            if (player_) {
                player_->playGame();
                player_->addAttempts(attempts_);
            }
            
            isGameOver_ = true;
        }
        
        return false;
    }
    
    bool isGameOver() const { return isGameOver_; }
    int getAttempts() const { return attempts_; }
    int getMaxAttempts() const { return difficulty_ ? difficulty_->getMaxAttempts() : 0; }
    int getSecretNumber() const { return secretNumber_; }
};

// Класс для пользовательского интерфейса
class GameMenu {
private:
    Game game_;
    Player player_;
    Statistics statistics_;
    
public:
    GameMenu() : game_(&player_) {
        statistics_.loadFromFile("statistics.txt");
    }
    
    void run() {
        int choice;
        
        while (true) {
            displayMainMenu();
            cout << "Выберите действие: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    playGame();
                    break;
                case 2:
                    player_.displayStats();
                    break;
                case 3:
                    statistics_.displayLeaderboard();
                    break;
                case 4:
                    statistics_.saveToFile("statistics.txt");
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
        cout << "\n" << string(50, '=') << endl;
        cout << "           ИГРА 'УГАДАЙ ЧИСЛО'" << endl;
        cout << string(50, '=') << endl;
        cout << "1. Играть" << endl;
        cout << "2. Показать статистику" << endl;
        cout << "3. Таблица лидеров" << endl;
        cout << "4. Сохранить статистику" << endl;
        cout << "0. Выход" << endl;
    }
    
    void playGame() {
        int difficultyChoice;
        
        cout << "\nВыберите уровень сложности:" << endl;
        cout << "1. Легкий (1-50, 10 попыток)" << endl;
        cout << "2. Средний (1-100, 7 попыток)" << endl;
        cout << "3. Сложный (1-200, 5 попыток)" << endl;
        cout << "Выбор: ";
        cin >> difficultyChoice;
        
        switch (difficultyChoice) {
            case 1:
                game_.setDifficulty(make_unique<EasyDifficulty>());
                break;
            case 2:
                game_.setDifficulty(make_unique<MediumDifficulty>());
                break;
            case 3:
                game_.setDifficulty(make_unique<HardDifficulty>());
                break;
            default:
                cout << "Неверный выбор! Установлен средний уровень." << endl;
                game_.setDifficulty(make_unique<MediumDifficulty>());
                break;
        }
        
        try {
            game_.startNewGame();
            
            int guess;
            while (!game_.isGameOver()) {
                cout << "\nПопытка " << (game_.getAttempts() + 1) << "/" << game_.getMaxAttempts() << ": ";
                cin >> guess;
                
                if (cin.fail()) {
                    cout << "Неверный ввод! Пожалуйста, введите число." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                
                game_.makeGuess(guess);
            }
            
        } catch (const exception& e) {
            cout << "Ошибка: " << e.what() << endl;
        }
    }
};

int main() {
    cout << "=== ПРОЕКТ 'ИГРА УГАДАЙ ЧИСЛО' ===" << endl;
    
    GameMenu menu;
    menu.run();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Добавление новых уровней сложности
Добавь в игру новые уровни сложности:
*/

class ExpertDifficulty : public Difficulty {
public:
    ExpertDifficulty() : Difficulty("Эксперт", 500, 3) {}
    
    string getHint(int guess, int secretNumber) const override {
        return Difficulty::getHint(guess, secretNumber);
    }
};

class MasterDifficulty : public Difficulty {
public:
    MasterDifficulty() : Difficulty("Мастер", 1000, 2) {}
    
    string getHint(int guess, int secretNumber) const override {
        return Difficulty::getHint(guess, secretNumber);
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: НОВЫЕ УРОВНИ СЛОЖНОСТИ ===" << endl;
    
    Player player("Тестовый игрок");
    Game game(&player);
    
    // Тестирование экспертного уровня
    game.setDifficulty(make_unique<ExpertDifficulty>());
    game.startNewGame();
    
    // Тестирование мастерского уровня
    game.setDifficulty(make_unique<MasterDifficulty>());
    game.startNewGame();
}

/*
Упражнение 2: Улучшение пользовательского интерфейса
Улучши пользовательский интерфейс игры:
*/

class ImprovedGameMenu : public GameMenu {
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
                    playGame();
                    break;
                case 2:
                    player_.displayStats();
                    break;
                case 3:
                    statistics_.displayLeaderboard();
                    break;
                case 4:
                    statistics_.saveToFile("statistics.txt");
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
        cout << "\n" << string(60, '=') << endl;
        cout << "           ДОБРО ПОЖАЛОВАТЬ В ИГРУ 'УГАДАЙ ЧИСЛО'" << endl;
        cout << string(60, '=') << endl;
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    
    ImprovedGameMenu menu;
    menu.run();
}

/*
Упражнение 3: Добавление новых функций
Добавь в игру новые функции:
*/

class GameFeatures {
public:
    static void displayRules() {
        cout << "\n=== ПРАВИЛА ИГРЫ ===" << endl;
        cout << "1. Компьютер загадывает число в определенном диапазоне" << endl;
        cout << "2. Вы должны угадать это число за ограниченное количество попыток" << endl;
        cout << "3. После каждой попытки вы получаете подсказку" << endl;
        cout << "4. Цель - угадать число за минимальное количество попыток" << endl;
    }
    
    static void displayTips() {
        cout << "\n=== СОВЕТЫ ===" << endl;
        cout << "1. Начинайте с середины диапазона" << endl;
        cout << "2. Используйте бинарный поиск" << endl;
        cout << "3. Внимательно читайте подсказки" << endl;
        cout << "4. Не паникуйте, если не угадали с первого раза" << endl;
    }
    
    static void displayAchievements(const Player& player) {
        cout << "\n=== ДОСТИЖЕНИЯ ===" << endl;
        
        if (player.getGamesWon() >= 10) {
            cout << "🏆 Мастер игры - выиграно 10+ игр" << endl;
        }
        
        if (player.getBestScore() <= 3) {
            cout << "🎯 Снайпер - угадано за 3 попытки или меньше" << endl;
        }
        
        if (player.getWinRate() >= 80) {
            cout << "⭐ Чемпион - процент побед 80% или выше" << endl;
        }
        
        if (player.getGamesPlayed() >= 50) {
            cout << "🎮 Ветеран - сыграно 50+ игр" << endl;
        }
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: НОВЫЕ ФУНКЦИИ ===" << endl;
    
    Player player("Тестовый игрок");
    
    // Симуляция достижений
    for (int i = 0; i < 15; ++i) {
        player.playGame();
        player.winGame();
        player.addAttempts(3);
        player.updateBestScore(3);
    }
    
    GameFeatures::displayRules();
    GameFeatures::displayTips();
    GameFeatures::displayAchievements(player);
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Расширение функциональности
Расширь игру дополнительными возможностями:
- Поддержка многопользовательской игры
- Турнирный режим
- Специальные события и бонусы
- Система достижений

Задание 2: Графический интерфейс
Создай версию игры с графическим интерфейсом:
- Использование библиотек GUI
- Визуальные элементы интерфейса
- Анимации и эффекты
- Звуковые эффекты

Задание 3: Сетевая игра
Создай сетевую версию игры:
- Многопользовательская игра
- Сетевое взаимодействие
- Синхронизация данных
- Чат между игроками

ПРОВЕРОЧНЫЕ ВОПРОСЫ:

1. Как применить ООП в игровом проекте?
2. Какие паттерны проектирования использованы?
3. Как организовать пользовательский интерфейс?
4. Как обрабатывать ошибки в игре?
5. Как расширить функциональность игры?
6. Какие тесты нужны для игры?
7. Как оптимизировать производительность?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Проект "Система управления студентами"
- Создание системы управления данными
- Работа с файлами и базами данных
- Пользовательский интерфейс системы
- Сохранение и загрузка данных

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
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 27: ПРОЕКТ 'ИГРА УГАДАЙ ЧИСЛО' ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: НОВЫЕ УРОВНИ СЛОЖНОСТИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: УЛУЧШЕННЫЙ ИНТЕРФЕЙС ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: НОВЫЕ ФУНКЦИИ ===" << endl;
    exercise3();
    
    return 0;
}





