#ifndef ENTHROPY_HPP
#define ENTHROPY_HPP

#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include "particle.hpp"
#include "enthropy.hpp"
#include "_vector.hpp"
#include "constants.hpp"

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
        Enthropy();
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