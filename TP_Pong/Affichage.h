#pragma once
#include "CRenderer.h"
#include "CPlayer.h"
#include "CBall.h"
#include "CEndScreen.h"

void Affiche(CRenderer &render, CPlayer &player1, CPlayer &player2, CBall &ball, SDL_Rect &rectDestBorder, bool gameOn, CEndScreen &end);