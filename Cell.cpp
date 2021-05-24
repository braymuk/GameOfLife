#include "Cell.h"

Cell::Cell() {
	isAlive = false;
	setFillColor(Color::Blue);
	setSize(Vector2f(WORLDSIZE, WORLDSIZE));
}

void Cell::setIsAlive(bool tf) {
	isAlive = tf;
}

bool Cell::getIsAlive() {
	return isAlive;
}
