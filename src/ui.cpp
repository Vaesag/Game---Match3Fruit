#include "../include/ui.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture loadTexture(const std::string& path, sf::IntRect rect, bool smooth) {
    sf::Texture texture;
    if (!texture.loadFromFile(path, rect)) {
        std::cerr << "Ошибка загрузки текстуры: " << path << std::endl;
    }
    if (smooth) {
        texture.setSmooth(true);
    }
    return texture;
}

UI::UI(sf::Texture& bgTexture, sf::Texture& StatusTexture, sf::Texture& progressTexture,
    sf::Texture& levelBannerTexture, sf::Texture& settingsTexture,
    sf::Texture& keyTexture, sf::RenderWindow& window) {

    // Фон
    background.setTexture(bgTexture);
    background.setPosition(0, 0);

    // Жизни
    statusBar.setTexture(StatusTexture);
    statusBar.setPosition(30, 10);


    // Прогресс
    progress.setTexture(progressTexture);
    progress.setPosition(47, 41);

    // Баннер "Level"
    levelBanner.setTexture(levelBannerTexture);
    levelBanner.setPosition(74.6, 90);
    levelBanner.scale(0.8, 0.8);

    // Кнопка настроек
    settingsBtn.setTexture(settingsTexture);
    settingsBtn.setPosition(10, 423.5);
    settingsBtn.scale(0.5, 0.5);

    // Кнопка ключа
    keyBtn.setTexture(keyTexture);
    keyBtn.setPosition(225, 423.5);
    keyBtn.scale(0.5, 0.5);
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(statusBar);
    window.draw(progress);
    window.draw(levelBanner);
    window.draw(settingsBtn);
    window.draw(keyBtn);
}