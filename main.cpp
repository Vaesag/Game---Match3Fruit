#include <SFML/Graphics.hpp>

using namespace sf;

const int M = 5; // ������ �������� ����
const int N = 4; // ������ �������� ����

int main()
{

	int field[M][N] = { 0 }; // ������� ����

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(500, 300), "SFML Works!");

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

		window.clear(Color(250, 220, 100, 0));
		// ������� ���� �������� 50
		// ������� ���������� ��������
		Texture texture;

		// ���������� ���� �������� �� ����� texture.png
		texture.loadFromFile("C:\\project\\SFML test1\\x64\\Debug\\avokado.png");
		texture.setSmooth(true);
		// ������� ������ � ������������� ��� ���� ��������
		Sprite sprite(texture);

		// ��������� �������	 
		window.draw(sprite);

		// ��������� ����	
		window.display();
	}

	return 0;
}