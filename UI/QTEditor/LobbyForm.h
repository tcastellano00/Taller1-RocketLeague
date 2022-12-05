#ifndef LOBBYFORM_H
#define LOBBYFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LobbyForm; }
QT_END_NAMESPACE

class LobbyForm : public QMainWindow
{
    Q_OBJECT

public:
    LobbyForm(std::string& clientName, QWidget *parent = nullptr);
    ~LobbyForm();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LobbyForm *ui;
    std::string clientName;
};
#endif // LOBBYFORM_H
