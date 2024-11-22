#ifndef TEACHERWINDOWGROUPSPAGE_H
#define TEACHERWINDOWGROUPSPAGE_H

#include "../../Data/Model/groupspagemodel.h"

#include <QScopedPointer>

namespace Ui {
class TeacherWindow;
}

class TeacherWindowGroupsPage
{
public:
    TeacherWindowGroupsPage(Ui::TeacherWindow* teacherWindow);

    void chooseGroup();
    void addGroup();
    void deleteGroup();

    void addSubject();
    void deleteSubject();

    void addStudent();
    void deleteStudent();

private:
    QScopedPointer<GroupsPageModel> groupsPageModel;
    Ui::TeacherWindow* ui;

};

#endif
