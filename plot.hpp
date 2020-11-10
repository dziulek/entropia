#ifndef PLOT_HPP
#define PLOT_HPP

#include "enthropy.hpp"
#include "renderer.hpp"
#include "simulation.hpp"
#include "constants.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include <vector>
#include <iostream>

class Plot : public Renderer{

    private:
        Enthropy* enthropy;
        sf::View* plotView;
        std::vector<float> xlabels;
        std::vector<float> ylabels;
        std::vector<sf::Vertex> data;
        float yOffset = 0;
        sf::Vector2f zeroZero;
        float xAxisUnit;

        float maxHeightPlot;
        float maxWidthPlot;

        void transformCoordToViewCoord();
        void transformViewCoordToCoord(); //inverse transformaton

    public:
        Plot(sf::RenderWindow &win, Enthropy &ent, sf::View &view) : Renderer(win){
            
            this->enthropy = &ent;
            this->plotView = &view;

            this->zeroZero = sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim);

            data.clear();
            data.push_back(sf::Vertex(sf::Vector2f(0, 0)));

            xAxisUnit = 0.25;// one quarter of a second

            maxHeightPlot = this->plotView->getSize().y - 2 * plotRim;
            maxWidthPlot = this->plotView->getSize().x - 2 * plotRim;
        }
        ~Plot(){
            std::cout<<"plot destructor called"<<std::endl;
        }
        void showView() override;
        void drawTicksAndAxis();
        void calculateTicks();
        void scalePlot(float xFactor, float yFactor);
        void keyCallback();
        void drawPlot(float deltaTime);
        
};




#endif