
#include "../inc/Ball.hpp"
#include "../inc/Circle.hpp"

int main(void){
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        SDL_Error("Failed to init SDL:", NULL, NULL);
    if (TTF_Init() == -1)
        SDL_Error("Failed to init TTF:", NULL, NULL);
    
    SDL_Window *window = SDL_CreateWindow("Bounce", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
        SDL_Error("Failed to create SDL window:", window, NULL);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        SDL_Error("Failed to create SDL renderer:", window, renderer);

    render_empty(renderer);

    bool quit = false;
    SDL_Event e;

    Circle toRender(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, MAX_RADIUS);
    // toRender.renderItSelf(renderer);

    //line
    // Ball line(SCREEN_WIDTH / 2 + 1 , SCREEN_HEIGHT / 2 + 1, 0.5, -0.5);
    //star
    // Ball line(SCREEN_WIDTH / 2 - (MAX_MID/2 - 1) , SCREEN_HEIGHT / 2 +  (MAX_MID/2 - 1), -4.5, 1.6);
    //square
    // Ball line(SCREEN_WIDTH / 2 - (MAX_MID/2 - 1) , SCREEN_HEIGHT / 2 +  (MAX_MID/2 - 1), 1, 1);
    //pentagramme
    // Ball line(SCREEN_WIDTH / 2 - (MAX_MID / 2) , SCREEN_HEIGHT / 2 +  (MAX_MID / 2), -5, 2.5);
    //triangle
    Ball line(SCREEN_WIDTH / 2 - (MAX_RADIUS/2) , SCREEN_HEIGHT / 2 -  (MAX_RADIUS/2), 1, 0);

    // Ball line(SCREEN_WIDTH / 2 - MAX_MID / 2 , SCREEN_HEIGHT / 2 +  MAX_MID / 2, -5, 2.5);

    line.setColor(color {255, 255, 255});
    while (!quit)
    {

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                quit = true;
            else if (e.type == SDL_KEYDOWN)
            {
                if (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_q)
                    quit = true;
            }
        }
        line.movement(toRender);
        line.renderItSelf(renderer);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}