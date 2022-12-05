#include "DialogJoinGame.h"
#include "DialogListGames.h"
#include "../../ui_dialogjoingame.h"
#include "../../Common/Protocol.h"

DialogJoinGame::DialogJoinGame(
        Socket &clientSocket,
        DialogListGames *listGames, 
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJoinGame),
    clientSocket(clientSocket),
    listGames(listGames)
{
    ui->setupUi(this);
}

DialogJoinGame::~DialogJoinGame()
{
    delete ui;
}

void DialogJoinGame::on_pushButton_clicked()
{
    QString qtGameName = ui->txt_gameName->text();

    if (qtGameName == ""){
        ui->errorMsg->setText("Ingrese el nombre de la partida");
        return;
    }

    ui->txt_gameName->setDisabled(true);
    ui->pushButton->setDisabled(true);

    Protocol protocol(this->clientSocket);
    protocol.sendMessage("UNIR " + qtGameName.toStdString());

    ui->infoClientConnected->setText("Conectado, aguardando jugadores..");
    
    std::string reply = protocol.reciveMessage();

    if (reply == "start!") {
        //Cerramos todo.
        this->listGames->close();
        this->close();
    }
}
