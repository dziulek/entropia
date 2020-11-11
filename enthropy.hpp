#ifndef ENTHROPY_HPP
#define ENTHROPY_HPP

#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cmath>
#include "particle.hpp"
#include "_vector.hpp"


typedef std::vector<Particle>::iterator VPI;

class Enthropy{
    private:
        unsigned int nOfParticles;
        std::vector<Particle> gas;
        float averageSpeed;
        float widthSpace;
        float heightSpace;
        float radiusOfParticle;
        bool start = false;
        std::pair<float, float> leftUpCorner;//y, x!
        std::pair<float, float> rightDownCornerStartBox;
        int curState[nOfIntervals][nOfIntervals][nOfIntervals][nOfIntervals];

        float enthropyValue;
        float entTime; // for simulations

        void setUpParameters();
        static void crash(VPI a, VPI b);
        void setStartPos();
        void setStartSpeed();
        void zeroCurState();

    public:
        Enthropy(){
            this->nOfParticles = defaultNumParticles;
            start = false;
            setUpParameters();
            setStartPos();
            setStartSpeed();
            enthropyValue = calcEnthropy();
        }
        Enthropy(unsigned int nofparticles){
            this->nOfParticles = nofparticles;
            start = false;
            setUpParameters();
            setStartPos();
            setStartSpeed();
            enthropyValue = calcEnthropy();
            
        }
        ~Enthropy(){
            std::cout<<"entropy destructor called"<<std::endl;
        }
        std::vector<Particle> & getParticles();
        void releaseParticles();
        void sortParticlesX(VPI b, VPI e);
        void sortParticlesY(VPI b, VPI e);
        void setDirOfParticles(bool parallel = false);
        void moveParticles(const float deltaTime);
        void loop(const float deltaTime);
        void borderBounce(bool parallel = false);
        float getRadiusOfParticle(){ return this->radiusOfParticle;}
        bool getState(){ return this->start; };
        float getEnthropyValue(){ return this->enthropyValue; }
        float getTime(){ return this->entTime; }

        float calcEnthropy();
        auto getCurState(){ return curState; }

};

#endif