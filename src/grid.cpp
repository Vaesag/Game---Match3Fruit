#include "../include/Grid.h"
#include <cstdlib>
#include <ctime>

Grid::Grid(sf::Texture textures[]) {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Рандомизация

    grid.resize(ROWS, std::vector<Tile*>(COLUMNS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            int randomType = std::rand() % 5; // 3 вида фишек
            grid[i][j] = new Tile(randomType, textures[randomType], j * 48 + 40, i * 50 + 140);
        }
    }
}

void Grid::draw(sf::RenderWindow& window) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            window.draw(grid[i][j]->sprite);
        }
    }
}