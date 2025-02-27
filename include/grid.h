#pragma once
#include "Tile.h"
#include <vector>

class Grid {
private:
	static const int COLUMNS = 4; // ���������� ��������
	static const int ROWS = 5; // ���������� �����
    std::vector<std::vector<Tile*>> grid; // ������ �����


    Tile* selectedTile1 = nullptr;  // ������ ��������� �����
    Tile* selectedTile2 = nullptr;  // ������ ����� ��� ������

public:
    Grid(sf::Texture textures[]); // �����������
    void draw(sf::RenderWindow& window);

    void handleClick(float mouseX, float mouseY); // ���������� ������
    bool areAdjacent(Tile* a, Tile* b); // �������� ���������
    void swapTiles(Tile* a, Tile* b); // ������ �������
};