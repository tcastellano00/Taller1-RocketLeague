#ifndef DIALOGLISTGAMES_H
#define DIALOGLISTGAMES_H

#include <QDialog>
#include "DialogJoinGame.h"
#include "DialogCreateGame.h"
#include "ThreadServerStartGame.h"
#include "../../Common/Socket.h"

namespace Ui {
class DialogListGames;
}

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
};

#endif // DIALOGLISTGAMES_H
