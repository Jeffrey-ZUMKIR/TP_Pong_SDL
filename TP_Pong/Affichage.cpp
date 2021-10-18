#include "Affichage.h"

void Affiche(CRenderer &render, CPlayer &player1, CPlayer &player2, CBall &ball, SDL_Rect &rectDestBorder)
{

    

    SDL_SetRenderDrawColor(render.getRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(render.getRenderer(), &rectDestBorder);

    SDL_RenderCopy(render.getRenderer(), player1.getTextScore(), NULL, player1.getRectScore());
    SDL_RenderCopy(render.getRenderer(), player2.getTextScore(), NULL, player2.getRectScore());

    SDL_RenderCopy(render.getRenderer(), player1.getTexture(), NULL, player1.getRect());
    SDL_RenderCopy(render.getRenderer(), player2.getTexture(), NULL, player2.getRect());

    SDL_RenderCopy(render.getRenderer(), ball.getTexture(), NULL, ball.getRect());

    SDL_RenderPresent(render.getRenderer());
}
