/*
 * IceTower.h
 *
 *  Created on: Mar 14, 2019
 *      Author: kevinw
 */

#ifndef TODOICETOWER_H_
#define TODOICETOWER_H_

#include "Tower.h"

class TodoIceTower: public Tower {

public:
	TodoIceTower(int, int);
	~TodoIceTower() = default;

	int getUpgradeCost() const override;
	bool isInRange(int, int) const override;
	void fire(Enemy&) override;
	void upgrade() override;

	char getSymbol() const override;
	string getName() const override;

};

#endif /* TODOICETOWER_H_ */
