#include "Cell.h"

Cell::Cell() {
	setIsAlive(false);
	setFillColor(Color::Blue);
	setSize(Vector2f(INIT_WORLDSIZE, INIT_WORLDSIZE));
}

void Cell::setIsAlive(bool tf) {
	isAlive = tf;
}

bool Cell::getIsAlive() {
	return isAlive;
}
