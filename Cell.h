#include <SFML/Graphics.hpp>
#include <iostream>

#define WORLDSIZE 16
#define xResolution 1024
#define yResolution 1024


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