#include <SFML/Graphics.hpp>
#include "include/ui.h"

using namespace sf;

const int M = 5; // высота игрового поля
const int N = 4; // ширина игрового поля

int main()
{

	// Загрузка текстур
	Texture bgTexture, statusTexture, progressTexture, levelBannerTexture, settingsTexture, keyTexture;
	if (!bgTexture.loadFromFile("resources/background.png", IntRect(31, 0, 262, 459)) ||
		!statusTexture.loadFromFile("resources/status.png") ||
		!progressTexture.loadFromFile("resources/progress.png") ||
		!levelBannerTexture.loadFromFile("resources/level.png") ||
		!settingsTexture.loadFromFile("resources/settings.png") ||
		!keyTexture.loadFromFile("resources/key.png")) {
		return -1;
	}

	bgTexture.setSmooth(true);
	statusTexture.setSmooth(true);
	progressTexture.setSmooth(true);
	levelBannerTexture.setSmooth(true);
	settingsTexture.setSmooth(true);
	keyTexture.setSmooth(true);

	UI ui(bgTexture, statusTexture, progressTexture, levelBannerTexture, settingsTexture, keyTexture);

	int field[M][N] = { 0 }; // игровое поле

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(262, 459), "SFML Works!");

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{

			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}

		window.clear(Color::White);
		ui.draw(window);	
		window.display();
	}

	return 0;
}