#include "../include/Tile.h"

Tile::Tile(int type, sf::Texture& texture, float x, float y) {
    this->type = type;
	this->x = x;
	this->y = y;

    sprite.setTexture(texture);
	sprite.scale(0.5, 0.5);
	sprite.setPosition(x * 48 + 40, y * 50 + 140);
}
