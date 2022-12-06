#include "DialogListGames.h"
#include "DialogCreateGame.h"
#include "DialogJoinGame.h"
#include "ThreadServerStartGame.h"

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

    this->threadServerStartGame = new ThreadServerStartGame(this->clientSocket, this);
    connect(threadServerStartGame, SIGNAL(HaveStartedGame(bool)), this, SLOT(startGame()));
    threadServerStartGame->start();
}

DialogListGames::~DialogListGames()
{
    delete threadServerStartGame;
    delete ui;
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

