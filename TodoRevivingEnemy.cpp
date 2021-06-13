/*
 * RevivingEnemy.cpp
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#include "TodoRevivingEnemy.h"

TodoRevivingEnemy::TodoRevivingEnemy(int hp, int x, int y): Enemy(hp, x, y), revived(false) {}

void TodoRevivingEnemy::fired(int power) {
	hp -= power;
	if (hp <= 0) {
		if (revived == false) {
			revived = true;
			hp = 1;
		}
		else setState(ObjectState::DEAD);
	}
}
char TodoRevivingEnemy::getSymbol() const {return 'R';}
std::string TodoRevivingEnemy::getName() const {return "Reviving Enemy";}
