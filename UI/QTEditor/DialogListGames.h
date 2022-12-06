#ifndef DIALOGLISTGAMES_H
#define DIALOGLISTGAMES_H

#include <QDialog>

namespace Ui {
class DialogListGames;
}

class DialogListGames : public QDialog
{
    Q_OBJECT

public:
    explicit DialogListGames(std::string clientName, QWidget *parent = nullptr);
    ~DialogListGames();

private slots:
    void on_btn_createGame_clicked();

    void on_btn_joinGame_clicked();

    void on_btn_reload_clicked();

private:
    Ui::DialogListGames *ui;
    std::string clientName;
};

#endif // DIALOGLISTGAMES_H
