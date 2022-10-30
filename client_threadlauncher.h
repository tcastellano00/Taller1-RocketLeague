#include "common_socket.h"
#include "client_gamestatusmonitor.h"

class ThreadLauncher {
public:
    ThreadLauncher();
    void start(Socket& connection,GameStatusMonitor& gameStatusMonitor);
    
};

