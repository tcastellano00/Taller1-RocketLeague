#ifndef DIALOGLISTGAMES_H
#define DIALOGLISTGAMES_H

#include <QDialog>
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

private:
    Ui::DialogListGames *ui;
    Socket &clientSocket;
    std::string clientName;
};

#endif // DIALOGLISTGAMES_H
