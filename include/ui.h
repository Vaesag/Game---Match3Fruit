#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class UI {
private:
    sf::Sprite background;
    sf::Sprite statusBar;
    sf::Sprite progress;     
    sf::Sprite levelBanner;
	sf::Sprite mascot1;
	sf::Sprite mascot2;
    sf::Sprite settingsBtn;
    sf::Sprite keyBtn;   

public:
    UI(sf::Texture& bgTexture, sf::Texture& StatusTexture, sf::Texture& progressTexture,
        sf::Texture& levelBannerTexture, sf::Texture& mascot1Texture, sf::Texture& mascot2Texture, sf::Texture& settingsTexture,
        sf::Texture& keyTexture, sf::RenderWindow& window);

    void draw(sf::RenderWindow& window);
};

sf::Texture loadTexture(const std::string& path, sf::IntRect rect = sf::IntRect(), bool smooth = true);