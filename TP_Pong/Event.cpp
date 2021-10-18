#include "Event.h"

void HandleEvent(SDL_Event& event, int &close, CPlayer &player1, CPlayer &player2)
{
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
}
