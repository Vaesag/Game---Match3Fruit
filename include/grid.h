#pragma once
#include "Tile.h"
#include <vector>

class Grid {
private:
	static const int COLUMNS = 4; // ���������� ��������
	static const int ROWS = 5; // ���������� �����
    std::vector<std::vector<Tile*>> grid; // ������ �����

public:
    Grid(sf::Texture textures[]); // �����������
    void draw(sf::RenderWindow& window);
};