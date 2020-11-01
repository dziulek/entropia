#include "renderer.hpp"
#include "simulation.hpp"
#include "enthropy.hpp"
#include <iostream>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(900, 600), "Enthropy");
    sf::View view(sf::FloatRect(0,0,1200, 1200));
    view.setViewport(sf::FloatRect(0 ,0 , 2.0f/3, 1));

    Enthropy enthropy;
    Simulation sim(window, enthropy, view);

    sim.startSimulation();

    while (sim.getWindow()->isOpen())
    {
        sf::Event event;
        while (sim.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        enthropy.loop(1.0f/30);

        sim.getWindow()->clear(sf::Color::Black);

        sim.showView();
        // end the current frame
        sim.getWindow()->display();
        window.setFramerateLimit(60);
    }

    return 0;
}