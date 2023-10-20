#ifndef ELLIPSE_HPP
# define ELLIPSE_HPP

# include "header.hpp"
# include <array>

# define MAX_MID ((SCREEN_HEIGHT / 2)- 20)
# define MAX_SIDE 100

class Ellipse
{
    public:
        Ellipse();
        Ellipse(int x, int y, double midRadius, double sideRadius);
        ~Ellipse();

        point  getCoo() const { return(this->_coo); } ;
        double  getMidRadius() const { return (this->_midRadius); };
        double  getSideRadius() const { return (this->_sideRadius); };

        Ellipse(const Ellipse& copy);
		Ellipse& operator=(const Ellipse &Ellipse);

        void    renderItSelf(SDL_Renderer *renderer) const;
        void    movement(const Ellipse& border);

    private:
        point   _coo;
        double _midRadius, _sideRadius;

};

#endif