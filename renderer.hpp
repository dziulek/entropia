#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Renderer{
    protected:
        sf::RenderWindow *window;

    public:
        Renderer() = default;
        Renderer(sf::RenderWindow &win);
        sf::RenderWindow* getWindow();
        virtual void showView(sf::View &v);
        static void scaleView(sf::View &v, float factor);
        void manageViews(sf::View &box, sf::View &stats, sf::View &plot);
        void resizeWindow();
        virtual void keycallback();

        static void RenderWindow();
};

#endif