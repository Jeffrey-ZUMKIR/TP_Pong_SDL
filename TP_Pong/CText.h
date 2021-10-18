#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

typedef struct TextStyle {
	TTF_Font* font;
	SDL_Color color;
}TextStyle;