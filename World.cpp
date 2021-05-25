#include "World.h"


World::World() {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			world[i][j] = nullptr;
		}
	}
}

World::World(const World& w1) {

	Cell tempArray[WORLDSIZE][WORLDSIZE];
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			tempArray[i][j] = *(w1.world[i][j]);
		}
	}
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			this->setWorldPtr(i, j, &tempArray[i][j]);
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
			world[i][j]->setPosition(float(i * (xResolution / WORLDSIZE)), float(j * (yResolution / WORLDSIZE)));
		}
	}
}

void World::renderWorld(RenderWindow& window) {
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			RectangleShape square(Vector2f((xResolution / WORLDSIZE), (yResolution / WORLDSIZE)));
			if (world[i][j]->getIsAlive()) {
				world[i][j]->setFillColor(Color::White);
			}
			else {
				world[i][j]->setFillColor(Color::Black);
			}
			window.draw(*(world[i][j]));
		}
	}
}

int World::countNeighbors(int x, int y) {
	int neighborCellCount = 0;
	
	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			if ((abs(x - i) <= 1 && abs(y - j) <= 1) && (getWorldPtr(i, j)->getIsAlive() == true)) {
			
					if (x != i || y != j) {
						neighborCellCount++;
					}
				
			}
		}
	}
	return neighborCellCount;
}


void World::updateWorld() {
	World initialWorld = *(this);

	/*for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			initialWorld.setWorldPtr(i, j, world[i][j]);
			
		}
	}
	initialWorld = */
	

	for (int i = 0; i < WORLDSIZE; i++) {
		for (int j = 0; j < WORLDSIZE; j++) {
			//Check neighbors
		
			int neighborCellCount = initialWorld.countNeighbors(i, j);

			if (initialWorld.getWorldPtr(i,j)->getIsAlive()) {
				if (neighborCellCount < 2) {
					world[i][j]->setIsAlive(false);
				}
				if (neighborCellCount > 3) {
					world[i][j]->setIsAlive(false);
				}
			}
			else if (neighborCellCount == 3) {
				world[i][j]->setIsAlive(true);
			}

		}
	}
}

