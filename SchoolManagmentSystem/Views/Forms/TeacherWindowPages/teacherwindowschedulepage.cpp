#include "teacherwindowschedulepage.h"
#include "ui_teacherwindow.h"

TeacherWindowSchedulePage::TeacherWindowSchedulePage(Ui::TeacherWindow* teacherWindow)
    : schedulePageModel(new SchedulePageModel),
    ui(teacherWindow)
{
    ui->groupCbxOnScheduleWindow->setModel(schedulePageModel->getGroupsListModel());
    ui->scheduleTableView->setModel(schedulePageModel->getScheduleModel());

    ui->scheduleTableView->horizontalHeader()->setDefaultSectionSize(130);
    ui->scheduleTableView->verticalHeader()->setDefaultSectionSize(30);
}

void TeacherWindowSchedulePage::chooseGroup()
{
    const QString groupName = ui->groupCbxOnScheduleWindow->currentText();

    if (!groupName.isEmpty())
    {
        schedulePageModel->chooseGroup(groupName);
    }
}

void TeacherWindowSchedulePage::loadData()
{
    schedulePageModel->loadData();
}
