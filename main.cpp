#include "renderer.hpp"
#include "simulation.hpp"
<<<<<<< HEAD
#include "enthropy.hpp"
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(500, 500), "Enthropy");
    sf::View view(sf::FloatRect(0,0,500, 500));

    Enthropy enthropy;
    Simulation sim(window, enthropy, view);

    std::cout<<"siemano"<<std::endl;

    // run the program as long as the window is open
    while (sim.getWindow()->isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (sim.getWindow()->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        sim.getWindow()->clear(sf::Color::Blue);

        // draw everything here...
        // window.draw(...);

        sim.showView();
        // end the current frame
        sim.getWindow()->display();
        window.setFramerateLimit(60);
    }

=======
#include "plot.hpp"
#include "entropy.hpp"
#include "stats.hpp"
#include <iostream>

#define SIMULATION 0
#define PLOT 1
#define STATS 2

int currentWindow = SIMULATION;


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 600), "Entropy");

    //views
    sf::View simulationView(sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second) * 4.0f, 
                            sf::Vector2f(defaultSizeOfStartBox.first, defaultSizeOfStartBox.second) * 2.0f);
    simulationView.setViewport(sf::FloatRect(0 ,0 , 2.0f/3, 1));

    sf::View plotView;//(sf::Vector2f(defaultSizeOfPlotView, defaultSizeOfPlotView), 
                      //sf::Vector2f(defaultSizeOfPlotView / 2, defaultSizeOfPlotView / 2));
    plotView.setViewport(sf::FloatRect(2.0f/3, 0, 1.0f/3, 1.0f/2));

    sf::View statsView;

    statsView.setViewport(sf::FloatRect(2.0f/3, 1.0f/2, 1.0f/3, 1.0f/2));

    Entropy entropy;
    Simulation sim(window, entropy, simulationView);
    Plot plot(window, entropy, plotView);
    Stats stats(window, entropy, statsView);

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

        window.clear(backSimColor);    
        
        sim.showView();

        time += 1.0f / 30;
        
        plot.showView();

        stats.showView();

        // end the current frame
        window.display();
        window.setFramerateLimit(60);
    }
>>>>>>> 633cdf26ec2f1f8263d306ae547f19215966b3bb
    return 0;
}