#include "CRenderer.h"

CRenderer::CRenderer()
{
    this->pWindow = NULL;
    this->pRenderer = NULL;
    /*this->pWindow = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WWIDTH,
        WHEIGHT,
        SDL_WINDOW_SHOWN);

    if (this->pWindow) {
        Uint32 render_flags = SDL_RENDERER_ACCELERATED;
        this->pRenderer = SDL_CreateRenderer(pWindow, -1, render_flags);
    }
    else {
        this->pRenderer = NULL;
    }*/
}

CRenderer::~CRenderer()
{
    //Destroy renderer
    SDL_DestroyRenderer(pRenderer);

    //Destroy window
    SDL_DestroyWindow(pWindow);
}

SDL_Window* CRenderer::getWindow()
{
    return this->pWindow;
}

SDL_Renderer* CRenderer::getRenderer()
{
    return this->pRenderer;
}

void CRenderer::setWindow(SDL_Window* pWindow)
{
    this->pWindow = pWindow;
}

void CRenderer::setRenderer(SDL_Renderer* pRenderer)
{
    this->pRenderer = pRenderer;
}
