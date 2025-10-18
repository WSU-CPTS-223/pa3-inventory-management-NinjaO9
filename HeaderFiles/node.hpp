#include "libs.h"
#include "productdata.hpp"

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

    Node*& getPrev() {return prev;}

    void setPrev(Node*& node) {prev=node;}

    Node*& getNext() {return next;}

    void setNext(Node*& node) {next=node;}

    T& getdata() {return data;}

    void setData(T& newdata) {data=newdata;}

    bool operator==(const Node<T>*& other);

    private:

    Node* prev;
    T data;
    Node* next;
};

template <typename T>
inline bool Node<T>::operator==(const Node<T> *&other)
{
    return this->data == other->data;
}
