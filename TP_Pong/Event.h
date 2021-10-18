#pragma once
#include "SDL.h"
#include "CPlayer.h"

void HandleEvent(SDL_Event &event, int& close, CPlayer &player1, CPlayer &player2);