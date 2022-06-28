// "Copyright 2022 Emily Sheehan"

#include "CelestialBody.hpp"
#include "Universe.hpp"

Universe::Universe(unsigned int num_planets, float radius) {
    n = num_planets;
    r = radius;
}

std::istream& operator>> (std::istream &input, Universe &u) {
    input >> u.n;
    input >> u.r;

    for (unsigned int i = 0; i < u.n; i++) {
        std::shared_ptr<CelestialBody> c = std::make_shared<CelestialBody>(u.r);
        std::cin >> *c;
        u.c_bodies.push_back(c);
    }


    return input;
}

std::ostream& operator<< (std::ostream &output, Universe &u) {
    output << "Number of Planets: " << u.n << std::endl;
    output << "Radius: " << u.r << std::endl;
    for (auto c : u.c_bodies) {
        output << *c << std::endl;
    }
    return output;
}

void Universe::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (size_t i = 0; i < c_bodies.size(); i++) {
        target.draw(*c_bodies[i]);
    }
}
void Universe::step(double time) {
    for (auto c : c_bodies) {
        for (size_t i = 0; i < c_bodies.size(); i++) {
            if (c != c_bodies[i]) {
               c->accelerate(*c_bodies[i], time);
            }
        }
    }
    for (auto c : c_bodies) {
        c->updatePosition(time);
    }
}

Universe::~Universe() {}
