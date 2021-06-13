/*
 * Catapult.h
 *
 *  Created on: Mar 12, 2019
 *      Author: kevinw
 */

#ifndef TODOCATAPULT_H_
#define TODOCATAPULT_H_

#include "Tower.h"

class TodoCatapult: public Tower {

public:
	TodoCatapult(int, int);
	~TodoCatapult() = default;

	int getUpgradeCost() const override;
	bool isInRange(int, int) const override;

	char getSymbol() const override;
	string getName() const override;
};

#endif /* TODOCATAPULT_H_ */
