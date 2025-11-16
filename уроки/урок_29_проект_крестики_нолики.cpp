/*
===========================================
УРОК 29: ПРОЕКТ "КРЕСТИКИ-НОЛИКИ"
===========================================

ЦЕЛИ УРОКА:
- Создать полноценную игру "Крестики-нолики"
- Применить все изученные концепции C++
- Научиться работать с игровой логикой
- Освоить создание игровых приложений
- Понять принципы разработки игр

ТЕОРЕТИЧЕСКАЯ ЧАСТЬ:

ПРОЕКТ "КРЕСТИКИ-НОЛИКИ":

Этот урок посвящен созданию полноценной игры "Крестики-нолики", которая демонстрирует
применение всех изученных концепций C++. Игра будет поддерживать игру между людьми,
игру против ИИ и игру ИИ против ИИ, с различными уровнями сложности.

ОПИСАНИЕ ПРОЕКТА:

Крестики-нолики - это классическая игра на поле 3x3, где два игрока по очереди ставят
свои символы (X и O). Цель - выстроить три своих символа в ряд (горизонтально,
вертикально или по диагонали). Игра включает искусственный интеллект для игры против
компьютера.

АРХИТЕКТУРА ПРОЕКТА:

1. ПЕРЕЧИСЛЕНИЕ PlayerSymbol:

   НАЗНАЧЕНИЕ:
   - Определяет возможные символы на поле
   - Типобезопасная альтернатива char или int
   
   ЗАЧЕМ НУЖНО:
   - Ясность кода
   - Предотвращение ошибок
   - Типобезопасность
   
   ЗНАЧЕНИЯ:
   - EMPTY - пустая клетка
   - X - крестик
   - O - нолик

2. КЛАСС GameBoard (игровое поле):

   НАЗНАЧЕНИЕ:
   - Представляет игровое поле 3x3
   - Управляет состоянием поля
   - Проверяет условия победы
   
   ЗАЧЕМ НУЖЕН:
   - Инкапсуляция логики поля
   - Проверка валидности ходов
   - Определение победителя
   
   ФУНКЦИИ:
   - display() - отображение поля в консоли
   - makeMove() - выполнение хода (проверка валидности)
   - checkWin() - проверка победы для символа
   - isFull() - проверка заполненности поля
   - getEmptyCells() - получение списка пустых клеток
   - getCell() - получение символа в клетке
   - reset() - сброс поля
   
   РЕАЛИЗАЦИЯ:
   - Использует vector<vector<PlayerSymbol>> для поля
   - Размер 3x3 (константа SIZE = 3)
   - Проверка победы по строкам, столбцам, диагоналям
   
   ЛОГИКА ПРОВЕРКИ ПОБЕДЫ:
   1. Проверка всех строк
   2. Проверка всех столбцов
   3. Проверка главной диагонали
   4. Проверка побочной диагонали

3. КЛАСС Player (базовый класс для игроков):

   НАЗНАЧЕНИЕ:
   - Определяет общий интерфейс для всех игроков
   - Хранит имя и символ игрока
   - Предоставляет виртуальный метод для хода
   
   ЗАЧЕМ НУЖЕН:
   - Единообразный интерфейс
   - Полиморфизм (человек и ИИ)
   - Легкое добавление новых типов игроков
   
   ФУНКЦИИ:
   - makeMove() - получение хода от игрока (чисто виртуальная)
   - getType() - тип игрока (чисто виртуальная)
   - getName() - имя игрока
   - getSymbol() - символ игрока
   
   ПОЛЯ:
   - name_ - имя игрока
   - symbol_ - символ (X или O)

4. КЛАСС HumanPlayer (игрок-человек):

   НАЗНАЧЕНИЕ:
   - Реализация игрока-человека
   - Получение хода от пользователя
   - Валидация ввода
   
   ЗАЧЕМ НУЖЕН:
   - Игра человека против человека
   - Игра человека против ИИ
   - Интерактивность
   
   ФУНКЦИИ:
   - makeMove() - запрос координат у пользователя
   - Валидация ввода (проверка диапазона, занятости клетки)
   - Повторный запрос при неверном вводе
   
   ОСОБЕННОСТИ:
   - Преобразование координат (пользователь вводит 1-3, мы используем 0-2)
   - Проверка занятости клетки
   - Сообщения об ошибках

5. КЛАСС AIPlayer (игрок-ИИ):

   НАЗНАЧЕНИЕ:
   - Реализация искусственного интеллекта
   - Автоматический выбор хода
   - Стратегия игры
   
   ЗАЧЕМ НУЖЕН:
   - Игра против компьютера
   - Демонстрация алгоритмов
   - Тестирование игры
   
   ФУНКЦИИ:
   - makeMove() - выбор хода ИИ
   - Стратегия выбора хода
   
   СТРАТЕГИЯ ИИ:
   1. Попытка выиграть (проверка выигрышных ходов)
   2. Блокировка противника (проверка выигрышных ходов противника)
   3. Случайный ход (если нет критических ходов)
   
   РЕАЛИЗАЦИЯ:
   - Перебор всех пустых клеток
   - Симуляция хода для проверки победы
   - Выбор оптимального хода

6. КЛАСС Game (основной класс игры):

   НАЗНАЧЕНИЕ:
   - Управление игровым процессом
   - Координация всех компонентов
   - Ведение статистики
   
   ЗАЧЕМ НУЖЕН:
   - Централизованное управление
   - Связь между компонентами
   - Логика игры
   
   ФУНКЦИИ:
   - setupPlayers() - настройка игроков (режим игры)
   - playGame() - главный игровой цикл
   - displayStatistics() - отображение статистики
   - resetStatistics() - сброс статистики
   
   ПОЛЯ:
   - board_ - игровое поле
   - player1_, player2_ - игроки (unique_ptr<Player>)
   - currentPlayer_ - текущий игрок
   - gamesPlayed_ - количество игр
   - player1Wins_, player2Wins_ - победы
   - draws_ - ничьи
   
   ИГРОВОЙ ЦИКЛ:
   1. Отображение поля
   2. Получение хода от текущего игрока
   3. Выполнение хода
   4. Проверка победы
   5. Проверка ничьей
   6. Переключение игрока
   7. Повтор до окончания игры

7. КЛАСС GameMenu (пользовательский интерфейс):

   НАЗНАЧЕНИЕ:
   - Взаимодействие с пользователем
   - Управление меню
   - Организация работы программы
   
   ЗАЧЕМ НУЖЕН:
   - Удобный интерфейс
   - Навигация
   - Обработка команд
   
   ФУНКЦИИ:
   - run() - главный цикл
   - displayMainMenu() - отображение меню
   
   РЕАЛИЗАЦИЯ:
   - Содержит объект Game
   - Цикл while для работы
   - Switch для обработки выбора

ПРОЦЕСС СОЗДАНИЯ ПРОЕКТА:

ШАГ 1: ПЛАНИРОВАНИЕ

1. Определение правил:
   - Размер поля (3x3)
   - Правила победы
   - Условия ничьей

2. Проектирование компонентов:
   - Игровое поле
   - Игроки (человек и ИИ)
   - Логика игры

ШАГ 2: СОЗДАНИЕ ПЕРЕЧИСЛЕНИЯ PlayerSymbol

1. Определение значений:
   - EMPTY, X, O
   - Типобезопасность

ШАГ 3: СОЗДАНИЕ КЛАССА GameBoard

1. Структура данных:
   - Двумерный вектор для поля
   - Константа размера

2. Методы:
   - Отображение поля
   - Выполнение хода
   - Проверка победы
   - Проверка заполненности

3. Логика проверки:
   - Проверка всех возможных комбинаций
   - Эффективный алгоритм

ШАГ 4: СОЗДАНИЕ КЛАССА Player

1. Базовый интерфейс:
   - Виртуальный метод makeMove()
   - Хранение имени и символа

ШАГ 5: СОЗДАНИЕ КЛАССА HumanPlayer

1. Получение хода:
   - Запрос координат у пользователя
   - Валидация ввода
   - Обработка ошибок

ШАГ 6: СОЗДАНИЕ КЛАССА AIPlayer

1. Алгоритм ИИ:
   - Проверка выигрышных ходов
   - Блокировка противника
   - Случайный ход

2. Реализация:
   - Перебор возможных ходов
   - Симуляция для проверки
   - Выбор оптимального

ШАГ 7: СОЗДАНИЕ КЛАССА Game

1. Инициализация:
   - Создание игроков
   - Настройка режима игры

2. Игровой цикл:
   - Чередование ходов
   - Проверка условий
   - Обновление статистики

ШАГ 8: СОЗДАНИЕ КЛАССА GameMenu

1. Интерфейс:
   - Главное меню
   - Выбор режима игры
   - Управление статистикой

СВЯЗИ МЕЖДУ КОМПОНЕНТАМИ:

1. Player → HumanPlayer, AIPlayer:
   - Наследование
   - Полиморфизм

2. Game → GameBoard:
   - Композиция
   - Использование методов поля

3. Game → Player:
   - Хранение игроков
   - Вызов методов хода

4. GameMenu → Game:
   - Композиция
   - Управление игрой

ПОТОК ВЫПОЛНЕНИЯ ИГРЫ:

1. Настройка:
   - Выбор режима игры
   - Создание игроков

2. Игровой цикл:
   - Отображение поля
   - Ход текущего игрока
   - Проверка условий
   - Переключение игрока

3. Окончание:
   - Определение результата
   - Обновление статистики
   - Возврат в меню

ПРИМЕНЯЕМЫЕ КОНЦЕПЦИИ:

1. Наследование:
   - Player → HumanPlayer, AIPlayer
   - Полиморфизм ходов

2. Инкапсуляция:
   - Скрытие деталей реализации
   - Публичный интерфейс

3. STL:
   - vector для игрового поля
   - pair для координат
   - algorithm для поиска

4. Умные указатели:
   - unique_ptr для игроков
   - Автоматическое управление памятью

5. Исключения:
   - Обработка ошибок ввода
   - Валидация ходов

ПРИМЕРЫ КОДА:
*/

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// Перечисление для символов игроков
enum class PlayerSymbol {
    EMPTY = 0,
    X = 1,
    O = 2
};

