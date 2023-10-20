#include "../inc/header.hpp"

void    render_empty(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void SDL_Error(const std::string &mess, SDL_Window *window, SDL_Renderer *renderer) {
    SDL_Log((mess + " %s").c_str(), SDL_GetError());
    if (renderer)
        SDL_DestroyRenderer(renderer);
    if (window) {
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    exit(1);
}

void drawCircle(point centre, int radius, SDL_Renderer *renderer){
    int x = radius - 1;
    int y = 0;
    int dx = 1, dy = 1;
    int err = dx - (radius * 2);

    while (x >= y){
        SDL_SetRenderDrawColor(renderer, RED, GREEN, BLUE, 255);


        SDL_RenderDrawPoint(renderer, centre.x + x, centre.y - y);
        SDL_RenderDrawPoint(renderer, centre.x + x, centre.y + y);
        SDL_RenderDrawPoint(renderer, centre.x - x, centre.y - y);
        SDL_RenderDrawPoint(renderer, centre.x - x, centre.y + y);
        SDL_RenderDrawPoint(renderer, centre.x + y, centre.y - x);
        SDL_RenderDrawPoint(renderer, centre.x + y, centre.y + x);
        SDL_RenderDrawPoint(renderer, centre.x - y, centre.y - x);
        SDL_RenderDrawPoint(renderer, centre.x - y, centre.y + x);
        if (err <= 0){
            y++;
            err += dy;
            dy += 2;
        }
        if (err > 0) {
            x--;
            dx += 2;
            err += dx - (radius * 2);
        }
    }
    SDL_RenderPresent(renderer);
}