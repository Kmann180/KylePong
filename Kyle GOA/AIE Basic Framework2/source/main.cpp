//////////////////////////////////////////////////////////////////////////
//File: Pong
//
//
//
//////////////////////////////////////////////////////////////////////////

#include "AIE.h"
#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <crtdbg.h>
#include <iostream>
using namespace std;


const int iScreenWidth = 1280;
const int iScreenHeight = 780;

const int SPEED = 10;
const int SCREEN_X = 1280;
const int SCREEN_Y = 780;

const int PLAYER1_X = 100;
const int PLAYER1_W = 50;
const int PLAYER1_H = 100;

const int PLAYER2_X = 1200;
const int PLAYER2_W = 50;
const int PLAYER2_H = 100;

const int BALL_W = 50;
const int BALL_H = 50;

struct Coords
{
	float x;
	float y;
};

struct movableObject
{
	Coords position;
	Coords speed;
	int sprite;
	int width;
	int height;
};

unsigned int bgImage = -1;

movableObject player1 = {PLAYER1_X, 100, 0, 0, -1 , PLAYER1_W, PLAYER1_H};
player1.sprite =   CreateSprite(".\resources\images\paddle1.png", PLAYER1_W, PLAYER1_H, true );

Object player2 = {PLAYER2_X, 100, 0, 0, -1, PLAYER2_W, PLAYER2_H};
CreateSprite( const char* a_pTextureName, PLAYER2_W, PLAYER2_H, true, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );

Object ball = {500, 500, 5+(rand()%40)/10, 5+(rand()%50)/10, -1, BALL_W, BALL_H};
CreateSprite( const char* a_pTextureName, BALL_W, BALL_H, true, SColour a_sColour = SColour(0xFF,0xFF,0xFF,0xFF) );


// add one vector to another, returns the result as a new vector
Coords vectorAdd(Coords &v, Coords &v2)
{
	Coords result = {v.x + v2.x, v.y + v2.y};
	return result;
}
void updateBallPosition(Object &obj)
{
	obj.position = vectorAdd(obj.position, obj.speed);
}

void updateGame()
{
	updateBallPosition(ball);
	if (IsKeyDown( KEY_DOWN ))
	{
		MoveSprite( unsigned int a_uiSpriteID, float a_fXPos, float a_fYPos );
	}
}

void drawGame()
{
	DrawSprite(bgImage);
	DrawSprite(player1.sprite);
	DrawSprite(player2.sprite);
	DrawSprite(ball.sprite);

}

void initGame()
{
	srand(time(0));

	bgImage = CreateSprite( "./images/bg.png", SCREEN_X, SCREEN_Y, true );
	MoveSprite(bgImage, SCREEN_X>>1, SCREEN_Y>>1);

	player1.sprite = CreateSprite( "./images/paddle1.png", PLAYER1_W, PLAYER1_H, true );
	MoveSprite(player1.sprite, player1.position.x, player1.position.y);

	player2.sprite = CreateSprite( "./images/paddle2.png", PLAYER2_W, PLAYER2_H, true );
	MoveSprite(player2.sprite, player2.position.x, player2.position.y);

	ball.sprite = CreateSprite( "./images/ball.png", BALL_W, BALL_H, true );
	MoveSprite(ball.sprite, ball.position.x, ball.position.y);
}


int main( int argc, char* argv[] )
{	

Initialise(SCREEN_X, SCREEN_Y );

	initGame();
		
	do {
//		frameCounter++;

//		if(frameCounter > 5000)
//			frameCounter = 0;

		ClearScreen();
		
		updateGame();

		drawGame();

	} while ( FrameworkUpdate() == false );
	
	Shutdown();

	return 0;
}


