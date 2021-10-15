#pragma once

#include "SDL.h"
#include "CPlayer.h"

class CBall {
private:
	int width;
	int height;
	float x, y;

	int speedx, speedy;

	SDL_Texture* pTexture;
public:
	//Constructeur
	CBall(int width = 0, int height = 0, float x = 0, float y = 0, int speedx = -4, int speedy = -4, SDL_Texture* pTexture = NULL);

	//Destructeur
	~CBall();

	//Mutateurs
	void setWidth(int);
	void setHeight(int);
	void setX(float);
	void setY(float);
	void setSpeedx(int);
	void setSpeedy(int);
	void setTexture(SDL_Texture*);

	//Ascesseurs
	int getWidth();
	int getHeight();
	float getX();
	float getY();
	int getSpeedx();
	int getSpeedy();
	SDL_Texture* getTexture();

	//Movement
	void LaunchBall(int MAXSPEEDBALL, int WWIDTH, int WHEIGHT, int winnerRound);
	void moveBall();
	void checkPos(int WHEIGHT, int WWIDTH, SDL_Rect rectDestP1, SDL_Rect rectDestP2, CPlayer& p1, CPlayer& p2, int MAXSPEEDBALL);


protected:

};