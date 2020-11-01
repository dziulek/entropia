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
            if(i->getPosition().x < leftUpCorner.first + epsilon && i->getSpeed().x < 0)
                i->setSpeed({-i->getSpeed().x, i->getSpeed().y});

            else if(i->getPosition().x < leftUpCorner.first + widthSpace - epsilon && i->getSpeed().x < 0)
                    i->setSpeed({-i->getSpeed().x, i->getSpeed().y});

            if(i->getPosition().y < leftUpCorner.second + epsilon && i->getSpeed().y < 0)
                i->setSpeed({i->getSpeed().x, -i->getSpeed().y});

            else if(i->getPosition().y < leftUpCorner.second + heightSpace - epsilon && i->getSpeed().y > 0)
                    i->setSpeed({i->getSpeed().x, -i->getSpeed().y});

            //particle bouncing
            auto ind = i + 1;
            while(ind != this->gas.end() && ind->getPosition().x - i->getPosition().x <= 2*radiusOfParticle + epsilon){

                _vector between = i->getSpeed() + _vector::negation(ind->getSpeed());
                float a = _vector::dotProduct(between, ind->getSpeed());
                float b = _vector::dotProduct(between, i->getSpeed());

                if(a < 0 && b < 0){
                    ind ++;
                    continue;
                }

                if(_vector::length(between) < epsilon){
                    crash(i, ind);
                }
            }
        }
    }
    else {

    }
}

void Enthropy::moveParticles(const float deltaTime){

    for(auto i:this->gas){
        _vector newPosition = i.getPosition() + i.getSpeed()*deltaTime;
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
    
    this->gas.resize(nOfParticles);
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
    
    setDirOfParticles(false);
    moveParticles(deltaTime);

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

        i->setSpeed({ x, float(pow(-1, rand()%2)) * (float)sqrt( averageSpeed - x * x)});
    }
}

void Enthropy::startSimulation(){
    
    this->start = 1;

    this->heightSpace = 4 * defaultSizeOfStartBox.first;
    
    this->widthSpace = 4 * defaultSizeOfStartBox.first;
}