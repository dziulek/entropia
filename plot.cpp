#include "plot.hpp"


void Plot::drawTicksAndAxis(){

    //x axis
    sf::Vertex yAxis[2] = {
        sf::Vertex(sf::Vector2f(plotRim, plotRim)),
        sf::Vertex(sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim))
    };

    sf::Vertex xAxis[2] = {
        sf::Vertex(sf::Vector2f(plotRim, this->plotView->getSize().y - plotRim)),
        sf::Vertex(sf::Vector2f(this->plotView->getSize().x - plotRim, this->plotView->getSize().y - plotRim))
    };


    this->window->draw(xAxis, 2, sf::LineStrip);
    this->window->draw(yAxis, 2, sf::LineStrip);

    //spikes
    sf::Vertex ySpike[3] = {
        sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
        sf::Vertex(sf::Vector2f(-10.0f, 30.0f)),
        sf::Vertex(sf::Vector2f(10.0f, 30.0f))
    };

    for(int i =0; i < 3; i++){
        ySpike[i] = sf::Vertex(sf::Vector2f(ySpike[i].position.x + yAxis[0].position.x, ySpike[i].position.y + yAxis[0].position.y));
    }

    this->window->draw(ySpike, 3, sf::Triangles);

    sf::Vertex xSpike[3] = {
        sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
        sf::Vertex(sf::Vector2f(-30.0f, -10.0f)),
        sf::Vertex(sf::Vector2f(-30.0f, 10.0f))
    };

    for(int i = 0; i < 3; i++){
        xSpike[i] = sf::Vertex(sf::Vector2f(xSpike[i].position.x + xAxis[1].position.x, xSpike[i].position.y + xAxis[1].position.y));
    }

    this->window->draw(xSpike, 3, sf::Triangles);
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
