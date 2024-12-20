#ifndef TEACHERWINDOWJOURNALPAGE_H
#define TEACHERWINDOWJOURNALPAGE_H

#include "../../Data/Model/journalpagemodel.h"

namespace Ui {
class TeacherWindow;
}


class TeacherWindowJournalPage
{
public:
    TeacherWindowJournalPage(Ui::TeacherWindow* teacherWindow);

    void loadData();
    void loadResData();
    void chooseGroup();
    void chooseSubject();
    void chooseQuarter();
    void addDate();

private:
    Ui::TeacherWindow* ui;
    QScopedPointer<JournalPageModel> journalPageModel;

};

#endif
