#include "simulation.hpp"
#include "renderer.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"


void Simulation::drawBox(){
    sf::Vector2f viewSize = this->simView->getSize();

    sf::Vector2f center = this->simView->getCenter();

    sf::Vector2f leftUp = {center.x - viewSize.x/2, center.y - viewSize.y/2};


    sf::Vertex lineStrip[5] ={
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(0, defaultSizeOfStartBox.second * 4 )),
        sf::Vertex(sf::Vector2f(defaultSizeOfStartBox.first * 4 , defaultSizeOfStartBox.second * 4)),
        sf::Vertex(sf::Vector2f( defaultSizeOfStartBox.first * 4, 0)),
        sf::Vertex(sf::Vector2f(0, 0))
    };

    sf::RectangleShape bigSquare = sf::RectangleShape(sf::Vector2f(4 * defaultSizeOfStartBox.first, 4 * defaultSizeOfStartBox.second));

    bigSquare.setFillColor(sf::Color(sf::Color(150, 200, 100, 255)));

    this->window->draw(bigSquare);

    this->window->draw(lineStrip, 5, sf::LineStrip);

    if(this->enthropy->getState() == false){

        sf::Vertex startBox[5] ={
            sf::Vertex(sf::Vector2f(0 , 0)),
            sf::Vertex(sf::Vector2f(0, defaultSizeOfStartBox.second)),
            sf::Vertex(sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second)),
            sf::Vertex(sf::Vector2f(defaultSizeOfStartBox.first, 0)),
            sf::Vertex(sf::Vector2f(0, 0))
        };



        this->window->draw(startBox, 5, sf::LineStrip);

        sf::RectangleShape squareXd = sf::RectangleShape(sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second));
        
        squareXd.setFillColor(sf::Color(100, 100, 100, 255));
        this->window->draw(squareXd);
    }
}

void Simulation::drawParticles(bool parallel){

    sf::CircleShape circle(this->enthropy->getRadiusOfParticle());

    circle.setOrigin(sf::Vector2f(this->enthropy->getRadiusOfParticle(), this->enthropy->getRadiusOfParticle()));
    circle.setFillColor(sf::Color(102, 51, 204, 255));
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

    this->window->setView(*this->simView);

    this->drawBox();
    drawParticles(false);

}

void Simulation::keyCallback(sf::Event event){

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){

                if(this->simView->getSize().x < 5 * defaultSizeOfStartBox.first)
                    this->simView->zoom(1.1);
                //std::cout<<this->simView->getSize().x<<" "<< this->simView->getSize().y<<std::endl;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                
                if(this->simView->getSize().x > 2 * this->enthropy->getRadiusOfParticle())
                this->simView->zoom(0.9);
                
                //std::cout<<this->simView->getSize().x<<" "<< this->simView->getSize().y<<std::endl;

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

                if(this->simView->getCenter().x > 0)
                    this->simView->move(sf::Vector2f(0,-10));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){

                if(this->simView->getCenter().x < defaultSizeOfStartBox.first * 4)
                    this->simView->move(sf::Vector2f(0,10));
           }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

                if(this->simView->getCenter().y > 0)
                    this->simView->move(sf::Vector2f(10,0));
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

                if(this->simView->getCenter().y < defaultSizeOfStartBox.second * 4)
                    this->simView->move(sf::Vector2f(-10,0));
            }
}