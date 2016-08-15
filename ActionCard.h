#include"IncludeThis.h"

#ifndef ACTIONCARD_H
#define ACTIONCARD_H
class Monster;
class Deck;

class ActionCard
{
private:
	int accuracy;
	string family;
	string description;
public:
	// CONSTRUCTORS {
	ActionCard()
		:description( "This card has no description" ), family("DEFAULT"), accuracy(100), cardInDeck(0){}
	ActionCard( const int &acc )
		:description( "This card has no description" ), family( "DEFAULT" ), accuracy( acc ), cardInDeck(0){}
	// } END CONSTRUCTORS

	bool accCheck( const int &acc );

	// ACCESSORS {
	int getAccuracy(){ return accuracy; }
	string getFamily(){ return family; }
	string getDescription(){ return description; }
	// } END ACCESSORS

	// MUTATORS
	void setAccuracy( const int &acc ){ accuracy = acc; }
	void setFamily( const string &fam ){ family = fam; }
	void setDescription( const string &desc ){ description = desc; }
	// } END MUTATORS

	vector<Deck*> cardInDeck;	// vector of pointers to decks that this card belongs to

	void insertCardLocation( Deck &d )
	{
		Deck* deckPtr = &d;
		cardInDeck.push_back( deckPtr );
	} // end function insertCardLocation

	bool inADeck(){ return cardInDeck[0]; }

}; // end class ActionCard

class AttackCard : public ActionCard
{
private:
	int attPow;
public:
	double calcDamage( Monster *p, Monster *e, double attPow );
	void displayAttack( const string &n, const double &d, Monster *p, Monster *e );

	void setAttPow( int aP ){ attPow = aP; }
	double getAttPow(){ return attPow; }
};

class SupportCard : public ActionCard
{
public:
	void displaySupport( const string &n, Monster *p, Monster *e);
};

#endif ACTIONCARD_H