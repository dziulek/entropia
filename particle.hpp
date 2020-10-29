#ifndef PARTICLE_HPP
#define PARTICLE_HPP   

#include "_vector.hpp"

class Particle{
    private:
        _vector position;
        _vector speed;
        float radius;
        //color maybe
    public:
        Particle() = default;
        _vector getPosition();
        _vector getSpeed();
        void setPosition(const _vector a);
        void setSpeed(const _vector a);
        void moveParticle(const _vector a);
        static bool collision(const Particle &a,const Particle &b);
};

#endif