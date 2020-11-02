#include "simulation.hpp"
#include "renderer.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


void Simulation::drawBox(){
    sf::Vector2f viewSize = this->simView.getSize();

    sf::Vector2f center = this->simView.getCenter();

    sf::Vector2f leftUp = {center.x - viewSize.x/2, center.y - viewSize.y/2};

    sf::Vertex lineStrip[5] ={
        sf::Vertex(sf::Vector2f(leftUp.x + rim, leftUp.y + rim)),
        sf::Vertex(sf::Vector2f(leftUp.x + rim, viewSize.y - rim + leftUp.y)),
        sf::Vertex(sf::Vector2f(viewSize.x - rim + leftUp.x, viewSize.y - rim + leftUp.y)),
        sf::Vertex(sf::Vector2f(viewSize.x - rim + leftUp.x, rim + leftUp.y)),
        sf::Vertex(sf::Vector2f(rim + leftUp.x, rim + leftUp.y))
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
    circle.setFillColor(sf::Color::White);
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

void Simulation::keyCallback(sf::Event event){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

                this->simView.zoom(1.1);
                std::cout<<this->simView.getSize().x<<" "<< this->simView.getSize().y<<std::endl;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                
                //this->simView.move(sf::Vector2f(-0.1 * this->simView.getSize().x, -0.1 * this->simView.getSize().y));
                this->simView.zoom(0.9);
                
                std::cout<<this->simView.getSize().x<<" "<< this->simView.getSize().y<<std::endl;

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                this->simView.move(sf::Vector2f(0,-10));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                this->simView.move(sf::Vector2f(0,10));
           }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                this->simView.move(sf::Vector2f(10,0));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

                this->simView.move(sf::Vector2f(-10,0));
            }
}