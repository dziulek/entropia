#ifndef _VECTOR_HPP
#define _VECTOR_HPP

class _vector{
    public:

    float x;
    float y;

    _vector(float x, float y);
    _vector();

    bool operator==(_vector a);
    _vector operator+(_vector a);
    inline static _vector negation(_vector a);
    _vector operator=(_vector a);
    _vector operator*(float f);
    inline static float length(_vector a);
    inline static _vector normalize(_vector a);
    inline static float dotProduct(_vector a, _vector b);
};

#endif