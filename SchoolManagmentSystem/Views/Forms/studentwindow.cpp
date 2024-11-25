#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(const Student& student, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
