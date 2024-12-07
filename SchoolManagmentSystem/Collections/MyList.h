#ifndef MY_LIST_H
#define MY_LIST_H

#include <iterator>
#include <cassert>

template <typename T>
class MyList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

    Node* getNodeAt(int i) const {
        Node* current = head;
        int index = 0;
        while (current && index < i) {
            current = current->next;
            index++;
        }
        return current;
    }

public:
    MyList() : head(nullptr), tail(nullptr), listSize(0) {}

    MyList(const MyList<T>& other) : head(nullptr), tail(nullptr), listSize(0) {
        Node* current = other.head;
        while (current) {
            append(current->data);
            current = current->next;
        }
    }

    MyList<T>& operator=(const MyList<T>& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                append(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    ~MyList() {
        clear();
    }

    void append(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        listSize++;
    }

    void prepend(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    void insert(int i, const T& value) {
        if (i < 0 || i > listSize) return;
        if (i == 0) {
            prepend(value);
            return;
        }
        if (i == listSize) {
            append(value);
            return;
        }

        Node* prevNode = getNodeAt(i - 1);
        Node* newNode = new Node(value);
        Node* nextNode = prevNode->next;

        newNode->next = nextNode;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        if (nextNode) nextNode->prev = newNode;

        listSize++;
    }

    void removeAt(int i) {
        if (i < 0 || i >= listSize) return;

        Node* nodeToRemove = getNodeAt(i);
        Node* prevNode = nodeToRemove->prev;
        Node* nextNode = nodeToRemove->next;

        if (prevNode) prevNode->next = nextNode;
        if (nextNode) nextNode->prev = prevNode;

        if (i == 0) head = nextNode;
        if (i == listSize - 1) tail = prevNode;

        delete nodeToRemove;
        listSize--;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        listSize = 0;
    }

    T at(int i) const {
        Node* node = getNodeAt(i);
        assert(node != nullptr);
        return node->data;
    }

    T& operator[](int i) const {
        Node* node = getNodeAt(i);
        assert(node != nullptr);
        return node->data;
    }

    T first() const {
        assert(!isEmpty());
        return head->data;
    }

    T last() const {
        assert(!isEmpty());
        return tail->data;
    }

    void replace(int i, const T& value) {
        Node* node = getNodeAt(i);
        assert(node != nullptr);
        node->data = value;
    }

    bool contains(const T& value) const {
        Node* current = head;
        while (current) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    bool isEmpty() const {
        return listSize == 0;
    }

    int size() const {
        return listSize;
    }

    class Iterator {
    private:
        Node* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        Iterator(Node* node) : current(node) {}

        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        Iterator& operator--() {
            if (current) current = current->prev;
            return *this;
        }

        T& operator*() const {
            return current->data;
        }

        T* operator->() const {
            return &(current->data);
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    class ConstIterator {
    private:
        const Node* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        ConstIterator(const Node* node) : current(node) {}

        ConstIterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        ConstIterator& operator--() {
            if (current) current = current->prev;
            return *this;
        }

        const T& operator*() const {
            return current->data;
        }

        const T* operator->() const {
            return &(current->data);
        }

        bool operator!=(const ConstIterator& other) const {
            return current != other.current;
        }

        bool operator==(const ConstIterator& other) const {
            return current == other.current;
        }
    };

    ConstIterator cbegin() const {
        return ConstIterator(head);
    }

    ConstIterator cend() const {
        return ConstIterator(nullptr);
    }

    class ReverseIterator {
    private:
        Node* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        ReverseIterator(Node* node) : current(node) {}

        ReverseIterator& operator++() {
            if (current) current = current->prev;
            return *this;
        }

        ReverseIterator& operator--() {
            if (current) current = current->next;
            return *this;
        }

        T& operator*() const {
            return current->data;
        }

        T* operator->() const {
            return &(current->data);
        }

        bool operator!=(const ReverseIterator& other) const {
            return current != other.current;
        }

        bool operator==(const ReverseIterator& other) const {
            return current == other.current;
        }
    };

    ReverseIterator rbegin() const {
        return ReverseIterator(tail);
    }

    ReverseIterator rend() const {
        return ReverseIterator(nullptr);
    }

    class ConstReverseIterator {
    private:
        const Node* current;
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        ConstReverseIterator(const Node* node) : current(node) {}

        ConstReverseIterator& operator++() {
            if (current) current = current->prev;
            return *this;
        }

        ConstReverseIterator& operator--() {
            if (current) current = current->next;
            return *this;
        }

        const T& operator*() const {
            return current->data;
        }

        const T* operator->() const {
            return &(current->data);
        }

        bool operator!=(const ConstReverseIterator& other) const {
            return current != other.current;
        }

        bool operator==(const ConstReverseIterator& other) const {
            return current == other.current;
        }
    };

    ConstReverseIterator crbegin() const {
        return ConstReverseIterator(tail);
    }

    ConstReverseIterator crend() const {
        return ConstReverseIterator(nullptr);
    }

    class RandomAccessIterator {
    private:
        MyList* list;
        int index;

    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        RandomAccessIterator(MyList* list, int index) : list(list), index(index) {}

        T& operator*() const {
            return (*list)[index];
        }

        RandomAccessIterator& operator++() {
            ++index;
            return *this;
        }

        RandomAccessIterator operator++(int) {
            RandomAccessIterator temp = *this;
            ++(*this);
            return temp;
        }

        RandomAccessIterator& operator--() {
            --index;
            return *this;
        }

        RandomAccessIterator operator--(int) {
            RandomAccessIterator temp = *this;
            --(*this);
            return temp;
        }

        RandomAccessIterator& operator+=(difference_type n) {
            index += n;
            return *this;
        }

        RandomAccessIterator& operator-=(difference_type n) {
            index -= n;
            return *this;
        }

        RandomAccessIterator operator+(difference_type n) const {
            return RandomAccessIterator(list, index + n);
        }

        RandomAccessIterator operator-(difference_type n) const {
            return RandomAccessIterator(list, index - n);
        }

        difference_type operator-(const RandomAccessIterator& other) const {
            return index - other.index;
        }

        bool operator==(const RandomAccessIterator& other) const {
            return list == other.list && index == other.index;
        }

        bool operator!=(const RandomAccessIterator& other) const {
            return !(*this == other);
        }

        bool operator<(const RandomAccessIterator& other) const {
            return index < other.index;
        }

        bool operator>(const RandomAccessIterator& other) const {
            return index > other.index;
        }

        bool operator<=(const RandomAccessIterator& other) const {
            return index <= other.index;
        }

        bool operator>=(const RandomAccessIterator& other) const {
            return index >= other.index;
        }
    };

    RandomAccessIterator rabegin() {
        return RandomAccessIterator(this, 0);
    }

    RandomAccessIterator raend() {
        return RandomAccessIterator(this, listSize);
    }
};

#endif
