#include <SFML/Graphics.hpp>
#include <iostream>


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