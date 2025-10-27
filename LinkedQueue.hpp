#ifndef LINKED_QUEUE_HPP
#define LINKED_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class LinkedQueue : public Queue<T> {
protected:
    struct Node {
        T value;
        Node* next;
        Node(T v = T(), Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head;
    Node* last;

private:
    void copy(const LinkedQueue<T>&);

public:
    LinkedQueue();
    LinkedQueue(const LinkedQueue<T>&);
    LinkedQueue<T>& operator=(const LinkedQueue<T>&);
    virtual ~LinkedQueue();

    virtual T back() const override;
    virtual void clear() override;
    virtual void dequeue() override;
    virtual void enqueue(const T&) override;
    virtual T front() const override;
    virtual int getLength() const override;
    virtual bool isEmpty() const override;
};

#include "LinkedQueue.tpp"
#endif