#include "libs.h"
#include "node.hpp"

template <typename T>
class LinkedList
{
    public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(const T& data);

    void erase(T& data);

    int getSize();

    bool empty() {return (head == nullptr) &&(head == tail);}

    class iterator
    {
        public:

        iterator(Node<T>* newnode) {node = newnode;}

        void operator++() {if (node) node = node->getNext();}

        void operator--() {if (node) node = node->getPrev();}

        bool operator!=(const iterator& other) {return this->node != other.node;}

        Node<T>*& operator*() {return this->node;}

        private:
        Node<T>* node;
    };

    iterator begin() {return iterator(head);}

    iterator end() {return iterator(nullptr);}

    //friend ostream& operator<<(ostream& lhs, LinkedList<T>& rhs);

    private:

    void push_back(Node<T>*& node);

    Node<T>* head;
    Node<T>* tail;
    int size;

};

template <typename T>
void LinkedList<T>::push_back(const T& data)
{
    Node<T>* newNode = new Node<T>(data);
    push_back(newNode);
}

template <typename T>
void LinkedList<T>::erase(T &data)
{
    Node<T>* temp = head;
    while (temp != nullptr && temp->getdata() != data) temp = temp->getNext();
    if (!temp) {return;}
    if (temp == head){head = head->getNext();}
    else
    {
        if (temp->getNext()){temp->getNext()->setPrev(temp->getPrev());}
        temp->getPrev()->setNext(temp->getNext());
    }
    delete temp;
    --size;
}

template <typename T>
inline int LinkedList<T>::getSize()
{
    return size;
}

/*
template <typename T>
inline ostream &operator<<(ostream &lhs, LinkedList<T> &rhs)
{
    auto it = rhs.begin();
    while (it != rhs.end())
    {
        lhs << (*it);
    }
    return lhs;
}
    */

template <typename T>
void LinkedList<T>::push_back(Node<T> *&node)
{
    if (!node) return;
    if (empty()) 
    {
        head = node;
        tail = head;
        return;
    }
    tail->setNext(node);
    node->setPrev(tail);
    tail = node;
    size++;
}