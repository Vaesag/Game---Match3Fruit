#pragma once
#include <SFML/Graphics.hpp>

class UI {
private:
    sf::Sprite background;
    sf::Sprite statusBar;
    sf::Sprite progress;     
    sf::Sprite levelBanner;
    sf::Sprite settingsBtn;
    sf::Sprite keyBtn;   
public:
    UI(sf::Texture& bgTexture, sf::Texture& StatusTexture, sf::Texture& progressTexture,
        sf::Texture& levelBannerTexture, sf::Texture& settingsTexture,
        sf::Texture& keyTexture);

    void draw(sf::RenderWindow& window);
};