#include "Init.h"

//GOAL  : Initialiser chaque object
//INPUT : All the object
//OUTPUT: All the object initialize
void Initialisation(int WWIDTH, int WHEIGHT, CRenderer &render, CPlayer &player1, CPlayer &player2, CBall& ball, TextStyle &style, CEndScreen &end)
{
    //Set window
    render.setWindow(SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WWIDTH,
        WHEIGHT,
        SDL_WINDOW_SHOWN));

    //Set render
    if (render.getWindow()) {
        Uint32 render_flags = SDL_RENDERER_ACCELERATED;
        render.setRenderer(SDL_CreateRenderer(render.getWindow(), -1, render_flags));
    }
    else {
        render.setRenderer (NULL);
    }

    TTF_Init();

    //Set style text
    style.font = TTF_OpenFont("ArialCE.ttf", 50);

    style.color = { 255, 255, 255 };

    //Set player
    SDL_Surface* pSurfacePlayer = IMG_Load("./Assets/Player.png");

    player1.setRect(100, (WHEIGHT / 2) - (150 / 2), 20, 150);
    player1.setPhase(phase::IDLE);
    player1.setScore(0);
    player1.setTexture(SDL_CreateTextureFromSurface(render.getRenderer(), pSurfacePlayer));
    player1.setTextScore(style, render.getRenderer());
    player1.setRectScore((WWIDTH / 2) - 200, 10, 100, 100);

    player2.setRect(WWIDTH - 100 - 20, (WHEIGHT / 2) - (150 / 2), 20, 150);
    player2.setPhase(phase::IDLE);
    player2.setScore(0);
    player2.setTexture(SDL_CreateTextureFromSurface(render.getRenderer(), pSurfacePlayer));
    player2.setTextScore(style, render.getRenderer());
    player2.setRectScore(WWIDTH / 2 + 100, 10, 100, 100);

    SDL_FreeSurface(pSurfacePlayer);

    //Set ball
    SDL_Surface* pSurfaceBall = IMG_Load("./Assets/Ball.png");

    ball.setRect(WWIDTH / 2 - 10, WHEIGHT / 2 - 10, 20, 20);
    ball.setSpeedx(0);
    ball.setSpeedy(0);
    ball.setTexture(SDL_CreateTextureFromSurface(render.getRenderer(), pSurfaceBall));

    SDL_FreeSurface(pSurfaceBall);

    //Set endgame
    std::string str_restart = "Press space to play again";
    char* ch_restart = const_cast<char*>(str_restart.c_str());
    SDL_Surface* pRestart = TTF_RenderText_Solid(style.font, ch_restart, style.color);
    end.setTexture(SDL_CreateTextureFromSurface(render.getRenderer(), pRestart));

    end.setRect((WWIDTH / 2) - 250, (WHEIGHT / 2) - 50, 500, 100);

    SDL_FreeSurface(pRestart);
}
