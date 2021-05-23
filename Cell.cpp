#include "Cell.h"

Cell::Cell() {
	isAlive = false;
	setColor(Color::Blue);
}

void Cell::setIsAlive(bool tf) {
	isAlive = tf;
}

bool Cell::getIsAlive() {
	return isAlive;
}

void Cell::draw(RenderWindow& window) {
	window.draw(*(dynamic_cast<Sprite*>(this)));
}