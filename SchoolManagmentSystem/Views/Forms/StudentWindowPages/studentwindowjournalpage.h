#ifndef STUDENTWINDOWJOURNALPAGE_H
#define STUDENTWINDOWJOURNALPAGE_H

#include "../../Data/Entity/student.h"
#include "../../Data/Model/studentjournalmodel.h"
#include "../../Data/Model/studentresjournalmodel.h"
#include "../../Data/Model/GradesService.h"

namespace Ui {
class StudentWindow;
}

class StudentWindowJournalPage
{
public:
    StudentWindowJournalPage(Ui::StudentWindow* studentWindow, const Student& student);
    ~StudentWindowJournalPage();

private:
    StudentJournalModel* studentJournalModel;
    StudentResJournalModel* studentResJournalModel;

    GradesService* gradesService;


    Ui::StudentWindow* ui;
    Student student;

    void showStudentData();

};

#endif
