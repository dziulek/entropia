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
    
}
