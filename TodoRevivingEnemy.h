/*
 * RevivingEnemy.h
 *
 *  Created on: Mar 15, 2019
 *      Author: kevinw
 */

#ifndef TODOREVIVINGENEMY_H_
#define TODOREVIVINGENEMY_H_

#include "Enemy.h"

class TodoRevivingEnemy: public Enemy {

private:
	bool revived;

public:
	TodoRevivingEnemy(int, int, int);
	~TodoRevivingEnemy() = default;

	void fired(int) override;
	char getSymbol() const;
	std::string getName() const;

};

#endif /* TODOREVIVINGENEMY_H_ */
