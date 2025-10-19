#include "libs.h"
#include "node.hpp"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// I think I generally have everything I want in my linked list now - I'll call it complete
template <typename T>
class LinkedList
{
    public:

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    LinkedList(const LinkedList& other)
    {
        head = new Node<T>(other.head->get_data());
        Node<T>* t_temp = head;
        Node<T>* o_temp = other.head->get_next();
        // Deep copy
        while (o_temp != nullptr)
        {
            t_temp->set_next(new Node<T>(o_temp->get_data()));
            o_temp = o_temp->get_next();
            t_temp = t_temp->get_next();
        }
        tail = t_temp;
        size = other.size;
    }

    ~LinkedList()
    {
        Node<T>* temp = head;
        while (head != nullptr)
        {
            head = head->get_next();
            delete temp;
            temp = head;
        }
        tail = nullptr;
        size = 0;
    }

    void push_back(const T& data);

    void erase(const T& data);

    int get_size();

    bool empty() const {return (head == nullptr);}

    void clear();

    class iterator
    {
        public:

        iterator(Node<T>* newnode) {node = newnode;}

        iterator& operator++() 
        {
            if (node) node = node->get_next(); 
            return *this;
        }

        iterator& operator--()
        {
            if (node) node = node->get_prev();
            return *this;
        }

        bool operator!=(const iterator& other) const {return this->node != other.node;}

        bool operator==(const iterator& other) const {return this->node == other.node;}

        T& operator*() const {return this->node->get_data();} // Return data rather than node, cause user shouldn't have to mess with node stuff

        private:
        Node<T>* node;
    };

    iterator begin() {return iterator(head);}

    iterator end() {return iterator(nullptr);}

    iterator find(const T& val);

    template <typename U>
    friend ostream& operator<<(ostream& lhs, LinkedList<U>& rhs);

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
void LinkedList<T>::erase(const T&data)
{
    // This looks ugly, come back to this
    Node<T>* temp = head;
    while (temp != nullptr && temp->get_data() != data) temp = temp->get_next();
    if (!temp) {return;}
    if (temp == head)
    {
        head = head->get_next();
        head->set_prev(nullptr);
    }
    else if (temp == tail)
    {
        tail = tail->get_prev();
        tail->set_next(nullptr);
    }
    else
    {
        if (temp->get_next()){temp->get_next()->set_prev(temp->get_prev());}
        temp->get_prev()->set_next(temp->get_next());
    }
    delete temp;
    --size;
}

template <typename T>
inline int LinkedList<T>::get_size()
{
    return size;
}

template <typename T>
void LinkedList<T>::clear()
{
    // Basically the same as the deconstructor
    Node<T>* temp = head;
        while (head != nullptr)
        {
            head = head->get_next();
            delete temp;
            temp = head;
        }
        tail = nullptr;
        size = 0;
}

template <typename U>
ostream &operator<<(ostream &lhs, LinkedList<U> &rhs)
{
    auto it = rhs.begin();
    while (it != rhs.end())
    {
        lhs << *it << endl;
        ++it;
    }
    return lhs;
}

template <typename T>
typename LinkedList<T>::iterator LinkedList<T>::find(const T &val)
{
    auto it = this->begin();

    while (it != this->end() && *it != val)
    {
        ++it;
    }

    return it;
}

template <typename T>
void LinkedList<T>::push_back(Node<T> *&node)
{
    if (!node) return;
    if (empty()) 
    {
        head = node;
        tail = head;
        size++;
        return;
    }
    tail->set_next(node);
    node->set_prev(tail);
    tail = node;
    size++;
}

#endif