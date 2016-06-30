#include<iostream>
#include"Monster.h"
#include "Battle.h"
using namespace std;

//class Battle;

// display the status of the current monster
void Monster::displayStatus()
{
	cout << getName() << " HP: " << getCurrHealth() << endl;
} // end function displayStatus

// display the Attack that is being performed for the user
void Monster::displayAttack( const string &n, const double &d, Monster *e )
{
	cout << getName() << " used " << n << " on " << e->getName() <<
		"\n for " << d << " damage" << endl;
	Battle::instance()->pressEnter();
	if( e->getCurrHealth() <= 0 )
	{
		cout << endl << e->getName() << " fainted" << endl;
		Battle::instance()->pressEnter();
	} // end if
	return;
} // end function displayAttack

// calculate the damage dealt from one monster to another
double Monster::calcDamage( Monster *e, double attPow )
{
	return ( ( attPow / e->currDefense ) * getCurrStrength() )		// divide attack by defense and multiply by strength 
															// so there's never a negative number
				* (((rand() % 22 + 1)/100.0) + 1 - .11);	// randomness modifier
} // end function calcDamage

// reset the current stats of the monster to normal
void Monster::resetStats()
{
	setCurrHealth( getTotalHealth() );
	setCurrStrength( getStrength() );
	setCurrDefense( getDefense() );
	setCurrSpeed( getSpeed() );
} // end function resetStats

// FUNCTION DEFINITION OF EVERY MOVE IN THE GAME
// {

// TACKLE Family
void Monster::Tackle( Monster *e )
{
	int acc = rand() % 100 + 1;
	if( acc > 5 )
	{
		double attPow = 35;
		double damage = calcDamage( e, attPow );
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "TACKLE", damage, e );
	} // end if
	else
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	cout << endl;
} // end Tackle Class
void Monster::SuperTackle( Monster *e )
{
	int acc = rand() % 100 + 1;
	if( acc > 5 )
	{
		double attPow = 45;
		double damage = calcDamage( e, attPow );
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "SUPER TACKLE", damage, e );
	} // end if
	else
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	cout << endl;
} // end SuperTackle class
void Monster::HyperTackle( Monster *e )
{
	int acc = rand() % 100 + 1;
	if( acc > 5 )
	{
		double attPow = 55;
		double damage = calcDamage( e, attPow );
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "HYPER TACKLE", damage, e );
	} // end if
	else
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	cout << endl;
} // end HyperTackle class
// -- End TACKLE Family

// SWIPE FAMILY
void Monster::Swipe( Monster *e )
{
	double attPow = 10;
	double damage = calcDamage( e, attPow );
	e->setCurrHealth( e->getCurrHealth() - damage );
	displayAttack( "SWIPE", damage, e );
	cout << endl;
} // end Swipe class
void Monster::DoubleSwipe( Monster *e )
{
	double attPow = 10;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	e->setCurrHealth( e->getCurrHealth() - damage );
	displayAttack( "DOUBLE SWIPE", damage, e );
	cout << endl;
	if( e->getCurrHealth() > 0 )
	{
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "DOUBLE SWIPE", damage, e );
		cout << endl << "DOUBLE SWIPE hit twice!" << endl;
		cout << endl;
	} // end if
} // end DoubleSwipe class
void Monster::FlashySwipe( Monster *e )
{
	double attPow = 20;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	e->setCurrHealth( e->getCurrHealth() - damage );
	displayAttack( "FLASHY SWIPE", damage, e );
	cout << endl;
	if( e->getCurrHealth() > 0 )
	{
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "FLASHY SWIPE", damage, e );
		cout << "FLASHY SWIPE hit twice!" << endl;
		cout << endl;
	} // end if
} // end FlashySwipe class
void Monster::RagingSwipe( Monster *e )
{
	double attPow = 20;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	int acc = rand() % 100 + 1;
	if( acc > 15 )
	{
		e->setCurrHealth( e->getCurrHealth() - damage );
		displayAttack( "RAGING SWIPE", damage, e );
	}
	else
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;

	if( e->getCurrHealth() > 0 )
	{
		acc = rand() % 100 + 1;
		cout << endl;
		if( acc > 15 )
		{
			e->setCurrHealth( e->getCurrHealth() - damage );
			displayAttack( "RAGING SWIPE", damage, e );
		}
		else
			cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	} // end if

	setCurrStrength( getCurrStrength() * 1.1 );
	cout << endl << getName() << "'s Attack increased!" << endl;
	cout << endl;
} // end Raging Swipe class
// -- End SWIPE Family

void Monster::SurpriseAttack( Monster *e )
{
	double attPow = 25;
	double damage = calcDamage( e, attPow );
	e->setCurrHealth( e->getCurrHealth() - damage );
	displayAttack( "SURPRISE ATTACK", damage, e );

	setCurrSpeed( getCurrSpeed() * 1.1 );
	cout << endl << getName() << "'s Speed increased!" << endl;
	cout << endl;
} // end SurpriseAttack class


// END FUNCTION DEFINITION OF EVERY MOVE IN THE GAME