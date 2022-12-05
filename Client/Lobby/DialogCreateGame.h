#ifndef DIALOGCREATEGAME_H
#define DIALOGCREATEGAME_H

#include <QDialog>
#include "DialogListGames.h"

namespace Ui {
class DialogCreateGame;
}

class DialogCreateGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateGame(DialogListGames *listGames, QWidget *parent = nullptr);
    ~DialogCreateGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogCreateGame *ui;
    DialogListGames *listGames;
};


#endif // DIALOGCREATEGAME_H
