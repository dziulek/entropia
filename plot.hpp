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

class Plot : public Renderer{

    private:
        Simulation* simulation;
        sf::View* plotView;
        std::vector<float> xlabels;
        std::vector<float> ylabels;
        std::vector<sf::Vertex> data;
        float yOffset = 0;
        sf::Vector2f zeroZero;

        bool startPlotting = 0;

        void transformCoordToView();

    public:
        Plot(sf::RenderWindow &win, Simulation &sim) : Renderer(win){
            
            this->simulation = &sim;
            this->plotView = new sf::View;

            //this->plotView->setSize(sf::Vector2f(300.0f, 300.0f));

            this->plotView->setViewport(sf::FloatRect(2.0f / 3 ,0 , 1.0f/3, 0.5));

            this->zeroZero = sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim);

            data.clear();
            data.push_back(sf::Vertex(sf::Vector2f(0, 0)));

            this->yOffset = this->simulation->getEnthropy();
        }
        ~Plot(){

            delete plotView;
        }
        void showView() override;
        void drawTicksAndAxis();
        void calculateTicks();
        void scalePlot(std::vector<sf::Vertex> & dataCopy, float xFactor, float yFactor);
        void keyCallback();
        void drawPlot(float deltaTime);
        void start(){ this->startPlotting = 1; }

        
};




#endif