#include "Cell.h"

Cell::Cell() {
	isAlive = false;
	setFillColor(Color::Black);
	setSize(Vector2f(xResolution/WORLDSIZE, yResolution/ WORLDSIZE));
}

void Cell::setIsAlive(bool tf) {
	isAlive = tf;
}

bool Cell::getIsAlive() {
	return isAlive;
}
