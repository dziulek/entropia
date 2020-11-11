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

void Plot::transformCoordToViewCoord(){

    float tempx, tempy;

    std::vector<sf::Vertex>::iterator i;
    for(i = this->data.begin(); i != this->data.end(); i++){

        tempx = i->position.x;
        tempy = i->position.y;

        tempx += zeroZero.x;
        tempy = -tempy;
        tempy += zeroZero.y;

        *i = sf::Vertex(sf::Vector2f(tempx, tempy));        
    }
}

void Plot::transformViewCoordToCoord(){

    float tempx;
    float tempy;

    std::vector<sf::Vertex>::iterator i;
    for(i = this->data.begin(); i != this->data.end(); i++){

        tempx = i->position.x - zeroZero.x;
        tempy = i->position.y - zeroZero.y;
        tempy = -tempy;

        *i = sf::Vertex(sf::Vector2f(tempx, tempy));
    }
}

void Plot::movePlotAlongYAxis(float yVec){

    std::vector<sf::Vertex>::iterator i;
    for(i = this->data.begin(); i != this->data.end(); i++){

        i->position.y += yVec;
    }
}

void Plot::drawPlot(){

    float time = this->enthropy->getTime();

    if(this->enthropy->getState() == 1 && time - this->data.back().position.x >= this->xAxisUnit){

        sf::Vertex newVertex = sf::Vertex(sf::Vector2f(time, this->enthropy->getEnthropyValue()));
        this->data.push_back(newVertex);

        if(this->data.back().position.y > this->globalMax) globalMax = this->data.back().position.y;

        if(this->data.back().position.y < this->globalMin) globalMin = data.back().position.y;

        //this->data.push_back(sf::Vertex(sf::Vector2f(newVertex.position.x, data[0].position.y)));

        if(this->data.size() > 400){

            for(int i = 1; i < data.size() / 2; i++){
               
                data[i] = data[ i * 2 ];

                if(data[i].position.y > this->globalMax)
                    globalMax = data[i].position.y;
                
                if(data[i].position.y < this->globalMin)
                    globalMin = data[i].position.y;               
            }
                

            this->data.resize(data.size() / 2);
            this->data.shrink_to_fit();
        }
        
        movePlotAlongYAxis(-globalMin);

        float diff = globalMax - globalMin;

        //scale coordinates
        float xf, yf;

        if(abs(this->data.back().position.x) <= ep) xf = 1;
        else xf = this->maxWidthPlot / data.back().position.x;

        if(abs(diff) <= ep) yf = 1;
        else yf = this->maxHeightPlot / diff;

        this->scalePlot(xf, yf);
        
        //transform coordinates
        this->transformCoordToViewCoord();

    //////////////
    //////////////  

        this->window->draw(&data[0], data.size(), sf::LineStrip);

        //undo transform coordinates
        this->transformViewCoordToCoord();

        //undo scale
        this->scalePlot(1 / xf, 1 / yf);  

        movePlotAlongYAxis(globalMin);     
    }
}

void Plot::keyCallback(){


}

void Plot::scalePlot(float xFactor, float yFactor){

    std::vector<sf::Vertex>::iterator i;
    for(i = data.begin(); i != data.end(); i++){

        i->position.x = i->position.x * xFactor;
        i->position.y = i->position.y * yFactor;
    }
}

void Plot::showView(){


    this->window->setView(*this->plotView);
    
    calculateTicks();

    drawTicksAndAxis();

    drawPlot();  
}
