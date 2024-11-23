#include "teacherwindowjournalpage.h"
#include "ui_teacherwindow.h"

TeacherWindowJournalPage::TeacherWindowJournalPage(Ui::TeacherWindow* teacherWindow)
    : ui(teacherWindow),
    journalPageModel(new JournalPageModel)
{
    ui->groupsCbx_2->setModel(journalPageModel->getGroupsListModel());
    ui->subjectsCbx->setModel(journalPageModel->getSubjectsListModel());
    ui->journalTableView->setModel(journalPageModel->getJournaltModel());
}

void TeacherWindowJournalPage::loadData()
{
    journalPageModel->loadData();
}

void TeacherWindowJournalPage::chooseSubject()
{
    const QString subjectName = ui->subjectsCbx->currentText();
    if (!subjectName.isEmpty())
    {
        journalPageModel->chooseSubject(subjectName);
    }
}

void TeacherWindowJournalPage::chooseGroup()
{
    const QString groupName = ui->groupsCbx_2->currentText();

    if (!groupName.isEmpty())
    {
        journalPageModel->loadGroupData(groupName);
    }
}
