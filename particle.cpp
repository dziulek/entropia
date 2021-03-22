#include "particle.hpp"

_vector Particle::getPosition(){
    return this->position;
}
_vector Particle::getSpeed(){
    return this->speed;
}
void Particle::moveParticle(const _vector a){
    this->position = this->position + a;
}
void Particle::setPosition(const _vector a){
    this->position = a;
}
void Particle::setSpeed(const _vector a){
    this->speed = a;
}
bool Particle::collision(const Particle &a, const Particle &b){
    return (_vector::length(a.position) + 
                _vector::length(_vector::negation(b.position)) < epsilon);
}
