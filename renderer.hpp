#ifndef RENDERER_HPP
#define RENDERER_HPP

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"

class Renderer{
    protected:
        sf::RenderWindow *window;

    public:
        Renderer(sf::RenderWindow &win){
            this->window = &win;
        };
        sf::RenderWindow* getWindow();
        virtual void showView();
        static void scaleView(sf::View &v, float factor);
        //void resizeView();
        void keycallback();

        static void RenderWindow();
};

#endif