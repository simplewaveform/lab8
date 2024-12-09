#include "Sorter.h"

bool Sorter::compareByAge(const shared_ptr<Person>& a, const shared_ptr<Person>& b) {

    return a->getAge() < b->getAge();
}