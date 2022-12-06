#ifndef DIALOGLISTGAMES_H
#define DIALOGLISTGAMES_H

#include <QDialog>
#include "DialogJoinGame.h"
#include "DialogCreateGame.h"
#include "ThreadServerStartGame.h"
#include "../../Common/Socket.h"
#include "../../Common/Protocol.h"

namespace Ui {
class DialogListGames;
}

/*
Esta clase de QT representa el dialog donde se listan todas
las partidas del servidor.
*/
class DialogListGames : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListGames(
        Socket &clientSocket,
        std::string clientName, 
        QWidget *parent = nullptr);
    ~DialogListGames();

private slots:
    void on_btn_createGame_clicked();

    void on_btn_joinGame_clicked();

    void on_btn_train_clicked();

public slots:
    void startGame();

private:
    Ui::DialogListGames *ui;
    DialogJoinGame *dialogJoinGame;
    DialogCreateGame *dialogCreateGame;
    bool dialogJoinGameIsOpen;
    bool dialogCreateGameIsOpen;
    Socket &clientSocket;
    std::string clientName;
    ThreadServerStartGame *threadServerStartGame;

    void loadGames();
};

#endif // DIALOGLISTGAMES_H
