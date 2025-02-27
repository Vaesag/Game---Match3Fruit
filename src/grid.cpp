#include "../include/Grid.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Grid::Grid(sf::Texture textures[], sf::RenderWindow* window) {
    this->textures = textures;
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Рандомизация

    grid.resize(ROWS, std::vector<Tile*>(COLUMNS));

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            int randomType = std::rand() % 4; // 3 вида фишек
            grid[i][j] = new Tile(randomType, textures[randomType], j, i);
        }
    }
    processMatchesAtStart(); // Проверяем совпадения после генерации
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
    int dx = std::abs(a->x - b->x);
    int dy = std::abs(a->y - b->y);
    return (dx == 1 && dy == 0) || (dx == 0 && dy == 1);
}



bool Grid::checkMatches() {
    bool foundMatch = false;

    // Перед проверкой сбрасываем все выделения (чтобы не висели)
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            grid[i][j]->sprite.setColor(sf::Color::White);
        }
    }

    // Создаём массив для отметки совпадений
    std::vector<std::vector<bool>> toRemove(ROWS, std::vector<bool>(COLUMNS, false));

    // 2️⃣ Горизонтальная проверка
    for (int i = 0; i < ROWS; ++i) {
        int count = 1;
        for (int j = 1; j < COLUMNS; ++j) {
            if (grid[i][j]->type == grid[i][j - 1]->type) {
                count++;
            }
            else {
                count = 1;
            }

            if (count >= 3) {
                for (int k = 0; k < count; ++k) {
                    toRemove[i][j - k] = true;
                }
                foundMatch = true;
            }
        }
    }

    // Вертикальная проверка
    for (int j = 0; j < COLUMNS; ++j) {
        int count = 1;
        for (int i = 1; i < ROWS; ++i) {
            if (grid[i][j]->type == grid[i - 1][j]->type) {
                count++;
            }
            else {
                count = 1;
            }

            if (count >= 3) {
                for (int k = 0; k < count; ++k) {
                    toRemove[i - k][j] = true;
                }
                foundMatch = true;
            }
        }
    }

    // Красим только совпавшие фишки
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (toRemove[i][j]) {
                grid[i][j]->sprite.setColor(sf::Color::Red);
            }
        }
    }

    return foundMatch;
}

void Grid::removeMatches() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (grid[i][j] == nullptr) continue; // Пропускаем пустые ячейки

            if (grid[i][j]->sprite.getColor() == sf::Color::Red) { // Если фишка выделена как совпавшая
                
                delete grid[i][j];  // Удаляем объект
                grid[i][j] = nullptr;  // Обнуляем ячейку
            }
        }
    }

    dropTiles();  // Опускаем оставшиеся фишки вниз
}


void Grid::dropTiles() {
    std::cout << "DROP TILES\n";
    for (int j = 0; j < COLUMNS; ++j) {
        int emptyRow = ROWS - 1;  // Начинаем с нижней строки

        for (int i = ROWS - 1; i >= 0; --i) {
            if (grid[i][j] != nullptr) {  // Если фишка есть
                if (i != emptyRow) {  // Если под ней пусто, двигаем вниз
                    grid[emptyRow][j] = grid[i][j];
                    grid[emptyRow][j]->y = emptyRow;  // Обновляем координаты
                    grid[emptyRow][j]->sprite.setPosition(j * 48 + 40, emptyRow * 50 + 140);
                    
                    grid[i][j] = nullptr;
                }
                emptyRow--;  // Поднимаем пустую строку вверх
            }
        }

        // Заполняем верхние пустые ячейки новыми фишками
        for (int i = emptyRow; i >= 0; --i) {
            int randomType = std::rand() % 3;
            grid[i][j] = new Tile(randomType, textures[randomType], j, i);
            
            grid[i][j]->sprite.setPosition(j * 48 + 40, i * 50 + 140);
            std::cout << "NEW TILES[" << j << "][" << i << "] (Type: " << randomType << ")\n";
        }
    }
    processMatchesAtStart();

}

void Grid::swapTiles(Tile * tile1, Tile * tile2) {
        // Меняем местами в `grid`
        std::swap(grid[tile1->y][tile1->x], grid[tile2->y][tile2->x]);

        // Меняем координаты `x, y` в самих фишках!
        std::swap(tile1->x, tile2->x);
        std::swap(tile1->y, tile2->y);

        // Обновляем позиции спрайтов
        tile1->sprite.setPosition(tile1->x * 48 + 40, tile1->y * 50 + 140);
        tile2->sprite.setPosition(tile2->x * 48 + 40, tile2->y * 50 + 140);

        if (checkMatches()) {
            removeMatches();  // Если есть совпадения, удаляем фишки
        }
        else {
            // Если совпадений нет, возвращаем фишки обратно
            std::swap(grid[tile1->y][tile1->x], grid[tile2->y][tile2->x]);
            std::swap(tile1->x, tile2->x);
            std::swap(tile1->y, tile2->y);

            tile1->sprite.setPosition(tile1->x * 48 + 40, tile1->y * 50 + 140);
            tile2->sprite.setPosition(tile2->x * 48 + 40, tile2->y * 50 + 140);
        }
}

void Grid::processMatchesAtStart() {
    bool foundMatch;

    do {
        foundMatch = checkMatches(); // Проверяем, есть ли совпадения
        if (foundMatch) {
            removeMatches(); // Если есть, удаляем фишки и заполняем пустые места
        }
    } while (foundMatch); // Повторяем, пока на поле остаются совпадения
}

