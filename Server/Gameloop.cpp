#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#include "Physics/Physics.h"
#include "ActionsClient/ActionsClient.h"
#include "../Common/GameStatus.h"



Gameloop::Gameloop() 
    : senderQueue(), 
      recibingQueue(),
      isRunning(false) { }

void Gameloop::run() {
    std::cout << "Gameloop::run" << std::endl;

    //Inicia el mundo del game.
    Physics gamePhysics(this->connectionList);
    
    //Instanciamos los receivers.
    for (auto connection = connectionList.begin(); connection != connectionList.end(); ++connection) {
        clientThreadReceiver.emplace_back((*connection).getSocketReference(),recibingQueue);
        clientThreadReceiver.back().start();
    }

    //Instanciamos el broadcaster
    ThreadClientBroadcaster broadcasterThread(senderQueue, connectionList);
    broadcasterThread.start();

    int commandsCounter = 0;


    //Iniciamos el Gameloop donde procesa los comandos.
    std::cout << "Gameloop::while" << std::endl;
    while (this->isRunning) {
        auto timeStart = Clock::now();

        while (!recibingQueue.empty() && commandsCounter < LIMITOFCOMANDS) {
            std::shared_ptr<ActionsClient> action = recibingQueue.pop();
            if (action != NULL && !gamePhysics.getIsInReplay()) {
                action->execute(gamePhysics);
            }

            commandsCounter += 1;
        }
        
        if (!gamePhysics.getIsInReplay()) {
            gamePhysics.simulateTimeStep();
        }

        GameStatus gameStatus = gamePhysics.getGameStatus(); //Creemos que hay que moverlo para despues del simulateTimeStep

        senderQueue.push(gameStatus);

        gamePhysics.resetPositionsIfGoal();
        gamePhysics.fillTurbos();
        gamePhysics.updateReplayStaus();
        
        auto timeFinish = Clock::now();

        synchronizeFrameRate(timeStart, timeFinish);

        commandsCounter = 0;

        if (gameStatus.isClosed()) {
            this->isRunning = false;
        }

    }
}

void Gameloop::init(std::list <ClientConnection>& connectionList) {
    this->isRunning = true;
    this->connectionList = std::move(connectionList);

    this->start();
}

void Gameloop::stop() {
    /*
        Al cerrar el gameLoop, necesitamos pushear
        un nuevo estado del mundo, pero con un
        estado indicando que esta cerrado
    */
    GameStatus gameStatus;
    gameStatus.setClose();

    senderQueue.push(gameStatus);

    this->isRunning = false;
}

void Gameloop::synchronizeFrameRate(
    std::chrono::_V2::system_clock::time_point timeStart,
    std::chrono::_V2::system_clock::time_point timeFinish
) {
    int elapsed = std::chrono::duration_cast<std::chrono::microseconds>(timeFinish - timeStart).count();
    if (DELTA - elapsed > 0) {
        usleep(DELTA - elapsed);
    }
}

Gameloop::~Gameloop() {
    this->join();
}