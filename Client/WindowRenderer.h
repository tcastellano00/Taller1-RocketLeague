#include "GameStatusMonitor.h"

class WindowRenderer {
public:
    WindowRenderer();

    void launch(GameStatusMonitor& gameStatusMonitor);

    void renderPlayers(GameStatusMonitor& gameStatusMonitor);
};