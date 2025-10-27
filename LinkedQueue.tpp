template <typename T>
LinkedQueue<T>::LinkedQueue() : head(nullptr), last(nullptr) {
    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) : head(nullptr), last(nullptr) {
    this->length = 0;
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    if (isEmpty()) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    Node* cur = head;
    while (cur != nullptr) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
    last = nullptr;
    this->length = 0;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    Node* cur = copyObj.head;
    while (cur != nullptr) {
        enqueue(cur->value);
        cur = cur->next;
    }
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    if (isEmpty()) {
        throw string("dequeue: error, queue is empty, avoiding underflow");
    }
    Node* tmp = head;
    head = head->next;
    delete tmp;
    --(this->length);
    if (head == nullptr) {
        last = nullptr;
    }
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    Node* node = new Node(elem, nullptr);
    if (isEmpty()) {
        head = last = node;
    } else {
        last->next = node;
        last = node;
    }
    ++(this->length);
}

template <typename T>
T LinkedQueue<T>::front() const {
    if (isEmpty()) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}