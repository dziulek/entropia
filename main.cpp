#include <iostream>
#include "ball.hpp"


int main(){ 

    _vector a;
    _vector b=a + _vector(4,4)*2;
    std::cout<<b.x<<" "<<b.y<<std::endl;

    return 0;
}