#ifndef PARTICLEL_HPP
#define PARTICLE_HPP   

#include "_vector.hpp"

class Particle{
    private:
        _vector position;
        _vector speed;
        _vector direction;
        //color maybe
    public:
        _vector getPosition();
        _vector getSpeed();
        _vector getDirection();
        void setPosition(const _vector a);
        void setDirection(const _vector a);
        void setSpeed(const _vector a);
        void moveParticle(const _vector a);
        static bool collision(const Particle &a,const Particle &b);
};

#endif