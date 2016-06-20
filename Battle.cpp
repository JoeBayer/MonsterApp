#include<iostream>
#include"Battle.h"
using namespace std;

Battle *Battle::bInstance = 0;

// "Where the magic happens" - Bill Gates, probably
// Controls the flow of the battle
void Battle::battleLoop()
{
	int turnCounter = 1;
	setUpTurnOrder();
	displayIntro();

	while( ( playerMonster1->getHealth() > 0 || playerMonster2->getHealth() > 0 )	// battle while at least one member of each team still has hp left
		&& ( oppMonster1->getHealth() > 0 || oppMonster2->getHealth() > 0 ) )		// ^^^
	{
		cout << endl;
		cout << "TURN: " << turnCounter << endl;
		displayHealth();
		findTurnOrder();

		for( int i = 0; i < 4; i++ )
		{
			if( turnOrder[ i ]->getHealth() > 0 &&											// battle if attacking monster is not fainted
				( ( playerMonster1->getHealth() > 0 || playerMonster2->getHealth() > 0 )	// battle if at least one member of each team still has hp left
				&& ( oppMonster1->getHealth() > 0 || oppMonster2->getHealth() > 0 ) ) )		// ^^^
			{
				if( turnOrder[ i ]->getIsPlayerMon() == true )
					playerTurn( turnOrder[ i ] );
				else
					enemyTurn( turnOrder[ i ] );
			} // end if
		} // end for
		turnCounter++;
	} // end while
	displayWinLoss();
} // end battleLoop function

// sets all of the monsters into the turnOrder vector
void Battle::setUpTurnOrder()
{
	turnOrder.push_back( playerMonster1 );
	turnOrder.push_back( playerMonster2 );
	turnOrder.push_back( oppMonster1 );
	turnOrder.push_back( oppMonster2 );
} // end setUpTurnOrder function

// calculates the turn order based on speed
// uses bubble sort to sort the four monsters into their proper order
void Battle::findTurnOrder()
{
	Monster *temp = 0;
	for( int i = 0; i < 4; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			if( turnOrder[ j ]->getSpeed() < turnOrder[ j + 1 ]->getSpeed() ) // swap monsters if one is faster than the other
				MonsterSwap( turnOrder[ j ], turnOrder[ j + 1 ] );
			if( turnOrder[ j ]->getSpeed() == turnOrder[ j + 1 ]->getSpeed() ) // swap monsters if they have equal speed - only swap %50 of the time
			{
				int opt = rand() % 2;
				if( opt == 1 )
					MonsterSwap( turnOrder[ j ], turnOrder[ j + 1 ] );
			} // end outer if
		} // end inner for
	} // end outer for
} // end findTurnOrder function

// swap two Monsters in the turnOrder vector
void Battle::MonsterSwap( Monster *one, Monster *two )
{
	Monster *temp = one;
	one = two;
	two = temp;
} // end function MonsterSwap

// displays all options for a player Monster during its turn
void Battle::battleMenu( Monster *m )
{
	int opt = 0;
	int opt2 = 0;
	while( opt2 != 1 && opt2 != 2 ) // main menu for monster
	{
		opt2 = 0;
		cout << m->getName() << ":" << endl;
		cout << "1: Attack\t2: Display Health" << endl;
		cin >> opt;
		switch( opt )
		{
		case 1: // Attack Submenu
			while( opt2 != 1 && opt2 != 2 && opt2 != 3 )	// continue in this submenu while the user does not attack 
			{												// or go back to the previous menu
				cout << "Which monster should your " << m->getName() << " to attack?" << endl;
				if( oppMonster1->getHealth() > 0 )			// only display enemy Monster as an attacking option if it is still active
					cout << "1: " << oppMonster1->getName() << endl;
				if( oppMonster2->getHealth() > 0 )			// only display enemy Monster as an attacking option if it is still active
					cout << "2: " << oppMonster2->getName() << endl;
				cout << "3: Go Back" << endl;
				cin >> opt2;
				switch( opt2 )
				{
				case 1:	// attack Opponent Monster 1
					if( oppMonster1->getHealth() > 0 )	// if selected monster is fainted, attack the other one
						m->attack( oppMonster1 );
					else
						m->attack( oppMonster2 );
					break;
				case 2:	// attack Opponent Monster 2
					if( oppMonster2->getHealth() > 0 )	// if selected monster is fainted, attack the other one
						m->attack( oppMonster2 );
					else
						m->attack( oppMonster1 );
					break;
				case 3:	// go back to previous menu
					break;
				default:
					cout << "Invalid Input, Try Again" << endl;
					break;
				}
			}	// end attack submenu while
			break;
		case 2:
			displayHealth();
			cout << endl;
			break;
		default:
			cout << "Invalid Input, Try Again" << endl;
			break;
		} // end switch
	} // end while
} // end battleMenu function

// executes during battle loop if it is a player Monster's turn
void Battle::playerTurn( Monster *p )
{
	battleMenu(p);	// opens battle menu for Monster p
} // end playerTurn function

// executes during battle loop if it is a enemy Monster's turn
void Battle::enemyTurn( Monster *e )
{
	int opt;
	opt = rand() % 2;	// randomly decides which player Monster to attack
	switch( opt )
	{
	case 0:
		if( playerMonster1->getHealth() > 0 )	// if selected monster is fainted, attack the other one
			e->attack( playerMonster1 );
		else if( playerMonster2->getHealth() > 0 )
			e->attack( playerMonster2 );
		break;
	case 1:
		if( playerMonster2->getHealth() > 0 )	// if selected monster is fainted, attack the other one
			e->attack( playerMonster2 );
		else if( playerMonster1->getHealth() > 0 )
			e->attack( playerMonster1 );
		break;
	}
} // end enemyTurn function

// displays the health of all Monsters on the field
void Battle::displayHealth()
{
	fixHealth();

	cout << "Player's ";
	playerMonster1->displayStatus();
	cout << "Player's ";
	playerMonster2->displayStatus();
	cout << "Enemy ";
	oppMonster1->displayStatus();
	cout << "Enemy ";
	oppMonster2->displayStatus();
	pressEnter();
	cout << endl;
} // end displayHealth function

// makes negative values equal to 0 for nicer display purposes
void Battle::fixHealth()
{
	if( playerMonster1->getHealth() < 0 )
		playerMonster1->setHealth( 0 );
	if( playerMonster2->getHealth() < 0 )
		playerMonster2->setHealth( 0 );
	if( oppMonster1->getHealth() < 0 )
		oppMonster1->setHealth( 0 );
	if( oppMonster2->getHealth() < 0 )
		oppMonster2->setHealth( 0 );
} // end function fixHealth

// displays Battle Intro
void Battle::displayIntro()
{
	cout << "Enemy played " << oppMonster1->getName() << "!" << endl;	// Introduce everybody on the field to the player
	cout << "Enemy played " << oppMonster2->getName() << "!" << endl;
	cout << "You played " << playerMonster1->getName() << "!" << endl;
	cout << "You played " << playerMonster2->getName() << "!" << endl;
	pressEnter();
} // end function displayIntro

// calculates and displays win/loss
void Battle::displayWinLoss()
{
	if( playerMonster1->getHealth() <= 0 && playerMonster2->getHealth() <= 0 )
		cout << "You Lose! Try Again." << endl;
	else
		cout << "You Win! Nice Job." << endl;
	pressEnter();
} // end function displayWinLoss

// creates a prompt for the user to see the next piece of text
void Battle::pressEnter()
{
	cout << "vvv";
	cin.ignore();
} // end pressEnter function