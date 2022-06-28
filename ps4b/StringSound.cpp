//  "Copyright 2022 Emily Sheehan"

#include <chrono>
#include <vector>
#include "StringSound.hpp"


StringSound::StringSound(double frequency) {
    unsigned int seed = std::chrono::system_clock::now()
                        .time_since_epoch().count();
    gen.seed(seed);
    int buffer_size = ceil(44100/frequency);
    this -> tics = 0;
    this -> cb = new CircularBuffer<sf::Int16>(buffer_size);
    for (int x=0; x < buffer_size; x++) {
        cb->enqueue(0);
    }
}
StringSound::StringSound(double frequency, unsigned int seed)
            : StringSound(frequency) {
    gen.seed(seed);
}

StringSound::StringSound(std::vector<sf::Int16> init) {
    unsigned int seed = std::chrono::system_clock::now()
                        .time_since_epoch().count();
    gen.seed(seed);
    this->cb = new CircularBuffer<sf::Int16>(init.size());
    this -> tics = 0;
    for (std::size_t i = 0; i < init.size(); i++) {
        this -> cb -> enqueue(init.at(i));
    }
}
void StringSound::pluck() {
    int max = 32767;
    int min = -32768;
    std::uniform_int_distribution<int> dist(min, max);

    cb->empty();
    while (!cb->isFull()) {
        int num = dist(gen);
        cb -> enqueue(num);
    }
}

void StringSound::tick() {
    tics++;
    sf::Int16 deleted = cb->dequeue();
    sf::Int16 first = cb->peek();
    sf::Int16 avg = .996*((deleted + first)/2);
    cb->enqueue(avg);
}

sf::Int16 StringSound::sample() const {
    return this->cb->peek();
}

size_t StringSound::time() const {
    return tics;
}
