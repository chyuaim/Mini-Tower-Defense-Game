/*
 * Laser.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoLaserTower.h"

const int LASER_COST = 3;
const int LASER_UPGRADE_COST = 2;
const int LASER_POWER = 10;

TodoLaserTower::TodoLaserTower(int x, int y):
		Tower(LASER_COST, LASER_UPGRADE_COST, LASER_POWER) {setXY(x,y);}

int TodoLaserTower::getUpgradeCost() const {return LASER_UPGRADE_COST;}
bool TodoLaserTower::isInRange(int x, int y) const {
	int mX, mY;
	getXY(mX,mY);
	if (mX == x || mY == y)
		return true;
	return false;
}

char TodoLaserTower::getSymbol() const {return 'L';}
string TodoLaserTower::getName() const {return "Laser";}
