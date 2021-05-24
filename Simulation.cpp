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
	RenderWindow window(VideoMode(xResolution, yResolution), "Game of Life", Style::Close | Style::Titlebar);

	World world;
	world.initWorld();

	Clock clock;
	int i = 1;

	bool isPaused = false;
	
	while (window.isOpen()) {
		float Time = clock.getElapsedTime().asSeconds();
		window.clear(Color::White);
		
		world.renderWorld(window);
		
		if (Time > i) {
			i = i + simulationRate;
			if (!isPaused) {
				world.updateWorld();
			}
			
		}
	

		

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
				if ((evnt.mouseButton.x >= 0 && evnt.mouseButton.x <= xResolution) && (evnt.mouseButton.y >= 0 && evnt.mouseButton.y <= yResolution)) {
					xClick = evnt.mouseButton.x / WORLDSIZE;
					yClick = evnt.mouseButton.y / WORLDSIZE;
					//cout << xClick << endl;
					//cout << yClick << endl;
					cout << world.countNeighbors(xClick, yClick) << endl;

					world.getWorldPtr(xClick, yClick)->setIsAlive(!world.getWorldPtr(xClick,yClick)->getIsAlive());
				}
				break;
			case Event::KeyPressed:
				if (evnt.key.code == Keyboard::Space) {
					isPaused = !isPaused;
				}
			}

		}
	}
}
