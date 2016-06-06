#include<iostream>
#include"Monster.h"
using namespace std;

#ifndef MONSTERLIST_H
#define MONSTERLIST_H
class BlockBert : public Monster
{
public:
	BlockBert( const int &m )
		:Monster( "BLOCKBERT", 50, 10, 30, 5, m ){}
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
};
class CoolCat : public Monster
{
public:
	CoolCat( const int &m )
		:Monster( "COOLCAT", 35, 20, 25, 10, m ){}
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
};
class CoolerThanCoolCat: public Monster
{
public:
	CoolerThanCoolCat( const int &m )
		:Monster( "COOLER THAN COOL CAT", 55, 30, 35, 15, m ){}
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
};

#endif MONSTERLIST_H
