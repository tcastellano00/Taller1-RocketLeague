#ifndef QUEUE_H
#define QUEUE_H

#include <queue>
#include <mutex>
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
    //le agrego un metodo para ver si esta vacia
    bool empty(){
        return internal.empty();
    }
};

#endif

