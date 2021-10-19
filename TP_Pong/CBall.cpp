#include "CBall.h"
#include <math.h>

#define PI 3.14159265

//GOAL	: Set the variables at the creation of the object
//INPUT	: The width, height, the phase, x, y, angle, speedx, speedy and the Texture
//OUTPUT: The ball
CBall::CBall()
{
	this->speedx = 0;
	this->speedy = 0;
	rectB = { 0,0,0,0 };
	pTexture = NULL;
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
	this->rectB.w = width;
}

//GOAL	: Set height
//INPUT	: Height
//OUTPUT: Height of ball set
void CBall::setHeight(int height)
{
	this->rectB.h = height;
}

//GOAL	: Set x
//INPUT	: X
//OUTPUT: X of ball set
void CBall::setX(int x)
{
	this->rectB.x = x;
}

//GOAL	: Set y
//INPUT	: Y
//OUTPUT: Y of ball set
void CBall::setY(int y)
{
	this->rectB.y = y;
}

//GOAL	: Set texture
//INPUT	: Texture
//OUTPUT: Texture of ball set
void CBall::setTexture(SDL_Texture* texture)
{
	this->pTexture = texture;
}

void CBall::setRect(int x, int y, int width, int height)
{
	this->rectB.x = x;
	this->rectB.y = y;
	this->rectB.w = width;
	this->rectB.h = height;
}

//GOAL	: Set speedx
//INPUT	: Speedx
//OUTPUT: Speedx of ball set
void CBall::setSpeedx(int speedX)
{
	this->speedx = speedX;
}

//GOAL	: Set Speedy
//INPUT	: Speedy
//OUTPUT: Speedy of ball set
void CBall::setSpeedy(int speedY)
{
	this->speedy = speedY;
}

//GOAL	: Get width
//INPUT	: /
//OUTPUT: Width of ball
int CBall::getWidth()
{
	return this->rectB.w;
}

//GOAL	: Get height
//INPUT	: /
//OUTPUT: Height of ball
int CBall::getHeight()
{
	return this->rectB.h;
}

//GOAL	: Get x
//INPUT	: /
//OUTPUT: X of ball
int CBall::getX()
{
	return this->rectB.x;
}

//GOAL	: Get y
//INPUT	: /
//OUTPUT: Y of ball
int CBall::getY()
{
	return this->rectB.y;
}

SDL_Rect* CBall::getRect()
{
	return &this->rectB;
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
	this->rectB.y = static_cast<int>(WHEIGHT / static_cast<float>(2));
	if (winnerRound == 1) {
		this->rectB.x = static_cast<int> (WWIDTH / static_cast<float>(4));
	}
	else if (winnerRound == -1) {
		this->rectB.x = 3 * static_cast<int> (WWIDTH / static_cast<float>(4));
	}
	this->speedy = 0;
	this->speedx = MAXSPEEDBALL * winnerRound;
}

//GOAL	: Check the collision of the ball with his collision
//INPUT	: Height of the window, width of the window, rect of the player 1 and 2
//OUTPUT: New speed for the ball
void CBall::checkPos(int WHEIGHT, int WWIDTH, CPlayer& p1, CPlayer& p2, int MAXSPEEDBALL, CRenderer& render, TextStyle style)
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
	if (this->getX() <= p1.getX() + p1.getWidth() && this->getX() >= p1.getX() && this->getY() + this->getHeight() >= p1.getY() && this->getY() <= p1.getY() + p1.getHeight()) {
		if (this->speedx < 0) {
			//Change the direction of the ball direction depending of where the collision is happening
			//Get the distance between the collision and the middle of the player 1 (get a number between -75 and 75
			float relativeIntersect = (p1.getY() + (p1.getHeight() / static_cast<float>(2))) - (this->getY() + (this->getHeight() / static_cast<float>(2)));
			//Get a position normalized around -1 and 1
			float normalizedRelativeIntersectionY = (relativeIntersect / (p1.getHeight() / static_cast<float>(2)));
			//Calculate the bounce angle 
			float bounceAngle = static_cast<float>(normalizedRelativeIntersectionY * 4*PI/12);

			//Give the new speed for the ball
			this->speedx = static_cast<int>(MAXSPEEDBALL * cos(bounceAngle));
			this->speedy = static_cast<int>(MAXSPEEDBALL * -sin(bounceAngle));
		}
	}

	//Check if the ball is in collision with the player 2
	if (this->getX() + this->getWidth() >= p2.getX() && this->getX() <= p2.getX() + p2.getWidth() && this->getY() + this->getHeight() >= p2.getY() && this->getY() <= p2.getY() + p2.getHeight()) {
		if (this->speedx > 0) {
			//Change the direction of the ball direction depending of where the collision is happening
			//Get the distance between the collision and the middle of the player 1 (get a number between -75 and 75
			float relativeIntersect = (p2.getY() + (p2.getHeight() / static_cast<float>(2))) - (this->getY() + (this->getHeight() / static_cast<float>(2)));
			//Get a position normalized around -1 and 1
			float normalizedRelativeIntersectionY = (relativeIntersect / (p2.getHeight() / static_cast<float>(2)));
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
		p2.setTextScore(style, render.getRenderer());
		LaunchBall(MAXSPEEDBALL, WWIDTH, WHEIGHT, 1);
	}
	else if (this->getX() + this->getWidth() >= WWIDTH) {
		p1.setScore(p1.getScore() + 1);
		p1.setTextScore(style, render.getRenderer());
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
