#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <utility>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const float epsilon = 0.1;//for crashes
const float ep = 0.0000001;
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

//stats
const float statsRim = 50.0f;

//colors
//a) simulation

const sf::Color particleColor = sf::Color(255, 255, 255, 255);
const sf::Color spaceColor = sf::Color(122, 157, 255, 255);
const sf::Color startBoxColor = sf::Color(122, 77, 255, 255);
const sf::Color backSimColor = sf::Color(120, 127, 99, 255);

//b) plot
const sf::Color  axisColor = sf::Color(255, 255, 255, 255);
const sf::Color plotColor = sf::Color(65, 0, 0, 255);
const sf::Color backPlotColor = sf::Color(160, 154, 118, 255);

//c) stats

const sf::Color backStatsColor = sf::Color(177, 180, 167, 255);


#endif