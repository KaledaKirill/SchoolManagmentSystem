#ifndef LOGIN_FORM_H
#define LOGIN_FORM_H

#define TEACHER_PASSWORD "qwerty"

#include "../../Data/DAO/istudentsdao.h"

#include <QMainWindow>
#include <QScopedPointer>
#include <QMessageBox>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget* parent = 0);
    ~LoginWindow();

private slots:
    void clickedBtnLogin();
    void clickedCbxShowPassword();
    void onRadioButtonStudentToggled(bool checked);
    void onRadioButtonTeacherToggled(bool checked);

private:
    Ui::LoginWindow* ui;
    QScopedPointer<IStudentsDAO> studentsDAO;

    void loginAsStudent();
    void loginAsTeacher();
    bool isValidStudentForm();
    bool isValidTeacherForm();
    void hideLineEdits();

};

#endif
