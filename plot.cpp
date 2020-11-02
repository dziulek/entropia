#include "plot.hpp"


void Plot::drawTicksAndAxis(){

    //x axis
    sf::Vertex xAxis[2] = {
        sf::Vertex(sf::Vector2f(plotRim, plotRim)),
        sf::Vertex(sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim))
    };

    sf::Vertex yAxis[2] = {
        sf::Vertex(sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim)),
        sf::Vertex(sf::Vector2f(this->plotView->getSize().x - plotRim, this->plotView->getSize().y - plotRim))
    };


    this->window->draw(xAxis, 2, sf::LineStrip);
    this->window->draw(yAxis, 2, sf::LineStrip);

    //spikes
}

void Plot::calculateTicks(){


}

void Plot::drawPlot(){

}

void Plot::keyCallback(){


}

void Plot::scalePlot(){


}

void Plot::showView(){

    this->window->setView(*this->plotView);
    
    calculateTicks();

    drawTicksAndAxis();
    drawPlot();

}
