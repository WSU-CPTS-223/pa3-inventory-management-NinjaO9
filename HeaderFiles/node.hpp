#include "libs.h"
#include "productdata.hpp"
#ifndef NODE_H
#define NODE_H

// Im happy with my node structure, so I will call it complete (even though I don't think I will ever use the overloaded << operator)
template <typename T>
class Node
{
    public:

    Node() 
    {
        prev = nullptr;
        next = nullptr;
    }

    Node(const T& newData) : data(newData) 
    {
        prev = nullptr;
        next = nullptr;
    }

    ~Node()
    {
        prev = nullptr;
        delete data;
        next = nullptr;
    }

    Node*& get_prev() {return prev;}

    void set_prev(Node*& node) {prev=node;}

    Node*& get_next() {return next;}

    void set_next(Node*& node) {next=node;}

    T& get_data() {return data;}

    void set_data(T& newdata) {data=newdata;}

    bool operator==(const Node<T>*& other);


    private:

    Node* prev;
    T data;
    Node* next;
};

template <typename T>
ostream& operator<<(ostream& lhs, Node<T>*& rhs);


template <typename T>
inline bool Node<T>::operator==(const Node<T> *&other)
{
    return this->data == other->data;
}

template <typename T>
ostream& operator<<(ostream& lhs, Node<T>*& rhs)
{
    lhs << rhs->get_data();
    return lhs;
}

#endif