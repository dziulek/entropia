#include "renderer.hpp"

sf::RenderWindow* Renderer::getWindow(){
    return this->window;
}

void Renderer::showView(){
    //function must be overriden
}