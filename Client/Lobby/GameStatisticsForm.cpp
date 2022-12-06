#include <string>

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

    for (auto &playerModel : gameStatusMonitor.getGameStatus().getPlayersModels()){
        statisticsData += "Nombre: " + playerModel.getName() + " \n";
        statisticsData += "---------------------------------------------------------------- \n";
        statisticsData += "> Goles: " + std::to_string(playerModel.getGoals()) + " \n";
        statisticsData += "> Asistencias: " + std::to_string(playerModel.getAssists()) + " \n";
        statisticsData += "\n \n \n \n";
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

