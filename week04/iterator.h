#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template<typename T>
class Iterator {
protected:
    Node<T> *current;

public:
    Iterator() : current(nullptr) {};

    explicit Iterator(Node<T> *current) : current(current) {};

    Iterator<T> &operator=(Iterator<T> other);

    bool operator!=(Iterator<T> other);

    T operator*();

};

template<typename T>
bool Iterator<T>::operator!=(Iterator<T> other) {
    return this->current != other.current;
}

template<typename T>
Iterator<T> &Iterator<T>::operator=(Iterator<T> other) {
    this->current = other.current;
    return *this;
}

template<typename T>
T Iterator<T>::operator*() {
    return this->current->data;
}

#endif