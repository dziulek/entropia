#ifndef SYMULATION_HPP
#define SYMULATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "enthropy.hpp"
#include "renderer.hpp"

class Symulation : public Renderer{

    private:

        Enthropy enthropy;
        sf::View symview;
    
    public:

        Symulation(sf::RenderWindow &win);
        void showView(sf::View &view);
        void drawBox();
        void drawParticles(bool parallel = false);
};

#endif