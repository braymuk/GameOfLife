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
	Cell* tempCell = new Cell;
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j] = tempCell;
			world[i][j]->setIsAlive(false);
			world[i][j]->setPosition(float(i * 64), float(j * 64));
		}
	}
}

void World::renderWorld(RenderWindow& window) {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			RectangleShape square(Vector2f(64, 64));
			if (world[i][j]->getIsAlive()) {
				world[i][j]->setFillColor(Color::White);
				std::cout << "isAlive" << std::endl;
			}
			else {
				world[i][j]->setFillColor(Color::Blue);
			}
			//world[i][j]->draw(window);
			window.draw(*(world[i][j]));
		}
	}
}

