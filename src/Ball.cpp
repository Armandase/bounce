#include "../inc/Ball.hpp"

Ball::Ball(){
    std::random_device rd;
    std::mt19937 gen(rd());

    this->_coo.x = (gen() % SCREEN_WIDTH);
    this->_coo.y = (gen() % SCREEN_HEIGHT);
    this->_direction.x = (gen() % SPEED);
    this->_direction.y = (gen() % SPEED);
    this->_color.r = gen() % 256;
    this->_color.g = gen() % 256;
    this->_color.b = gen() % 256;
}

Ball::Ball(int x, int y, double dirX, double dirY){
    std::random_device rd;
    std::mt19937 gen(rd());
    this->_coo.x = x;
    this->_coo.y = y;
    this->_direction.x = dirX;
    this->_direction.y = dirY;
    this->_color.r = gen() % 256;
    this->_color.g = gen() % 256;
    this->_color.b = gen() % 256;
}

Ball::~Ball(){}

Ball::Ball(const Ball& copy){
    Ball::operator=(copy);
}

Ball& Ball::operator=(const Ball &ball){
    if (this != &ball){
        this->_coo = ball.getCoo();
        this->_direction = ball.getDirection();
    }
    return (*this);
}

void       modifyColor(color& ballColor){
    static int index = 0;

    if (ballColor.r > 0 && index == 0){
        --ballColor.r;
        if (ballColor.b < 255)
            ++ballColor.b;
        if (ballColor.r == 0)
            index = 1;

    }
    if (ballColor.g > 0 && index == 1){
        --ballColor.g;
        ++ballColor.r;
        if (ballColor.g == 0)
            index = 2;
    }
    if (ballColor.b > 0 && index == 2){
        --ballColor.b;
        ++ballColor.g;
        if (ballColor.b == 0)
            index = 0;
    }
}


void    Ball::handleBounce(point circle, float radius) {
    point dist = { this->_coo.x - circle.x, this->_coo.y - circle.y};
    double distance = sqrt(dist.x * dist.x + dist.y * dist.y);

    if (distance < radius - 1)
        return;
    modifyColor(this->_color);
    point normal = {dist.x / distance, dist.y / distance};
    point tangent = { -normal.y, normal.x};
    double normalSpeed = -(normal.x * this->_direction.x + normal.y * this->_direction.y);
    double tangentSpeed = tangent.x * this->_direction.x + tangent.y * this->_direction.y;
    this->_direction.x = normalSpeed * normal.x + tangentSpeed * tangent.x;
    this->_direction.y = normalSpeed * normal.y + tangentSpeed * tangent.y;
    
}

void    Ball::movement(const Ellipse& border){
    handleBounce(border.getCoo(), border.getMidRadius());

    this->_coo.x = this->_coo.x + this->_direction.x * FRAME;
    this->_coo.y = this->_coo.y + this->_direction.y * FRAME;
}

void    multiplePoint(SDL_Renderer *renderer, double x, double y){
    SDL_RenderDrawPoint(renderer, x, y);
    SDL_RenderDrawPoint(renderer, x, y+1);
    SDL_RenderDrawPoint(renderer, x+1, y+1);
    SDL_RenderDrawPoint(renderer, x+1, y);
}

void    Ball::renderItSelf(SDL_Renderer *renderer) const {
    SDL_SetRenderDrawColor(renderer, this->_color.r, this->_color.g, this->_color.b, 255);

    // SDL_RenderDrawPoint(renderer, this->_coo.x, this->_coo.y);
    // SDL_RenderDrawPoint(renderer, this->_coo.x, this->_coo.y+1);
    // SDL_RenderDrawPoint(renderer, this->_coo.x+1, this->_coo.y+1);
    // SDL_RenderDrawPoint(renderer, this->_coo.x+1, this->_coo.y);

    multiplePoint(renderer, this->_coo.x, this->_coo.y);
    multiplePoint(renderer, this->_coo.x, this->_coo.y+2);
    multiplePoint(renderer, this->_coo.x+2, this->_coo.y+2);
    multiplePoint(renderer, this->_coo.x+2, this->_coo.y);


}