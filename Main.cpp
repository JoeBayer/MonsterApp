// Program last updated 6/29/16
//-----------//
//-CHANGELOG-//
//-----------//
// 7/5/2016
// CHANGES
// - Added Acurracy Check function in Monster class
//		- removes redundancy, makes checking accuracy a lot easier
// BUGS
// - Text is broken up during SOME moves that hit twice
// - Odd Spacing will randomly occur
// FUTURE UPDATES
// - Make a seperate class for moves ( rather than having them all be under the Monster class )
//		- Monster class should feature a "HAS A" relationship with the upcoming Move class

// 6/26/2016
// CHANGES
// - Fixed SOME spacing issues
// - Made Syntax for current Health easier to read and understand
// - Added reset stats function to monsters to reset stats after buffs and nerfs
// - Added reset all stats function to battle.cpp to reset the stats of all monsters that take part in a battle after it is over
// - Added Comments to make multiple parts of the program more readable
// BUGS
// - Text is broken up during SOME moves that hit twice
// - Odd Spacing will randomly occur

// 6/19/2016
// CHANGES
// - Made Monster battles 2v2 rather than 1v1
// - Made the display easier to read by breaking up text and only showing small amounts of it at a time
// - Tweaked the power of some Monsters to create more balance
// - Added a new Monster - Flamingwondo
// BUGS
// - Text isn't broken up during moves that hit twice
// - Odd Spacing will randomly occur
#include"IncludeThis.h"
#include"Battle.h"
#include"MonsterList.h"

int main()
{
	srand( time( 0 ) );	// seed time
	Monster *playMon1 = new Flamingwondo( 2, true );	// set up player Monster pointers
	Monster *playMon2 = new BlockBert( 1, true );

	Monster *oppMon1 = new BlockBert( 1, false );	// set up enemy Monster pointers
	Monster *oppMon2 = new CoolerThanCoolCat( 1, false );

	Battle::instance()->setMonsters( playMon1, playMon2, oppMon1, oppMon2 );	// There can only be one battle at a time, therefore battle is a singleton
	Battle::instance()->battleLoop();	

	return 0;
}