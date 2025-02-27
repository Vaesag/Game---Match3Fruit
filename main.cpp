#include <SFML/Graphics.hpp>
#include "include/ui.h"
#include "include/const.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!", Style::Close);

	Texture bgTexture = loadTexture(PATH_BACKGROUND, sf::IntRect(31, 0, 262, 459)),
		statusTexture = loadTexture(PATH_STATUS),
		progressTexture = loadTexture(PATH_PROGRESS),
		levelBannerTexture = loadTexture(PATH_LEVEL_BANNER),
		settingsTexture = loadTexture(PATH_SETTINGS_BTN),
		keyTexture = loadTexture(PATH_KEY_BTN);

	UI ui(bgTexture, statusTexture, progressTexture, levelBannerTexture, settingsTexture, keyTexture);

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color::White);
		ui.draw(window);	
		window.display();
	}

	return 0;
}