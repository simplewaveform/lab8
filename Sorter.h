#include <memory>
#include "Person.h"

using namespace std;

class Sorter {
public:
    static bool compareByAge(const shared_ptr<Person>& a, const shared_ptr<Person>& b);

};