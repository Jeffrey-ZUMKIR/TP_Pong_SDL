#pragma once
#include "CRenderer.h"
#include "CPlayer.h"
#include "CBall.h"
#include "CEndScreen.h"
#include <map>
#include <string>
#include "CText.h"

using namespace std;



class TextureManager {
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
public:
	TextureManager();
	~TextureManager();

	bool loadPNG(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	bool loadTEXT(std::string fileName, std::string id, SDL_Renderer* pRenderer, TextStyle style);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void render(CPlayer &player1, CPlayer &player2, CBall &ball, SDL_Renderer* pRenderer, TextStyle style, bool gameOn, CEndScreen& end, SDL_Rect rectDestBorder);
protected:

};



