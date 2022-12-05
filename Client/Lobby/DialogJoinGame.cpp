#include "DialogJoinGame.h"
#include "DialogListGames.h"
#include "../../ui_dialogjoingame.h"

DialogJoinGame::DialogJoinGame(DialogListGames *listGames, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogJoinGame),
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
    ui->infoClientConnected->setText("Conectado, aguardando jugadores..");


    //Cerramos todo.
    this->listGames->close();
    this->close();
}
