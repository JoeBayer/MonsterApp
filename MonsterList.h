#include"IncludeThis.h"
#include"Monster.h"
#include"ActionCardList.h"

#ifndef MONSTERLIST_H
#define MONSTERLIST_H
class Deck;

class BlockBert : public Monster
{
public:
	BlockBert( const int &m, const bool &ipm )
		:Monster( "BLOCKBERT", 50, 15, 35, 5, m, ipm ){}
	virtual void attack( Monster *e )
	{
		switch( getMoveNumber() )
		{
		case 1:
			Tackle( e );
			break;
		case 2:
			SuperTackle( e );
			break;
		case 3:
			HyperTackle( e );
			break;
		default:
			Tackle( e );
			break;
		} // end switch
	} // end attack
}; // end BlockBert class 
class CoolCat : public Monster
{
public:
	CoolCat( const int &m, const bool &ipm )
		:Monster( "COOLCAT", 35, 20, 25, 10, m, ipm ){}
	virtual void attack( Monster *e )
	{
		switch( getMoveNumber() )
		{
		case 1:
			Swipe( e );
			break;
		case 2:
			DoubleSwipe( e );
			break;
		case 3:
			FlashySwipe( e );
			break;
		default:
			Swipe( e );
			break;
		} // end switch
	} // end attack
}; // end CoolCat class
class CoolerThanCoolCat: public Monster
{
public:
	CoolerThanCoolCat( const int &m, const bool &ipm )
		:Monster( "COOLER THAN COOL CAT", 40, 25, 25, 15, m, ipm ){}
	virtual void attack( Monster *e )
	{
		switch( getMoveNumber() )
		{
		case 1:
			FlashySwipe( e );
			break;
		case 2:
			SurpriseAttack( e );
			break;
		case 3:
			RagingSwipe( e );
			break;
		default:
			FlashySwipe( e );
			break;
		} // end switch
	} // end attack
}; // end CoolerThanCoolCat class
class Flamingwondo : public Monster
{
public:
	Flamingwondo( const int &m, const bool &ipm )
		:Monster( "FLAMINGWONDO", 35, 35, 20, 20, m, ipm ){}
	virtual void attack( Monster *e )
	{
		switch( getMoveNumber() )
		{
		case 1:
			DoubleSwipe( e );
			break;
		case 2:
			SuperTackle( e );
			break;
		case 3:
			SurpriseAttack( e );
			break;
		default:
			SurpriseAttack( e );
			break;
		} // end switch
	} // end attack
}; // end Flamingwondo class

#endif MONSTERLIST_H
