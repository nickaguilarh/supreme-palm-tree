#ifndef DOUBLE_H
#define DOUBLE_H

#include "iterator.h"

template<typename T>
class DoubleListIterator : public Iterator<T> {
public:
    DoubleListIterator() : Iterator<T>() {};

    explicit DoubleListIterator(Node<T> *current) : Iterator<T>(current) {};

    DoubleListIterator<T> &operator++() {
        this->current = this->current->next;
        return *this;
    }//++it

    DoubleListIterator<T> operator++(int) //it++
    {
        Node<T> *temp = this->current;
        this->current = this->current->next;
        return DoubleListIterator<T>(temp);//mas memoria
    }

    DoubleListIterator<T> &operator--() {
        this->current = this->current->prev;
        return *this;
    }//--it

    DoubleListIterator<T> operator--(int) //it--
    {
        Node<T> *temp = this->current;
        this->current = this->current->prev;
        return DoubleListIterator<T>(temp);//mas memoria
    }
};

template<typename T>
class DoubleList : public List<T> {
public:
    T front() override {
        T value = this->head->data;
        return value;
    }

    T back() override {
        T value = this->tail->data;
        return value;
    }

    void push_front(T t) override {
        Node<T> *node = new Node<T>(t);
        node->next = this->head;
        this->head = node;
        if (this->nodes == 0) {
            this->tail = node;
        }else{
            node->next->prev = node;
        }
        this->nodes++;
    }

    void push_back(T t) override {
        Node<T> *node = new Node<T>(t);
        node->prev = this->tail;
        this->tail->next = node;
        this->tail = node;
        this->nodes++;
    }

    T pop_front() override {
        T value = this->head->data;
        this->head = this->head->next;

        this->nodes--;
        return value;
    }

    T pop_back() override {
        T value = this->tail->data;

        Node<T> *tmp = this->tail;
        this->tail = tmp->prev;
        delete tmp;

        this->nodes--;
        return value;
    }

    T insert(T t, int pos) override {
        Node<T> *node = new Node<T>(t);

        Node<T> *looper = this->head;

        if (pos == 0) {
            this->push_front(t);
        }

        for (int i = 0; i < pos; ++i) {
            if (pos == i + 1) {
                node->next = looper->next;
                looper->next = node;
            }
        }

        delete looper;
        this->nodes++;
        return t;
    }

    void remove(T t) override {
        Node<T> *looper = this->head;

        while (looper != nullptr) {
            if (looper == this->head && looper->data == t) {
                this->head = looper->next;
                this->nodes--;
                looper = looper->next;
                continue;
            }
            if (looper->next != nullptr && looper->next->data == t) {
                if (looper->next == this->tail) {
                    this->tail = looper;
                }
                Node<T> *aux = looper->next->next;
                delete looper->next;
                looper->next = aux;
                this->nodes--;
                looper = looper->next;
                continue;
            }
            looper = looper->next;
        }

        delete looper;
    }

    T operator[](int pos) override {
        T value;

        int current = 0;
        Node<T> *looper = this->head;
        while (looper != nullptr) {
            if (current == pos) {
                value = looper->data;
                break;
            }
            looper = looper->next;
            current++;
        }
        delete looper;
        return value;
    }

    bool empty() override {
        return this->nodes == 0;
    }

    bool find(T t) override {
        Node<T> *looper = this->head;
        while (looper != nullptr) {
            if (looper->data == t) {
                return true;
            }
            looper = looper->next;
        }
        delete looper;
        return false;
    }

    int size() override {
        return this->nodes;
    }

    void clear() override {
        this->head->killSelf();
        this->nodes = 0;
    }

    void sort() override {
        T tmp;

        Node<T> *current = this->head;
        Node<T> *index;

        if (this->head == nullptr) {
            return;
        }

        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    tmp = current->data;
                    current->data = index->data;
                    index->data = tmp;
                }
                index = index->next;
            }
            current = current->next;
        }

    }

    bool is_sorted() override {
        return false;
    }

    List<T> *reverse() override {
        return nullptr;
    }

    void display(std::ostream &os) override {
        os << name() << ": ";

        Node<T> *looper = this->head;
        while (looper != nullptr) {
            os << looper->data << " ";
            looper = looper->next;
        }

        delete looper;
        os << "\n\r";
    }

    std::string name() override {
        return "DoubleList";
    }

public:
    typedef DoubleListIterator<T> iterator;

public:
    /* new functions */
    iterator begin() {
        return iterator(this->head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    ~DoubleList() {
        if (this->head) {
            this->head->killSelf();
        }
    }
};

#endif