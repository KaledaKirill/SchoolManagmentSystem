#include "teacherwindowgroupspage.h"
#include "../../Data/UndoRedo/addgroupcommand.h"
#include "../../Data/UndoRedo/deletegroupcommand.h"
#include "../../Data/UndoRedo/addstudentcommand.h"
#include "../../Data/UndoRedo/deletestudentcommand.h"
#include "../../Data/UndoRedo/addsubjectcommand.h"
#include "../../Data/UndoRedo/deletesubjectcommand.h"
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
        try
        {
            auto* command = new AddGroupCommand(groupsPageModel.get(), groupName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Класс [" + groupName + "] был успешно добавлен.");
        }
        catch (const std::exception& e)
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
        try
        {
            auto* command = new DeleteGroupCommand(groupsPageModel.get(), groupName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Класс [" + groupName + "] был успешно удалён.");
        }
        catch (const std::exception& e)
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
        try
        {
            auto* command = new AddSubjectCommand(groupsPageModel.get(), subjectName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Предмет [" + subjectName + "] был успешно добавлен.");
        }
        catch (const std::exception& e)
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
        try
        {
            auto* command = new DeleteSubjectCommand(groupsPageModel.get(), subjectName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Предмет [" + subjectName + "] был успешно удалён.");
        }
        catch (const std::exception& e)
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
        try
        {
            auto* command = new AddStudentCommand(groupsPageModel.get(), studentName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Ученик [" + studentName + "] был успешно добавлен.");
        }
        catch (const std::exception& e)
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
        try
        {
            auto* command = new DeleteStudentCommand(groupsPageModel.get(), studentName);
            groupsPageModel->getUndoStack()->push(command);
            QMessageBox::information(0, "Успешная операция", "Ученик [" + studentName + "] был успешно удалён.");
        }
        catch (const std::exception& e)
        {
            QMessageBox::warning(0, "Неуспешная операция", "Видимо ученика с таким ФИО не существует, добавление удаление невозможно.");
        }
    }
}

void TeacherWindowGroupsPage::undoLastAction()
{
    groupsPageModel->getUndoStack()->undo();
}

void TeacherWindowGroupsPage::redoLastAction()
{
    groupsPageModel->getUndoStack()->redo();
}
