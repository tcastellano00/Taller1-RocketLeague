#ifndef CLIENT_GAMESTATUSMONITOR_H
#define CLIENT_GAMESTATUSMONITOR_H

#include <mutex>
#include <string>
#include <atomic>
#include "../Common/GameStatus.h"
#include "../Common/Model/PlayerModel.h"


/*
Monitor del estado actual de la partida que posee el cliente. Evita posibles race conditions
ya que este estado es accedido por el hilo CmdReader, Sender, Receiver y opr el Renderer.
*/
class GameStatusMonitor{
    std::mutex gameMutex;
    GameStatus gamestatus;
    std::atomic<bool> clientClosedGame;
    bool isPlayingMusic;
    bool callNext = false;

    public:
    GameStatusMonitor();

    bool gameIsClosed();
    
    GameStatus getGameStatus();

    void statusUpdate(GameStatus newGameStatus);
    
    void setClose();

    void toggleMusic();

    void toggleNext();

    bool getCallNext();

    bool getIsPlayingMusic();
};

#endif
