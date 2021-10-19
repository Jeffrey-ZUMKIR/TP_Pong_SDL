#include "Affichage.h"
#include <string>

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
}

bool TextureManager::loadPNG(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
    SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
    if (pTempSurface == 0)
    {
        return false;
    }
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    // everything went ok, add the texture to our list
    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    // reaching here means something went wrong
    return false;
}

bool TextureManager::loadTEXT(std::string fileName, std::string id, SDL_Renderer* pRenderer, TextStyle style)
{
    SDL_Surface* pTempSurface = TTF_RenderText_Solid(style.font, fileName.c_str(), style.color);
    if (pTempSurface == 0)
    {
        return false;
    }
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
    SDL_FreeSurface(pTempSurface);
    // everything went ok, add the texture to our list
    if (pTexture != 0)
    {
        m_textureMap[id] = pTexture;
        return true;
    }
    // reaching here means something went wrong
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    SDL_RenderCopyEx(pRenderer, m_textureMap[id], NULL, &destRect, 0, 0, flip);
}

void TextureManager::render(CPlayer &player1, CPlayer &player2, CBall &ball, SDL_Renderer* pRenderer, TextStyle style, bool gameOn, CEndScreen& end, SDL_Rect rectDestBorder)
{
    
    draw("player", player1.getX(), player1.getY(), player1.getWidth(), player1.getHeight(), pRenderer);
    draw("player", player2.getX(), player2.getY(), player2.getWidth(), player2.getHeight(), pRenderer);
    draw("ball", ball.getX(), ball.getY(), ball.getWidth(), ball.getHeight(), pRenderer);
    loadTEXT(to_string(player1.getScore()), "score1", pRenderer, style);
    loadTEXT(to_string(player2.getScore()), "score2", pRenderer, style);
    draw("score1", player1.getRectScore()->x, player1.getRectScore()->y, player1.getRectScore()->w, player1.getRectScore()->h, pRenderer);
    draw("score2", player2.getRectScore()->x, player2.getRectScore()->y, player2.getRectScore()->w, player2.getRectScore()->h, pRenderer);
    if (gameOn) {
        SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);
        SDL_RenderFillRect(pRenderer, &rectDestBorder);
    }
    else {
        draw("endGame", end.getRect()->x, end.getRect()->y, end.getRect()->w, end.getRect()->h, pRenderer);
    }

    SDL_RenderPresent(pRenderer);
}
