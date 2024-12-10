#include <memory>
#include "Person.h"

#pragma once

using namespace std;

class Sorter {
public:
    static bool compareByAge(const shared_ptr<Person>& a, const shared_ptr<Person>& b);

};