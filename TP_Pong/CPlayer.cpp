#include "CPlayer.h"
#include "define.h"
#include "SDL.h"

//GOAL	: Set the variables at the creation of the object
//INPUT	: The width, height, the phase, x, y, the texture and the score
//OUTPUT: The player
CPlayer::CPlayer(int width, int height, int x, int y, phase actualPhase, SDL_Texture* pTexture, int score)
{
	this->height = height;
	this->width = width;
	this->x = x;
	this->y = y;
	this->actualPhase = actualPhase;
	this->pTexture = pTexture;
	this->score = score;
}

//GOAL	: Free the memory
//INPUT	: /
//OUPUT	: /
CPlayer::~CPlayer()
{
	SDL_DestroyTexture(this->pTexture);
}

//GOAL	: Set width
//INPUT	: Width
//OUPUT	: Width of player set
void CPlayer::setWidth(int width)
{
	this->width = width;
}

//GOAL	: Set height
//INPUT	: Height
//OUPUT	: Height of player set
void CPlayer::setHeight(int height)
{
	this->height = height;
}

//GOAL	: Set x
//INPUT	: Xidth
//OUPUT	: Xidth of player set
void CPlayer::setX(int x)
{
	this->x = x;
}

//GOAL	: Set y
//INPUT	: Y
//OUPUT	: Y of player set
void CPlayer::setY(int y)
{
	this->y = y;
}

//GOAL	: Set texture
//INPUT	: Texture
//OUPUT	: Texture of player set
void CPlayer::setTexture(SDL_Texture* texture)
{
	this->pTexture = texture;
}

//GOAL	: Set phase
//INPUT	: Phase
//OUPUT	: Phase of player set
void CPlayer::setPhase(phase newPhase)
{
	this->actualPhase = newPhase;
}

//GOAL	: Set score
//INPUT	: Score
//OUPUT	: Score of player set
void CPlayer::setScore(int score)
{
	this->score = score;
}

//GOAL	: Get width
//INPUT	: /
//OUTPUT: Width of player
int CPlayer::getWidth()
{
	return this->width;
}

//GOAL	: Get height
//INPUT	: /
//OUTPUT: Height of player
int CPlayer::getHeight()
{
	return this->height;
}

//GOAL	: Get x
//INPUT	: /
//OUTPUT: X of player
int CPlayer::getX()
{
	return this->x;
}

//GOAL	: Get y
//INPUT	: /
//OUTPUT: Y of player
int CPlayer::getY()
{
	return this->y;
}

//GOAL	: Get texture
//INPUT	: /
//OUTPUT: Texture of player
SDL_Texture* CPlayer::getTexture()
{
	return this->pTexture;
}

//GOAL	: Get phase
//INPUT	: /
//OUTPUT: Phase of player
phase CPlayer::getPhase()
{
	return this->actualPhase;
}

//GOAL	: Get score
//INPUT	: /
//OUTPUT: Score of player
int CPlayer::getScore()
{
	return this->score;
}

//GOAL	: Set the position
//INPUT	: The movement and the height of the page
//OUTPUT: A new position
void CPlayer::setPosition(int move, int WHEIGHT)
{
	this->setY(this->getY() + move);
	if (this->getY() < 0) {
		this->setY(0);
	}
	else if (this->getY()>WHEIGHT-this->getHeight()) {
		this->setY(WHEIGHT - this->getHeight());
	}
}

//GOAL	: Move the player depending on the phase
//INPUT	: Height of the window
//OUTPUT: New position for the player
void CPlayer::move(int WHEIGHT)
{
	if (this->getPhase() == phase::UP) {
		this->setPosition(-5, WHEIGHT);
	}
	else if (this->getPhase() == phase::DOWN) {
		this->setPosition(5, WHEIGHT);
	}
}