// Класс для игрового поля
class GameBoard {
private:
    static const int SIZE = 3;
    vector<vector<PlayerSymbol>> board_;
    
public:
    GameBoard() {
        board_.resize(SIZE, vector<PlayerSymbol>(SIZE, PlayerSymbol::EMPTY));
    }
    
    void display() const {
        cout << "\n  1 2 3" << endl;
        for (int i = 0; i < SIZE; ++i) {
            cout << (i + 1) << " ";
            for (int j = 0; j < SIZE; ++j) {
                char symbol = getSymbolChar(board_[i][j]);
                cout << symbol << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    bool makeMove(int row, int col, PlayerSymbol symbol) {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            return false; // Неверные координаты
        }
        
        if (board_[row][col] != PlayerSymbol::EMPTY) {
            return false; // Клетка уже занята
        }
        
        board_[row][col] = symbol;
        return true;
    }
    
    bool isFull() const {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board_[i][j] == PlayerSymbol::EMPTY) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkWin(PlayerSymbol symbol) const {
        // Проверка строк
        for (int i = 0; i < SIZE; ++i) {
            bool win = true;
            for (int j = 0; j < SIZE; ++j) {
                if (board_[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        
        // Проверка столбцов
        for (int j = 0; j < SIZE; ++j) {
            bool win = true;
            for (int i = 0; i < SIZE; ++i) {
                if (board_[i][j] != symbol) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
        
        // Проверка главной диагонали
        bool win = true;
        for (int i = 0; i < SIZE; ++i) {
            if (board_[i][i] != symbol) {
                win = false;
                break;
            }
        }
        if (win) return true;
        
        // Проверка побочной диагонали
        win = true;
        for (int i = 0; i < SIZE; ++i) {
            if (board_[i][SIZE - 1 - i] != symbol) {
                win = false;
                break;
            }
        }
        return win;
    }
    
    vector<pair<int, int>> getEmptyCells() const {
        vector<pair<int, int>> emptyCells;
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board_[i][j] == PlayerSymbol::EMPTY) {
                    emptyCells.push_back({i, j});
                }
            }
        }
        return emptyCells;
    }
    
    PlayerSymbol getCell(int row, int col) const {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
            return PlayerSymbol::EMPTY;
        }
        return board_[row][col];
    }
    
    void reset() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                board_[i][j] = PlayerSymbol::EMPTY;
            }
        }
    }
    
private:
    char getSymbolChar(PlayerSymbol symbol) const {
        switch (symbol) {
            case PlayerSymbol::EMPTY: return '.';
            case PlayerSymbol::X: return 'X';
            case PlayerSymbol::O: return 'O';
            default: return '.';
        }
    }
};

// Базовый класс для игрока
class Player {
protected:
    string name_;
    PlayerSymbol symbol_;
    
public:
    Player(const string& name, PlayerSymbol symbol) : name_(name), symbol_(symbol) {}
    virtual ~Player() = default;
    
