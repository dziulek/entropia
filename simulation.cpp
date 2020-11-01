#include "simulation.hpp"
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

    if(this->enthropy->getState() == false){

        sf::Vertex startBox[5] ={
            sf::Vertex(sf::Vector2f(rim , rim)),
            sf::Vertex(sf::Vector2f(rim, defaultSizeOfStartBox.second + rim)),
            sf::Vertex(sf::Vector2f(defaultSizeOfStartBox.first + rim, defaultSizeOfStartBox.second + rim)),
            sf::Vertex(sf::Vector2f(defaultSizeOfStartBox.first + rim, rim)),
            sf::Vertex(sf::Vector2f(rim, rim))
        };

        this->window->draw(startBox, 5, sf::LineStrip);
    }
}

void Simulation::drawParticles(bool parallel){

    sf::CircleShape circle(this->enthropy->getRadiusOfParticle());

    circle.setOrigin(sf::Vector2f(this->enthropy->getRadiusOfParticle(), this->enthropy->getRadiusOfParticle()));
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