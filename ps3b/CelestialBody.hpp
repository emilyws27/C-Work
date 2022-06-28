// "Copyright 2022 Emily Sheehan"

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class CelestialBody: public sf::Drawable {
 private:
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
    double universe_radius, window_radius, xpos, ypos, xvel, yvel, mass;
    std::string img_name;
    sf::Image image;
    sf::Sprite sprite;
    sf::Texture texture;

 public:
    friend std::istream& operator>> (std::istream &input, CelestialBody &CB);
    friend std::ostream& operator<< (std::ostream &output, CelestialBody &CB);

    void accelerate(CelestialBody &, double time);
    void updatePosition(double time);

    explicit CelestialBody(double universe_radius, double window_radius = 300);
};

std::istream& operator>> (std::istream &input, CelestialBody &CB);
std::ostream& operator<< (std::ostream &output, CelestialBody &CB);
