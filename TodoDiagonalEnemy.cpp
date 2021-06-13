/*
 * DiagonalEnemy.cpp
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#include "TodoDiagonalEnemy.h"
#include "Arena.h"

TodoDiagonalEnemy::TodoDiagonalEnemy(int hp, int x, int y): Enemy(hp, x, y), upward(true) {}

void TodoDiagonalEnemy::move() {
	if (getState() == ObjectState::DEAD)
			return;
	if (getState() == ObjectState::FROZEN) {
		setState(ObjectState::NORMAL);
		return;
		}

	int x, y;
	getXY(x,y);
	if (y <= 0 && upward == true)
		upward = false;
	if (y >= ARENA_H-1 && upward == false)
		upward = true;

	if (upward == true)
		setXY(x+1, y-1);
	else setXY(x+1, y+1);

}
char TodoDiagonalEnemy::getSymbol() const {return 'D';}
std::string TodoDiagonalEnemy::getName() const {return "Diagonal Enemy";}
