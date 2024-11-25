#ifndef TEACHERWINDOWSCHEDULEPAGE_H
#define TEACHERWINDOWSCHEDULEPAGE_H

#include "../../Data/Model/schedulepagemodel.h"

#include <QScopedPointer>

namespace Ui {
class TeacherWindow;
}

class TeacherWindowSchedulePage
{
public:
    TeacherWindowSchedulePage(Ui::TeacherWindow* teacherWindow);

    void chooseGroup();
    void loadData();

private:
    QScopedPointer<SchedulePageModel> schedulePageModel;
    Ui::TeacherWindow* ui;

};

#endif
