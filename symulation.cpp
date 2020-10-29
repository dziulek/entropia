#include "symulation.hpp"
#include "constants.hpp"


Symulation::Symulation(sf::RenderWindow &win){
    this->window = &win;
    bool fun = enthropy.setStartPos();
}

void drawBox(){

}

void Symulation::drawParticles(bool parallel = false){

    sf::CircleShape circle(radiusOfParticle);

    if(!parallel){
        for(auto i : this->enthropy.getParticles()){

            circle.setPosition(i.getPosition().x, i.getPosition().y);
            window->draw(circle);
        }
    }
    else {

    }
}

void Symulation::showView(sf::View &view){

    this->window->setView(view);

    drawBox();
    drawParticles(false);


}