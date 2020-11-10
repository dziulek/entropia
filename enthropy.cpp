#include "enthropy.hpp"
#include <iostream>

typedef std::vector<Particle>::iterator VPI;

void Enthropy::sortParticlesX(VPI b, VPI e){
    std::sort(b, e, [](Particle &s, Particle &t){return s.getPosition().x < t.getPosition().x;});
}

void Enthropy::sortParticlesY(VPI b, VPI e){
    std::sort(b, e, [](Particle &s, Particle &t){return s.getPosition().y < t.getPosition().y;});
}

void Enthropy::setDirOfParticles(bool parallel){
    if(!parallel){
        this->sortParticlesX(this->gas.begin(), this->gas.end());

        for(VPI i=this->gas.begin(); i!=this->gas.end();i++){
            //borders bouncing
            if(i->getPosition().x < epsilon + radiusOfParticle && i->getSpeed().x < 0){
                i->setSpeed({ -i->getSpeed().x, i->getSpeed().y});
            }
                

            else if(i->getPosition().x > widthSpace - epsilon - radiusOfParticle && i->getSpeed().x > 0)
                    i->setSpeed({-i->getSpeed().x, i->getSpeed().y});

            if(i->getPosition().y < epsilon + radiusOfParticle && i->getSpeed().y < 0)
                i->setSpeed({i->getSpeed().x, -i->getSpeed().y});

            else if(i->getPosition().y > heightSpace - epsilon - radiusOfParticle && i->getSpeed().y > 0)
                    i->setSpeed({i->getSpeed().x, -i->getSpeed().y});

            //particle bouncing
            auto ind = i + 1;
            while(ind != this->gas.end() && ind->getPosition().x - i->getPosition().x <= 2*radiusOfParticle + epsilon){

                _vector positionBetween = i->getPosition() + _vector::negation(ind->getPosition());

                float a = _vector::dotProduct(positionBetween, ind->getSpeed());
                float b = _vector::dotProduct(_vector::negation(positionBetween), i->getSpeed());


                if(_vector::length(positionBetween) < 2 * radiusOfParticle + epsilon){
                    if(a <= 0 && b <= 0){
                        ind ++;
                        continue;
                    }
                    crash(i, ind);
                }
                ind++;
            }
        }
    }
    else {
            
    }
}

void Enthropy::moveParticles(const float deltaTime){

    for(VPI i = this->gas.begin(); i != this->gas.end(); i++){

        _vector newPosition = i->getPosition() + i->getSpeed()*deltaTime;
        i->setPosition(newPosition);
    }
}

void Enthropy::setUpParameters(){
    
    float inRow = (int)ceil(sqrt(float(nOfParticles)));

    this->radiusOfParticle = sqrt(defaultSizeOfStartBox.first * defaultSizeOfStartBox.second) / ((2 + StartDensityOfParticles) * inRow);

    this->widthSpace = defaultSizeOfStartBox.first;//at the beginning when var start =0
    this->heightSpace = defaultSizeOfStartBox.first;

    this->leftUpCorner = defaultCorner;
    this->rightDownCornerStartBox = {leftUpCorner.first + defaultSizeOfStartBox.first, 
                                        leftUpCorner.second + defaultSizeOfStartBox.second};
    this->averageSpeed = avspeed;
    this->gas.resize((int)inRow * (int)inRow);

    this->entTime = 0;
}

void Enthropy::crash(VPI a, VPI b){//particle "a" has smaller x corrdinate

    _vector crashAxis = b->getPosition() + _vector::negation(a->getPosition());
    _vector vaPerp, vbPerp, vaPar, vbPar;
    crashAxis = _vector::normalize(crashAxis);

    if(_vector::dotProduct(crashAxis, a->getSpeed()) < 0)
        crashAxis = _vector::negation(crashAxis);

    vaPar = crashAxis * _vector::dotProduct(a->getSpeed(), crashAxis);

    if(_vector::dotProduct(crashAxis, b->getSpeed()) < 0)
        crashAxis = _vector::negation(crashAxis);

    vbPar = crashAxis * _vector::dotProduct(b->getSpeed(), crashAxis);

    vaPerp = a->getSpeed() + _vector::negation(vaPar);
    vbPerp = b->getSpeed() + _vector::negation(vbPar);

    //finally
    a->setSpeed(vbPar + vaPerp);
    b->setSpeed(vaPar + vbPerp);
}

void Enthropy::loop(const float deltaTime){

    if(this->start == true)
        this->entTime += deltaTime;
    
    setDirOfParticles(false);
    moveParticles(deltaTime);

    zeroCurState();
    this->enthropyValue = calcEnthropy();
}

std::vector<Particle> & Enthropy::getParticles(){
    return this->gas;
}

void Enthropy::setStartPos(){

    srand(time(NULL));

    int n = nOfParticles;
    float x = leftUpCorner.first + radiusOfParticle;
    float y = leftUpCorner.second + radiusOfParticle;

    VPI i = this->gas.begin();

    while(y < rightDownCornerStartBox.second - radiusOfParticle){
        
        while(x < rightDownCornerStartBox.first - radiusOfParticle){
            
            i->setPosition({x, y});  
            x += (2 * radiusOfParticle + StartDensityOfParticles * radiusOfParticle);
            if(++i == this->gas.end())break;
        }
            x = leftUpCorner.first + radiusOfParticle;
        if(i == this->gas.end())break;

        y += radiusOfParticle * (2 + StartDensityOfParticles);
    }
}

void Enthropy::setStartSpeed(){
    
    std::srand(time(NULL));
    
    for(VPI i = this->gas.begin(); i != this->gas.end(); i++){

        float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float x = r * 2 * averageSpeed - averageSpeed;

        r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float y = r * 2 * averageSpeed - averageSpeed;

        i->setSpeed({ x, y});
    }
}

void Enthropy::releaseParticles(){
    
    this->start = 1;

    this->heightSpace = 4 * defaultSizeOfStartBox.first;
    
    this->widthSpace = 4 * defaultSizeOfStartBox.first;
}

float Enthropy::calcEnthropy(){

    zeroCurState();

    for(VPI i = this->gas.begin(); i != this->gas.end(); i++){

        int x = floor(i->getPosition().x / (1200.0f / nOfIntervals));
        int y = floor(i->getPosition().y / (1200.0f / nOfIntervals));
        int vx = floor(i->getSpeed().x / (2 * sqrt(2.0f) * averageSpeed / nOfIntervals));
        int vy = floor(i->getSpeed().y / (2 * sqrt(2.0f) * averageSpeed / nOfIntervals));

        this->curState[abs(x)][abs(y)][abs(vx)][abs(vy)]++;
    }

    float score=this->nOfParticles*log(this->nOfParticles) - this->nOfParticles, f;

    for(int i=0;i<nOfIntervals;i++){
        for(int j=0;j< nOfIntervals;j++){
            for(int k=0;k< nOfIntervals;k++){
                for(int h=0;h< nOfIntervals;h++){
                    f=this->curState[i][j][k][h];
                    if(f>0)
                        score+=(-f*log(f)+f);
                }
            }
        }
    }
    return score;
}

void Enthropy::zeroCurState(){

    for(int i = 0; i < nOfIntervals; i++)
        for(int j = 0; j < nOfIntervals; j++)
            for(int k = 0; k < nOfIntervals; k++)
                for(int l = 0; l < nOfIntervals; l++)
                    this->curState[i][j][k][l] = 0;
}