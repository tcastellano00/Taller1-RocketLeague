#ifndef LOBBYFORM_H
#define LOBBYFORM_H

#include <QMainWindow>
#include "../../Common/Socket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LobbyForm; }
QT_END_NAMESPACE

/*
Esta clase de QT representa la ventana principal donde se
encuentra el lobby, es la primera pantalla que ve el
cliente cuando se conecta.
*/
class LobbyForm : public QMainWindow
{
    Q_OBJECT

public:
    LobbyForm(
        Socket &clientSocket,
        std::string& clientName,
        QWidget *parent = nullptr);
    ~LobbyForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LobbyForm *ui;
    Socket &clientSocket;
    std::string clientName;
};
#endif // LOBBYFORM_H
