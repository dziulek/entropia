#ifndef STATS_HPP
#define STATS_HPP

#include "entropy.hpp"
#include "renderer.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <iostream>

class Stats : public Renderer{

private:

    Entropy* entropy;
    sf::View* statsView;

    float lowThresholdDensity;
    float highThresholdDensity;

    const unsigned int numberOfFields = 12; //in a row

public:

    Stats(sf::RenderWindow & win, Entropy & ent, sf::View & view) : Renderer{win} {

        this->entropy = &ent;
        this->statsView = &view;

        this->lowThresholdDensity = float(entropy->getParticles().size()) * 0.0f / float(numberOfFields * numberOfFields * numberOfFields);
        this->highThresholdDensity = float(entropy->getParticles().size()) * 2.5f / float(numberOfFields * numberOfFields);

    }
    void showView() override;
    void drawDensitySquares();
    void drawInfo();
    void keyCallback(sf::Event event) override;

};


#endif