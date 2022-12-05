#ifndef DIALOGJOINGAME_H
#define DIALOGJOINGAME_H

#include <QDialog>
#include "DialogListGames.h"
#include "../../Common/Socket.h"

namespace Ui {
class DialogJoinGame;
}

class DialogJoinGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoinGame(
        Socket &clientSocket,
        DialogListGames *listGames, 
        QWidget *parent = nullptr);
    ~DialogJoinGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogJoinGame *ui;
    Socket &clientSocket;
    DialogListGames *listGames;
};

#endif // DIALOGJOINGAME_H
