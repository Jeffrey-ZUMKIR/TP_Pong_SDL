#pragma once

#include "define.h"
#include "SDL.h"

class CPlayer {
private:
	int width;
	int height;
	int x, y;
	SDL_Texture* pTexture;

	phase actualPhase;

	int score;

public:
	//Constructeur
	CPlayer(int width = 0, int height = 0, int x = 0, int y = 0, phase actualPhase = phase::IDLE, SDL_Texture* pTexture = NULL, int score = 0);

	//Destructeur
	~CPlayer();

	//Mutateurs
	void setWidth(int);
	void setHeight(int);
	void setX(int);
	void setY(int);
	void setTexture(SDL_Texture*);
	void setPhase(phase);
	void setScore(int);

	//Ascesseurs
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	SDL_Texture* getTexture();
	phase getPhase();
	int getScore();

	//Movement
	void setPosition(int move, int WHEIGHT);
	void move(int WHEIGHT);

protected:

};