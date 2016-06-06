#include<iostream>
#include<string>
#include"Monster.h"
using namespace std;

// Battle is a singleton

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
private:
	Monster *playerMonster;
	Monster *enemyMonster;
	void playerTurn();
	void enemyTurn();
	void displayOptions();
	void playerFirst();
	void enemyFirst();
	static Battle *bInstance;
	// CONSTRUCTORS
	Battle(){}
	Battle( Monster *p, Monster *e )
		:playerMonster( p ), enemyMonster( e ){}
	// -- End Construcytors
public:
	static Battle *instance()
	{
		if( !bInstance )
			bInstance = new Battle;
		return bInstance;
	}

	// This function is where the fun happens!
	void battleLoop();

	// ACCESSORS / MUTATORS
	Monster* getPlayerMonster(){ return playerMonster; }
	void setPlayerMonster( Monster* p ){ playerMonster = p; }
	Monster* getEnemyMonster(){ return enemyMonster; }
	void setEnemyMonster( Monster *e ){ enemyMonster = e;}
	void setMonsters( Monster *p, Monster *e )
	{
		playerMonster = p;
		enemyMonster = e;
	}
	// -- End Accessors and Mutators

};

#endif BATTLE_H