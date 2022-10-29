#include <iostream>
#include "common_thread.h"


void Thread::runExpecting() {
    try {
        run();
    } catch (const std::exception &e) {
        std::cerr << "Exception caught in a thread: '"
                  << e.what() << "'" << std::endl;
    } catch (...) {
        std::cerr << "Unknown error caught in thread" << std::endl;
    }
}

void Thread::start() {
    t = std::thread(&Thread::runExpecting, this);
}


void Thread::join() {
    t.join();
}
