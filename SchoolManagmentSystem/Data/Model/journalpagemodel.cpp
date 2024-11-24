#include "journalpagemodel.h"
#include "../DAO/groupsDAO.h"
#include "../DAO/studentsDAO.h"
#include "../DAO/subjectsdao.h"


JournalPageModel::JournalPageModel()
    : groupsDAO(new GroupsDAO),
    subjectsDAO(new SubjectsDAO),
    studentsDAO(new StudentsDAO),
    datesService(new DatesService)
{
    currentQuarter = 1;
    loadData();
}

void JournalPageModel::loadData()
{
    groupNamesList = groupsDAO->getAllGroupNames();
    groupsListModel.setStringList(groupNamesList);
    if(!groupNamesList.isEmpty())
        loadGroupData(groupNamesList[0]);
}

void JournalPageModel::chooseSubject(const QString &subjectName)
{
    if(currentSubject == subjectName)
        return;

    currentSubject = subjectName;
    journalModel.setSubject(subjectName);
    journalModel.setDates(QList<QDate>());
    currentGroup = groupsDAO->getGroup(currentGroup.getName());
}

void JournalPageModel::chooseQuarter(int quarter)
{
    currentQuarter = quarter;
    journalModel.setDates(datesService->getQuarterDatesForGroupForSubject(currentGroup, quarter, currentSubject));
    currentGroup = groupsDAO->getGroup(currentGroup.getName());
}

bool JournalPageModel::addDate(const QDate &date)
{
    if(!datesService->isDateInQuarter(date, currentQuarter))
        return false;

    journalModel.addDate(date);
    log.debug(__FILE__, "Date [" + date.toString() + "] was added.");
    return true;
}

void JournalPageModel::chooseGroup(const QString &groupName)
{
    if(currentGroup.getName() == groupName)
        return;

    loadGroupData(groupName);
}

void JournalPageModel::loadGroupData(const QString &groupName)
{
    currentGroup = groupsDAO->getGroup(groupName);
    subjectsListModel.setStringList(currentGroup.getSubjectsList());
    journalModel.setStudentList(currentGroup.getStudentsList());
    journalModel.setDates(QList<QDate>());
}

QStringListModel *JournalPageModel::getGroupsListModel()
{
    return &groupsListModel;
}

QStringListModel *JournalPageModel::getSubjectsListModel()
{
    return &subjectsListModel;
}

JournalModel *JournalPageModel::getJournalModel()
{
    return &journalModel;
}
