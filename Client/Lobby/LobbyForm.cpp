#include "LobbyForm.h"
#include "DialogListGames.h"
#include "../../Common/Protocol.h"

#include "../../ui_lobbyform.h"

LobbyForm::LobbyForm(
    Socket &clientSocket,
    std::string &clientName,
    bool &clientJoinedGame, 
    QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LobbyForm)
    , clientSocket(clientSocket)
    , clientName(clientName)
    , clientJoinedGame(clientJoinedGame)
{
    ui->setupUi(this);
}

LobbyForm::~LobbyForm()
{
    delete ui;
}

void LobbyForm::on_pushButton_clicked()
{
    QString qtClientName = ui->clientName->text();

    if (qtClientName == ""){
        ui->errorMsg->setText("Todo campeón necesita un nombre, ingresalo!");
        return;
    }
    
    this->clientName = qtClientName.toStdString();
    std::replace(clientName.begin(), clientName.end(), ' ', '_');

    Protocol protocol(this->clientSocket);
    protocol.sendMessage("GUARDAR_NOMBRE " + this->clientName);

    this->hide();

    DialogListGames listGames(
        this->clientSocket, 
        this->clientName, 
        this->clientJoinedGame
    );
    listGames.setModal(true);
    listGames.exec();
}