    virtual pair<int, int> makeMove(const GameBoard& board) = 0;
    virtual string getType() const = 0;
    
    const string& getName() const { return name_; }
    PlayerSymbol getSymbol() const { return symbol_; }
};

// Класс для человеческого игрока
class HumanPlayer : public Player {
public:
    HumanPlayer(const string& name, PlayerSymbol symbol) : Player(name, symbol) {}
    
    pair<int, int> makeMove(const GameBoard& board) override {
        int row, col;
        
        while (true) {
            cout << name_ << ", введите координаты хода (строка столбец): ";
            cin >> row >> col;
            
            // Преобразование в индексы (пользователь вводит 1-3, мы используем 0-2)
            row--;
            col--;
            
            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                if (board.getCell(row, col) == PlayerSymbol::EMPTY) {
                    return {row, col};
                } else {
                    cout << "Клетка уже занята! Попробуйте снова." << endl;
                }
            } else {
                cout << "Неверные координаты! Введите числа от 1 до 3." << endl;
            }
        }
    }
    
    string getType() const override {
        return "Человек";
    }
};

// Класс для ИИ игрока
class AIPlayer : public Player {
public:
    AIPlayer(const string& name, PlayerSymbol symbol) : Player(name, symbol) {
        srand(time(0));
    }
    
