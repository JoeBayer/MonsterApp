#include<iostream>
#include<string>
#include<vector>
#include"Monster.h"
using namespace std;

// Battle is a singleton

#ifndef BATTLE_H
#define BATTLE_H

// Class that controls everything related to Monster interaction
class Battle
{
private:
	Monster *playerMonster1;
	Monster *playerMonster2;
	Monster *oppMonster1;
	Monster *oppMonster2;
	vector<Monster*> turnOrder;
	static Battle *bInstance; // object that forces only one instance at a time

	void setUpTurnOrder();
	void findTurnOrder();
	void MonsterSwap( Monster *one, Monster *two );
	void playerTurn(Monster *p);
	void enemyTurn(Monster *e);
	void battleMenu(Monster *m);
	void displayHealth();
	void fixHealth();
	void displayIntro();
	void displayWinLoss();
	void pressEnter();
	// CONSTRUCTORS
	Battle(){}
	Battle( Monster *p1, Monster *p2, Monster *e1, Monster *e2 )
		:playerMonster1( p1 ), playerMonster2( p2 ), 
			oppMonster1( e1 ), oppMonster2( e2 )
	{}
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
	Monster* getPlayerMonster1(){ return playerMonster1; }
	Monster* getPlayerMonster2(){ return playerMonster2; }
	void setPlayerMonster1( Monster* p ){ playerMonster1 = p; }
	void setPlayerMonster2( Monster* p ){ playerMonster2 = p; }
	Monster* getOppMonster1(){ return oppMonster1; }
	Monster* getOppMonster2(){ return oppMonster2; }
	void setOppMonster1( Monster *e ){ oppMonster1 = e;}
	void setOppMonster2( Monster *e ){ oppMonster2 = e; }
	void setMonsters( Monster *p1, Monster *p2,
						Monster *e1, Monster *e2 )
	{
		playerMonster1 = p1;
		playerMonster2 = p2;
		oppMonster1 = e1;
		oppMonster2 = e2;
	} // end setMonsters function
	// -- End Accessors and Mutators

}; // end class Battle

#endif BATTLE_H