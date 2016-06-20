#include<iostream>
#include<string>
#include<time.h>
using namespace std;

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

	// ACCESSORS / MUTATORS
	string getName(){ return name; }
	void setName( const string &n ){ name = n; }
	double getTotalHealth(){ return totalHealth; }
	void setTotalHealth( const double &th ){ totalHealth = th; }
	double getHealth(){ return currHealth; }
	void setHealth( const double &h ){ currHealth = h; }
	double getStrength(){ return strength; }
	void setStrength( const double &s ){ strength = s; }
	double getCurrStrength(){ return currStrength; }
	void setCurrStrength( const double &s ){ currStrength = s; }
	double getDefense(){ return defense; }
	void setDefense( const double &d ){ defense = d; }
	double getCurrDefense(){ return currDefense; }
	void setCurrDefense( const double &d ){ currDefense = d; }
	double getSpeed(){ return speed; }
	void setSpeed( const double &sp ){ speed = sp; }
	double getCurrSpeed(){ return currSpeed; }
	void setCurrSpeed( const double &sp ){ currSpeed = sp; }
	int getMoveNumber(){ return moveNumber; }
	void setMoveNumber( const int &m ){ moveNumber = m; }
	int getIsPlayerMon(){ return isPlayerMon;  }
	void setIsPlayerMon( const bool &ipm ){ isPlayerMon = ipm; }
	// -- End Accessors and Mutators

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