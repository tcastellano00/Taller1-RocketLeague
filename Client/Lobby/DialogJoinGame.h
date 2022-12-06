#ifndef DIALOGJOINGAME_H
#define DIALOGJOINGAME_H

#include <QDialog>
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
        QWidget *parent = nullptr);
    ~DialogJoinGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogJoinGame *ui;
    Socket &clientSocket;
};

#endif // DIALOGJOINGAME_H
