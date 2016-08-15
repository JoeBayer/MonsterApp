#include"IncludeThis.h"
#include<time.h>

#ifndef MONSTER_H
#define MONSTER_H

// Base Class for every monster in the game
class Monster
{
private:
	string name;
	double totalHealth;
	double currHealth;

	double strength;
	double currStrength;

	double defense;
	double currDefense;

	double speed;
	double currSpeed;

	bool isPlayerMon;

	int moveNumber;
	double calcDamage( Monster *e, double attPow );
	bool accCheck( const int &num );

	
public:
	// CONSTRUCTORS
	Monster(){}
	Monster( const string &n, const double &th, const double &s, const double &d, const double &sp, const int &m, const bool &ipm )
		:name( n ), totalHealth( th ), strength( s ), defense( d ), speed(sp), moveNumber( m ), isPlayerMon( ipm )
	{
		currHealth = totalHealth;
		currStrength = strength;
		currDefense = defense;
		currSpeed = speed;
	}
	Monster( const Monster &right )
	{
		name = right.name;
		totalHealth = right.totalHealth;
		strength = right.strength;
		currHealth = totalHealth;
	}
	// -- End Constructors
	
	void displayStatus();
	void displayAttack( const string &n, const double &d, Monster *e );

	// ACCESSORS
	string getName(){ return name; }
	double getTotalHealth(){ return totalHealth; }
	double getCurrHealth(){ return currHealth; }
	double getStrength(){ return strength; }
	double getCurrStrength(){ return currStrength; }
	double getDefense(){ return defense; }
	double getCurrDefense(){ return currDefense; }
	double getSpeed(){ return speed; }
	double getCurrSpeed(){ return currSpeed; }
	int getMoveNumber(){ return moveNumber; }
	int getIsPlayerMon(){ return isPlayerMon;  }

	// MUTATORS
	void setName( const string &n ){ name = n; }
	void setTotalHealth( const double &th ){ totalHealth = th; }
	void setCurrHealth( const double &h ){ currHealth = h; }
	void setStrength( const double &s ){ strength = s; }
	void setCurrStrength( const double &s ){ currStrength = s; }
	void setDefense( const double &d ){ defense = d; }
	void setCurrDefense( const double &d ){ currDefense = d; }
	void setSpeed( const double &sp ){ speed = sp; }
	void setCurrSpeed( const double &sp ){ currSpeed = sp; }
	void setMoveNumber( const int &m ){ moveNumber = m; }
	void setIsPlayerMon( const bool &ipm ){ isPlayerMon = ipm; }


	// -- End Accessors and Mutators
	void resetStats();

	virtual void attack( Monster *e ) = 0;

	// PROTOTYPE FOR EVERY MOVE IN THE GAME
	// {
		// TACKLE Family {
		void Tackle( Monster *e );
		void SuperTackle( Monster *e );
		void HyperTackle( Monster *e );
		// } End TACKLE Family

		// SWIPE Family {
		void Swipe( Monster *e );
		void DoubleSwipe( Monster *e );
		void FlashySwipe( Monster *e );
		void RagingSwipe( Monster *e );
		// } End TACKLE Family

		void SurpriseAttack( Monster *e );


	// } END PROTOTYPES FOR EVERY MOVE IN THE GAME
}; // end class Monster

#endif MONSTER_H