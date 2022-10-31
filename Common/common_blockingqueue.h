#ifndef COMMON_BLOCKINGQUEUE_H
#define COMMON_BLOCKINGQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class BlockingQueue {
private:
    std::queue<T> internal;
    std::mutex mutex;
    std::condition_variable keep_popping;

public:
    void push(T& element);

    T pop();

};

#endif