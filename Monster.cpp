#include<iostream>
#include"Monster.h"
using namespace std;

void Monster::displayStatus()
{
	cout << getName() << " HP: " << getHealth() << endl;
}

void Monster::displayAttack( const string &n, const double &d, Monster *e )
{
	cout << getName() << " used " << n << " on " << e->getName() <<
		"\n for " << d << " damage" << endl;
}

double Monster::calcDamage( Monster *e, double attPow )
{
	return ( ( attPow / e->currDefense ) * getCurrStrength() )		// divide attack by defense and multiply by strength 
															// so there's never a negative number
				* (((rand() % 22 + 1)/100.0) + 1 - .11);	// randomness modifier
}

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
		e->setHealth( e->getHealth() - damage );
		displayAttack( "TACKLE", damage, e );
	}
	else
	{
		cout << getName() << "'s move missed the enemy's" << e->getName() << endl;
	}
}
void Monster::SuperTackle( Monster *e )
{
	int acc = rand() % 100 + 1;
	if( acc > 5 )
	{
		double attPow = 45;
		double damage = calcDamage( e, attPow );
		e->setHealth( e->getHealth() - damage );
		displayAttack( "SUPER TACKLE", damage, e );
	}
	else
	{
		cout << getName() << "'s move missed the enemy's" << e->getName() << endl;
	}
}
void Monster::HyperTackle( Monster *e )
{
	int acc = rand() % 100 + 1;
	if( acc > 5 )
	{
		double attPow = 55;
		double damage = calcDamage( e, attPow );
		e->setHealth( e->getHealth() - damage );
		displayAttack( "HYPER TACKLE", damage, e );
	}
	else
	{
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	}
}
// -- End TACKLE Family

// SWIPE FAMILY
void Monster::Swipe( Monster *e )
{
	double attPow = 10;
	double damage = calcDamage( e, attPow );
	e->setHealth( e->getHealth() - damage );
	displayAttack( "SWIPE", damage, e );
}
void Monster::DoubleSwipe( Monster *e )
{
	double attPow = 10;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	e->setHealth( e->getHealth() - damage );
	displayAttack( "DOUBLE SWIPE", damage, e );
	e->setHealth( e->getHealth() - damage );
	displayAttack( "DOUBLE SWIPE", damage, e );
	cout << "DOUBLE SWIPE hit twice!" << endl;
}
void Monster::FlashySwipe( Monster *e )
{
	double attPow = 20;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	e->setHealth( e->getHealth() - damage );
	displayAttack( "FLASHY SWIPE", damage, e );
	e->setHealth( e->getHealth() - damage );
	displayAttack( "FLASHY SWIPE", damage, e );
	cout << "FLASHY SWIPE hit twice!" << endl;
}
void Monster::RagingSwipe( Monster *e )
{
	double attPow = 20;
	double damage = calcDamage( e, attPow );
	// Hits Twice
	int acc = rand() % 100 + 1;
	if( acc > 15 )
	{
		e->setHealth( e->getHealth() - damage );
		displayAttack( "RAGING SWIPE", damage, e );
	}
	else
	{
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	}
	acc = rand() % 100 + 1;
	if( acc > 15 )
	{
		e->setHealth( e->getHealth() - damage );
		displayAttack( "RAGING SWIPE", damage, e );
	}
	else
	{
		cout << getName() << "'s move missed the enemy's " << e->getName() << endl;
	}
		setCurrStrength( getCurrStrength() * 1.1 );
		cout << getName() << "'s Attack increased!" << endl;
}
// -- End SWIPE Family

void Monster::SurpriseAttack( Monster *e )
{
	double attPow = 25;
	double damage = calcDamage( e, attPow );
	e->setHealth( e->getHealth() - damage );
	displayAttack( "SURPRISE ATTACK", damage, e );
	setCurrSpeed( getCurrSpeed() * 1.1 );
	cout << getName() << "'s Speed increased!" << endl;
}


// END FUNCTION DEFINITION OF EVERY MOVE IN THE GAME