#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "../../Data/DAO/studentsDAO.h"
#include "../../Exceptions/studentnotfound.h"
#include "teacherwindow.h"
#include "studentwindow.h"

LoginWindow::LoginWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::LoginWindow), studentsDAO(new StudentsDAO)
{
    ui->setupUi(this);

    connect(ui->loginBtn, SIGNAL(clicked(bool)), this, SLOT(clickedBtnLogin()));
    connect(ui->showPasswordCbx, SIGNAL(clicked(bool)), this, SLOT(clickedCbxShowPassword()));
    connect(ui->studentRadioButton, &QRadioButton::toggled, this, &LoginWindow::onRadioButtonStudentToggled);
    connect(ui->TeacherRadioButton, &QRadioButton::toggled, this, &LoginWindow::onRadioButtonTeacherToggled);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    hideForm();
}

void LoginWindow::clickedBtnLogin()
{
    if (ui->studentRadioButton->isChecked())
        loginAsStudent();

    else if (ui->TeacherRadioButton->isChecked())
        loginAsTeacher();

    clearForm();
}

void LoginWindow::loginAsStudent()
{
    if(!isValidStudentForm())
        return;

    const QString studentName = ui->nameLineEdit->text();
    const QString groupName = ui->classLineEdit->text();
    try
    {
        Student student = studentsDAO->getStudent(studentName, groupName);
        StudentWindow* studentWindow = new StudentWindow(student);
        studentWindow->show();
        this->close();
    }
    catch(const StudentNotFound& e)
    {
        QMessageBox::warning(this, "Ошибка авторизации", "Такого ученика не существует");
    }
}

void LoginWindow::loginAsTeacher()
{
    if(!isValidTeacherForm())
        return;

    QString password = ui->passwordLineEdit->text();
    if (password == TEACHER_PASSWORD)
    {
        TeacherWindow* teacherWindow = new TeacherWindow();
        teacherWindow->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Ошибка авторизации", "Неверный пароль учителя");
    }
}

bool LoginWindow::isValidStudentForm()
{
    if(ui->nameLineEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введено имя, авторизация невозможна.");
        return false;
    }
    if(ui->classLineEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введен класс, авторизация невозможна.");
        return false;
    }
    return true;
}

bool LoginWindow::isValidTeacherForm()
{
    if(ui->passwordLineEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка авторизации", "Не введене пароль, авторизация невозможна.");
        return false;
    }

    return true;
}

void LoginWindow::hideForm()
{
    ui->nameLabel->setVisible(false);
    ui->nameLineEdit->setVisible(false);
    ui->classLabel->setVisible(false);
    ui->classLineEdit->setVisible(false);
    ui->passwordLabel->setVisible(false);
    ui->passwordLineEdit->setVisible(false);
    ui->showPasswordCbx->setVisible(false);
}

void LoginWindow::clearForm()
{
    ui->classLineEdit->clear();
    ui->nameLineEdit->clear();
    ui->passwordLineEdit->clear();
}

void LoginWindow::onRadioButtonStudentToggled(bool checked)
{
    ui->nameLabel->setVisible(checked);
    ui->nameLineEdit->setVisible(checked);
    ui->classLabel->setVisible(checked);
    ui->classLineEdit->setVisible(checked);
    ui->passwordLineEdit->setVisible(!checked);
    ui->passwordLabel->setVisible(!checked);
     ui->showPasswordCbx->setVisible(!checked);
}

void LoginWindow::onRadioButtonTeacherToggled(bool checked)
{
    ui->nameLabel->setVisible(!checked);
    ui->nameLineEdit->setVisible(!checked);
    ui->classLabel->setVisible(!checked);
    ui->classLineEdit->setVisible(!checked);
    ui->passwordLineEdit->setVisible(checked);
    ui->passwordLabel->setVisible(checked);
    ui->showPasswordCbx->setVisible(checked);
}

void LoginWindow::clickedCbxShowPassword() {
    if(ui->showPasswordCbx->isChecked()) {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Normal);
    } else {
        ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    }
}

LoginWindow::~LoginWindow() {
    delete ui;
}
