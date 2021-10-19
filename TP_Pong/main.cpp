#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <stdio.h>
#include <cstdlib>
#include "CPlayer.h"
#include "CBall.h"
//#include <time.h> 
//#include <iostream>
//#include <string>
#include "CRenderer.h"
#include "Init.h"
#include "CText.h"
#include "Event.h"
#include "Affichage.h"
#include "Update.h"
#include "CEndScreen.h"

const int WWIDTH = 1200;
const int WHEIGHT = 600;
const int MAXSPEEDBALL = 10;
const int MAXSCORE = 2;

int main(int argc, char** argv)
{
    
    /* Initialisation */
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stdout, "Échec de l'initialisation de la SDL (%s)\n", SDL_GetError());
        return -1;
    }
    CRenderer render;

    CPlayer player1;
    CPlayer player2;

    CBall ball;

    TextStyle style;

    CEndScreen end;

    Initialisation(WWIDTH, WHEIGHT, render, player1, player2, ball, style, end);

    if (!render.getWindow()) {
        return -1;
    }

    if (!render.getRenderer()) {
        return -1;
    }

    //TTF_Init();
    if (TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }
    
    //Var for while of the game
    int close = 0;

    //Middle line
    SDL_Rect rectDestBorder = { (WWIDTH / 2) - 5,0,10,WHEIGHT };

    //Bool to launch ball at the start of the round
    bool roundStart = true;

    bool gameOn = true;

    //(-1 (player 1) or 1 (player 2)
    int winnerRound = 0;



    //Gameplay
    while (!close) {
        SDL_Event event;
        //Background
        SDL_SetRenderDrawColor(render.getRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(render.getRenderer());

        HandleEvent(event, close, player1, player2, roundStart, gameOn);
        if (gameOn) {
            Update(player1, player2, ball, WWIDTH, WHEIGHT, MAXSPEEDBALL, style, render, roundStart, winnerRound, gameOn, MAXSCORE);
        }
        //Display
        Affiche(render, player1, player2, ball, rectDestBorder, gameOn, end);

        //60 FPS
        SDL_Delay(1000 / 60);  
    }

    /*//Destroy Texture
    SDL_DestroyTexture(pTextSc1);
    SDL_DestroyTexture(pTextSc2);*/

    /*//Destroy Surface
    SDL_FreeSurface(pScore1);
    SDL_FreeSurface(pScore2);*/

    /*//Destroy renderer
    SDL_DestroyRenderer(render.getRenderer());

    //Destroy window
    SDL_DestroyWindow(pWindow);*/

    //Close TTF
    TTF_CloseFont(style.font);
    TTF_Quit();

    //Quit game
    SDL_Quit();

    return 0;
}