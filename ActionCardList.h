#include"IncludeThis.h"
#include"ActionCard.h"
#include "Monster.h"

#ifndef ACTIONCARDLIST_H
#define ACTIONCARDLIST_H

class Tackle : public AttackCard
{
public:
	Tackle()
	{
		setAccuracy( 95 );
		setAttPow( 35 );
	}

	void attack( Monster *p, Monster *e )
	{
		if( accCheck( getAccuracy() ) )
		{
		} // end if
		else
			cout << p->getName() << "'s move missed the enemy's " << e->getName() << endl;
		cout << endl;
	}
};

#endif ACTIONCARDLIST_H