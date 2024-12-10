#include <memory>
#include <functional>
#include <iostream>
#include "Sorter.h"

template <typename T>
class Container {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;
        explicit Node(const T& value) : data(value), next(nullptr), prev() {}
    };

    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

public:
    class Iterator {
    public:
        explicit Iterator(const std::shared_ptr<Node>& node) : current(node) {}

        T& operator*() { return current->data; }

        Iterator& operator++() {
            current = current->next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            current = current->next;
            return temp;
        }

        Iterator& operator--() {
            if (auto prevNode = current->prev.lock()) {
                current = prevNode;
            }
            return *this;
        }

        Iterator operator--(int) {
            Iterator temp = *this;
            if (auto prevNode = current->prev.lock()) {
                current = prevNode;
            }
            return temp;
        }

        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }

        std::shared_ptr<Node> current;
    };

    Container() : head(nullptr), tail(nullptr) {}

    void add(const T& value) {
        auto newNode = std::make_shared<Node>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(const Iterator& it) {
        auto node = it.current;
        if (!node) return;

        if (node->prev.lock()) {
            node->prev.lock()->next = node->next;
        } else {
            head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev.lock();
        }
    }

    void sort() {
        if (!head || !head->next) return;

        for (auto i = head; i; i = i->next) {
            for (auto j = i->next; j; j = j->next) {
                if (Sorter::compareByAge(j->data, i->data)) {
                    std::swap(i->data, j->data);
                }
            }
        }
    }

    void printAll() const {
        for (auto current = head; current; current = current->next) {
            current->data->print();
        }
        std::cout << std::endl;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};
