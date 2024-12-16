#include "teacherwindowjournalpage.h"
#include "ui_teacherwindow.h"

#include <QDate>
#include <QMessageBox>

TeacherWindowJournalPage::TeacherWindowJournalPage(Ui::TeacherWindow* teacherWindow)
    : ui(teacherWindow),
    journalPageModel(new JournalPageModel)
{
    ui->groupsCbx_2->setModel(journalPageModel->getGroupsListModel());
    ui->subjectsCbx->setModel(journalPageModel->getSubjectsListModel());
    ui->journalTableView->setModel(journalPageModel->getJournalModel());
    ui->resJournalTableView->setModel(journalPageModel->getResJournalModel());
}

void TeacherWindowJournalPage::loadData()
{
    journalPageModel->loadData();
}

void TeacherWindowJournalPage::loadResData()
{
    journalPageModel->loadResJournalData();
}

void TeacherWindowJournalPage::chooseSubject()
{
    const QString subjectName = ui->subjectsCbx->currentText();
    if (!subjectName.isEmpty())
    {
        journalPageModel->chooseSubject(subjectName);
    }
}

void TeacherWindowJournalPage::chooseQuarter()
{
    const int quarter = ui->quartersCbx->currentIndex() + 1;
    journalPageModel->chooseQuarter(quarter);
}

void TeacherWindowJournalPage::addDate()
{
    const QString dateString = ui->dateLineEdit->text();
    QDate date = QDate::fromString(dateString, "dd.MM.yyyy");

    if (!date.isValid() || !journalPageModel->addDate(date))
    {
        QMessageBox::warning(0, "Неуспешная операция", "Видимо данная дата не входит в выбранную четверть.");
    }
    ui->dateLineEdit->clear();
}


void TeacherWindowJournalPage::chooseGroup()
{
    const QString groupName = ui->groupsCbx_2->currentText();

    if (!groupName.isEmpty())
    {
        journalPageModel->chooseGroup(groupName);
    }
}
