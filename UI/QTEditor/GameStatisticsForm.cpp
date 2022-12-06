#include "GameStatisticsForm.h"
#include "ui_gamestatisticsform.h"

GameStatisticsForm::GameStatisticsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStatisticsForm)
{
    ui->setupUi(this);
}

GameStatisticsForm::~GameStatisticsForm()
{
    delete ui;
}

void GameStatisticsForm::on_btn_goLobby_clicked()
{

}

