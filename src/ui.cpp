#include "../include/ui.h"

UI::UI(sf::Texture& bgTexture, sf::Texture& StatusTexture, sf::Texture& progressTexture,
    sf::Texture& levelBannerTexture, sf::Texture& settingsTexture,
    sf::Texture& keyTexture) {

    // ���
    background.setTexture(bgTexture);
    background.setPosition(0, 0);

    // �����
    statusBar.setTexture(StatusTexture);
    statusBar.setPosition(30, 10);

    // ��������
    progress.setTexture(progressTexture);
    progress.setPosition(47, 41);

    // ������ "Level"
    levelBanner.setTexture(levelBannerTexture);
    levelBanner.setPosition(74.6, 90);
    levelBanner.scale(0.8, 0.8);

    // ������ ��������
    settingsBtn.setTexture(settingsTexture);
    settingsBtn.setPosition(50, 550);

    // ������ �����
    keyBtn.setTexture(keyTexture);
    keyBtn.setPosition(500, 550);
}

void UI::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(statusBar);
    window.draw(progress);
    window.draw(levelBanner);
    window.draw(settingsBtn);
    window.draw(keyBtn);
}