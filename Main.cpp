#include<iostream>
#include"Battle.h"
#include"MonsterList.h"
using namespace std;

int main()
{
	srand( time( 0 ) );	// seed time
	Monster *playMon1 = new Flamingwondo( 2, true );	// set up player Monster pointers
	Monster *playMon2 = new CoolCat( 3, true );

	Monster *oppMon1 = new BlockBert( 1, false );	// set up enemy Monster pointers
	Monster *oppMon2 = new CoolerThanCoolCat( 1, false );

	Battle::instance()->setMonsters( playMon1, playMon2, oppMon1, oppMon2 );	// There can only be one battle at a time, therefore battle is a singleton
	Battle::instance()->battleLoop();	

	return 0;
}