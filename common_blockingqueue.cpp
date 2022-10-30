#include <queue>
#include <mutex>
#include <condition_variable>
#include "common_blockingqueue.h"

template<typename T>
void BlockingQueue<T>::push(T& element) {
    std::unique_lock<std::mutex> lock(mutex);
    internal.push(element);
    keep_popping.notify_all();
}

template<typename T>
T BlockingQueue<T>::pop() {
    std::unique_lock<std::mutex> lock(mutex);
    
    while (internal.empty()) {
        keep_popping.wait();
    }

    T element = internal.front();
    internal.pop();
    return element;
}
