#ifndef DIALOGJOINGAME_H
#define DIALOGJOINGAME_H

#include <QDialog>
#include "DialogListGames.h"

namespace Ui {
class DialogJoinGame;
}

class DialogJoinGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoinGame(DialogListGames *listGames, QWidget *parent = nullptr);
    ~DialogJoinGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogJoinGame *ui;
    DialogListGames *listGames;
};

#endif // DIALOGJOINGAME_H
