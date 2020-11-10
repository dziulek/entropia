#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <utility>

const float epsilon = 0.1;
const float defaultNumParticles = 1000;
const float defaultWidth = 200;
const float defaultHeight = 200;
const std::pair<float, float> defaultCorner = {10.0f, 10.0f};
//const float radiusOfParticle = 30.0f;
const float minimumRadius = 1.0f;
const float StartDensityOfParticles = 0.8; //fraction of radius of particle
const std::pair<float, float> defaultSizeOfStartBox = {300.0f, 300.0f};
const float rim = 10.0f;

const unsigned int nOfIntervals = 12;

const float avspeed = 40.0f;

//plot
const float plotRim = 50.0f;

const float defaultSizeOfPlotView = 1000.0f;

const int maxVertex = 1010;
#endif