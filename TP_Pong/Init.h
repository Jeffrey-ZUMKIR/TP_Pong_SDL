#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "CRenderer.h"
#include "CPlayer.h"
#include "CBall.h"
#include "CText.h"
#include <string>
#include "CEndScreen.h"
#include "Affichage.h"

void Initialisation(int WWIDTH, int WHEIGHT, CRenderer &render, CPlayer &player1, CPlayer &player2, CBall &ball, TextStyle &style, CEndScreen &end, TextureManager &m_textureManager);