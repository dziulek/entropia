#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <cmath>

class _vector{
    public:

    float x;
    float y;

    _vector(float x, float y);
    _vector();

    bool operator==(_vector a);
    _vector operator+(_vector a);
    inline static _vector negation(_vector a){ return _vector(-a.x, -a.y); }
    _vector operator=(_vector a);
    _vector operator*(float f);
    inline static float length(_vector a){
        return std::sqrt(a.x*a.x + a.y*a.y);
    }
    inline static _vector normalize(_vector a){
        return a*(1.0f/length(a));
    }
    inline static float dotProduct(_vector a, _vector b){
        return a.x*b.x + a.y*b.y;
    }
};

#endif