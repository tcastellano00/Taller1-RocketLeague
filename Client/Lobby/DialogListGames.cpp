#include "DialogListGames.h"
#include "DialogCreateGame.h"
#include "DialogJoinGame.h"

#include "../../ui_dialoglistgames.h"

DialogListGames::DialogListGames(
        Socket &clientSocket,
        std::string clientName, 
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListGames),
    clientSocket(clientSocket),
    clientName(clientName)
{
    ui->setupUi(this);
    ui->label_clientName->setText(QString::fromStdString("Bievenido " + clientName));
}

DialogListGames::~DialogListGames()
{
    delete ui;
}


void DialogListGames::on_btn_createGame_clicked()
{
    DialogCreateGame dialogCreateGame(this->clientSocket, this);
    dialogCreateGame.setModal(true);
    dialogCreateGame.exec();
}

void DialogListGames::on_btn_joinGame_clicked()
{
    DialogJoinGame dialogJoinGame(this->clientSocket, this);
    dialogJoinGame.setModal(true);
    dialogJoinGame.exec();
}

