#include "World.h"
#include <iostream>

class Simulation {
public:
	//Handles world initlization
	Simulation();

	void setWorld(World* world);
	World* getWorld();

	void runSimulation();

private:
	World* world;
};