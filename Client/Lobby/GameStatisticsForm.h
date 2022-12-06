#ifndef GAMESTATISTICSFORM_H
#define GAMESTATISTICSFORM_H

#include <QWidget>
#include "../GameStatusMonitor.h"

namespace Ui {
class GameStatisticsForm;
}

class GameStatisticsForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameStatisticsForm(
        GameStatusMonitor &gameStatusMonitor,
        bool &goBackLobby,
        QWidget *parent = nullptr);
    ~GameStatisticsForm();

private slots:
    void on_btn_goLobby_clicked();

private:
    Ui::GameStatisticsForm *ui;
    GameStatusMonitor &gameStatusMonitor;
    bool &goBackLobby;
};

#endif // GAMESTATISTICSFORM_H
