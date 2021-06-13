/*
 * Catapult.cpp
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#include "TodoCatapult.h"

const int TODO_CATAPULT_COST = 2;
const int TODO_CATAPULT_UPGRADE_COST = 2;
const int TODO_CATAPULT_POWER = 5;
const int TODO_CATAPULT_RANGE = 5;

TodoCatapult::TodoCatapult(int x, int y):
		Tower(TODO_CATAPULT_COST, TODO_CATAPULT_UPGRADE_COST, TODO_CATAPULT_POWER) {setXY(x,y);}

int TodoCatapult::getUpgradeCost() const {return TODO_CATAPULT_UPGRADE_COST;}
bool TodoCatapult::isInRange(int x, int y) const {
	int mX, mY;
	getXY(mX,mY);
	int x_difference = (mX>x)?(mX-x):(x-mX);
	int y_difference = (mY>y)?(mY-y):(y-mY);
	if (x_difference + y_difference == TODO_CATAPULT_RANGE)
		return true;
	return false;
}

char TodoCatapult::getSymbol() const {return 'C';}
string TodoCatapult::getName() const {return "Catapult";}
