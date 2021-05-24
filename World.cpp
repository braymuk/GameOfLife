#include "World.h"


World::World() {
	worldSize = INIT_WORLDSIZE;
	for (int i = 0; i < INIT_WORLDSIZE; ++i) {
		world[i].resize(worldSize);
	}
	
}

void World::setWorldCell(int x, int y, Cell ptr) {
	world[x][y] = ptr;

}

Cell World::getWorldCell(int x, int y) {

	return world[x][y];
}

void World::setWorldSize(int val) {
	worldSize = val;
}

int World::getWorldSize() {
	return worldSize;
}

//Initializes world as dead
void World::initWorld() {
	Cell emptyCell;
	emptyCell.setIsAlive(false);

	for (int i = 0; i < worldSize; i++) {
		for (int j = 0; j < worldSize; j++) {
			emptyCell.setPosition(float(i * (xResolution / worldSize)), float(j * (yResolution / worldSize)));
			//world.push_back(emptyCell);
			world[i].push_back(emptyCell);
		}
	}
}

void World::renderWorld(RenderWindow& window) {
	for (int i = 0; i < worldSize; i++) {
		for (int j = 0; j < worldSize; j++) {
			RectangleShape square(Vector2f((xResolution / worldSize), (yResolution / worldSize)));
			if (world[i][j].getIsAlive()) {
				world[i][j].setFillColor(Color::White);
			}
			else {
				world[i][j].setFillColor(Color::Blue);
			}
			window.draw(world[i][j]);
		}
	}
}

int World::countNeighbors(int x, int y) {
	int count = 0;
	
	for (int i = 0; i < worldSize; i++) {
		for (int j = 0; j < worldSize; j++) {
			//My Version
			if ((abs(x - i) <= 1 && abs(y - j) <= 1) && (world[i][j].getIsAlive() == true)) {
			
					if (x != i || y != j) {
						count++;
					}
				
			}

			

		}
	}
	return count;
}


void World::updateWorld() {
	World initialWorld;

	for (int i = 0; i < worldSize; i++) {
		for (int j = 0; j < worldSize; j++) {
			initialWorld.setWorldCell(i, j, world[i][j]);
			initialWorld[i].push_back(world[i][j]);
			initialWorld[i].push_back(getWorldCell(i,j));
		}
	}
	int neighborCellCount = 0;
	for (int i = 0; i < worldSize; i++) {
		for (int j = 0; j < worldSize; j++) {
			//Check neighbors
		
			neighborCellCount = initialWorld.countNeighbors(i, j);

			if (neighborCellCount < 2) {
				world[i][j].setIsAlive(false);
			}
			else if (neighborCellCount == 3) {
				world[i][j].setIsAlive(true);
			}
			else if (neighborCellCount > 3) {
				world[i][j].setIsAlive(false);
			}

			/*if (initialWorld.getWorldPtr(i,j)->getIsAlive()) {
				if (neighborCellCount < 2) {
					world[i][j]->setIsAlive(false);
				}
				if (neighborCellCount > 3) {
					world[i][j]->setIsAlive(false);
				}
				if (neighborCellCount == 2 || neighborCellCount == 3) {
					world[i][j]->setIsAlive(true);
				}
			}
			if (!initialWorld.getWorldPtr(i, j)->getIsAlive()) {
				if (neighborCellCount == 3) {
					world[i][j]->setIsAlive(true);
				}
			}*/
		}
	}
}

