#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include "../../Data/Entity/student.h"
#include "../Forms/StudentWindowPages/studentwindowschedulepage.h"

#include <memory>
#include <QWidget>

namespace Ui {
class StudentWindow;
}

class StudentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StudentWindow(const Student& student = Student(), QWidget *parent = nullptr);
    ~StudentWindow();

private:
    const Student student;
    Ui::StudentWindow *ui;

    std::unique_ptr<StudentWindowSchedulePage> schedulePage;
};

#endif
