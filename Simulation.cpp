#include "Simulation.h"


//Simulation::Simulation() {
//	//World* tempWorld = new World;
//	//tempWorld->initWorld();
//	//world = tempWorld;
//}
//
//void Simulation::setWorld(World* newWorld) {
//	world = newWorld;
//}
//World* Simulation::getWorld() {
//	return world;
//}

void Simulation::runSimulation() {
	RenderWindow window(VideoMode(1024, 1024), "Game of Life", Style::Close | Style::Titlebar);

	World world;
	world.initWorld();

	while (window.isOpen()) {
		window.clear(Color::White);
		world.renderWorld(window);

		window.display();


		int xClick, yClick = 0;
		Event evnt;
		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::TextEntered:
				std::cout << evnt.text.unicode << std::endl;
				break;
			case Event::MouseButtonPressed:
				if ((evnt.mouseButton.x >= 0 && evnt.mouseButton.x <= 1024) && (evnt.mouseButton.y >= 0 && evnt.mouseButton.y <= 1024)) {
					xClick = evnt.mouseButton.x / 64;
					yClick = evnt.mouseButton.y / 64;

					world.getWorldPtr(xClick, yClick)->setIsAlive(true);
				}

				break;
			}

		}
	}
}
