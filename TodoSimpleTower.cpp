/*
 * LazyTower.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#include "TodoSimpleTower.h"

const int SIMPLE_TOWER_COST = 1;
const int SIMPLE_TOWER_UPGRADE_COST = 1;
const int SIMPLE_TOWER_POWER = 3;

TodoSimpleTower::TodoSimpleTower(int x, int y):
		Tower(SIMPLE_TOWER_COST, SIMPLE_TOWER_UPGRADE_COST, SIMPLE_TOWER_POWER) {setXY(x,y);}

int TodoSimpleTower::getUpgradeCost() const {return SIMPLE_TOWER_UPGRADE_COST;}
bool TodoSimpleTower::isInRange(int x, int y) const {
	int mX, mY;
	getXY(mX,mY);
	if (mY == y)
		if (mX - x == 1 or mX - x == 2)
			return true;
	return false;
}

char TodoSimpleTower::getSymbol() const {return 'S';}
string TodoSimpleTower::getName() const {return "Simple Tower";}

