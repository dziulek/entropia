#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "entropy.hpp"
#include "renderer.hpp"

class Simulation : public Renderer{

    private:

        Entropy* entropy;
        sf::View* simView;
    
    public:

        Simulation(sf::RenderWindow & win, Entropy & ent, sf::View &simulationView) : Renderer{win}{
            this->entropy = &ent;
            this->simView = &simulationView;

            simView->setSize(sf::Vector2f(4 * defaultSizeOfStartBox.first, 4 * defaultSizeOfStartBox.second));
            
            simView->setCenter(sf::Vector2f(2 * defaultSizeOfStartBox.first, 2 * defaultSizeOfStartBox.second));
        }
        ~Simulation(){
            // std::cout<<"simulation destructor called"<<std::endl;
        }
        void showView() override;
        void drawBox();
        void drawParticles(bool parallel = false);
        void releaseParticles(){ this->entropy->releaseParticles(); }
        void loopSimulation(const float deltaTime){ this->entropy->loop(deltaTime); }
        void keyCallback(sf::Event event) override;
        float getEntropy(){ return this->entropy->getEntropyValue(); }
};

#endif