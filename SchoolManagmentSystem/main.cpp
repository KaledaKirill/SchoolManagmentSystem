#include "Utils/database.h"
#include "Views/Forms/teacherwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DataBase* database = DataBase::getInstance();
    database->connect();
    TeacherWindow w;
    w.show();
    return app.exec();
}
