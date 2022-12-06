#ifndef THREADSEVERSTARTGAME_H
#define THREADSEVERSTARTGAME_H

#include <QObject>
#include <QThread>
#include "../../Common/Socket.h"

class ThreadServerStartGame : public QThread
{
    Q_OBJECT

public:
    explicit ThreadServerStartGame(Socket &clientSocket, QObject *parent = 0);
    void run();

signals:
    // Señal para indicar que el servidor arranco el juego.
    void HaveStartedGame(bool);

public slots:

private:
    Socket &clientSocket;
};

#endif