#pragma once
#include "Tile.h"
#include <vector>

class Grid {
private:
	static const int COLUMNS = 4; // Количество столбцов
	static const int ROWS = 5; // Количество строк
    std::vector<std::vector<Tile*>> grid; // Массив фишек

public:
    Grid(sf::Texture textures[]); // Конструктор
    void draw(sf::RenderWindow& window);
};