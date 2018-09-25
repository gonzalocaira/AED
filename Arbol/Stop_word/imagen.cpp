#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	// Crea una ventana de 640x480x32 con el título SFML window
	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "SFML window");

	// Activa la sincronización vertical (60 fps)
	window.setVerticalSyncEnabled(true);

	// Creamos una textura
	sf::Texture textura;

	// Cargamos la textura desde un archivo
	if(!textura.loadFromFile("menu.png"))
	{
		// Si hay un error salimos
		return EXIT_FAILURE;
	}

	// Creamos un sprite
	sf::Sprite sprite;
	// Asignamos la textura al sprite
	sprite.setTexture(textura);
	// Seleccionamos solo un rectangulo de la textura
	


	// Creamos otro sprite con la MISMA textura
	sf::Sprite otro(textura);
	otro.setPosition(200, 150);
	otro.setTextureRect(sf::IntRect(128, 128, 64, 64));

	// Game Loop mientras la ventana esté abierta
	while (window.isOpen())
	{
		// Creamos un objeto evento
		sf::Event event;
		// Procesamos la pila de eventos
		while (window.pollEvent(event))
		{
			// Si el evento es de tipo Closed cerramos la ventana
			if (event.type == sf::Event::Closed)
			window.close();
		}

		// Limpiamos la pantalla
		window.clear(sf::Color(180, 200, 255));

		// Dibujamos en pantalla
		window.draw(sprite);
		window.draw(otro);

		// Actualizamos la ventana
		window.display();
	}

	return 0;
}
