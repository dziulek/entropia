#include "renderer.hpp"


Renderer::Renderer(sf::RenderWindow &win){
    win.setSize(sf::Vector2u(500, 500));
}

sf::RenderWindow* Renderer::getWindow(){
    return this->window;
}