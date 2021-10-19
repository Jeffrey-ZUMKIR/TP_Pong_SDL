#include "CPlayer.h"
#include "define.h"
#include "SDL.h"

#include <iostream>
#include <string>

//GOAL	: Set the variables at the creation of the object
//INPUT	: The width, height, the phase, x, y, the texture and the score
//OUTPUT: The player
CPlayer::CPlayer()
{
	this->actualPhase = phase::IDLE;
	this->pTexture = NULL;
	this->pTextScore = NULL;
	this->score = 0;

	this->rectP.x = 0;
	this->rectP.y = 0;
	this->rectP.w = 0;
	this->rectP.h = 0;

	this->rectScore.x = 0;
	this->rectScore.y = 0;
	this->rectScore.w = 0;
	this->rectScore.h = 0;
}

//GOAL	: Free the memory
//INPUT	: /
//OUPUT	: /
CPlayer::~CPlayer()
{
	SDL_DestroyTexture(this->pTexture);
	SDL_DestroyTexture(this->pTextScore);
}

//GOAL	: Set width
//INPUT	: Width
//OUPUT	: Width of player set
void CPlayer::setWidth(int width)
{
	this->rectP.w = width;
}

//GOAL	: Set height
//INPUT	: Height
//OUPUT	: Height of player set
void CPlayer::setHeight(int height)
{
	this->rectP.h = height;
}

//GOAL	: Set x
//INPUT	: X
//OUPUT	: X of player set
void CPlayer::setX(int x)
{
	this->rectP.x= x;
}

//GOAL	: Set y
//INPUT	: Y
//OUPUT	: Y of player set
void CPlayer::setY(int y)
{
	this->rectP.y = y;
}

//GOAL  : Set rect
//INPUT : x, y, width, height
//OUTPUT: Rect set
void CPlayer::setRect(int x, int y, int width, int height)
{
	this->rectP.x = x;
	this->rectP.y = y;
	this->rectP.w = width;
	this->rectP.h = height;
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

//GOAL  : Set text score
//INPUT : style and render
//OUTPUT: Text score set
void CPlayer::setTextScore(TextStyle style, SDL_Renderer* render)
{
	//Get score player 1
	std::string str_score = std::to_string(this->getScore());
	char* ch_score = const_cast<char*>(str_score.c_str());

	//Set surface and texture of score 1
	SDL_Surface* pScore = TTF_RenderText_Solid(style.font, ch_score, style.color);
	this->pTextScore = SDL_CreateTextureFromSurface(render, pScore);
}

//GOAL  : Set rect
//INPUT : X, Y, width, height
//OUTPUT: Rect set
void CPlayer::setRectScore(int x, int y, int width, int height)
{
	this->rectScore.x = x;
	this->rectScore.y = y;
	this->rectScore.w = width;
	this->rectScore.h = height;
}

//GOAL	: Get width
//INPUT	: /
//OUTPUT: Width of player
int CPlayer::getWidth()
{
	return this->rectP.w;
}

//GOAL	: Get height
//INPUT	: /
//OUTPUT: Height of player
int CPlayer::getHeight()
{
	return this->rectP.h;
}

//GOAL	: Get x
//INPUT	: /
//OUTPUT: X of player
int CPlayer::getX()
{
	return this->rectP.x;
}

//GOAL	: Get y
//INPUT	: /
//OUTPUT: Y of player
int CPlayer::getY()
{
	return this->rectP.y;
}

//GOAL  : Get rect
//INPUT : /
//OUTPUT: The rect
SDL_Rect* CPlayer::getRect()
{
	return &this->rectP;
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

//GOAL  : Get text score
//INPUT : / 
//OUTPUT: Text score
SDL_Texture* CPlayer::getTextScore()
{
	return this->pTextScore;
}

//GOAL  : Get rect score
//INPUT : /
//OUTPUT: The rect score
SDL_Rect* CPlayer::getRectScore()
{
	return &rectScore;
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
	else if (this->getY() >WHEIGHT- this->getHeight()) {
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


