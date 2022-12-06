#include "GameStatusMonitor.h"
#include "ThreadCmdReader.h"
#include "../Common/BlockingQueue.h"
#include "BackGroundMusic.h"


//Clase encargada de levantar la ventana principal de SDL.
//Ademas de inicilizar todas las texturas, el mixer (encargado de
//la musica), y renderizar todo hasta que el juego termine.
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