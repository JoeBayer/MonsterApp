#include"IncludeThis.h"
#include"ActionCard.h"
#include"Monster.h"
#include"Battle.h"
#include"Deck.h"

// ACTION CARD FUNCTIONS 
// roll accuracy check and return true if hit, false if miss
bool ActionCard::accCheck( const int &num )
{
	int acc = rand() % 100 + 1;
	if( acc <= num )
		return true;
	else
		return false;
} // end function accuracyCheck

// ATTACK CARD FUNCTIONS
// display the Attack that is being performed for the user
void AttackCard::displayAttack( const string &n, const double &d, Monster *p, Monster *e )
{
	cout << p->getName() << " used " << n << " on " << e->getName() <<
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
double AttackCard::calcDamage( Monster *p, Monster *e, double attPow )
{
	return ( ( attPow / e->getCurrDefense() ) * p->getCurrStrength() )		// divide attack by defense and multiply by strength 
																	// so there's never a negative number
		* ( ( ( rand() % 22 + 1 ) / 100.0 ) + 1 - .11 );	// randomness modifier
} // end function calcDamage

// SUPPORT CARD FUNCTIONS
// display the Support Action that is being performed for the user
void SupportCard::displaySupport( const string &n, Monster *p, Monster *e )
{
	cout << p->getName() << " used " << n << " on " << e->getName() << endl;
	Battle::instance()->pressEnter();
	return;
}