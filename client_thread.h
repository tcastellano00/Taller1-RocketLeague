#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
private:
	std::thread t;

    // This template method catches exceptions (they can't be caught from main)
    void runExpecting();

protected:
    virtual void run() = 0;

public:
    /**
     * @brief      Starts a thread with the behavior of the method run().
     */
    void start();
    void join();
    virtual ~Thread() = default;
};

#endif