    pair<int, int> makeMove(const GameBoard& board) override {
        cout << name_ << " думает..." << endl;
        
        // Простая стратегия ИИ
        auto emptyCells = board.getEmptyCells();
        
        if (emptyCells.empty()) {
            return {-1, -1}; // Нет доступных ходов
        }
        
        // Попытка выиграть
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, symbol_);
            if (testBoard.checkWin(symbol_)) {
                return cell;
            }
        }
        
        // Попытка заблокировать противника
        PlayerSymbol opponentSymbol = (symbol_ == PlayerSymbol::X) ? PlayerSymbol::O : PlayerSymbol::X;
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, opponentSymbol);
            if (testBoard.checkWin(opponentSymbol)) {
                return cell;
            }
        }
        
        // Случайный ход
        int randomIndex = rand() % emptyCells.size();
        return emptyCells[randomIndex];
    }
    
    string getType() const override {
        return "ИИ";
    }
};

// Основной класс игры
class Game {
private:
    GameBoard board_;
    unique_ptr<Player> player1_;
    unique_ptr<Player> player2_;
    Player* currentPlayer_;
    int gamesPlayed_;
    int player1Wins_;
    int player2Wins_;
    int draws_;
    
public:
    Game() : currentPlayer_(nullptr), gamesPlayed_(0), player1Wins_(0), player2Wins_(0), draws_(0) {}
    
    void setupPlayers() {
        int gameMode;
        cout << "Выберите режим игры:" << endl;
        cout << "1. Игрок против игрока" << endl;
        cout << "2. Игрок против ИИ" << endl;
        cout << "3. ИИ против ИИ" << endl;
        cout << "Выбор: ";
        cin >> gameMode;
        
        string name1, name2;
        
        switch (gameMode) {
            case 1:
                cout << "Введите имя первого игрока: ";
                cin >> name1;
                cout << "Введите имя второго игрока: ";
                cin >> name2;
                
                player1_ = make_unique<HumanPlayer>(name1, PlayerSymbol::X);
                player2_ = make_unique<HumanPlayer>(name2, PlayerSymbol::O);
                break;
                
            case 2:
                cout << "Введите ваше имя: ";
                cin >> name1;
                
                player1_ = make_unique<HumanPlayer>(name1, PlayerSymbol::X);
                player2_ = make_unique<AIPlayer>("ИИ", PlayerSymbol::O);
                break;
                
            case 3:
                player1_ = make_unique<AIPlayer>("ИИ 1", PlayerSymbol::X);
                player2_ = make_unique<AIPlayer>("ИИ 2", PlayerSymbol::O);
                break;
                
            default:
                cout << "Неверный выбор! Установлен режим по умолчанию." << endl;
                player1_ = make_unique<HumanPlayer>("Игрок 1", PlayerSymbol::X);
                player2_ = make_unique<HumanPlayer>("Игрок 2", PlayerSymbol::O);
                break;
        }
        
        currentPlayer_ = player1_.get();
    }
    
