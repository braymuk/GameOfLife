#include "cell.h"



#define xResolution 1024
#define yResolution 1024

class World {
public:
	World();

	World(const World &w1);

	void setWorldPtr(int x, int y, Cell* ptr);
	Cell* getWorldPtr(int x, int y);

	void initWorld();
	void renderWorld(RenderWindow& window);

	int countNeighbors(int x, int y);
	void updateWorld();
	

private:
	Cell* world[WORLDSIZE][WORLDSIZE];
};