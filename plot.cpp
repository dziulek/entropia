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
    yAxis[0].color = axisColor;
    yAxis[1].color = axisColor;
    xAxis[0].color = axisColor;
    xAxis[1].color = axisColor;

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
    for(auto & v : ySpike)
        v.color = axisColor;

    this->window->draw(ySpike, 3, sf::Triangles);

    sf::Vertex xSpike[3] = {
        sf::Vertex(sf::Vector2f(0.0f, 0.0f)),
        sf::Vertex(sf::Vector2f(-30.0f, -10.0f)),
        sf::Vertex(sf::Vector2f(-30.0f, 10.0f))
    };

    for(int i = 0; i < 3; i++){
        xSpike[i] = sf::Vertex(sf::Vector2f(xSpike[i].position.x + xAxis[1].position.x, xSpike[i].position.y + xAxis[1].position.y));
    }


    for(auto & v : xSpike)
        v.color = axisColor;

    this->window->draw(xSpike, 3, sf::Triangles);
}

void Plot::calculateTicks(){


}

void Plot::transformCoordToViewCoord(){

    float tempx, tempy;

    for(int i = 0; i < this->data.getVertexCount(); i++){

        tempx = data[i].position.x;
        tempy = data[i].position.y;

        tempx += zeroZero.x;
        tempy = -tempy;
        tempy += zeroZero.y;

        data[i] = sf::Vertex(sf::Vector2f(tempx, tempy));        
    }
}

void Plot::transformViewCoordToCoord(){

    float tempx;
    float tempy;

    for(int i = 0; i < data.getVertexCount(); i++){

        tempx = data[i].position.x - zeroZero.x;
        tempy = data[i].position.y - zeroZero.y;
        tempy = -tempy;

        data[i] = sf::Vertex(sf::Vector2f(tempx, tempy));
    }
}

void Plot::movePlotAlongYAxis(float yVec){

    for(int i =0; i < data.getVertexCount(); i++){

        data[i].position.y += yVec;
    }
}

void Plot::drawPlot(){

    float time = this->entropy->getTime();

    if(this->entropy->getState() == 1){
        if(time - this->data[data.getVertexCount()-1].position.x >= this->xAxisUnit){

            sf::Vertex newVertex = sf::Vertex(sf::Vector2f(time, this->entropy->getEntropyValue()));
            this->data.append(newVertex);
            data[data.getVertexCount() - 1].color = sf::Color::Blue;

            if(this->data[data.getVertexCount() - 1].position.y > this->globalMax) globalMax = this->data[data.getVertexCount() - 1].position.y;

            if(this->data[data.getVertexCount() - 1].position.y < this->globalMin) globalMin = data[data.getVertexCount() - 1].position.y;

            this->data.append(sf::Vertex(sf::Vector2f(newVertex.position.x, data[0].position.y)));
            this->data[data.getVertexCount()-1].color = sf::Color::Blue;

            if(this->data.getVertexCount() > 400){

                for(int i = 3; i < 200; i+=2){
                
                    data[ i ] = data[ i * 2 - 1 ];
                    data[ i + 1 ] = data[ i * 2];

                    if(data[i].position.y > this->globalMax)
                        globalMax = data[i].position.y;
                    
                    if(data[i].position.y < this->globalMin)
                        globalMin = data[i].position.y;        
                    
                    //i++;       
                }
                this->xAxisUnit *= 2;    

                this->data.resize(data.getVertexCount() / 2 + 1);
            }
        }   

            movePlotAlongYAxis(-globalMin);

            float diff = globalMax - globalMin;

            //scale coordinates
            float xf, yf;

            if(abs(this->data[data.getVertexCount() - 1].position.x) <= ep) xf = 1;
            else xf = this->maxWidthPlot / data[data.getVertexCount() - 1].position.x;

            if(abs(diff) <= ep) yf = 1;
            else yf = this->maxHeightPlot / diff;

            this->scalePlot(xf, yf);
            
            //transform coordinates
            this->transformCoordToViewCoord();

        //////////////
        //////////////  
            for(int i = 0; i < data.getVertexCount(); i++)
                data[i].color = plotColor;
        
            this->window->draw(data);

            //undo transform coordinates
            this->transformViewCoordToCoord();

            //undo scale
            this->scalePlot(1 / xf, 1 / yf);  

            movePlotAlongYAxis(globalMin); 
        
    }
}

void Plot::keyCallback(sf::Event event){

    if(event.type == sf::Event::Resized){
        
        float new_height, new_width;
        new_height = event.size.height;
        new_width = event.size.width;

        float temp = std::max(0.0f, new_width - new_height / 2)/new_width;

        this->plotView->setViewport(sf::FloatRect(temp, 0, 1 - temp, 1.0f/2));

        // sf::Vector2f center = this->plotView->getCenter();

        // float newRatio = 0.5f * event.size.height / (1.0f / 3 * event.size.width);

        // this->plotView->setSize(sf::Vector2f(this->plotView->getSize().x, this->plotView->getSize().x * newRatio));
        // this->plotView->setCenter(sf::Vector2f(center));

    }

}

void Plot::scalePlot(float xFactor, float yFactor){

    for(int i = 0; i < data.getVertexCount(); i++){

        data[i].position.x = data[i].position.x * xFactor;
        data[i].position.y = data[i].position.y * yFactor;
    }
}

void Plot::showView(){


    this->window->setView(*this->plotView);

    sf::RectangleShape plotBackground = sf::RectangleShape(sf::Vector2f(this->plotView->getSize().x, 
                                                                        this->plotView->getSize().y));
    plotBackground.setFillColor(backPlotColor);

    this->window->draw(plotBackground);
    
    calculateTicks();

    drawPlot();  

    drawTicksAndAxis();
}