    void playGame() {
        if (!player1_ || !player2_) {
            cout << "Игроки не настроены!" << endl;
            return;
        }
        
        board_.reset();
        currentPlayer_ = player1_.get();
        gamesPlayed_++;
        
        cout << "\n=== НОВАЯ ИГРА ===" << endl;
        cout << "Игрок 1: " << player1_->getName() << " (X)" << endl;
        cout << "Игрок 2: " << player2_->getName() << " (O)" << endl;
        
        while (true) {
            board_.display();
            
            auto move = currentPlayer_->makeMove(board_);
            
            if (move.first == -1 && move.second == -1) {
                cout << "Нет доступных ходов!" << endl;
                break;
            }
            
            if (!board_.makeMove(move.first, move.second, currentPlayer_->getSymbol())) {
                cout << "Неверный ход!" << endl;
                continue;
            }
            
            if (board_.checkWin(currentPlayer_->getSymbol())) {
                board_.display();
                cout << "Поздравляем! " << currentPlayer_->getName() << " выиграл!" << endl;
                
                if (currentPlayer_ == player1_.get()) {
                    player1Wins_++;
                } else {
                    player2Wins_++;
                }
                break;
            }
            
            if (board_.isFull()) {
                board_.display();
                cout << "Ничья!" << endl;
                draws_++;
                break;
            }
            
            // Переключение игрока
            currentPlayer_ = (currentPlayer_ == player1_.get()) ? player2_.get() : player1_.get();
        }
        
        displayStatistics();
    }
    
    void displayStatistics() const {
        cout << "\n=== СТАТИСТИКА ===" << endl;
        cout << "Игр сыграно: " << gamesPlayed_ << endl;
        cout << "Побед " << player1_->getName() << ": " << player1Wins_ << endl;
        cout << "Побед " << player2_->getName() << ": " << player2Wins_ << endl;
        cout << "Ничьих: " << draws_ << endl;
    }
    
    void resetStatistics() {
        gamesPlayed_ = 0;
        player1Wins_ = 0;
        player2Wins_ = 0;
        draws_ = 0;
        cout << "Статистика сброшена!" << endl;
    }
};

// Класс для пользовательского интерфейса
class GameMenu {
private:
    Game game_;
    
public:
    void run() {
        int choice;
        
        while (true) {
            displayMainMenu();
            cout << "Выберите действие: ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    game_.setupPlayers();
                    break;
                case 2:
                    game_.playGame();
                    break;
                case 3:
                    game_.displayStatistics();
                    break;
                case 4:
                    game_.resetStatistics();
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
        cout << "           ИГРА 'КРЕСТИКИ-НОЛИКИ'" << endl;
        cout << string(50, '=') << endl;
        cout << "1. Настроить игроков" << endl;
        cout << "2. Играть" << endl;
        cout << "3. Показать статистику" << endl;
        cout << "4. Сбросить статистику" << endl;
        cout << "0. Выход" << endl;
    }
};

int main() {
    cout << "=== ПРОЕКТ 'КРЕСТИКИ-НОЛИКИ' ===" << endl;
    
    GameMenu menu;
    menu.run();
    
    return 0;
}

/*
ПРАКТИЧЕСКИЕ УПРАЖНЕНИЯ:

Упражнение 1: Улучшение ИИ
Улучши алгоритм ИИ для более умной игры:
*/

class SmartAIPlayer : public AIPlayer {
public:
    SmartAIPlayer(const string& name, PlayerSymbol symbol) : AIPlayer(name, symbol) {}
    
