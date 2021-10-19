#pragma once
#include "SDL.h"

class CEndScreen {
private:
	SDL_Texture* pTextRestart;
	SDL_Rect rectRestart;
public:
	//Constructeur
	CEndScreen();

	//Destructeur
	~CEndScreen();

	//Accesseurs
	SDL_Rect* getRect();
	SDL_Texture* getTexture();

	//Mutateurs
	void setRect(int x, int y, int width, int height);
	void setTexture(SDL_Texture* texture);

protected:

};