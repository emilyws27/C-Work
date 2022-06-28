// Copyright 2022 Emily Sheehan

#include "RandWriter.hpp"
#include<bits/stdc++.h>

#include <string>
#include <algorithm>
#include <map>
#include <utility>
#include <stdexcept>
#include <vector>
#include <ctime>
#include <cmath>
#include <chrono>
#include <random>

RandWriter::RandWriter(std::string text, int k) {
    if (k < 0) {
        throw std::invalid_argument("k must be at least 0");
    }
    if (static_cast<int>(text.size()) < k) {
        throw std::invalid_argument("text length must be larger than k");
    }

    srand(time(NULL));
    num = k;
    std::string words = text;
    for (unsigned int i = 0; i < text.size(); i++) {
        size_t pos = letters_used.find(text[i]);
        if (std::string::npos == pos) {
            letters_used.push_back(text[i]);
        }
    }

    for (unsigned int i = 0; i < text.size(); i++) {
        std::string temp;
        if ((i+k) > text.size()) {
            temp = text.substr(i) + text.substr(0, k - text.size() + i);
        } else {
            temp = text.substr(i, k);
        }
        char c = text[(i+k) % text.size()];
        kgrams[temp]++;
        kgrams[temp+c]++;
    }
}

int RandWriter::orderK() const {
    return num;
}

int RandWriter::freq(std::string kgram) const {
    int klen = kgram.length();

    if (klen !=num) {
        throw std::runtime_error("kgram is not length k");
    }
    auto it = kgrams.find(kgram);

    if (it == kgrams.end()) {
        return 0;
    }

    return it->second;
}

int RandWriter::freq(std::string kgram, char c) const {
    int klen = kgram.length();
    if (klen !=num) {
        throw std::runtime_error("kgram is not length k");
    }

    kgram.push_back(c);
    auto it = kgrams.find(kgram);

    if (it == kgrams.end()) {
        return 0;
    }

    return it->second;
}

char RandWriter::kRand(std::string kgram) {
    auto it = kgrams.find(kgram);

    int klen = std::count_if(kgram.begin(),
                             kgram.end(),
                            [](char c) {
                                return true;
                            });
    // int klen = count(kgram.begin(), kgram.end(), [](int i) { return i++; });

    if (klen !=num) {
        throw std::runtime_error("kgram is not of length k");
    }
    if (it == kgrams.end()) {
        throw std::runtime_error("no such kgram");
    }
    std::mt19937 gen;
    unsigned int seed = std::chrono::system_clock::now()
                        .time_since_epoch().count();
    gen.seed(seed);
    int max = 32767;
    int min = -32768;
    std::uniform_int_distribution<int> dist(min, max);
    int q = dist(gen);

    int ran = q % freq(kgram);
    double test_freq = 0;
    double ran2 = static_cast<double>(ran) / freq(kgram);
    double prev = 0;

    for (unsigned int i= 0; i< (unsigned)letters_used.length(); i++) {
        int f = freq(kgram, letters_used[i]);

        test_freq = static_cast<double>(f)/ freq(kgram);
        if (ran2 < test_freq + prev && test_freq != 0) {
            return letters_used[i];
        }
        prev = prev + test_freq;
    }
    return ' ';
}

std::string RandWriter::generate(std::string kgram, int L) {
    int klen = kgram.length();

    if (klen !=num) {
        throw std::runtime_error("kgram not of length k");
    }

    std::string final_string = "";
    char return_char;
    final_string += kgram;

    for (int i= 0; i< (L - num); i++) {
        std::string sub = final_string.substr(i, num);
        return_char = kRand(sub);
        final_string.push_back(return_char);
    }
    return final_string;
}
std::ostream &operator<<(std::ostream &o, RandWriter &rw) {
    o << "Original: " << rw.words  << std::endl;
    o << "Order: " << rw.num << std::endl;
    o << "Alphabet: " << rw.letters_used << std::endl;

    std::map<std::string, int>::iterator it;
    for (it = rw.kgrams.begin(); it != rw.kgrams.end(); it++) {
        o << it->first << "   " << it->second << std::endl;
    }

    return o;
}
