#pragma once

#include "SDL.h"
#include "CPlayer.h"
#include "CRenderer.h"
#include "CText.h"

class CBall {
private:
	SDL_Rect rectB;

	int speedx, speedy;

	SDL_Texture* pTexture;
public:
	//Constructeur
	CBall();

	//Destructeur
	~CBall();

	//Mutateurs
	void setWidth(int);
	void setHeight(int);
	void setX(int);
	void setY(int);
	void setRect(int x, int y, int width, int height);
	void setSpeedx(int);
	void setSpeedy(int);
	void setTexture(SDL_Texture*);

	//Ascesseurs
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	SDL_Rect* getRect();
	int getSpeedx();
	int getSpeedy();
	SDL_Texture* getTexture();

	//Movement
	void LaunchBall(int MAXSPEEDBALL, int WWIDTH, int WHEIGHT, int winnerRound);
	void moveBall();
	void checkPos(int WHEIGHT, int WWIDTH, CPlayer& p1, CPlayer& p2, int MAXSPEEDBALL, CRenderer &render, TextStyle style);


protected:

};