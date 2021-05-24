#include "cell.h"



#define xResolution 1024
#define yResolution 1024

class World {
public:
	World();

	void setWorldCell(int x, int y, Cell ptr);
	Cell getWorldCell(int  x, int  y);

	void setWorldSize(int val);
	int getWorldSize();

	void initWorld();
	void renderWorld(RenderWindow& window);

	int countNeighbors(int x, int y);
	void updateWorld();
	

private:
	vector<vector<Cell>> world;
	int worldSize;
};