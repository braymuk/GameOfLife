#include <SFML/Graphics.hpp>
#include <iostream>

#define INIT_WORLDSIZE 32


using namespace sf;
using std::cout;
using std::endl;
using std::vector;

class Cell : public RectangleShape{
public:
	Cell();

	void setIsAlive(bool tf);
	bool getIsAlive();

private:
	bool isAlive;
};