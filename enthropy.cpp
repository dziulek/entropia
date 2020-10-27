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
    this->heightSpace = defaultHeight;
    this->widthSpace = defaultWidth;
    this->leftUpCorner = defaultCorner;
    this->gas.resize(defaultNumParticles);
}

Enthropy::Enthropy(unsigned int nofparticles){
    this->nOfParticles = defaultNumParticles;
    this->heightSpace = defaultHeight;
    this->widthSpace = defaultWidth;
    this->leftUpCorner = defaultCorner;
    this->gas.resize(defaultNumParticles);
}

void Enthropy::sortParticlesX(VPI b, VPI e){
    std::sort(b, e, [b, e](){return b->getPosition().x < e->getPosition().x;});
}

void Enthropy::sortParticlesY(VPI b, VPI e){
    std::sort(b, e, [b, e](){return b->getPosition().y < e->getPosition().y;});
}

void Enthropy::setDirOfParticles(bool parallel = false){

}

void Enthropy::moveParticles(const float deltaTime){

}

