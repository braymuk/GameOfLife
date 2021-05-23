#include <SFML/Graphics.hpp>

using namespace sf;

class Cell : public Sprite{
public:
	Cell();

	void setIsAlive(bool tf);
	bool getIsAlive();

	void draw(RenderWindow& window);

private:
	bool isAlive;
};