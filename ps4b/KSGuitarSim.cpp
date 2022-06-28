/*
  Copyright 2015 Fred Martin,
  Y. Rykalova, 2020
  J. Daly 2022
*/

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include "CircularBuffer.hpp"
#include "StringSound.hpp"

#define TOTAL 400
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamples(StringSound &gs) {
    std::vector<sf::Int16> samples;
    gs.pluck();
    int duration = 8;
    int i;
    for (i = 0; i < SAMPLES_PER_SEC * duration; i++) {
        gs.tick();
        samples.push_back(gs.sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200),
                            "SFML Plucked String Sound Lite");
    sf::Event event;
    double freq;
    std::vector<std::vector<sf::Int16>> samples;

    freq = TOTAL;
    StringSound ss(freq);
    sf::Sound sound1;
    sf::SoundBuffer buf1;

    int index;
    std::string keys = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

    int vals[] = {16, 28, 22, 4, 30, 17, 31, 19, 24, 33,
                  20, 34, 8, 35, 14, 15, 56, 46, 55, 25,
                  23, 3, 2, 5, 21, 6, 1, 13, 9, 12, 10,
                  49, 50, 48, 52, 51, 57};

    std::vector<int> numbers;

    for (int i = 0; i < 37; i++) {
        std::vector<sf::Int16> s;
        numbers.push_back(vals[i]);
        freq = 440 * (pow(2.0, ((24 - i) / 12.0)));
        ss = StringSound(freq);
        try {
            s = makeSamples(ss);
        }
        catch (const std::exception &e) {
            std::cout << "error in make samples" << std::endl;
        }
        samples.push_back(s);
    }

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                    index = std::find(numbers.begin(), numbers.end(),
                                      event.key.code) -
                            numbers.begin();
                    if (index < 37) {
                        if (!buf1.loadFromSamples(&(samples[index][0]),
                            samples[index].size(), 2, SAMPLES_PER_SEC)) {
                            throw std::runtime_error(
                                "sf::SoundBuffer: failed to load from samples");
                        }
                        sound1.setBuffer(buf1);
                        sound1.play();
                    }
                }
            }
        }
            return 0;
    }
