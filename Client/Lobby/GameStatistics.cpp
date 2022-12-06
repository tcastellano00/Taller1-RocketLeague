#include "Lobby.h"
#include <iostream>
#include <string>

#include <QApplication>
#include "GameStatistics.h"
#include "GameStatisticsForm.h"

GameStatistics::GameStatistics(
    GameStatusMonitor& gameStatusMonitor) : gameStatusMonitor(gameStatusMonitor) { }

bool GameStatistics::start() {
    return this->initGameStatisticsForms();
}

bool GameStatistics::initGameStatisticsForms() {
    int argc = 1;
    char w1[] = "";
    char *argv[] = { w1 };
    QApplication qtApplication(argc, argv);

    std::string clientName = "";
    bool clientGoBackLobby = false;

    GameStatisticsForm gameStatisticsForm(
        this->gameStatusMonitor,
        clientGoBackLobby
    );

    gameStatisticsForm.show();

    qtApplication.exec();

    return clientGoBackLobby;
}