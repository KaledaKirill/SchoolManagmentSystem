#include "teacherwindow.h"
#include "ui_teacherwindow.h"

#include <QInputDialog>
#include <QShortcut>
#include <QToolTip>

TeacherWindow::TeacherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TeacherWindow)
{
    ui->setupUi(this);
    resize(minimumSizeHint());

    teacherWindowGroupsPage = std::make_unique<TeacherWindowGroupsPage>(ui);
    teacherWindowJournalPage = std::make_unique<TeacherWindowJournalPage>(ui);
    teacherWindowSchedulePage = std::make_unique<TeacherWindowSchedulePage>(ui);

    setupShortcuts();

    connect(ui->addGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddGroup()));
    connect(ui->deleteGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteGroup()));

    connect(ui->addStudentBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddStudent()));
    connect(ui->deleteStudentBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteStudent()));

    connect(ui->addSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddSubject()));
    connect(ui->deleteSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnDeleteSubject()));

    connect(ui->chooseGroupBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseGroup()));

    connect(ui->mainTabWidget, SIGNAL(currentChanged(int)), this, SLOT(clickedJournalTab(int)));
    connect(ui->mainTabWidget, SIGNAL(currentChanged(int)), this, SLOT(clickedScheduleTab(int)));
    connect(ui->journalTabWidget, SIGNAL(currentChanged(int)), this, SLOT(clickedResJournalTab(int)));

    connect(ui->chooseSubjectBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseSubject()));
    connect(ui->chooseGroupBtnOnJournalPage, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseGroupOnJournalPage()));
    connect(ui->chooseQuarterBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseQuarter()));
    connect(ui->addDateBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnAddDate()));

    connect(ui->chooseGroupBtnOnSchedulePage, SIGNAL(clicked(bool)), this, SLOT(clickedBtnChooseGroupOnSchedulePage()));
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

void TeacherWindow::clickedJournalTab(int index)
{
    if(index == 1)
        teacherWindowJournalPage->loadData();
}

void TeacherWindow::clickedResJournalTab(int index)
{
    if(index == 1)
        teacherWindowJournalPage->loadResData();
}

void TeacherWindow::clickedScheduleTab(int index)
{
    if(index == 2)
        teacherWindowSchedulePage->loadData();
}

void TeacherWindow::clickedBtnChooseSubject()
{
    teacherWindowJournalPage->chooseSubject();
}

void TeacherWindow::clickedBtnChooseQuarter()
{
    teacherWindowJournalPage->chooseQuarter();
}

void TeacherWindow::clickedBtnAddDate()
{
    teacherWindowJournalPage->addDate();
}

void TeacherWindow::clickedBtnChooseGroupOnSchedulePage()
{
    teacherWindowSchedulePage->chooseGroup();
}

void TeacherWindow::clickedBtnUndo()
{
    teacherWindowGroupsPage->undoLastAction();
}

void TeacherWindow::clickedBtnRedo()
{
    teacherWindowGroupsPage->redoLastAction();
}

void TeacherWindow::clickedBtnChooseGroupOnJournalPage()
{
    teacherWindowJournalPage->chooseGroup();
}

void TeacherWindow::setupShortcuts()
{
    QShortcut* undoShortcut = new QShortcut(QKeySequence::Undo, this);
    connect(undoShortcut, &QShortcut::activated, this, &TeacherWindow::clickedBtnUndo);

    QShortcut* redoShortcut = new QShortcut(QKeySequence::Redo, this);
    connect(redoShortcut, &QShortcut::activated, this, &TeacherWindow::clickedBtnRedo);
}
