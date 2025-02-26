#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 5; // высота игрового поля
const int N = 4; // ширина игрового поля

int main()
{

	int field[M][N] = { 0 }; // игровое поле

	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(500, 300), "SFML Works!");

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

		window.clear(Color(250, 220, 100, 0));
		// Создаем круг радиусом 50
		// Создаем переменную текстуры
		Texture texture;

		// Подгружаем нашу текстуру из файла texture.png
		texture.loadFromFile("C:\\project\\SFML test1\\x64\\Debug\\avokado.png");
		texture.setSmooth(true);
		// Создаем спрайт и устанавливаем ему нашу текстуру
		Sprite sprite(texture);

		// Отрисовка спрайта	 
		window.draw(sprite);

		// Отрисовка окна	
		window.display();
	}

	return 0;
}