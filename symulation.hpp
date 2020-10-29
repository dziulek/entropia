#ifndef SYMULATION_HPP
#define SYMULATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "enthropy.hpp"

class Symulation{
    Enthropy enthropy;
    sf::View view;
    void drawBox();
    void drawParticles(bool parallel = false);
};

#endif