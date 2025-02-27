#pragma once
#include "Tile.h"
#include <vector>

class Grid {
private:
	static const int COLUMNS = 4;
	static const int ROWS = 5;
    std::vector<std::vector<Tile*>> grid;
    sf::Texture* textures; 


    Tile* selectedTile1 = nullptr;
    Tile* selectedTile2 = nullptr;

public:
    Grid(sf::Texture textures[], sf::RenderWindow* window); // Конструктор
    void draw(sf::RenderWindow& window);

    void handleClick(float mouseX, float mouseY); // Обработчик кликов
    bool areAdjacent(Tile* a, Tile* b); // Проверка соседства
   void swapTiles(Tile* tile1, Tile* tile2); // Меняем местами

   void removeMatches();  // Удаляет совпавшие фишки
   void dropTiles();      // Опускает фишки вниз
    void processMatchesAtStart(); // Проверяем совпадения после генерации
    bool checkMatches(); // Проверка совпадений (3+ одинаковых фишек)

};