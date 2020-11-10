#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "enthropy.hpp"
#include "renderer.hpp"

class Simulation : public Renderer{

    private:

        Enthropy* enthropy;
        sf::View* simView;
    
    public:

        Simulation(sf::RenderWindow & win, Enthropy & ent, sf::View &simulationView) : Renderer{win}{
            this->enthropy = &ent;
            this->simView = &simulationView;

            simView->setSize(sf::Vector2f(4 * defaultSizeOfStartBox.first, 4 * defaultSizeOfStartBox.second));
            
            simView->setCenter(sf::Vector2f(2 * defaultSizeOfStartBox.first, 2 * defaultSizeOfStartBox.second));
        }
        ~Simulation(){
            std::cout<<"simulation destructor called"<<std::endl;
        }
        void showView() override;
        void drawBox();
        void drawParticles(bool parallel = false);
        void releaseParticles(){ this->enthropy->releaseParticles(); }
        void loopSimulation(const float deltaTime){ this->enthropy->loop(deltaTime); }
        void keyCallback(sf::Event event) override;
        float getEnthropy(){ return this->enthropy->getEnthropyValue(); }
};

#endif