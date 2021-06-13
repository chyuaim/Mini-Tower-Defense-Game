/*
 * Arena.cpp
 *
 *  Created on: Feb 25, 2016
 *      Author: kevinw
 */

#include "Arena.h"

#include "Enemy.h"
#include "TodoCatapult.h"
#include "TodoDiagonalEnemy.h"
#include "TodoIceTower.h"
#include "TodoLaserTower.h"
#include "TodoRevivingEnemy.h"
#include "TodoSimpleTower.h"

const int ARENA_W = 45;
const int ARENA_H = 5;
const int TOWER_X = 35;
const int ENEMY_X = 0;

Arena::~Arena() {
//TODO
	for (int i=0; i<num_objects; ++i)
		delete objects[i];
	delete [] objects;
}

//Perform shadow copying and add this object to the array objects.
//The ownership of this object is transfered to Arena.
void Arena::addObject(Object* newobj) {
//TODO
	if (objects == nullptr)
		objects = new Object*[ARENA_W*ARENA_H];
	objects[num_objects] = newobj;
	num_objects += 1;
}

//To return a dynamic const Object array. You might treat the memory
//pointed by obj is garbage.
void Arena::getConstObjects(const Object**& obj, int& count) const {
//TODO
	count = num_objects;
	if (objects != nullptr) {
		obj = new const Object*[count];
		for (int i=0; i<count; ++i)
			obj[i] = objects[i];
	}
	else obj = nullptr;
}

//Return the object in the array objects with the coordinate aX and aY.
//If there are more than one object is in this coordinate, return any
//one of them. If there are no object is in this coordinate, return nullptr 
Object* Arena::getObjectAt(int aX, int aY) const {
//TODO
	int x, y;
	for (int i=0; i<num_objects; ++i) {
		objects[i]->getXY(x,y);
		if (x==aX && y==aY)
			return objects[i];
	}
	return nullptr;
}

//Return true if the game is over, false otherwise.
//The game is over when any not DEAD enemy reaches the end-zone - i.e., its
//x-coordinate >= the constant TOWER_X.
bool Arena::isGameOver() const {
//TODO
	int x;
	int y;
	for (int i=0; i<num_objects; ++i) {
		objects[i]->getXY(x,y);
		if (objects[i]->getObjectType() == ObjectType::ENEMY)
			if (objects[i]->getState() != ObjectState::DEAD && x>=TOWER_X)
				return true;
	}
	return false;
}


//Remove the object pointed by the pointer r from the array objects if it is 
//in the list. Do nothing if r is a nullptr or r is not in the array.
void Arena::removeObject(Object* r) {
//TODO
	if (r == nullptr)
		return;
	for (int i=0; i<num_objects; ++i)
		if (r == objects[i]) {
			delete objects[i];
			for (int j=i; j<num_objects-1; ++j)
				objects[j] = objects[j+1];
			objects[num_objects] = nullptr;
			num_objects -= 1;
			return;
		}
}


//Depends on the value of the variable building, construct a tower at the coordinate x, y when money is larger than the building cost.
// if building is SIMPLE_TOWER - construct a TodoSimpleTower
// if building is CATAPUL_TOWER - construct a TodoCatapult
// if building is LASER_TOWER - construct a TodoLaserTower
// if building is ICE_TOWER - construct a TodoIceTower
// otherwise - do nothing.
// After building the tower, deduct the money by the building cost of the tower
void Arena::addBuilding(int building, int x, int y) {
//TODO
	Tower* t;
	switch (building) {
	case 0: t = new TodoSimpleTower(x,y); break;
	case 1: t = new TodoCatapult(x,y); break;
	case 2: t = new TodoLaserTower(x,y); break;
	case 3: t = new TodoIceTower(x,y); break;
	default: break;
	}
	if (money < t->getCost()) {
		delete t;
		return;
	}
	addObject(t);
	money -= t->getCost();
}


