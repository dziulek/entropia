#include "renderer.hpp"
#include "simulation.hpp"
#include "plot.hpp"
#include "enthropy.hpp"
#include <iostream>

#define SIMULATION 0
#define PLOT 1
#define STATS 2

int currentWindow = SIMULATION;


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 600), "Enthropy");

    Simulation sim(window);
    Plot plot(window, sim);

    while (sim.getWindow()->isOpen())
    {
        sf::Event event;
        while (sim.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                //switch between windows: simulation -> plot -> stats -> ...
                currentWindow = ( currentWindow + 1 ) % 3;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){

                sim.releaseParticles();
            }

            switch (currentWindow)
            {
            case SIMULATION:
                sim.keyCallback(event);

                break;
            case PLOT:
                sim.keyCallback(event);

            case STATS:
                sim.keyCallback(event);

            default:
                break;
            }
        }

        sim.getWindow()->clear(sf::Color(255, 153, 153, 255));

        sim.loopSimulation(1.0f / 30);
        sim.showView();

        plot.showView();
        // end the current frame
        sim.getWindow()->display();
        window.setFramerateLimit(60);
    }

    return 0;
}