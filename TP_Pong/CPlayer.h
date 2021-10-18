#pragma once

#include "define.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "CText.h"


class CPlayer {
private:
	/*int width;
	int height;
	int x, y;*/
	//rect myRect;
	SDL_Rect rectP;
	SDL_Texture* pTexture;

	phase actualPhase;

	int score;
	SDL_Texture* pTextScore;
	SDL_Rect rectScore;

public:
	//Constructeur
	CPlayer();

	//Destructeur
	~CPlayer();

	//Mutateurs
	void setWidth(int);
	void setHeight(int);
	void setX(int);
	void setY(int);
	void setRect(int x, int y, int width, int height);
	void setTexture(SDL_Texture*);
	void setPhase(phase);
	void setScore(int);
	void setTextScore(TextStyle style, SDL_Renderer* render);
	void setRectScore(int x, int y, int width, int height);

	//Ascesseurs
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	SDL_Rect* getRect();
	SDL_Texture* getTexture();
	phase getPhase();
	int getScore();
	SDL_Texture* getTextScore();
	SDL_Rect* getRectScore();

	//Movement
	void setPosition(int move, int WHEIGHT);
	void move(int WHEIGHT);

protected:

};