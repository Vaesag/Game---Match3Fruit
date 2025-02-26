#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Tile {
public:
	int type;		// Тип фрукта
	Sprite sprite;

	Tile(int type, sf::Texture& texture, float x, float y);
};