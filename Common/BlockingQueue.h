#ifndef BLOCKING_QUEUE_H
#define BLOCKING_QUEUE_H

#include <queue>
#include <mutex>
#include <iostream>
#include <condition_variable>

template<typename T>
class BlockingQueue {
private:
    std::queue<T> internal;
    std::mutex mutex;
    std::condition_variable keep_popping;
public:
    BlockingQueue() { }

    void push(T element) {
        std::unique_lock<std::mutex> lock(mutex);
        internal.push(element);
        keep_popping.notify_all();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mutex);

        while (internal.empty()) {
            keep_popping.wait(lock);
        }

        T element = internal.front();
        internal.pop();
        return element;
    }
    
    bool empty(){
        std::unique_lock<std::mutex> lock(mutex);
        return internal.empty();
    }
    
    ~BlockingQueue() { }
};

#endif

