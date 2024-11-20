#include "Utils/database.h"
#include "Views/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DataBase* database = DataBase::getInstance();
    database->connect();
    MainWindow w;
    w.show();
    return app.exec();
}