    pair<int, int> makeMove(const GameBoard& board) override {
        cout << name_ << " думает..." << endl;
        
        auto emptyCells = board.getEmptyCells();
        if (emptyCells.empty()) {
            return {-1, -1};
        }
        
        // Попытка выиграть
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, symbol_);
            if (testBoard.checkWin(symbol_)) {
                return cell;
            }
        }
        
        // Попытка заблокировать противника
        PlayerSymbol opponentSymbol = (symbol_ == PlayerSymbol::X) ? PlayerSymbol::O : PlayerSymbol::X;
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, opponentSymbol);
            if (testBoard.checkWin(opponentSymbol)) {
                return cell;
            }
        }
        
        // Стратегические ходы
        vector<pair<int, int>> corners = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
        vector<pair<int, int>> center = {{1, 1}};
        vector<pair<int, int>> edges = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
        
        // Приоритет: центр, углы, края
        for (const auto& cell : center) {
            if (find(emptyCells.begin(), emptyCells.end(), cell) != emptyCells.end()) {
                return cell;
            }
        }
        
        for (const auto& cell : corners) {
            if (find(emptyCells.begin(), emptyCells.end(), cell) != emptyCells.end()) {
                return cell;
            }
        }
        
        for (const auto& cell : edges) {
            if (find(emptyCells.begin(), emptyCells.end(), cell) != emptyCells.end()) {
                return cell;
            }
        }
        
        // Случайный ход
        int randomIndex = rand() % emptyCells.size();
        return emptyCells[randomIndex];
    }
};

void exercise1() {
    cout << "=== УПРАЖНЕНИЕ 1: УЛУЧШЕННЫЙ ИИ ===" << endl;
    
    GameBoard board;
    SmartAIPlayer ai1("Умный ИИ 1", PlayerSymbol::X);
    SmartAIPlayer ai2("Умный ИИ 2", PlayerSymbol::O);
    
    // Симуляция игры между умными ИИ
    cout << "Симуляция игры между умными ИИ:" << endl;
    
    Player* currentPlayer = &ai1;
    while (!board.isFull() && !board.checkWin(PlayerSymbol::X) && !board.checkWin(PlayerSymbol::O)) {
        auto move = currentPlayer->makeMove(board);
        board.makeMove(move.first, move.second, currentPlayer->getSymbol());
        
        if (board.checkWin(currentPlayer->getSymbol())) {
            cout << currentPlayer->getName() << " выиграл!" << endl;
            break;
        }
        
        currentPlayer = (currentPlayer == &ai1) ? &ai2 : &ai1;
    }
    
    if (board.isFull() && !board.checkWin(PlayerSymbol::X) && !board.checkWin(PlayerSymbol::O)) {
        cout << "Ничья!" << endl;
    }
    
    board.display();
}

/*
Упражнение 2: Добавление новых функций
Добавь в игру новые функции:
*/

class AdvancedGame : public Game {
public:
    void playTournament(int rounds) {
        cout << "\n=== ТУРНИР ===" << endl;
        cout << "Количество раундов: " << rounds << endl;
        
        int player1Wins = 0, player2Wins = 0, draws = 0;
        
        for (int round = 1; round <= rounds; ++round) {
            cout << "\n--- Раунд " << round << " ---" << endl;
            
            board_.reset();
            currentPlayer_ = player1_.get();
            
            while (true) {
                auto move = currentPlayer_->makeMove(board_);
                
                if (move.first == -1 && move.second == -1) {
                    break;
                }
                
                board_.makeMove(move.first, move.second, currentPlayer_->getSymbol());
                
                if (board_.checkWin(currentPlayer_->getSymbol())) {
                    cout << currentPlayer_->getName() << " выиграл раунд " << round << "!" << endl;
                    
                    if (currentPlayer_ == player1_.get()) {
                        player1Wins++;
                    } else {
                        player2Wins++;
                    }
                    break;
                }
                
                if (board_.isFull()) {
                    cout << "Ничья в раунде " << round << "!" << endl;
                    draws++;
                    break;
                }
                
                currentPlayer_ = (currentPlayer_ == player1_.get()) ? player2_.get() : player1_.get();
            }
        }
        
        cout << "\n=== РЕЗУЛЬТАТЫ ТУРНИРА ===" << endl;
        cout << "Побед " << player1_->getName() << ": " << player1Wins << endl;
        cout << "Побед " << player2_->getName() << ": " << player2Wins << endl;
        cout << "Ничьих: " << draws << endl;
        
        if (player1Wins > player2Wins) {
            cout << "Победитель турнира: " << player1_->getName() << "!" << endl;
        } else if (player2Wins > player1Wins) {
            cout << "Победитель турнира: " << player2_->getName() << "!" << endl;
        } else {
            cout << "Турнир завершился вничью!" << endl;
        }
    }
    
