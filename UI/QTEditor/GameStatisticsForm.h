#ifndef GAMESTATISTICSFORM_H
#define GAMESTATISTICSFORM_H

#include <QWidget>

namespace Ui {
class GameStatisticsForm;
}

class GameStatisticsForm : public QWidget
{
    Q_OBJECT

public:
    explicit GameStatisticsForm(QWidget *parent = nullptr);
    ~GameStatisticsForm();

private slots:
    void on_btn_goLobby_clicked();

private:
    Ui::GameStatisticsForm *ui;
};

#endif // GAMESTATISTICSFORM_H
