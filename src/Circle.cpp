#include "../inc/Circle.hpp"
#include <random>
#include <cmath>

Circle::Circle(){
    std::random_device rd;
    std::mt19937 gen(rd());

    this->_radius = (gen() % MAX_RADIUS) + 1;
    this->_coo.x = (gen() % SCREEN_WIDTH);
    this->_coo.y = (gen() % SCREEN_HEIGHT);
}

Circle::Circle(int x, int y, double radius){
    this->_coo.x = x;
    this->_coo.y = y;
    this->_radius = radius;
}

Circle::~Circle(){}

Circle::Circle(const Circle& copy){
    Circle::operator=(copy);
}

Circle& Circle::operator=(const Circle &circle){
    if (this != &circle){
        this->_coo = circle.getCoo();
        this->_radius = circle.getRadius();
    }
    return (*this);
}

void    Circle::renderItSelf(SDL_Renderer *renderer) const {
    drawCircle(this->_coo, this->_radius, renderer);
}