#include "World.h"


World::World() {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j] = nullptr;
		}
	}
}

void World::setWorldPtr(int x, int y, Cell* ptr) {
	world[x][y] = ptr;
}

Cell* World::getWorldPtr(int x, int y) {
	return world[x][y];
}

//Initializes world as dead
void World::initWorld() {
	
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j] = new Cell;
			world[i][j]->setIsAlive(false);
			world[i][j]->setPosition(float(i * (xResolution/WORLDSIZE)), float(j * (yResolution/WORLDSIZE)));
		}
	}
}

void World::renderWorld(RenderWindow& window) {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			RectangleShape square(Vector2f((xResolution / WORLDSIZE), (yResolution / WORLDSIZE)));
			if (world[i][j]->getIsAlive()) {
				world[i][j]->setFillColor(Color::White);
				std::cout << "isAlive" << std::endl;
			}
			else {
				world[i][j]->setFillColor(Color::Blue);
			}
			window.draw(*(world[i][j]));
		}
	}
}

