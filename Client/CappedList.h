#include <list>

template<typename T>
class CappedList {
private:
    int cap;
    std::list<T> internal;

public:
    CappedList(int cap) {
        this->cap = cap;
    }

    void push_back(T element) {
        internal.push_back(element);
        if (internal.size() > cap) {
            internal.pop_front();
        }
    }

};
