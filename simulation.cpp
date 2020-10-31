#include "simulation.hpp"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


void Simulation::drawBox(){
    sf::Vector2f viewSize = this->simView.getSize();

    sf::Vertex lineStrip[5] ={
        sf::Vertex(sf::Vector2f(rim, rim)),
        sf::Vertex(sf::Vector2f(rim, viewSize.y - rim)),
        sf::Vertex(sf::Vector2f(viewSize.x - rim, viewSize.y - rim)),
        sf::Vertex(sf::Vector2f(viewSize.x - rim, rim)),
        sf::Vertex(sf::Vector2f(rim, rim))
    };

    this->window->draw(lineStrip, 5, sf::LineStrip);
}

void Simulation::drawParticles(bool parallel){

    sf::CircleShape circle(radiusOfParticle);
    circle.setFillColor(sf::Color::Red);
    int j = 0;
    if(!parallel){
        for(auto i : this->enthropy->getParticles()){

            circle.setPosition(i.getPosition().x, i.getPosition().y);
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