#ifndef SIMULATION_HPP
# define SIMULATION_HPP

# include <SDL.h>
# include <exception>
# include <iostream>
# include <vector>
# include <SDL_ttf.h>
# include <SDL_image.h>

# define SCREEN_HEIGHT 720
# define SCREEN_WIDTH 1080
# define RED 255
# define GREEN 255
# define BLUE 255 

typedef struct t_point {
    double  x;
    double  y;
} point;

typedef struct t_color {
    int  r;
    int  g;
    int  b;
} color;

void    SDL_Error(const std::string &mess, SDL_Window *window, SDL_Renderer *renderer);
void    render_empty(SDL_Renderer *renderer);
void    drawCircle(point centre, int radius, SDL_Renderer *renderer);
void    drawEmptyCircle(point centre, point nextCentre, int nextRadius, int radius, SDL_Renderer *renderer);


#endif // !SIMULATION_HPP