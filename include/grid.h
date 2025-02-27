#pragma once
#include "Tile.h"
#include <vector>

class Grid {
private:
	static const int COLUMNS = 4; // Количество столбцов
	static const int ROWS = 5; // Количество строк
    std::vector<std::vector<Tile*>> grid; // Массив фишек


    Tile* selectedTile1 = nullptr;  // Первая выбранная фишка
    Tile* selectedTile2 = nullptr;  // Вторая фишка для обмена

public:
    Grid(sf::Texture textures[]); // Конструктор
    void draw(sf::RenderWindow& window);

    void handleClick(float mouseX, float mouseY); // Обработчик кликов
    bool areAdjacent(Tile* a, Tile* b); // Проверка соседства
    void swapTiles(Tile* a, Tile* b); // Меняем местами
};