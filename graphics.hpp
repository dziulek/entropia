#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Graphics{
    virtual void showView(sf::View &v);
    static void scaleView(sf::View &v, float factor);
    void manageViews(sf::View &box, sf::View &stats, sf::View &plot);
};

#endif