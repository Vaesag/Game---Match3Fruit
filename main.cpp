#include <SFML/Graphics.hpp>
#include "include/ui.h"

using namespace sf;

const int M = 5; // ������ �������� ����
const int N = 4; // ������ �������� ����

int main()
{

	// �������� �������
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

	int field[M][N] = { 0 }; // ������� ����

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(262, 459), "SFML Works!");

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{

			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		window.clear(Color::White);
		ui.draw(window);	
		window.display();
	}

	return 0;
}