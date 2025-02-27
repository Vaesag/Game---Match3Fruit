#include "../include/Tile.h"

Tile::Tile(int type, sf::Texture& texture, float x, float y) {
    this->type = type;
    sprite.setTexture(texture);
	sprite.scale(0.5, 0.5);
    sprite.setPosition(x, y);
}
