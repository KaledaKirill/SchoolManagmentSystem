#include "teacherwindow.h"
#include "ui_teacherwindow.h"

TeacherWindow::TeacherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    resize(minimumSizeHint());

    teacherWindowGroupsPage = std::make_unique<TeacherWindowGroupsPage>(ui);
    teacherWindowJournalPage = std::make_unique<TeacherWindowJournalPage>(ui);
    teacherWindowSchedulePage = std::make_unique<TeacherWindowSchedulePage>(ui);

    connect(ui->addGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddGroup()));
    connect(ui->deleteGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteGroup()));

    connect(ui->addStudentBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddStudent()));
    connect(ui->deleteStudentBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteStudent()));

    connect(ui->addSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddSubject()));
    connect(ui->deleteSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteSubject()));

    connect(ui->chooseGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseGroup()));
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::clickedBtnAddStudent()
{

}

void TeacherWindow::clickedBtnDeleteStudent()
{

}

void TeacherWindow::clickedBtnAddSubject()
{

}

void TeacherWindow::clickedBtnDeleteSubject()
{

}

void TeacherWindow::clickedBtnAddGroup()
{

}

void TeacherWindow::clickedBtnDeleteGroup()
{

}

void TeacherWindow::clickedBtnChooseGroup()
{

}
