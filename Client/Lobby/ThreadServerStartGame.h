#ifndef THREADSEVERSTARTGAME_H
#define THREADSEVERSTARTGAME_H

#include <QObject>
#include <QThread>
#include "../../Common/Socket.h"

/*
Esta clase es utilizada para no bloquear el hilo principal de QT
mientras se esta esperando que el servidor le informe al cliente
que se tiene que unir a una partida.
*/
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