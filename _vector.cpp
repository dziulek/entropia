#include "_vector.hpp"
#include <cmath>

    _vector::_vector(float x, float y){
        this->x = x;
        this->y = y;
    }
    _vector::_vector(){
        this->x = this->y = 0;
    }

    bool _vector::operator==(_vector a){
        return (this->x == a.x && this->y == a.x);
    }
    _vector _vector::operator+(_vector a){
        return _vector(this->x + a.x, this->y + a.y);
    }
    _vector _vector::negation(_vector a){
        return _vector(-a.x, -a.y);
    }
    _vector _vector::operator=(_vector a){
        this->x = a.x;
        this->y = a.y;
        return *this;
    }
    _vector _vector::operator*(float f){
        return _vector(this->x*f, this->y*f);
    }
    float _vector::length(_vector a){
        return std::sqrt(a.x*a.x + a.y*a.y);
    }
    _vector _vector::normalize(_vector a){
        return a*(1/length(a));
    }
    float _vector::dotProduct(_vector a, _vector b){
        return a.x*b.x + a.y*b.y;
    }