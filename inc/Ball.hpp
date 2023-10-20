#ifndef BALL_HPP
# define BALL_HPP

# include "header.hpp"
# include "Circle.hpp"
# include <random>
# include <cmath>

# define SPEED 10
# define FRAME 0.8

class Ball
{
    public:
        Ball();
        Ball(int x, int y, double dirX, double dirY);
        ~Ball();

        void    setColor(color rgb) { this->_color = rgb; };

        point  getCoo() const { return(this->_coo); } ;
        point  getDirection() const { return (this->_direction); };

        Ball(const Ball& copy);
		Ball& operator=(const Ball &ball);

        void    renderItSelf(SDL_Renderer *renderer) const;
        void    movement(const Circle& border);

    private:
        point   _coo;
        point   _direction;
        color   _color;

        void    handleBounce(point circle, float radius);
};

#endif