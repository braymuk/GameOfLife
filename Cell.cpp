#include "Cell.h"

Cell::Cell() {
	isAlive = false;
	setFillColor(Color::Blue);
	setSize(Vector2f(64, 64));
}

void Cell::setIsAlive(bool tf) {
	isAlive = tf;
}

bool Cell::getIsAlive() {
	return isAlive;
}

void Cell::draw(RenderWindow& window) {
	//window.draw(*(dynamic_cast<RectangleShape*>(this)));
	window.draw(*(this));
}