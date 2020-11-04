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

    public:
        Plot(sf::RenderWindow &win, Simulation &sim) : Renderer(win){
            
            this->simulation = &sim;
            this->plotView = new sf::View;

            plotView->setViewport(sf::FloatRect(2.0f / 3 ,0 , 1.0f/3, 0.5));
        }
        ~Plot(){

            delete plotView;
        }
        void showView() override;
        void drawTicksAndAxis();
        void calculateTicks();
        void scalePlot();
        void keyCallback();
        void drawPlot();

        
};




#endif