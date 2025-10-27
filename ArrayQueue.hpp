#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue : public Queue<T> {
private:
    T* buffer;
    int maxSize;
    int frontIndex;
    int backIndex;

    void copy(const ArrayQueue<T>&);

public:
    ArrayQueue(int = 100);
    ArrayQueue(const ArrayQueue<T>&);
    ArrayQueue<T>& operator=(const ArrayQueue<T>&);
    virtual ~ArrayQueue();

    virtual T back() const override;
    virtual void clear() override;
    virtual void dequeue() override;
    virtual void enqueue(const T&) override;
    virtual T front() const override;
    virtual int getLength() const override;
    int getMaxSize() const;
    virtual bool isEmpty() const override;
    bool isFull() const;
};

#include "ArrayQueue.tpp"
#endif