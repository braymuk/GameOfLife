#include "cell.h"

#define WORLDSIZE 16

#define xResolution 1024
#define yResolution 1024

class World {
public:
	World();

	void setWorldPtr(int x, int y, Cell* ptr);
	Cell* getWorldPtr(int x, int y);

	void initWorld();
	void renderWorld(RenderWindow& window);

private:
	Cell* world[WORLDSIZE][WORLDSIZE];
};