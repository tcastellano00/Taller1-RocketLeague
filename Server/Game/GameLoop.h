#include "../../Common/BlockingQueue.h"
#include "../../Common/NonBlockingQueue.h"
#include "../ActionsClient/ActionsClient.h"
#include "../../Common/Config/CommonConfig.h"
#include "../Physics/Physics.h"

#include <chrono>
#include <unistd.h>
typedef std::chrono::high_resolution_clock Clock;

#define LIMITOFCOMANDS 10

#define DELTA CommonConfig::getFrameTimeInMicroseconds()

/*
Loop del juego. En el se reciben los nuevos cambios a aplicar al estado actual del juego,
se aplican, se simula el paso del tiempo y se envia el nuevo estado del juego a los clientes.
*/
class GameLoop {
public:
    void run(bool& isRunning, NonBlockingQueue<std::shared_ptr<ActionsClient>>& recibingQueue, Physics& gamePhysics, BlockingQueue<GameStatus>& senderQueue);

    void synchronizeFrameRate(
        std::chrono::_V2::system_clock::time_point timeStart,
        std::chrono::_V2::system_clock::time_point timeFinish
    );
};
