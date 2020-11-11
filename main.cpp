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

    //views
    sf::View simulationView(sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second) * 4.0f, 
                            sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second) * 2.0f);
    simulationView.setViewport(sf::FloatRect(0 ,0 , 2.0f/3, 1));

    sf::View plotView;//(sf::Vector2f(defaultSizeOfPlotView, defaultSizeOfPlotView), 
                      //sf::Vector2f(defaultSizeOfPlotView / 2, defaultSizeOfPlotView / 2));
    plotView.setViewport(sf::FloatRect(2.0f/3, 0, 1.0f/3, 1.0f/2));


    Enthropy entropy;
    Simulation sim(window, entropy, simulationView);
    Plot plot(window, entropy, plotView);

    float time = 0; // temporary for plot

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                //switch between windows: simulation -> plot -> stats -> ...
                currentWindow = ( currentWindow + 1 ) % 3;
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){

                entropy.releaseParticles();
            }

            switch (currentWindow)
            {
            case SIMULATION:
                sim.keyCallback(event);

                break;
            case PLOT:
                //plot.keyCallback(event);

            case STATS:
                //stats.keyCallback(event);

            default:
                break;
            }
        }
        sim.loopSimulation(1.0f / 30);

        window.clear(sf::Color(255, 153, 153, 255));    
        
        sim.showView();

        time += 1.0f / 30;
        
        plot.showView();

        // end the current frame
        window.display();
        window.setFramerateLimit(60);
    }
    return 0;
}