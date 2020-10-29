#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include "particle.hpp"
#include "enthropy.hpp"
#include "_vector.hpp"
#include "constants.hpp"

typedef std::vector<Particle>::iterator VPI;

Enthropy::Enthropy(){
    this->nOfParticles = defaultNumParticles;
}

Enthropy::Enthropy(unsigned int nofparticles){
    this->nOfParticles = defaultNumParticles;
}

void Enthropy::sortParticlesX(VPI b, VPI e){
    std::sort(b, e, [b, e](){return b->getPosition().x < e->getPosition().x;});
}

void Enthropy::sortParticlesY(VPI b, VPI e){
    std::sort(b, e, [b, e](){return b->getPosition().y < e->getPosition().y;});
}

void Enthropy::setDirOfParticles(bool parallel = false){
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

bool Enthropy::setStartPos(){
    //for testing
    for(auto i : this->gas){
            i.setPosition({radiusOfParticle*3.0*i.getPosition().x, 100.0f});
    }
}