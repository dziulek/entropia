#include "simulation.hpp"
#include <iostream>


void Simulation::drawBox(){

}

void Simulation::drawParticles(bool parallel){

    sf::CircleShape circle(radiusOfParticle);
    circle.setFillColor(sf::Color::Red);
    int j = 0;
    if(!parallel){
        for(auto i : this->enthropy->getParticles()){

            circle.setPosition(i.getPosition().x, i.getPosition().y);
            //std::cout<<i.getPosition().x<<" "<<i.getPosition().y<<" "<<j++<<std::endl;
            window->draw(circle);
        }
    }
    else {

    }
}

void Simulation::showView(){

    this->window->setView(this->simView);

    this->drawBox();
    drawParticles(false);

}