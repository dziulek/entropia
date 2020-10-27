#ifndef ENTHROPY_HPP
#define ENTHROPY_HPP

#include <algorithm>
#include <cmath>
#include "particle.hpp"
#include <vector>
#include <_vector.hpp>
#include <utility>

typedef std::vector<Particle>::iterator VPI;

class Enthropy{
    private:
        unsigned int nOfParticles;
        std::vector<Particle> gas;
        float maxSpeed;
        float widthSpace;
        float heightSpace;
        std::pair<float, float> leftUpCorner;//y, x!
    public:
        Enthropy();
        Enthropy(unsigned int nofparticles);
        void sortParticlesX(VPI b, VPI e);
        void sortParticlesY(VPI b, VPI e);
        void setDirOfParticles(bool parallel = false);
        void moveParticles(const float deltaTime);
};

#endif