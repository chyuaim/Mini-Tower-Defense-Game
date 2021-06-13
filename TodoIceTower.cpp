/*
 * IceTower.cpp
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#include "TodoIceTower.h"
#include "Enemy.h"

const int TODO_ICE_TOWER_COST = 3;
const int TODO_ICE_TOWER_UPGRADE_COST = 0;
const int TODO_ICE_TOWER_POWER = 0;

TodoIceTower::TodoIceTower(int x, int y):
		Tower(TODO_ICE_TOWER_COST, TODO_ICE_TOWER_UPGRADE_COST, TODO_ICE_TOWER_POWER) {setXY(x,y);}

int TodoIceTower::getUpgradeCost() const {return TODO_ICE_TOWER_UPGRADE_COST;}
bool TodoIceTower::isInRange(int x, int y) const {
	int mX, mY;
	getXY(mX,mY);
	if (x >= mX)
		return true;
	return false;
}
void TodoIceTower::fire(Enemy& enemy) {
	int x, y;
	enemy.getXY(x, y);
	if (isInRange(x, y))
		if (enemy.getState() != ObjectState::DEAD)
			enemy.setState(ObjectState::FROZEN);
}
void TodoIceTower::upgrade() {}

char TodoIceTower::getSymbol() const {return 'I';}
string TodoIceTower::getName() const {return "Ice Tower";}
