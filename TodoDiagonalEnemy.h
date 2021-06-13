/*
 * DiagonalEnemy.h
 *
 *  Created on: Mar 13, 2019
 *      Author: kevinw
 */

#ifndef TODODIAGONALENEMY_H_
#define TODODIAGONALENEMY_H_

#include "Enemy.h"

class TodoDiagonalEnemy: public Enemy {

public:
	TodoDiagonalEnemy(int, int, int);
	~TodoDiagonalEnemy() = default;

	void move() override;
	char getSymbol() const;
	std::string getName() const;

private:
	bool upward;
};

#endif /* TODODIAGONALENEMY_H_ */
