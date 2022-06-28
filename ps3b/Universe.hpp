// "Copyright 2022 Emily Sheehan"

#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "CelestialBody.hpp"

class Universe : public sf::Drawable {
 private:
    unsigned int n;
    float r;
    std::vector<std::shared_ptr<CelestialBody>> c_bodies;
    void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;

 public:
    explicit Universe(unsigned int num_planets = 0, float radius = 0);

    friend std::istream& operator>> (std::istream &input, Universe &u);
    friend std::ostream& operator<< (std::ostream &output, Universe &u);

    void step(double time);

    ~Universe();
};

std::istream& operator>> (std::istream &input, Universe &u);
std::ostream& operator<< (std::ostream &output, Universe &u);
