#include"IncludeThis.h"
#include"ActionCard.h"

#ifndef DECK_H
#define DECK_H

class Deck
{
private:
	vector<ActionCard*> deck;
public:
	vector<ActionCard*> getDeck(){ return deck; }
	ActionCard* getCard( int num ){ return deck[ num ]; }

};

#endif DECK_H