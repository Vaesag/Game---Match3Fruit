#include "include/const.h"
#include "include/Grid.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Match3FRUIT!", Style::Close);

	Texture bgTexture = loadTexture(PATH_BACKGROUND, sf::IntRect(31, 0, 262, 459)),
		statusTexture = loadTexture(PATH_STATUS),
		progressTexture = loadTexture(PATH_PROGRESS),
		levelBannerTexture = loadTexture(PATH_LEVEL_BANNER),
		mascot1Texture = loadTexture(PATH_MASCOT1),
		mascot2Texture = loadTexture(PATH_MASCOT2),
		settingsTexture = loadTexture(PATH_SETTINGS_BTN),
		keyTexture = loadTexture(PATH_KEY_BTN);

	sf::Texture textures[4]; // Массив текстур фишек
		textures[0] = loadTexture(PATH_AVOKADO);
		textures[1] = loadTexture(PATH_KLUBNIKA_SVET);
		textures[2] = loadTexture(PATH_LIMON);
		textures[3] = loadTexture(PATH_KLUBNIKA_TENM);


	
	UI ui(bgTexture, statusTexture, progressTexture, levelBannerTexture, mascot1Texture, mascot2Texture, settingsTexture, keyTexture, window);

	Grid grid(textures, &window, &ui); // Создаём игровое поле

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					grid.handleClick(event.mouseButton.x, event.mouseButton.y);
				}
			}
		}
	

		window.clear(Color::White);

		ui.draw(window);
		
		grid.updateAnimation();
		
		grid.draw(window);
		

		window.display();
	}

	return 0;
}