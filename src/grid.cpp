#include "../include/Grid.h"
#include <cstdlib>
#include <ctime>

Grid::Grid(sf::Texture textures[]) {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Рандомизация

    grid.resize(ROWS, std::vector<Tile*>(COLUMNS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            int randomType = std::rand() % 4; // 3 вида фишек
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

void Grid::handleClick(float mouseX, float mouseY) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            Tile* tile = grid[i][j];

            if (tile->sprite.getGlobalBounds().contains(mouseX, mouseY)) {
                if (selectedTile1 == nullptr) {
                    selectedTile1 = tile;
                    selectedTile1->sprite.setColor(sf::Color(200, 200, 200)); // Затемняем фишку
                }
                else if (selectedTile2 == nullptr && tile != selectedTile1) {
                    selectedTile2 = tile;
                    selectedTile2->sprite.setColor(sf::Color(200, 200, 200)); // Затемняем вторую фишку

                    // Проверяем, можно ли менять местами
                    if (areAdjacent(selectedTile1, selectedTile2)) {
                        swapTiles(selectedTile1, selectedTile2);
                    }

                    // Сбрасываем выделение после обмена
                    selectedTile1->sprite.setColor(sf::Color::White);
                    selectedTile2->sprite.setColor(sf::Color::White);
                    selectedTile1 = nullptr;
                    selectedTile2 = nullptr;
                }
                return;
            }
        }
    }
}

bool Grid::areAdjacent(Tile* a, Tile* b) {
    float dx = std::abs(a->sprite.getPosition().x - b->sprite.getPosition().x);
    float dy = std::abs(a->sprite.getPosition().y - b->sprite.getPosition().y);

    // Используем фактические размеры ячеек
    return (dx == 48 && dy == 0) || (dx == 0 && dy == 50);
}


// Обмен местами фишек
void Grid::swapTiles(Tile* a, Tile* b) {
    sf::Vector2f tempPos = a->sprite.getPosition();
    a->sprite.setPosition(b->sprite.getPosition());
    b->sprite.setPosition(tempPos);
}