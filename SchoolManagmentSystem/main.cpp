#include "Utils/database.h"
#include "Views/Forms/loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DataBase* database = DataBase::getInstance();
    database->connect();
    LoginWindow w;
    w.show();
    return app.exec();
}
