#include "stats.hpp"

void Stats::drawDensitySquares(){

    float xsquare = (this->statsView->getSize().x - 2 * statsRim) / numberOfFields;
    float ysquare = (this->statsView->getSize().y - 2 * statsRim) / numberOfFields;


    sf::RectangleShape square = sf::RectangleShape(sf::Vector2f(xsquare, ysquare));

    auto ptr = this->entropy->getCurState();

    for(int i = 0; i<numberOfFields; i++){

        for(int j = 0; j<numberOfFields; j++){

            int sum = 0;

            for(int k = 0; k<12; k++){

                for(int l = 0; l<12; l++){

                    sum += ptr[i][j][k][l];
                }
            }
            float col = (float(sum) - this->lowThresholdDensity) / (this->highThresholdDensity - this->lowThresholdDensity);

            int intcol = int(col * 255.0f);
            if(intcol > 255) intcol = 255;

            if(intcol < 0) intcol = 0;

            if(intcol < 127)
                square.setFillColor(sf::Color(intcol * 2,  255, 0, 255));
            else 
                square.setFillColor(sf::Color(255, 255 - (intcol-128) * 2, 0, 255));

            square.setPosition(sf::Vector2f(statsRim + xsquare * float(i), statsRim + ysquare * float(j)));

            this->window->draw(square);
        }
    }
}

void Stats::showView(){

    this->window->setView(*this->statsView);

    sf::RectangleShape statsBackground = sf::RectangleShape(sf::Vector2f(this->statsView->getSize().x,
                                                                        this->statsView->getSize().y));
    statsBackground.setFillColor(backStatsColor);

    this->window->draw(statsBackground);

     drawDensitySquares();
}

void Stats::keyCallback(sf::Event event){
    
    if(event.type == sf::Event::Resized){

        float new_height, new_width;
        new_height = event.size.height;
        new_width = event.size.width;

        float temp = std::max(0.0f, new_width - new_height / 2)/new_width;

        this->statsView->setViewport(sf::FloatRect(temp, 1.0f/2, 1 - temp, 1.0f/2));
        // sf::Vector2f center = this->statsView->getCenter();

        // float newRatio = 0.5f * event.size.height / (1.0f / 3 * event.size.width);

        // this->statsView->setSize(sf::Vector2f(this->statsView->getSize().x, this->statsView->getSize().x * newRatio));
        // this->statsView->setCenter(sf::Vector2f(center));

    }
}