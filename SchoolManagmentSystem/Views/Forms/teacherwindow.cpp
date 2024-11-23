#include "teacherwindow.h"
#include "ui_teacherwindow.h"

#include <QInputDialog>

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

    connect(ui->mainTabWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));

    connect(ui->chooseSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseSubject()));
    connect(ui->chooseGroupBtnOnJournalPage, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseGroupOnJournalPage()));
}

TeacherWindow::~TeacherWindow()
{
    delete ui;
}

void TeacherWindow::clickedBtnAddStudent()
{
    teacherWindowGroupsPage->addStudent();
}

void TeacherWindow::clickedBtnDeleteStudent()
{
    teacherWindowGroupsPage->deleteStudent();
}

void TeacherWindow::clickedBtnAddSubject()
{
    teacherWindowGroupsPage->addSubject();
}

void TeacherWindow::clickedBtnDeleteSubject()
{
    teacherWindowGroupsPage->deleteSubject();
}

void TeacherWindow::clickedBtnAddGroup()
{
    teacherWindowGroupsPage->addGroup();
}

void TeacherWindow::clickedBtnDeleteGroup()
{
    teacherWindowGroupsPage->deleteGroup();
}

void TeacherWindow::clickedBtnChooseGroup()
{
    teacherWindowGroupsPage->chooseGroup();
}

void TeacherWindow::onTabChanged(int index)
{
    if(index == 1)
        teacherWindowJournalPage->loadData();
}

void TeacherWindow::clickedBtnChooseSubject()
{
    teacherWindowJournalPage->chooseSubject();
}

void TeacherWindow::clickedBtnChooseGroupOnJournalPage()
{
    teacherWindowJournalPage->chooseGroup();
}

