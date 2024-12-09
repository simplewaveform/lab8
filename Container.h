#include <vector>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
class Container {
private:
    vector<shared_ptr<T>> elements;

public:
    class Iterator {
    public:
        explicit Iterator(typename vector<shared_ptr<T>>::iterator it);
        shared_ptr<T>& operator*();
        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator!=(const Iterator& other) const;
        bool operator==(const Iterator& other) const;

        typename vector<shared_ptr<T>>::iterator current;

    };

    Iterator begin();
    Iterator end();
    void add(const shared_ptr<T>& element);
    void remove(const Iterator& it);
    void sort(function<bool(const shared_ptr<T>&, const shared_ptr<T>&)> compare);
    void printAll() const;

};