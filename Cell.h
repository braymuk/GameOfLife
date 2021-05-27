#include <SFML/Graphics.hpp>
#include <iostream>

#define WORLDSIZE 4 //current max worldsize is somewhere in the 55-59 range
#define xResolution 400
#define yResolution 400


using namespace sf;
using std::cout;
using std::endl;

class Cell : public RectangleShape{
public:
	Cell();

	void setIsAlive(bool tf);
	bool getIsAlive();

private:
	bool isAlive;
};