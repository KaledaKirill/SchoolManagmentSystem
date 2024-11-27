#include "teacherwindowgroupspage.h"
#include "ui_teacherwindow.h"

#include <QMessageBox>
#include <QInputDialog>

TeacherWindowGroupsPage::TeacherWindowGroupsPage(Ui::TeacherWindow* teacherWindow)
    : groupsPageModel(new GroupsPageModel),
    ui(teacherWindow)
{
    ui->groupsCbx->setModel(groupsPageModel->getGroupsListModel());
    ui->subjectsListView->setModel(groupsPageModel->getSubjectsListModel());
    ui->studentsListView->setModel(groupsPageModel->getStudentsListModel());

    ui->subjectsListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->studentsListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void TeacherWindowGroupsPage::chooseGroup()
{
    const QString groupName = ui->groupsCbx->currentText();
    if (!groupName.isEmpty())
    {
        groupsPageModel->chooseGroup(groupName);
    }
}

void TeacherWindowGroupsPage::addGroup()
{
    const QString groupName = ui->groupsLineEdit->text();
    if (!groupName.isEmpty())
    {
        if (groupsPageModel->addGroup(groupName))
        {
            QMessageBox::information(0, "Успешная операция", "Класс [" + groupName + "] был успешно добавлен.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо вы неправильно ввели класс либо такой класс уже добавлен, добавление нового невозможно.");
        }
    }
    ui->groupsLineEdit->clear();
}

void TeacherWindowGroupsPage::deleteGroup()
{
    const QString groupName = ui->groupsLineEdit->text();
    if (!groupName.isEmpty())
    {
        if (groupsPageModel->deleteGroup(groupName))
        {
            QMessageBox::information(0, "Успешная операция", "Класс [" + groupName + "] был успешно удалён.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо класса с таким именем не существует, удаление невозможно.");
        }
    }
    ui->groupsLineEdit->clear();
}

void TeacherWindowGroupsPage::addSubject()
{
    bool ok;
    const QString &subjectName = QInputDialog::getText(nullptr, QObject::tr("Добавить предмет"), QObject::tr("Введите предмет:"), QLineEdit::Normal, QString(), &ok);

    if (!subjectName.isEmpty())
    {
        if (groupsPageModel->addSubject(subjectName))
        {
            QMessageBox::information(0, "Успешная операция", "Предмет [" + subjectName + "] был успешно добавлен.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Такого предмета не существует либо он уже добавлен, добавление нового невозможно.");
        }
    }
}

void TeacherWindowGroupsPage::deleteSubject()
{
    bool ok;
    const QString &subjectName = QInputDialog::getText(nullptr, QObject::tr("Удалить предмет"), QObject::tr("Введите предмет:"), QLineEdit::Normal, QString(), &ok);

    if (!subjectName.isEmpty())
    {
        if (groupsPageModel->deleteSubject(subjectName))
        {
            QMessageBox::information(0, "Успешная операция", "Предмет [" + subjectName + "] был успешно удалён.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо предмета с таким именем не существует, удаление невозможно.");
        }
    }
}

void TeacherWindowGroupsPage::addStudent()
{
    bool ok;
    const QString &studentName = QInputDialog::getText(nullptr, QObject::tr("Добавить ученика"), QObject::tr("Введите ФИО:"), QLineEdit::Normal, QString(), &ok);

    if (!studentName.isEmpty())
    {
        if (groupsPageModel->addStudent(studentName))
        {
            QMessageBox::information(0, "Успешная операция", "Ученик [" + studentName + "] был успешно добавлен.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо вы неправильео ввели ФИО либо такой ученик уже добавлен, добавление нового невозможно.");
        }
    }
}

void TeacherWindowGroupsPage::deleteStudent()
{
    bool ok;
    const QString &studentName = QInputDialog::getText(nullptr, QObject::tr("Добавить ученика"), QObject::tr("Введите ФИО:"), QLineEdit::Normal, QString(), &ok);

    if (!studentName.isEmpty())
    {
        if (groupsPageModel->deleteStudent(studentName))
        {
            QMessageBox::information(0, "Успешная операция", "Ученик [" + studentName + "] был успешно удалён.");
        }
        else
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо ученика с таким ФИО не существует, добавление удаление невозможно.");
        }
    }
}
