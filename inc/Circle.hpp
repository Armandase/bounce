#ifndef CIRCLE_HPP
# define CIRCLE_HPP

# include "header.hpp"
# include <array>

# define MAX_RADIUS ((SCREEN_HEIGHT / 2)- 20)

class Circle
{
    public:
        Circle();
        Circle(int x, int y, double radius);
        ~Circle();

        point  getCoo() const { return(this->_coo); } ;
        double  getRadius() const { return (this->_radius); };

        Circle(const Circle& copy);
		Circle& operator=(const Circle &circle);

        void    renderItSelf(SDL_Renderer *renderer) const;
        void    movement(const Circle& border);

    private:
        point   _coo;
        double _radius;

};

#endif