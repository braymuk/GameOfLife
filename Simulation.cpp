#include "Simulation.h"


Simulation::Simulation() {
	World* tempWorld = new World;
	tempWorld->initWorld();
	world = tempWorld;
}

void Simulation::setWorld(World* newWorld) {
	world = newWorld;
}
World* Simulation::getWorld() {
	return world;
}

void Simulation::runSimulation() {
	RenderWindow window(VideoMode(1024, 1024), "Game of Life", Style::Close | Style::Titlebar);

	while (window.isOpen()) {
		getWorld()->renderWorld(window);

		window.display();

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
				break;
			}

		}
	}
}
