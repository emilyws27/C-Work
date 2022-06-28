// "Copyright 2022 Emily Sheehan"

#pragma once

#include <string>
#include <iostream>
#include <queue>
#include <exception>
#include <utility>

template<typename T>
class CircularBuffer {
 public:
    explicit CircularBuffer(size_t c);
    size_t size() const;
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(T item);
    void empty();
    T dequeue();
    T peek() const;
 private:
    size_t capacity;
    std::queue<T> q;
};

template<typename T>
CircularBuffer<T>::CircularBuffer(size_t c) : capacity(c), q() {
    if (capacity < 1) {
        throw std::invalid_argument("capacity less than 1");
    }
}

template<typename T>
size_t CircularBuffer<T>::size() const {
    return q.size();
}

template<typename T>
bool CircularBuffer<T>::isEmpty() const {
    return q.empty();
}

template<typename T>
void CircularBuffer<T>::empty() {
    std::queue<T> empty;
    std::swap(q, empty);
}

template<typename T>
bool CircularBuffer<T>::isFull() const {
    if (q.size() == capacity) {
        return true;
    }
    return false;
}

template<typename T>
void CircularBuffer<T>::enqueue(T item) {
    if (isFull()) {
        throw std::runtime_error("buffer is already at capacity");
    }
    q.emplace(item);
}

template<typename T>
T CircularBuffer<T>::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("buffer is empty");
    }
    T t = q.front();
    q.pop();
    return t;
}

template<typename T>
T CircularBuffer<T>::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("buffer is empty");
    }
    return q.front();
}
