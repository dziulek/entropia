#include "renderer.hpp"
#include "simulation.hpp"
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

    return 0;
}