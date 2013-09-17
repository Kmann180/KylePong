// Game of Adventure.cpp : Defines the entry point for the console application.
//

//////////////////////////////////////////////////////////////////////////////
// File: Game of Adventure
// Author: Kyle Kennedy
// Date Created: 

#include "stdafx.h"
#include <iostream>
#include <time.h>
using namespace std;

char cAction;
int iTired = 0;
bool bAte = false;

void Menu ();

void Walk () 
{
	
	if (iTired <= 9)
	{
		cout << endl << "You went for a walk." << endl << "Five hours later." << endl;
		iTired += 1; 
	}
	else if (iTired > 9)
	{
		cout << endl << "You can not do that at the moment you are too tired." << endl;
	}
	cout << "You are " << iTired << "0% tired." << endl << endl;
	Menu();
}
void Jump ()
{

	if (iTired <= 10)
	{
		cout << endl << "You jumped." << endl;
		iTired += 2; 
	}
	else if (iTired >= 10)
	{
		cout << endl << "You can not do that at the moment you are too tired." << endl;
	}
	cout << "You are " << iTired << "0% tired." << endl << endl;

	Menu();
}
void Attack ()
{
	if (iTired <= 10)
	{
		cout << endl << "You attacked a tree." << endl << "your hand now hurts, stupid" << endl;
		iTired += 3; 
	}
	else if (iTired >= 10)
	{
		cout << endl << "You can not do that at the moment you are too tired." << endl;
	}
	cout << "You are " << iTired << "0% tired." << endl << endl;

	Menu();
}
void Sleep ()
{

		cout << endl << "You slept." << endl;
		iTired = 0; 
		bAte = false;
		cout << "You are " << iTired << "0% tired." << endl << endl;


	Menu();
}
void Eat ()
{
	if (bAte == false)
	{
		cout << endl << "You ate, yum." << endl;
		bAte = true;
	}
	 else if (bAte == true)
	{
		cout << endl << "You are not hungery." << endl;
	}
	cout << "You are " << iTired << "0% tired." << endl << endl;

	Menu();
}
void Run ()
{
	if (iTired <= 6)
	{
		cout << endl << "You went for a run." << endl;
		iTired += 4; 
	}
	else if (iTired > 6)
	{
		cout << endl << "You can not do that at the moment you are too tired." << endl;
	}
	cout << "You are " << iTired << "0% tired." << endl << endl;

	Menu();
}
void Die ()
{
	cout << "You died, loser" << endl << "But then a Phionex of Life can and brought you back to life," << endl << "just so that you can lose again." << endl;
	iTired = 0;
	cout << "You are " << iTired << "0% tired." << endl << endl;

	Menu();
}

void Menu ()
{
	cout << "what do you want to do?" << endl << "Walk = W, Jump = J, Attack = A, Sleep = S, " << endl << "Eat = E, Run = R, or Die = D," << endl;
	cin >> cAction;

	 switch (cAction)
	{
	case 'W' : 
		Walk();
		break;
	case 'J' : 
		Jump();
		break;
	case 'A' : 
		Attack();
		break;
	case 'S' : 
		Sleep();
		break;
	case 'E' :
		Eat();
		break;
	case 'R' : 
		Run();
		break;
	case 'D' : 
		Die();
		break;

	default:
		Menu();
		break;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Menu();
	return 0;
}

