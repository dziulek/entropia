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

void Plot::transformCoordToView(){

    std::vector<sf::Vertex>::iterator i;
    for(i = this->data.begin(); i != this->data.end(); i++){

        *i = sf::Vertex(sf::Vector2f(i->position.x + zeroZero.x, -i->position.y + yOffset + zeroZero.y ));        
    }
}

void Plot::drawPlot(float deltaTime){

    if(this->startPlotting == 1){
        if(this->data.size() > 1000){

            int currIndex = 1;
            for(auto i = 1; i < this->data.size(); i+=4){

                this->data[currIndex] = this->data[i];
                currIndex ++;
            }
            this->data.resize(currIndex);
            this->data.shrink_to_fit();
        }
        
        sf::Vertex newVertex = sf::Vertex(sf::Vector2f(this->data.back().position.x + deltaTime, 
                                                    this->simulation->getEnthropy() - this->yOffset));
        this->data.push_back(newVertex);

        //this->data.push_back(sf::Vertex(sf::Vector2f(newVertex.position.x, 0)));
    
        std::vector<sf::Vertex> dataCopy;
        dataCopy.resize(this->data.size());
        
        for(int i = 0; i < dataCopy.size(); i++) dataCopy[i] = this->data[i];

        this->scalePlot(dataCopy, xEndCoord / this->data.back().position.x,
                                yEndCoord / this->data.back().position.y);

    //////////////
    //////////////  

        this->window->setView(*this->plotView);


        this->window->draw(&dataCopy[0], dataCopy.size(), sf::LineStrip);

        //this->data.pop_back();        
    }
}

void Plot::keyCallback(){


}

void Plot::scalePlot(std::vector<sf::Vertex> & dataCopy,float xFactor, float yFactor){

    std::vector<sf::Vertex>::iterator i;
    for(i = dataCopy.begin(); i != dataCopy.end(); i++){

        i->position.x = i->position.x * xFactor + this->zeroZero.x;
        i->position.y = -i->position.y * yFactor + this->zeroZero.y;
    }
}

void Plot::showView(){

    this->window->setView(*this->plotView);
    
    calculateTicks();

    drawTicksAndAxis();

}
