#include<iostream>
#include"Battle.h"
using namespace std;

Battle *Battle::bInstance = 0;

void Battle::playerTurn()
{
	cout << "Player's ";
	playerMonster->displayStatus();
	cout << "Enemy ";
	enemyMonster->displayStatus();
	displayOptions();
}

void Battle::enemyTurn()
{
	enemyMonster->attack( playerMonster );
}

void Battle::displayOptions()
{
	int opt = 0;
	while( opt != 1 )
	{
		cout << "1: Attack\t2: Display Health" << endl;
		cin >> opt;
		switch( opt )
		{
		case 1:
			playerMonster->attack( enemyMonster );
			break;
		case 2:
			cout << "Player's ";
			playerMonster->displayStatus();
			cout << "Enemy ";
			enemyMonster->displayStatus();
			break;
		default:
			cout << "Invalid Input, Try Again" << endl;
			break;
		} // end switch
	} // end while
}

void Battle::playerFirst()
{
	playerTurn();
	if( enemyMonster->getHealth() <= 0 )
		cout << "You Win! Congratulations!" << endl;
	else
		enemyTurn();
	if( playerMonster->getHealth() <= 0 )
		cout << "You Lose! Better Luck Next Time!" << endl;
}

void Battle::enemyFirst()
{
	enemyTurn();
	if( playerMonster->getHealth() <= 0 )
		cout << "You Lose! Better Luck Next Time!" << endl;
	else
		playerTurn();
	if( enemyMonster->getHealth() <= 0 )
		cout << "You Win! Congratulations!" << endl;
}

void Battle::battleLoop()
{
	int turnCounter = 1;
	cout << "Enemy played " << enemyMonster->getName() << "!" << endl;
	cout << "You played " << playerMonster->getName() << "!" << endl;
	cout << endl;

	while( playerMonster->getHealth() > 0 
			&& enemyMonster->getHealth() > 0 )
	{
		cout << "TURN: " << turnCounter << endl;

		if( playerMonster->getCurrSpeed() > enemyMonster->getCurrSpeed() )	// PLAYER IS FASTER
		{
			playerFirst();
		}
		else if( playerMonster->getCurrSpeed() < enemyMonster->getCurrSpeed() )	// ENEMY IS FASTER
		{
			enemyFirst();
		}		
		else  // SPEED IS EQUAL
		{
			int num = rand() % 2 + 1;
			if( num == 1 )
			{
				playerFirst();
			}
			else
			{
				enemyFirst();
			}
		}

		turnCounter++;
		cout << endl;
	}
}