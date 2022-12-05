#include "LobbyForm.h"
#include "DialogListGames.h"

#include "../../ui_lobbyform.h"

LobbyForm::LobbyForm(std::string& clientName, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LobbyForm)
    , clientName(clientName)
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

    this->hide();

    DialogListGames listGames(this->clientName);
    listGames.setModal(true);
    listGames.exec();
}

