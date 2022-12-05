#include "DialogCreateGame.h"
#include "../../ui_dialogcreategame.h"

DialogCreateGame::DialogCreateGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateGame)
{
    ui->setupUi(this);
}

DialogCreateGame::~DialogCreateGame()
{
    delete ui;
}

void DialogCreateGame::on_pushButton_clicked()
{
    QString qtGameName = ui->txt_gameName->text();

    if (qtGameName == ""){
        ui->errorMsg->setText("Ingrese el nombre de la partida");
        return;
    }

    QString qtGameMaxPlayers = ui->txt_gameMaxPlayers->text();

    if (qtGameMaxPlayers == ""){
        ui->errorMsg_2->setText("Ingrese la cantidad de jugadores");
        return;
    }

    ui->txt_gameName->setDisabled(true);
    ui->txt_gameMaxPlayers->setDisabled(true);
    ui->pushButton->setDisabled(true);
    ui->infoClientConnected->setText("Conectado, aguardando jugadores..");
}

