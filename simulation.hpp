#ifndef SYMULATION_HPP
#define SYMULATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "enthropy.hpp"
#include "renderer.hpp"

class Simulation : public Renderer{

    private:

        Enthropy* enthropy;
        sf::View simView;
    
    public:

        Simulation(sf::RenderWindow & win, Enthropy & ent, sf::View & view) : Renderer{win}{
            this->enthropy = &ent;
            this->simView = view;
        }
        void showView() override;
        void drawBox();
        void drawParticles(bool parallel = false);
        void startSimulation(){ this->enthropy->releaseParticles(); }
};

#endif