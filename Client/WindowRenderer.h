#include "GameStatusMonitor.h"
#include "ThreadCmdReader.h"

class WindowRenderer {
private:
    Queue<Command>& commandQueue;
    GameStatusMonitor& gameStatusMonitor;
    ThreadCmdReader threadCmdReader;

public:
    WindowRenderer(
        Queue<Command>& commandQueue,
        GameStatusMonitor& gameStatusMonitor);

    void launch();

    void renderPlayers(GameStatusMonitor& gameStatusMonitor);

    ~WindowRenderer() = default;
};