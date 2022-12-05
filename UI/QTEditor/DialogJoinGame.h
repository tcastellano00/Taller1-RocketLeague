#ifndef DIALOGJOINGAME_H
#define DIALOGJOINGAME_H

#include <QDialog>

namespace Ui {
class DialogJoinGame;
}

class DialogJoinGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoinGame(QWidget *parent = nullptr);
    ~DialogJoinGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogJoinGame *ui;
};

#endif // DIALOGJOINGAME_H
