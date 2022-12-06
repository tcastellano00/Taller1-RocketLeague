#include <string>
#include <iostream>

#include "GameStatisticsForm.h"
#include "../../ui_gamestatisticsform.h"

GameStatisticsForm::GameStatisticsForm(
        GameStatusMonitor &gameStatusMonitor,
        bool &goBackLobby,
        QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStatisticsForm),
    gameStatusMonitor(gameStatusMonitor),
    goBackLobby(goBackLobby)
{
    ui->setupUi(this);

    std::string statisticsData("");


    std::list<PlayerModel> playerModels = gameStatusMonitor.getGameStatus().getPlayersModels();


    for (auto playerModel = playerModels.begin(); playerModel != playerModels.end(); ++playerModel){
        statisticsData += "Nombre: " + playerModel->getName() + " \n";
        statisticsData += "---------------------------------------------------------------- \n";
        statisticsData += "> Goles: " + std::to_string(playerModel->getGoals()) + " \n";
        statisticsData += "> Asistencias: " + std::to_string(playerModel->getAssists()) + " \n";
        statisticsData += "> Atajadas: " + std::to_string(playerModel->getSaves()) + " \n";
        statisticsData += "\n \n";
    }

    ui->lbl_data->setText(QString::fromStdString(statisticsData));
}

GameStatisticsForm::~GameStatisticsForm()
{
    delete ui;
}

void GameStatisticsForm::on_btn_goLobby_clicked()
{
    this->goBackLobby = true;
    this->close();
}

