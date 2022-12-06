#ifndef DIALOGCREATEGAME_H
#define DIALOGCREATEGAME_H

#include <QDialog>
#include "../../Common/Socket.h"

/*
Esta clase de QT representa el dialog para crear un juego
*/
namespace Ui {
class DialogCreateGame;
}

class DialogCreateGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateGame(
        Socket &clientSocket,
        QWidget *parent = nullptr);
    ~DialogCreateGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogCreateGame *ui;
    Socket &clientSocket;
};


#endif // DIALOGCREATEGAME_H
