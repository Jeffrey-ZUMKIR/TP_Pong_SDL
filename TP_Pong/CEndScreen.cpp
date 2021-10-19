#include "CEndScreen.h"

//GOAL	: Set the variables at the creation of the object
//INPUT	: /
//OUTPUT: The end screen
CEndScreen::CEndScreen()
{
	pTextRestart = NULL;
	rectRestart = { 0,0,0,0 };
}

//GOAL	: Free the memory
//INPUT	: /
//OUPUT	: /
CEndScreen::~CEndScreen()
{
	SDL_DestroyTexture(pTextRestart);
}

//GOAL	: Get rectangle
//INPUT	: /
//OUPUT	: The rect
SDL_Rect* CEndScreen::getRect()
{
	return &rectRestart;
}

//GOAL	: Get texture
//INPUT	: /
//OUPUT	: The texture
SDL_Texture* CEndScreen::getTexture()
{
	return pTextRestart;
}

//GOAL	: Set the rect
//INPUT	: X, y, width and height
//OUPUT	: The rect set
void CEndScreen::setRect(int x, int y, int width, int height)
{
	rectRestart.x = x;
	rectRestart.y = y;
	rectRestart.w = width;
	rectRestart.h = height;
}

//GOAL	: Set the texture
//INPUT	: Texture
//OUPUT	: Texture set
void CEndScreen::setTexture(SDL_Texture* texture)
{
	pTextRestart = texture;
}