    void analyzePosition(const GameBoard& board) {
        cout << "\n=== АНАЛИЗ ПОЗИЦИИ ===" << endl;
        
        // Анализ возможных выигрышных ходов
        auto emptyCells = board.getEmptyCells();
        
        cout << "Возможные ходы: " << emptyCells.size() << endl;
        
        // Проверка выигрышных ходов для X
        int xWinningMoves = 0;
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, PlayerSymbol::X);
            if (testBoard.checkWin(PlayerSymbol::X)) {
                xWinningMoves++;
            }
        }
        
        // Проверка выигрышных ходов для O
        int oWinningMoves = 0;
        for (const auto& cell : emptyCells) {
            GameBoard testBoard = board;
            testBoard.makeMove(cell.first, cell.second, PlayerSymbol::O);
            if (testBoard.checkWin(PlayerSymbol::O)) {
                oWinningMoves++;
            }
        }
        
        cout << "Выигрышных ходов для X: " << xWinningMoves << endl;
        cout << "Выигрышных ходов для O: " << oWinningMoves << endl;
        
        if (xWinningMoves > 0) {
            cout << "X может выиграть в следующем ходу!" << endl;
        }
        if (oWinningMoves > 0) {
            cout << "O может выиграть в следующем ходу!" << endl;
        }
    }
};

void exercise2() {
    cout << "=== УПРАЖНЕНИЕ 2: НОВЫЕ ФУНКЦИИ ===" << endl;
    
    AdvancedGame game;
    
    // Настройка игроков
    game.setupPlayers();
    
    // Турнир
    game.playTournament(3);
    
    // Анализ позиции
    GameBoard board;
    board.makeMove(0, 0, PlayerSymbol::X);
    board.makeMove(1, 1, PlayerSymbol::O);
    board.makeMove(0, 1, PlayerSymbol::X);
    
    game.analyzePosition(board);
}

/*
Упражнение 3: Создание рейтинговой системы
Создай рейтинговую систему для игроков:
*/

class PlayerRating {
private:
    string name_;
    int rating_;
    int gamesPlayed_;
    int wins_;
    int losses_;
    int draws_;
    
public:
    PlayerRating(const string& name, int initialRating = 1000)
        : name_(name), rating_(initialRating), gamesPlayed_(0), wins_(0), losses_(0), draws_(0) {}
    
    void updateRating(bool won, bool draw, int opponentRating) {
        gamesPlayed_++;
        
        if (draw) {
            draws_++;
            // Рейтинг не изменяется при ничьей
        } else if (won) {
            wins_++;
            // Увеличение рейтинга при победе
            int ratingChange = max(1, (opponentRating - rating_) / 20);
            rating_ += ratingChange;
        } else {
            losses_++;
            // Уменьшение рейтинга при поражении
            int ratingChange = max(1, (rating_ - opponentRating) / 20);
            rating_ -= ratingChange;
        }
    }
    
    void displayStats() const {
        cout << "\n=== РЕЙТИНГ ИГРОКА ===" << endl;
        cout << "Имя: " << name_ << endl;
        cout << "Рейтинг: " << rating_ << endl;
        cout << "Игр сыграно: " << gamesPlayed_ << endl;
        cout << "Побед: " << wins_ << endl;
        cout << "Поражений: " << losses_ << endl;
        cout << "Ничьих: " << draws_ << endl;
        
        if (gamesPlayed_ > 0) {
            double winRate = (double)wins_ / gamesPlayed_ * 100;
            cout << "Процент побед: " << fixed << setprecision(1) << winRate << "%" << endl;
        }
    }
    
    const string& getName() const { return name_; }
    int getRating() const { return rating_; }
    int getGamesPlayed() const { return gamesPlayed_; }
    int getWins() const { return wins_; }
    int getLosses() const { return losses_; }
    int getDraws() const { return draws_; }
};

