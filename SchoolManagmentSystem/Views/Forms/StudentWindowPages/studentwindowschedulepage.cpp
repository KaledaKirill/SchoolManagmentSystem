#include "studentwindowschedulepage.h"
#include "ui_studentwindow.h"

StudentWindowSchedulePage::StudentWindowSchedulePage(Ui::StudentWindow* studentWindow, const Student &student)
    : scheduleModel(new ScheduleModel),
    ui(studentWindow)
{
    scheduleModel->loadSchedule(student.getGroup());
    ui->scheduleTableView->setModel(scheduleModel);
    ui->scheduleTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

StudentWindowSchedulePage::~StudentWindowSchedulePage()
{
    delete scheduleModel;
}
