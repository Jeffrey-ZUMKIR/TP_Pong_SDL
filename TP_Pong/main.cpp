#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdio.h>
#include <cstdlib>
#include "CPlayer.h"
#include "CBall.h"
#include <time.h> 
#include <iostream>
#include <string>

const int WWIDTH = 1200;
const int WHEIGHT = 600;
const int MAXSPEEDBALL = 10;
const int MAXSCORE = 10;

int main(int argc, char** argv)
{
    
    /* Initialisation */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }

    //Create window
    SDL_Window* pWindow = NULL;
    pWindow = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WWIDTH,
        WHEIGHT,
        SDL_WINDOW_SHOWN);

    if (!pWindow) {
        return -1;
    }

    //Create renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED;

    SDL_Renderer* pRenderer = SDL_CreateRenderer(pWindow, -1, render_flags);

    if (!pRenderer) {
        return -1;
    }

    //TTF_Init();
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    //Init player
    CPlayer player1(20, 150, 100, (WHEIGHT / 2) - 150 / 2, phase::IDLE);
    CPlayer player2(20, 150, WWIDTH-100-20, (WHEIGHT / 2) - (150 / 2), phase::IDLE);

    SDL_Surface* pSurfacePlayer = IMG_Load("./Assets/Player.png");

    if (pSurfacePlayer) {
        player1.setTexture(SDL_CreateTextureFromSurface(pRenderer, pSurfacePlayer));
        player2.setTexture(SDL_CreateTextureFromSurface(pRenderer, pSurfacePlayer));
    }
    
    SDL_FreeSurface(pSurfacePlayer);

    SDL_Rect rectDestP1 = { 0,0,0,0 };
    SDL_Rect rectDestP2 = { 0,0,0,0 };

    //Init ball
    CBall ball(20, 20, (WWIDTH / 2) - 10, (WHEIGHT / 2) - 10, 0, 0);

    SDL_Surface* pSurfaceBall = IMG_Load("./Assets/Ball.png");

    ball.setTexture(SDL_CreateTextureFromSurface(pRenderer, pSurfaceBall));

    SDL_FreeSurface(pSurfaceBall);

    SDL_Rect rectDestBall = { 0,0,0,0 };

    //Var for while of the game
    int close = 0;

    //Middle line
    SDL_Rect rectDestBorder = { (WWIDTH / 2) - 5,0,10,WHEIGHT };


    //Font and color for score
    TTF_Font* font = TTF_OpenFont("ArialCE.ttf", 50);

    SDL_Color color = { 255, 255, 255 };


    //Score Player 1
    SDL_Surface* pScore1;
    SDL_Texture* pTextSc1;

    SDL_Rect rectDestSc1 = { 0,0,0,0 };
    rectDestSc1.x = WWIDTH / 2 - 200;
    rectDestSc1.y = 10;
    rectDestSc1.w = 100;
    rectDestSc1.h = 100;

    //Get score player 1
    std::string str_score1 = std::to_string(player1.getScore());
    char* ch_score1 = const_cast<char*>(str_score1.c_str());

    //Set surface and texture of score 1
    pScore1 = TTF_RenderText_Solid(font, ch_score1, color);
    pTextSc1 = SDL_CreateTextureFromSurface(pRenderer, pScore1);


    //Score Player 2
    SDL_Surface* pScore2;
    SDL_Texture* pTextSc2;

    SDL_Rect rectDestSc2 = { 0,0,0,0 };
    rectDestSc2.x = WWIDTH/2 + 100;
    rectDestSc2.y = 10;
    rectDestSc2.w = 100;
    rectDestSc2.h = 100;

    //Get score player 2
    std::string str_score2 = std::to_string(player2.getScore());
    char* ch_score2 = const_cast<char*>(str_score2.c_str());

    //Set surface and texture of score 2
    pScore2 = TTF_RenderText_Solid(font, ch_score2, color);
    pTextSc2 = SDL_CreateTextureFromSurface(pRenderer, pScore2);

    //Bool to launch ball at the start of the round
    bool roundStart = true;

    //(-1 (player 1) or 1 (player 2)
    int winnerRound = 0;
    //for random beginner
    srand(time(NULL));
    int n_i;

    //Timer
    float timer = 3.f;
    std::string str_timer = std::to_string(timer+1);
    char* ch_timer = const_cast<char*>(str_timer.c_str());
    SDL_Surface* pTimer = TTF_RenderText_Solid(font, ch_timer, color);
    SDL_Texture* pTextTimer = SDL_CreateTextureFromSurface(pRenderer, pTimer);

    SDL_Rect rectDestTimer = { 0, 0, 0, 0 };
    rectDestTimer.x = WWIDTH / 2-25;
    rectDestTimer.y = WHEIGHT / 2-50;
    rectDestTimer.w = 50;
    rectDestTimer.h = 100;


    //Gameplay
    while (!close) {
        SDL_Event event;

        if (pRenderer) {
            //Background
            SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
            SDL_RenderClear(pRenderer);
            //Middle line
            if (!roundStart) {
                SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
                SDL_RenderFillRect(pRenderer,&rectDestBorder);
            }  
        }
        else {
            return -1;
        }

        if (!roundStart) {
            //Score 1
            str_score1 = std::to_string(player1.getScore());
            ch_score1 = const_cast<char*>(str_score1.c_str());

            //Set surface and texture of score 1
            pScore1 = TTF_RenderText_Solid(font, ch_score1, color);
            pTextSc1 = SDL_CreateTextureFromSurface(pRenderer, pScore1);

            //Score 2
            str_score2 = std::to_string(player2.getScore());
            ch_score2 = const_cast<char*>(str_score2.c_str());

            //Set surface and texture of score 2
            pScore2 = TTF_RenderText_Solid(font, ch_score2, color);
            pTextSc2 = SDL_CreateTextureFromSurface(pRenderer, pScore2);

            //Display score
            SDL_RenderCopy(pRenderer, pTextSc1, NULL, &rectDestSc1);
            SDL_RenderCopy(pRenderer, pTextSc2, NULL, &rectDestSc2);

            //Set player 1
            rectDestP1.x = player1.getX();
            rectDestP1.y = player1.getY();
            rectDestP1.w = player1.getWidth();
            rectDestP1.h = player1.getHeight();

            SDL_RenderCopy(pRenderer, player1.getTexture(), NULL, &rectDestP1);

            //Set player 2
            rectDestP2.x = player2.getX();
            rectDestP2.y = player2.getY();
            rectDestP2.w = player2.getWidth();
            rectDestP2.h = player2.getHeight();

            SDL_RenderCopy(pRenderer, player2.getTexture(), NULL, &rectDestP2);

            //Set ball
            rectDestBall.x = ball.getX();
            rectDestBall.y = ball.getY();
            rectDestBall.w = ball.getWidth();
            rectDestBall.h = ball.getHeight();

            SDL_RenderCopy(pRenderer, ball.getTexture(), NULL, &rectDestBall);
        }

        //Check for event
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            //Close window
            case SDL_QUIT:
                close = 1;
                break;
            //Input press
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                case SDLK_z:
                    player1.setPhase(phase::UP);
                    break;
                case SDLK_s:
                    player1.setPhase(phase::DOWN);
                    break;
                case SDLK_UP:
                    player2.setPhase(phase::UP);
                    break;
                case SDLK_DOWN:
                    player2.setPhase(phase::DOWN);
                    break;
                default:
                    break;
                }
                break;
            //Input release
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                case SDLK_z:
                case SDLK_s:
                    player1.setPhase(phase::IDLE);
                    break;
                case SDLK_UP:
                case SDLK_DOWN:
                    player2.setPhase(phase::IDLE);
                    break;
                }
                break;
            }
        }
        //Movement player
        player1.move(WHEIGHT);

        player2.move(WHEIGHT);

        //Check position of the ball for collision
        ball.checkPos(WHEIGHT, WWIDTH, rectDestP1, rectDestP2, player1, player2, MAXSPEEDBALL);

        //Launch ball at the beginning of the round
        if (roundStart) {
            //Show timer on screen
            player1.setScore(0);
            player2.setScore(0);
            timer -= 0.015;

            str_timer = std::to_string(static_cast<int>(timer + 1));
            ch_timer = const_cast<char*>(str_timer.c_str());
            pTimer = TTF_RenderText_Solid(font, ch_timer, color);
            pTextTimer = SDL_CreateTextureFromSurface(pRenderer, pTimer);

            SDL_RenderCopy(pRenderer, pTextTimer, NULL, &rectDestTimer);
            //when timer is = to 0, launch the ball and show the game
            if (timer <= 0.f) {
                n_i = (rand() % 2) + 1;
                switch (n_i) {
                case 1:
                    winnerRound = -1;
                    break;
                case 2:
                    winnerRound = 1;
                    break;
                }
                ball.LaunchBall(MAXSPEEDBALL, WWIDTH, WHEIGHT, winnerRound);
                timer = 3.f;
                roundStart = false;
            }
            
        }

        //Win condition
        if (player1.getScore() >= MAXSCORE || player2.getScore()>= MAXSCORE) {
            roundStart = true;
            player1.setScore(0);
            player1.setY((WHEIGHT / 2) - (150 / 2));
            player2.setScore(0);
            player2.setY((WHEIGHT / 2) - (150 / 2));
        }

        //Display
        SDL_RenderPresent(pRenderer);

        //60 FPS
        SDL_Delay(1000 / 60);
    }

    //Destroy Texture
    SDL_DestroyTexture(pTextSc1);
    SDL_DestroyTexture(pTextSc2);

    //Destroy Surface
    SDL_FreeSurface(pScore1);
    SDL_FreeSurface(pScore2);

    //Destroy renderer
    SDL_DestroyRenderer(pRenderer);

    //Destroy window
    SDL_DestroyWindow(pWindow);

    //Close TTF
    TTF_CloseFont(font);
    TTF_Quit();

    //Quit game
    SDL_Quit();

    return 0;
}