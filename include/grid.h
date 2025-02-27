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
    Grid(sf::Texture textures[], sf::RenderWindow* window); // �����������
    void draw(sf::RenderWindow& window);

    void handleClick(float mouseX, float mouseY); // ���������� ������
    bool areAdjacent(Tile* a, Tile* b); // �������� ���������
   void swapTiles(Tile* tile1, Tile* tile2); // ������ �������

   void removeMatches();  // ������� ��������� �����
   void dropTiles();      // �������� ����� ����
    void processMatchesAtStart(); // ��������� ���������� ����� ���������
    bool checkMatches(); // �������� ���������� (3+ ���������� �����)

};