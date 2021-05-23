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
	tempCell->setIsAlive(false);
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j] = tempCell;
		}
	}
}

void World::renderWorld(RenderWindow& window) {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j]->draw(window);
		}
	}
}

