/*
 * Laser.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOLASERTOWER_H_
#define TODOLASERTOWER_H_

#include "Tower.h"

class TodoLaserTower: public Tower {

public:
	TodoLaserTower(int, int);
	~TodoLaserTower() = default;

	int getUpgradeCost() const override;
	bool isInRange(int, int) const override;

	char getSymbol() const override;
	string getName() const override;

};

#endif /* TODOLASERTOWER_H_ */
