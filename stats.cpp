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
                square.setFillColor(sf::Color(255, intcol%127 * 2, 0, 255));

            square.setPosition(sf::Vector2f(statsRim + xsquare * float(i), statsRim + ysquare * float(j)));

            this->window->draw(square);
        }
    }
}

void Stats::showView(){

    this->window->setView(*this->statsView);

    drawDensitySquares();

    //sf::RectangleShape r = sf::RectangleShape(sf::Vector2f(500.0f, 500.0f));

    //this->window->draw(r);
}

void Stats::keyCallback(sf::Event event){

}