#include "journalpagemodel.h"
#include "../DAO/groupsDAO.h"
#include "../DAO/studentsDAO.h"
#include "../DAO/subjectsdao.h"
#include "../../Exceptions/notworkingrequest.h"

JournalPageModel::JournalPageModel()
    : groupsDAO(new GroupsDAO),
    subjectsDAO(new SubjectsDAO),
    studentsDAO(new StudentsDAO)
{
    loadData();
}

void JournalPageModel::loadData()
{
    groupNamesList = groupsDAO->getAllGroupNames();
    groupsListModel.setStringList(groupNamesList);
    loadGroupData(groupNamesList[0]);
}

void JournalPageModel::chooseSubject(const QString &subjectName)
{

}

void JournalPageModel::loadGroupData(const QString &groupName)
{
    currentGroup = groupsDAO->getGroup(groupName);
    subjectsListModel.setStringList(currentGroup.getSubjectsList());
}

QStringListModel *JournalPageModel::getGroupsListModel()
{
    return &groupsListModel;
}

QStringListModel *JournalPageModel::getSubjectsListModel()
{
    return &subjectsListModel;
}

JournalModel *JournalPageModel::getJournaltModel()
{
    return &journalModel;
}
