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
    
    bool empty(){
        std::unique_lock<std::mutex> lock(mutex);
        return internal.empty();
    }
    
    ~Queue() {
        std::cout << "Se destruye la cola" << std::endl;
    }
};

#endif

