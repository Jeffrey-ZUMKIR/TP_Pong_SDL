#include "CBall.h"
#include <math.h>

#define PI 3.14159265

//GOAL	: Set the variables at the creation of the object
//INPUT	: The width, height, the phase, x, y, angle, speedx, speedy and the Texture
//OUTPUT: The ball
CBall::CBall(int width, int height, float x, float y, int speedx, int speedy, SDL_Texture* pTexture)
{
	this->width = width;
	this->height = height;
	this->x = x;
	this->y = y;
	this->speedx = speedx;
	this->speedy = speedy;
	this->pTexture = pTexture;
}

//GOAL	: Free the memory
//INPUT	: /
//OUTPUT: /
CBall::~CBall()
{
	SDL_DestroyTexture(this->pTexture);
}

//GOAL	: Set width
//INPUT	: Width
//OUTPUT: Width of ball set
void CBall::setWidth(int width)
{
	this->width = width;
}

//GOAL	: Set height
//INPUT	: Height
//OUTPUT: Height of ball set
void CBall::setHeight(int height)
{
	this->height = height;
}

//GOAL	: Set x
//INPUT	: X
//OUTPUT: X of ball set
void CBall::setX(float x)
{
	this->x = x;
}

//GOAL	: Set y
//INPUT	: Y
//OUTPUT: Y of ball set
void CBall::setY(float y)
{
	this->y = y;
}

//GOAL	: Set texture
//INPUT	: Texture
//OUTPUT: Texture of ball set
void CBall::setTexture(SDL_Texture* texture)
{
	this->pTexture = texture;
}

//GOAL	: Set speedx
//INPUT	: Speedx
//OUTPUT: Speedx of ball set
void CBall::setSpeedx(int)
{
}

//GOAL	: Set Speedy
//INPUT	: Speedy
//OUTPUT: Speedy of ball set
void CBall::setSpeedy(int)
{
}

//GOAL	: Get width
//INPUT	: /
//OUTPUT: Width of ball
int CBall::getWidth()
{
	return this->width;
}

//GOAL	: Get height
//INPUT	: /
//OUTPUT: Height of ball
int CBall::getHeight()
{
	return this->height;
}

//GOAL	: Get x
//INPUT	: /
//OUTPUT: X of ball
float CBall::getX()
{
	return this->x;
}

//GOAL	: Get y
//INPUT	: /
//OUTPUT: Y of ball
float CBall::getY()
{
	return this->y;
}

//GOAL	: Get texture
//INPUT	: /
//OUTPUT: Texture of ball
SDL_Texture* CBall::getTexture()
{
	return this->pTexture;
}

//GOAL	: Get Speedx
//INPUT	: /
//OUTPUT: Speedx of ball
int CBall::getSpeedx()
{
	return this->speedx;
}

//GOAL	: Get Speedy
//INPUT	: /
//OUTPUT: Speedy of ball
int CBall::getSpeedy()
{
	return this->speedy;
}

//GOAL	: Lanch the ball to the player who won the round
//INPUT	: The max speed of the ball, the width of the window and the winner of the last round (-1 (player 1) or 1 (player 2))
//OUTPUT: The speed of the ball and it's direction
void CBall::LaunchBall(int MAXSPEEDBALL, int WWIDTH, int WHEIGHT, int winnerRound)
{
	this->y = WHEIGHT / static_cast<float>(2);
	if (winnerRound == 1) {
		this->x = static_cast<int> (WWIDTH / static_cast<float>(4));
	}
	else if (winnerRound == -1) {
		this->x = 3 * static_cast<int> (WWIDTH / static_cast<float>(4));
	}
	this->speedy = 0;
	this->speedx = MAXSPEEDBALL * winnerRound;
}

//GOAL	: Check the collision of the ball with his collision
//INPUT	: Height of the window, width of the window, rect of the player 1 and 2
//OUTPUT: New speed for the ball
void CBall::checkPos(int WHEIGHT, int WWIDTH, SDL_Rect rectDestP1, SDL_Rect rectDestP2, CPlayer& p1, CPlayer& p2, int MAXSPEEDBALL)
{
	//Check if the ball is in collision with the top of the window
	if (this->getY() <= 0) {
		this->speedy = this->speedy *-1;
	}
	//Check if the ball is in collision with the bottom of the window
	else if (this->getY() + this->getHeight() >= WHEIGHT) {
		this->speedy = this->speedy * -1;
	}

	//Check if the ball is in collision with the player 1
	if (this->getX() <= rectDestP1.x + rectDestP1.w && this->getX() >= rectDestP1.x && this->getY() + this->getHeight() >= rectDestP1.y && this->getY() <= rectDestP1.y + rectDestP1.h) {
		if (this->speedx < 0) {
			//Change the direction of the ball direction depending of where the collision is happening
			//Get the distance between the collision and the middle of the player 1 (get a number between -75 and 75
			float relativeIntersect = (rectDestP1.y + (rectDestP1.h / static_cast<float>(2))) - (this->getY() + (this->getHeight() / static_cast<float>(2)));
			//Get a position normalized around -1 and 1
			float normalizedRelativeIntersectionY = (relativeIntersect / (rectDestP1.h / static_cast<float>(2)));
			//Calculate the bounce angle 
			float bounceAngle = static_cast<float>(normalizedRelativeIntersectionY * 4*PI/12);

			//Give the new speed for the ball
			this->speedx = static_cast<int>(MAXSPEEDBALL * cos(bounceAngle));
			this->speedy = static_cast<int>(MAXSPEEDBALL * -sin(bounceAngle));
		}
	}

	//Check if the ball is in collision with the player 2
	if (this->getX() + this->getWidth() >= rectDestP2.x && this->getX() <= rectDestP2.x + rectDestP2.w && this->getY() + this->getHeight() >= rectDestP2.y && this->getY() <= rectDestP2.y + rectDestP2.h) {
		if (this->speedx > 0) {
			//Change the direction of the ball direction depending of where the collision is happening
			//Get the distance between the collision and the middle of the player 1 (get a number between -75 and 75
			float relativeIntersect = (rectDestP2.y + (rectDestP2.h / static_cast<float>(2))) - (this->getY() + (this->getHeight() / static_cast<float>(2)));
			//Get a position normalized around -1 and 1
			float normalizedRelativeIntersectionY = (relativeIntersect / (rectDestP2.h / static_cast<float>(2)));
			//Calculate the bounce angle 
			float bounceAngle = static_cast<float>(normalizedRelativeIntersectionY * 4 * PI / 12);

			//Give the new speed for the ball
			this->speedx = static_cast<int>(MAXSPEEDBALL * -cos(bounceAngle));
			this->speedy = static_cast<int>(MAXSPEEDBALL * -sin(bounceAngle));
		}
	}

	//Call the function move the ball to change is position for the next frame
	if (this->getX() <= 0) {
		p2.setScore(p2.getScore() + 1);
		LaunchBall(MAXSPEEDBALL, WWIDTH, WHEIGHT, 1);
	}
	else if (this->getX() + this->getWidth() >= WWIDTH) {
		p1.setScore(p1.getScore() + 1);
		LaunchBall(MAXSPEEDBALL, WWIDTH, WHEIGHT, -1);
	}
	this->moveBall();
}

//GOAL	: Change the position of the ball for the next frame
//INPUT	: /
//OUTPUT: New position
void CBall::moveBall()
{
	this->setX(this->getX() + this->speedx);
	this->setY(this->getY() + this->speedy);
}
