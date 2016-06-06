#include<iostream>
#include"Battle.h"
#include"MonsterList.h"
using namespace std;

int main()
{
	srand( time( 0 ) );
	Monster *block1 = new BlockBert( 1 );
	Monster *cool1 = new CoolCat( 2 );
	Monster *ccool1 = new CoolerThanCoolCat( 2 );
	Monster *ccool2 = new CoolerThanCoolCat( 3 );
	Battle::instance()->setMonsters( ccool2, ccool1 );	// There can only be one battle at a time, therefore battle is a singleton
	Battle::instance()->battleLoop();

	return 0;
}