#ifndef PLOT_HPP
#define PLOT_HPP

#include "entropy.hpp"
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
        Entropy* entropy;
        sf::View* plotView;
        std::vector<float> xlabels;
        std::vector<float> ylabels;
        std::vector<sf::Vertex> data;
        float yOffset;
        sf::Vector2f zeroZero;
        float xAxisUnit;

        float maxHeightPlot;
        float maxWidthPlot;

        float globalMax;
        float globalMin;

        void transformCoordToViewCoord();
        void transformViewCoordToCoord(); //inverse transformaton
        void movePlotAlongYAxis(float yVec);

    public:
        Plot(sf::RenderWindow &win, Entropy &ent, sf::View &view) : Renderer(win){
            
            this->entropy = &ent;
            this->plotView = &view;

            this->zeroZero = sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim);

            data.clear();
            data.push_back(sf::Vertex(sf::Vector2f( 0.0f, this->entropy->getEntropyValue())));
            data[data.size() - 1].color = plotColor;

            this->globalMax = data.back().position.y;
            this->globalMin = data.back().position.y;

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
        void drawPlot();
        
};




#endif