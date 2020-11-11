#ifndef STATS_HPP
#define STATS_HPP

#include "enthropy.hpp"
#include "renderer.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Stats : public Renderer{

private:

    Enthropy* enthropy;
    sf::View* statsView;

    float lowThresholdDensity;
    float highThresholdDensity;

    const unsigned int numberOfFields = 12; //in a row

public:

    Stats(sf::RenderWindow & win, Enthropy & ent, sf::View & view) : Renderer{win} {

        this->enthropy = &ent;
        this->statsView = &view;

        this->lowThresholdDensity = float(enthropy->getParticles().size()) / float(numberOfFields * numberOfFields * 4);
        this->highThresholdDensity = float(enthropy->getParticles().size()) / float(numberOfFields * numberOfFields);

    }
    void showView() override;
    void drawDensitySquares();
    void drawInfo();
    void keyCallback(sf::Event event) override;

};


#endif