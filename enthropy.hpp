#ifndef ENTHROPY_HPP
#define ENTHROPY_HPP

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include "particle.hpp"
#include "_vector.hpp"


typedef std::vector<Particle>::iterator VPI;

class Enthropy{
    private:
        unsigned int nOfParticles;
        std::vector<Particle> gas;
        float maxSpeed;
        float widthSpace;
        float heightSpace;
        std::pair<float, float> leftUpCorner;//y, x!
        void setUpParameters();
        static void crash(VPI a, VPI b);
    public:
        Enthropy(){//reallyyyy ugly
            this->nOfParticles = defaultNumParticles;
            Particle particle;
            this->gas.assign(defaultNumParticles, particle);
            bool fun = setStartPos();
        }
        Enthropy(unsigned int nofparticles);
        std::vector<Particle> & getParticles();
        void sortParticlesX(VPI b, VPI e);
        void sortParticlesY(VPI b, VPI e);
        void setDirOfParticles(bool parallel = false);
        void moveParticles(const float deltaTime);
        void loop(const float deltaTime);
        void borderBounce(bool parallel = false);
        float calcEnthropy();
        bool setStartPos();
};

#endif