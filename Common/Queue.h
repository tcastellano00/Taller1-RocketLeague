#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>

template<typename T>
class Queue {
private:
    std::queue<T> internal;
    std::mutex mutex;
    std::condition_variable keep_popping;
    bool blocksPop;
public:

    // Prefiero que sean dos clases distintas en vez de un bool, sino cuando
    // blocksPop==false, esa condition variable ni se usa.
    Queue(bool blocksPop) {
        this->blocksPop = blocksPop; 
    }

    void push(T element) {
        std::unique_lock<std::mutex> lock(mutex);
        internal.push(element);
        keep_popping.notify_all();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex);

        if (this->blocksPop) {
            while (internal.empty()) {
                keep_popping.wait(lock);
            }
        }

        T element = internal.front();
        internal.pop();
        return element;
    }
    

    // Los métodos de abajo también tienen que tomar el mutex!

    //le agrego un metodo para ver si esta vacia
    bool empty(){
        return internal.empty();
    }

    void liberar() {
        keep_popping.notify_all();
    }
    
    int longitud(){
        return internal.size();
    }
    
    ~Queue() {
        std::cout << "Se destruye la cola" << std::endl;
    }
};

#endif

