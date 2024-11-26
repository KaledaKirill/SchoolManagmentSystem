#include "studentwindow.h"
#include "ui_studentwindow.h"

StudentWindow::StudentWindow(const Student& student, QWidget *parent)
    : QWidget(parent),
    student(student),
    ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

    schedulePage = std::make_unique<StudentWindowSchedulePage>(ui, student);
    journalPage = std::make_unique<StudentWindowJournalPage>(ui, student);
}

StudentWindow::~StudentWindow()
{
    delete ui;
}
