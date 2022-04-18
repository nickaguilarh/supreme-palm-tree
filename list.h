#ifndef LIST_H
#define LIST_H

#include "node.h"

// TODO: Implement all methods
template<typename T>
class List {
protected:
    Node<T> *head;
    Node<T> *tail;
    int nodes;

public:
    List() : head(nullptr), tail(nullptr), nodes(0) {};

    ~List() {};

    virtual T front() = 0;

    virtual T back() = 0;

    virtual void push_front(T) = 0;

    virtual void push_back(T) = 0;

    virtual T pop_front() = 0;

    virtual T pop_back() = 0;

    virtual T insert(T, int) = 0;

    virtual void remove(T) = 0;

    virtual T operator[](int) = 0;

    virtual bool empty() = 0;

    virtual bool find(T) = 0;

    virtual int size() = 0;

    virtual void clear() = 0;

    virtual void sort() = 0;

    virtual bool is_sorted() = 0;

    virtual List *reverse() = 0;

    virtual void display(std::ostream &os) = 0;

    virtual std::string name() = 0;
};

#endif