class RatingSystem {
private:
    vector<PlayerRating> players_;
    
public:
    void addPlayer(const string& name) {
        players_.push_back(PlayerRating(name));
        cout << "Игрок " << name << " добавлен в рейтинговую систему" << endl;
    }
    
    void updateGameResult(const string& player1, const string& player2, bool player1Won, bool draw) {
        PlayerRating* p1 = findPlayer(player1);
        PlayerRating* p2 = findPlayer(player2);
        
        if (p1 && p2) {
            p1->updateRating(player1Won, draw, p2->getRating());
            p2->updateRating(!player1Won, draw, p1->getRating());
        }
    }
    
    void displayLeaderboard() const {
        cout << "\n=== ТАБЛИЦА ЛИДЕРОВ ===" << endl;
        
        if (players_.empty()) {
            cout << "Нет игроков в системе" << endl;
            return;
        }
        
        vector<PlayerRating> sortedPlayers = players_;
        sort(sortedPlayers.begin(), sortedPlayers.end(),
            [](const PlayerRating& a, const PlayerRating& b) {
                return a.getRating() > b.getRating();
            });
        
        cout << "Место | Имя | Рейтинг | Игр | Побед | Поражений | Ничьих" << endl;
        cout << "------|-----|---------|-----|-------|-----------|-------" << endl;
        
        for (size_t i = 0; i < sortedPlayers.size(); ++i) {
            const PlayerRating& player = sortedPlayers[i];
            cout << setw(5) << (i + 1) << " | "
                 << setw(3) << player.getName() << " | "
                 << setw(7) << player.getRating() << " | "
                 << setw(3) << player.getGamesPlayed() << " | "
                 << setw(5) << player.getWins() << " | "
                 << setw(9) << player.getLosses() << " | "
                 << setw(7) << player.getDraws() << endl;
        }
    }
    
private:
    PlayerRating* findPlayer(const string& name) {
        for (auto& player : players_) {
            if (player.getName() == name) {
                return &player;
            }
        }
        return nullptr;
    }
};

void exercise3() {
    cout << "=== УПРАЖНЕНИЕ 3: РЕЙТИНГОВАЯ СИСТЕМА ===" << endl;
    
    RatingSystem ratingSystem;
    
    // Добавление игроков
    ratingSystem.addPlayer("Алексей");
    ratingSystem.addPlayer("Мария");
    ratingSystem.addPlayer("Дмитрий");
    
    // Симуляция игр
    ratingSystem.updateGameResult("Алексей", "Мария", true, false);
    ratingSystem.updateGameResult("Мария", "Дмитрий", true, false);
    ratingSystem.updateGameResult("Алексей", "Дмитрий", false, false);
    ratingSystem.updateGameResult("Мария", "Алексей", false, true);
    
    // Отображение таблицы лидеров
    ratingSystem.displayLeaderboard();
}

/*
ДОМАШНИЕ ЗАДАНИЯ:

Задание 1: Расширение функциональности
Расширь игру дополнительными возможностями:
- Поддержка различных размеров поля
- Различные режимы игры
- Система достижений
- Сохранение статистики

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
3. Как организовать игровую логику?
4. Как обрабатывать ошибки в игре?
5. Как расширить функциональность игры?
6. Какие тесты нужны для игры?
7. Как оптимизировать производительность?

ЧТО ДАЛЬШЕ:
На следующем уроке мы изучим:
- Итоговый проект
- Создание полноценного приложения
- Применение всех изученных концепций
- Заключение курса
- Планы на будущее

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
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main() {
    // Основная программа
    cout << "=== УРОК 29: ПРОЕКТ 'КРЕСТИКИ-НОЛИКИ' ===" << endl;
    
    // Выполняем упражнения
    cout << "\n=== УПРАЖНЕНИЕ 1: УЛУЧШЕННЫЙ ИИ ===" << endl;
    exercise1();
    
    cout << "\n=== УПРАЖНЕНИЕ 2: НОВЫЕ ФУНКЦИИ ===" << endl;
    exercise2();
    
    cout << "\n=== УПРАЖНЕНИЕ 3: РЕЙТИНГОВАЯ СИСТЕМА ===" << endl;
    exercise3();
    
    return 0;
}


















