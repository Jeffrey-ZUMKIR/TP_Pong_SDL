#pragma once
#include "SDL.h"

class CRenderer {
private:
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
public:
	//Constructeur
	CRenderer();
	//Destructeur
	~CRenderer();

	//Accesseurs
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();

	//Mutateurs
	void setWindow(SDL_Window* pWindow);
	void setRenderer(SDL_Renderer* pRenderer);

protected:

};