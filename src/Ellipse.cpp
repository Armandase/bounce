#include "../inc/Ellipse.hpp"
#include <random>
#include <cmath>

Ellipse::Ellipse(){
    std::random_device rd;
    std::mt19937 gen(rd());

    this->_midRadius = (gen() % MAX_MID) + 1;
    this->_sideRadius = (gen() % MAX_SIDE) + 1;
    this->_coo.x = (gen() % SCREEN_WIDTH);
    this->_coo.y = (gen() % SCREEN_HEIGHT);
}

Ellipse::Ellipse(int x, int y, double midRadius, double sideRadius){
    this->_coo.x = x;
    this->_coo.y = y;
    this->_midRadius = midRadius;
    this->_sideRadius = sideRadius;
}

Ellipse::~Ellipse(){}

Ellipse::Ellipse(const Ellipse& copy){
    Ellipse::operator=(copy);
}

Ellipse& Ellipse::operator=(const Ellipse &ellipse){
    if (this != &ellipse){
        this->_coo = ellipse.getCoo();
        this->_midRadius = ellipse.getMidRadius();
        this->_sideRadius = ellipse.getSideRadius();
    }
    return (*this);
}

void    Ellipse::renderItSelf(SDL_Renderer *renderer) const {
    drawCircle(this->_coo, this->_midRadius, renderer);
}