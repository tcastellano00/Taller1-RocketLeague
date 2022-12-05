#include <string>

#include "LobbyForm.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string clientName;

    LobbyForm w(clientName);
    w.show();

    return a.exec();
}
