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
        if ( (int) internal.size() > cap) {
            internal.pop_front();
        }
    }

    T pop_front() {
        T elem = internal.front();
        if (internal.size() > 1) {
            internal.pop_front();
        }
        return elem;
    }

};
