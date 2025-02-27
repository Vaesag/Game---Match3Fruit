#pragma once
#include "Tile.h"
#include "ui.h"
#include <vector>

class Grid {
private:
    static const int COLUMNS = 4;
    static const int ROWS = 5;

    // Двумерный вектор для хранения фишек
    std::vector<std::vector<Tile*>> grid;
    sf::Texture* textures;

    UI* ui;

    // Анимационные параметры
    bool isAnimating = false;
    sf::Clock animationClock;
    float animationDuration = 0.9f;
    bool waitingForAnimation = false;

    // Выбранные пользователем фишки
    Tile* selectedTile1 = nullptr;
    Tile* selectedTile2 = nullptr;

public:
    // Конструктор
    Grid(sf::Texture textures[], sf::RenderWindow* window, UI* ui);

    // Отрисовка игрового поля
    void draw(sf::RenderWindow& window);

    // Обработка кликов пользователя
    void handleClick(float mouseX, float mouseY);

    // Проверка, являются ли две фишки соседними
    bool areAdjacent(Tile* a, Tile* b);

    // Обмен местами двух фишек
    void swapTiles(Tile* tile1, Tile* tile2);

    // Удаление совпадающих фишек
    void removeMatches();

    // Опускание фишек вниз
    void dropTiles();

    // Проверка совпадений после генерации
    void processMatchesAtStart();

    // Проверка наличия совпадений (3 и более одинаковых фишек)
    bool checkMatches();

    // Пересоздание игрового поля
    void resetGrid();

    // Обновление состояния анимации
    void updateAnimation();

    // Проверка, идет ли анимация
    bool isAnimationRunning() { return isAnimating; }
};