/*
 * LazyTower.h
 *
 *  Created on: Mar 11, 2019
 *      Author: kevinw
 */

#ifndef TODOSIMPLETOWER_H_
#define TODOSIMPLETOWER_H_

#include "Tower.h"

class TodoSimpleTower: public Tower {

public:
	TodoSimpleTower(int, int);
	~TodoSimpleTower() = default;

	int getUpgradeCost() const override;
	bool isInRange(int, int) const override;

	char getSymbol() const override;
	string getName() const override;

};

#endif /* TODOSIMPLETOWER_H_ */
