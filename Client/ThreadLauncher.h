#include "../Common/common_socket.h"
#include "GameStatusMonitor.h"

class ThreadLauncher {
public:
    ThreadLauncher();
    void start(Socket& connection,GameStatusMonitor& gameStatusMonitor);
    
};

