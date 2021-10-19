#include "Affichage.h"

//GOAL  : Afficher
//INPUT : Toute les textures
//OUTPUT: Afficher render
void Affiche(CRenderer &render, CPlayer &player1, CPlayer &player2, CBall &ball, SDL_Rect &rectDestBorder, bool gameOn, CEndScreen& end)
{
    SDL_SetRenderDrawColor(render.getRenderer(), 255, 255, 255, 255);
    if (gameOn) {
        //Midlle line
        SDL_RenderFillRect(render.getRenderer(), &rectDestBorder);
        //Ball
        SDL_RenderCopy(render.getRenderer(), ball.getTexture(), NULL, ball.getRect());
    }
    else {
        //Show end screen
        SDL_RenderCopy(render.getRenderer(), end.getTexture(), NULL, end.getRect());
    }
    
    //Score
    SDL_RenderCopy(render.getRenderer(), player1.getTextScore(), NULL, player1.getRectScore());
    SDL_RenderCopy(render.getRenderer(), player2.getTextScore(), NULL, player2.getRectScore());

    //Player
    SDL_RenderCopy(render.getRenderer(), player1.getTexture(), NULL, player1.getRect());
    SDL_RenderCopy(render.getRenderer(), player2.getTexture(), NULL, player2.getRect());

    SDL_RenderPresent(render.getRenderer());
}
