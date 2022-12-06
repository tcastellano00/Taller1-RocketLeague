#include <iostream>

#include "DialogListGames.h"
#include "DialogCreateGame.h"
#include "DialogJoinGame.h"
#include "ThreadServerStartGame.h"
#include "../../Common/Protocol.h"

#include "../../ui_dialoglistgames.h"

DialogListGames::DialogListGames(
        Socket &clientSocket,
        std::string clientName, 
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogListGames),
    dialogJoinGameIsOpen(false),
    dialogCreateGameIsOpen(false),
    clientSocket(clientSocket),
    clientName(clientName)
{
    ui->setupUi(this);
    ui->label_clientName->setText(QString::fromStdString("Bievenido " + clientName));

    this->loadGames();

    this->threadServerStartGame = new ThreadServerStartGame(this->clientSocket, this);
    connect(threadServerStartGame, SIGNAL(HaveStartedGame(bool)), this, SLOT(startGame()));
    threadServerStartGame->start();
}

void DialogListGames::loadGames() {
    Protocol protocol(this->clientSocket);
    protocol.sendMessage("LISTAR");
    std::string response = protocol.reciveMessage();

    if (response.length() < 3) {
        ui->lbl_listGames->setText("No encontramos partidas! Se el primero en crear una");
    } else {
        ui->lbl_listGames->setText(QString::fromStdString(response.substr(3)));
    }
}

void DialogListGames::startGame() {
    if (this->dialogCreateGameIsOpen)
        this->dialogCreateGame->hide();

    if (this->dialogJoinGameIsOpen)
        this->dialogJoinGame->hide();

    this->close();
}

void DialogListGames::on_btn_createGame_clicked()
{
    this->dialogCreateGame = new DialogCreateGame(this->clientSocket, this);
    this->dialogCreateGame->setModal(true);
    this->dialogCreateGame->exec();
    this->dialogCreateGameIsOpen = true;
}

void DialogListGames::on_btn_joinGame_clicked()
{
    this->dialogJoinGame = new DialogJoinGame(this->clientSocket, this);
    this->dialogJoinGame->setModal(true);
    this->dialogJoinGame->exec();
    this->dialogJoinGameIsOpen = true;
}

/*
void DialogListGames::on_btn_reload_clicked()
{
    this->loadGames();
}
*/

DialogListGames::~DialogListGames()
{
    delete threadServerStartGame;
    delete ui;
}

