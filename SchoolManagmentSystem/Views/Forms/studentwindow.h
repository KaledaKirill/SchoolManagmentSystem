#ifndef STUDENTWINDOW_H
#define STUDENTWINDOW_H

#include "../../Data/Entity/student.h"

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
    Ui::StudentWindow *ui;
};

#endif
