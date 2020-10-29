#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "renderer.hpp"
#include "enthropy.hpp"
#include "symulation.hpp"

int main()
{
    // create the window
    sf::RenderWindow window;

    Symulation sym(window);


    sf::View view(sf::FloatRect(0,0,500, 500));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (sym.getWindow()->pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        sym.getWindow()->clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        sym.showView(view);
        // end the current frame
        sym.getWindow()->display();
    }

    return 0;
}