//This function would first make all tower fires (if there is 
//at least one enemy in its range). By default, the tower will select 
//the nearest enemy to shoot. If there are more than one nearest enemies,
//pick anyone of them (we would not test this case during grading).
//
//Next all enemies are going to move. Remember that an enemy in the state
//FROZEN or DEAD cannot move.  
//
//Next you need to generate one new Enemy by calling the function genereateEnemy(). The function generateEnemy has been written for you already.
//
//Finally you need to clean up all DEAD enemy and tower that was destroyed by enemy in this turn.
//
//The amount of money will be increased by the enemies killed in this turn.
//(*noted: if a RevivingEnemy revive, money will not be added) 
void Arena::nextRound() {
//TODO
	for (int i=0; i<num_objects; ++i)
		if (objects[i]->getObjectType() == ObjectType::TOWER) {
			int tX,tY;
			objects[i]->getXY(tX,tY);
			Object* nearest_object = nullptr;
			int nearest_distance = ARENA_W + ARENA_H;
			for (int j=0; j<num_objects; ++j)
				if (objects[j]->getObjectType() == ObjectType::ENEMY) {
					int eX,eY;
					objects[j]->getXY(eX,eY);
					if (static_cast<Tower*>(objects[i])->isInRange(eX,eY)) {
						int x_difference = (tX>eX)?(tX-eX):(eX-tX);
						int y_difference = (tY>eY)?(tY-eY):(eY-tY);
						if (x_difference + y_difference <= nearest_distance) {
							nearest_object = objects[j];
							nearest_distance = x_difference + y_difference;
						}
					}
				}
			if (nearest_object != nullptr)
				static_cast<Tower*>(objects[i])->fire(static_cast<Enemy&>(*nearest_object));
		}

	for (int i=0; i<num_objects; ++i)
		if (objects[i]->getObjectType() == ObjectType::ENEMY)
			if (objects[i]->getState() != ObjectState::DEAD) {
				switch (objects[i]->getSymbol()) {
				case 'E': static_cast<Enemy*>(objects[i])->move(); break;
				case 'D': static_cast<TodoDiagonalEnemy*>(objects[i])->move(); break;
				case 'R': static_cast<TodoRevivingEnemy*>(objects[i])->move(); break;
				default: break;
				}
				int eX, eY;
				objects[i]->getXY(eX,eY);
				for (int j=0; j<num_objects; ++j)
					if (objects[j]->getObjectType() == ObjectType::TOWER) {
						int tX, tY;
						objects[j]->getXY(tX,tY);
						if (eX == tX && eY == tY)
							objects[j]->setState(ObjectState::DEAD);
					}
			}

	generateEnemy();

	for (int i=num_objects-1; i>=0; --i)
		if (objects[i]->getState() == ObjectState::DEAD) {
			if (objects[i]->getObjectType() == ObjectType::ENEMY) {
				enemy_kill += 1;
			}
			removeObject(objects[i]);
		}

	for (int i=0; i<num_objects; ++i)
		if (objects[i]->getObjectType() == ObjectType::TOWER)
			money += static_cast<Tower*>(objects[i])->collectMoney();
}

//Completed
bool Arena::upgrade(Tower* t) {
	if (t == nullptr || money < t->getUpgradeCost())
		return false;
	money -= t->getUpgradeCost();
	t->upgrade();
	return true;
}

//Completed
void Arena::generateEnemy() {
	int i = rand() % ARENA_H;
	Enemy* e;
	switch (rand() % 3) {
	case 0: e = new Enemy(5, ENEMY_X, i); break;
	case 1: e = new TodoDiagonalEnemy(6, ENEMY_X, i); break;
	case 2: e = new TodoRevivingEnemy(10, ENEMY_X, i); break;
	}
	addObject(e);

}

//Completed
Arena::Arena() : objects(nullptr), num_objects(0), money(10), enemy_kill(0) {
	nextRound();
}
