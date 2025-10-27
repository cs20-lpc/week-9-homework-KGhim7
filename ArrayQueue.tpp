template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    if (i <= 0) i = 1;
    buffer = new T[i];
    maxSize = i;
    this->length = 0;
    frontIndex = 0;
    backIndex  = -1;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    buffer = nullptr;
    maxSize = 0;
    this->length = 0;
    frontIndex = 0;
    backIndex  = -1;
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    delete[] buffer;
    buffer = nullptr;
    this->length = 0;
    frontIndex = 0;
    backIndex  = -1;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int k = 0; k < this->length; ++k) {
        int src = (copyObj.frontIndex + k) % copyObj.maxSize;
        buffer[k] = copyObj.buffer[src];
    }
    frontIndex = 0;
    backIndex  = this->length - 1;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("dequeue: error, queue is empty, avoiding underflow");
    }
    frontIndex = (frontIndex + 1) % maxSize;
    --(this->length);
    if (this->length == 0) {
        frontIndex = 0;
        backIndex  = -1;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    if (isFull()) {
        throw string("enqueue: error, queue is full, avoiding overflow");
    }
    if (buffer == nullptr) {
        buffer = new T[maxSize];
        frontIndex = 0;
        backIndex  = -1;
        this->length = 0;
    }
    backIndex = (backIndex + 1) % maxSize;
    buffer[backIndex] = elem;
    ++(this->length);
}

template <typename T>
T ArrayQueue<T>::front() const {
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}