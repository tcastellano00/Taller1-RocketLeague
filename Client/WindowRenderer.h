#include "GameStatusMonitor.h"
#include "ThreadCmdReader.h"
#include "../Common/BlockingQueue.h"
#include "BackGroundMusic.h"

class WindowRenderer {
private:
    BlockingQueue<Command>& commandQueue;
    GameStatusMonitor& gameStatusMonitor;
    ThreadCmdReader threadCmdReader;
    //BackGroundMusic backGroundMusic;

public:
    WindowRenderer(
        BlockingQueue<Command>& commandQueue,
        GameStatusMonitor& gameStatusMonitor);

    void launch();

    void renderPlayers(GameStatusMonitor& gameStatusMonitor);

    ~WindowRenderer() = default;
};