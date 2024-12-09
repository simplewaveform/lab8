#include "Container.h"
#include "Person.h"

using namespace std;

template <typename T>
Container<T>::Iterator::Iterator(typename vector<shared_ptr<T>>::iterator it) : current(it) {}

template <typename T>
shared_ptr<T>& Container<T>::Iterator::operator*() {

    return *current;
}

template <typename T>
Container<T>::Iterator& Container<T>::Iterator::operator++() {

    ++current;

    return *this;
}

template <typename T>
Container<T>::Iterator Container<T>::Iterator::operator++(int) {

    Iterator temp = *this;
    ++current;

    return temp;
}

template <typename T>
Container<T>::Iterator& Container<T>::Iterator::operator--() {

    --current;

    return *this;
}


template <typename T>
bool Container<T>::Iterator::operator!=(const Iterator& other) const {

    return current != other.current;
}

template <typename T>
bool Container<T>::Iterator::operator==(const Iterator& other) const {

    return current == other.current;
}

template <typename T>
void Container<T>::add(const shared_ptr<T>& element) {

    elements.push_back(element);

}

template <typename T>
void Container<T>::remove(const Iterator& it) {

    elements.erase(it.current);

}

template <typename T>
Container<T>::Iterator Container<T>::begin() {

    return Iterator(elements.begin());
}

template <typename T>
Container<T>::Iterator Container<T>::end() {

    return Iterator(elements.end());
}

template <typename T>
void Container<T>::sort(function<bool(const shared_ptr<T>&, const shared_ptr<T>&)> compare) {

    std::sort(elements.begin(), elements.end(), compare);

}

template <typename T>
void Container<T>::printAll() const {

    for (const auto& elem : elements) {
        elem->print();
    }

}

template class Container<Person>;