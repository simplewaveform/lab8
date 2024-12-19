#include <iostream>
#include <vector>
#include <algorithm>
#include "Sorter.h"

template <typename T>
class Container {
    static_assert(std::is_same_v<T, std::shared_ptr<Person>>,
                  "Контейнер поддерживает только std::shared_ptr<Person>.");

private:
    T* data;
    size_t capacity;
    size_t m_size;

    void reallocate(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = std::move(data[i]);
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    class Iterator {
    public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        pointer ptr;
        bool is_valid;

        explicit Iterator(pointer p) : ptr(p), is_valid(true) {}

        void invalidate() { is_valid = false; }

        Iterator& operator++() {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            ++ptr;

            return *this;
        }

        Iterator operator++(int) {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            Iterator temp = *this;
            ++ptr;

            return temp;
        }

        Iterator& operator--() {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            --ptr;

            return *this;
        }

        Iterator operator--(int) {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            Iterator temp = *this;
            --ptr;

            return temp;
        }

        Iterator operator+(difference_type n) const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return Iterator(ptr + n);
        }

        Iterator operator-(difference_type n) const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return Iterator(ptr - n);
        }

        Iterator& operator+=(difference_type n) {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            ptr += n;

            return *this;
        }

        Iterator& operator-=(difference_type n) {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");
            ptr -= n;

            return *this;
        }

        difference_type operator-(const Iterator& other) const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return ptr - other.ptr;
        }

        reference operator*() const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return *ptr;
        }

        pointer operator->() const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return ptr;
        }

        reference operator[](difference_type n) const {

            if (!is_valid) throw std::out_of_range("Итератор недействителен.");

            return *(ptr + n);
        }

        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        bool operator<(const Iterator& other) const { return ptr < other.ptr; }
        bool operator>(const Iterator& other) const { return ptr > other.ptr; }
        bool operator<=(const Iterator& other) const { return ptr <= other.ptr; }
        bool operator>=(const Iterator& other) const { return ptr >= other.ptr; }

    };

    std::vector<Iterator> activeIterators;

    Container() : data(nullptr), capacity(0), m_size(0) {}

    ~Container() {

        delete[] data;

    }

    void clear() {

        delete[] data;
        data = nullptr;
        m_size = 0;
        capacity = 0;

    }

    void add(const T& value) {

        if (m_size == capacity) reallocate(capacity == 0 ? 1 : capacity * 2);
        data[m_size++] = value;
        syncIterators();

    }

    void remove(const Iterator& it) {

        if (it.ptr < data || it.ptr >= data + m_size) throw std::out_of_range("Итератор вне диапазона.");
        size_t index = it.ptr - data;
        for (size_t i = index; i < m_size - 1; ++i) data[i] = std::move(data[i + 1]);
        --m_size;
        syncIterators();

    }

    void sort() {

        std::sort(begin(), end(), [](const T& a, const T& b) { return Sorter::compare(a, b); });

    }

    void printAll() const {

        std::for_each(begin(), end(), [](const T& item) { item->print(); });
        std::cout << std::endl;

    }

    [[nodiscard]] size_t size() const { return m_size; }
    [[nodiscard]] bool empty() const { return m_size == 0; }

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + m_size); }

    Iterator begin() const { return Iterator(data); }
    Iterator end() const { return Iterator(data + m_size); }

    void addActiveIterator(const Iterator& it) {

        activeIterators.push_back(it);

    }

    void syncIterators() {

        for (auto& iter : activeIterators) {
            if (!iter.is_valid) continue;
            if (iter.ptr < data || iter.ptr >= data + m_size) {
                iter.invalidate();
            }
        }

    }

};