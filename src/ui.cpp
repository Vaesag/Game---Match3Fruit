#include "../include/ui.h"

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
    sf::Texture& levelBannerTexture, sf::Texture& mascot1Texture, sf::Texture& mascot2Texture, sf::Texture& settingsTexture,
    sf::Texture& keyTexture, sf::RenderWindow& window) {

    // Фон
    background.setTexture(bgTexture);
    background.setPosition(0, 0);

    // Жизни
    statusBar.setTexture(StatusTexture);
    statusBar.setOrigin(StatusTexture.getSize().x / 2, StatusTexture.getSize().y / 2); // Устанавливаем точку привязки в центр спрайта
    statusBar.setPosition(window.getSize().x / 2, 20); 

    // Прогресс
    progress.setTexture(progressTexture);
    progress.setOrigin(progressTexture.getSize().x / 2, progressTexture.getSize().y / 2);
    progress.setPosition(window.getSize().x / 2, 60);

    // Баннер "Level"
    levelBanner.setTexture(levelBannerTexture);
    levelBanner.scale(0.8, 0.8);
	levelBanner.setOrigin(levelBannerTexture.getSize().x / 2, levelBannerTexture.getSize().y / 2);
	levelBanner.setPosition(window.getSize().x / 2, 110);

	// Маскоты
	mascot1.setTexture(mascot1Texture);
    mascot1.scale(0.7, 0.7);
	mascot1.setOrigin(mascot1Texture.getSize().x / 2, mascot1Texture.getSize().y / 2);
	mascot1.setPosition(window.getSize().x / 2 - 60, 120);

	mascot2.setTexture(mascot2Texture);
	mascot2.scale(0.7, 0.7);
	mascot2.setOrigin(mascot2Texture.getSize().x / 2, mascot2Texture.getSize().y / 2);
	mascot2.setPosition(window.getSize().x / 2 + 80, 130);

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
	window.draw(mascot1);
	window.draw(mascot2);
    window.draw(settingsBtn);
    window.draw(keyBtn);
}