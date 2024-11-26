#ifndef STUDENTWINDOWSCHEDULEPAGE_H
#define STUDENTWINDOWSCHEDULEPAGE_H

#include "../../Data/Entity/student.h"
#include "../../Data/Model/schedulemodel.h"

namespace Ui {
class StudentWindow;
}


class StudentWindowSchedulePage
{
public:
    StudentWindowSchedulePage(Ui::StudentWindow* studentWindow, const Student& student);
    ~StudentWindowSchedulePage();

private:
    ScheduleModel* scheduleModel;

    Ui::StudentWindow* ui;

};

#endif
