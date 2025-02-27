#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile {
public:
	int type;
	Sprite sprite;
	int x, y;

	Tile(int type, sf::Texture& texture, float x, float y);
};