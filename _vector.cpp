#include "_vector.hpp"

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
    _vector _vector::operator=(_vector a){
        this->x = a.x;
        this->y = a.y;
        return *this;
    }
    _vector _vector::operator*(float f){
        return _vector(this->x*f, this->y*f);
    }