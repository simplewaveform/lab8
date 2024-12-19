#pragma once

#include "Person.h"

class Sorter {
public:
    template <typename U>
    static bool compare(const U& a, const U& b) {
        if constexpr (std::is_same_v<U, std::shared_ptr<Person>>) {
            return a->getAge() < b->getAge();
        } else {
            return a < b;
        }
    }

};