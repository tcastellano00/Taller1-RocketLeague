#include "Gameloop.h"
#include "ThreadClientBroadcaster.h"
#include "Physics/Physics.h"
#include "ActionsClient/ActionsClient.h"
#include "../Common/GameStatus.h"



Gameloop::Gameloop() 
    : senderQueue(true), 
      recibingQueue(false) { 
        isRunning = false;
      }

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


    //Iniciamos el Gameloop donde procesa los comandos. Acá arrancan las responsabilidades del GameLoop, 
    // lo de antes no debería ser parte de esta clase. Para preservar el esquema de hilos, podrían:
    // 1. Renombrar esta clase a algo que evidencie que va a hacer todas estas acciones
    // 2. Extraer lo que es propio del GameLoop a otra clase con ese nombre, que no extienda de hilo
    // 3. Acá simplemente instancian un GameLoop y lo mandan a correr.
    std::cout << "Gameloop::while" << std::endl;
    while (this->isRunning) {
        auto timeStart = Clock::now();

        while (!recibingQueue.empty() && commandsCounter < LIMITOFCOMANDS) {
            std::shared_ptr<ActionsClient> action = recibingQueue.pop();
            if (action != NULL) {
                action->execute(gamePhysics);
            }

            commandsCounter += 1;
        }
        
        // Para hacer que el delta sea cambiable, este simulateTimeStep debería recibir
        // por parámetro esa constante. Eso va a hacer más testeable todo.
        // Además, DELTA y gamePhysics.timeStep representan lo mismo, no? Por qué no tienen
        // el mismo valor? No deberían salir de la misma constante?
        gamePhysics.simulateTimeStep();

        GameStatus gameStatus = gamePhysics.getGameStatus(); //Creemos que hay que moverlo para despues del simulateTimeStep <- yo lo veo después... :)

        senderQueue.push(gameStatus);

        gamePhysics.resetPositionsIfGoal();
        
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