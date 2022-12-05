#ifndef DIALOGCREATEGAME_H
#define DIALOGCREATEGAME_H

#include <QDialog>

namespace Ui {
class DialogCreateGame;
}

class DialogCreateGame : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateGame(QWidget *parent = nullptr);
    ~DialogCreateGame();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogCreateGame *ui;
};

#endif // DIALOGCREATEGAME_H
