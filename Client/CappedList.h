#include <list>

/*
Lista con un tope maximo de elementos. Si se quiere agregar un nuevo elemento al final
de la lista cuando la misma se encuentra llena, se elimina el primer elemento de la lista,
para que la misma no supere su tope.
*/
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
