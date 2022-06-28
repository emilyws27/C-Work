//  "Copyright 2022 Emily Sheehan"

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <SFML/Audio.hpp>

#include "CircularBuffer.hpp"

#pragma once

class StringSound {
 public:
    explicit StringSound(double frequency);
    StringSound(double frequency, unsigned int seed);
    explicit StringSound(std::vector<sf::Int16> init);
    StringSound(const StringSound &obj) = delete;
    void pluck();
    void tick();
    sf::Int16 sample() const;
    size_t time() const;

 private:
    size_t tics;
    CircularBuffer<sf::Int16> *cb;
    std::mt19937 gen;
};
