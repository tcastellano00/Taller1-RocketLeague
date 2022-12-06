#ifndef NONBLOCKING_QUEUE_H
#define NONBLOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>

/*
Esta clase implementa la funcionalidad de una cola no bloqueante.
*/
template<typename T>
class NonBlockingQueue {
private:
    std::queue<T> internal;
    std::mutex mutex;
public:
    NonBlockingQueue() { }

    void push(T element) {
        std::unique_lock<std::mutex> lock(mutex);
        internal.push(element);
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex);
        T element = internal.front();
        internal.pop();
        return element;
    }
    
    bool empty(){
        std::unique_lock<std::mutex> lock(mutex);
        return internal.empty();
    }
    
    ~NonBlockingQueue() { }
};

#endif

