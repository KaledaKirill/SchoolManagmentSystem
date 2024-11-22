#ifndef TEACHERWINDOW_H
#define TEACHERWINDOW_H

#include "TeacherWindowPages/teacherwindowgroupspage.h"
#include "TeacherWindowPages/teacherwindowjournalpage.h"
#include "TeacherWindowPages/teacherwindowschedulepage.h"

#include <memory>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TeacherWindow;
}
QT_END_NAMESPACE

class TeacherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherWindow(QWidget *parent = nullptr);
    ~TeacherWindow();

private slots:
    void clickedBtnAddStudent();
    void clickedBtnDeleteStudent();

    void clickedBtnAddSubject();
    void clickedBtnDeleteSubject();

    void clickedBtnAddGroup();
    void clickedBtnDeleteGroup();

    void clickedBtnChooseGroup();


private:
    Ui::TeacherWindow* ui;

    std::unique_ptr<TeacherWindowGroupsPage> teacherWindowGroupsPage;
    std::unique_ptr<TeacherWindowJournalPage> teacherWindowJournalPage;
    std::unique_ptr<TeacherWindowSchedulePage> teacherWindowSchedulePage;
};
#endif