#include "groupspagemodel.h"
#include "../DAO/groupsDAO.h"
#include "../DAO/studentsDAO.h"
#include "../DAO/subjectsdao.h"
#include "../../Exceptions/notworkingrequest.h"

GroupsPageModel::GroupsPageModel()
    :
    groupsDAO(new GroupsDAO),
    subjectsDAO(new SubjectsDAO),
    studentsDAO(new StudentsDAO)
{
    loadData();
    groupsListModel.setStringList(groupNamesList);
}

void GroupsPageModel::chooseGroup(const QString& groupName)
{
    loadGroupData(groupName);
}

bool GroupsPageModel::addGroup(const QString &groupName)
{
    try
    {
        if(!groupNamesList.contains(groupName))
        {
            groupsDAO->addGroup(groupName);
            groupNamesList.append(groupName);
            updateGroupsListModelFromList();
            log.debug(__FILE__, "Group [" + groupName + "] was added.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool GroupsPageModel::deleteGroup(const QString &groupName)
{
    try
    {
        if(groupNamesList.contains(groupName))
        {
            groupsDAO->deleteGroup(groupName);
            groupNamesList.removeOne(groupName);
            updateGroupsListModelFromList();
            log.debug(__FILE__, "Group [" + groupName + "] was deleted.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool GroupsPageModel::addSubject(const QString& subjectName)
{
    try
    {
        if(currentGroup.addSubject(subjectName))
        {
            subjectsDAO->addSubject(subjectName, currentGroup.getName());
            updateSubjectsListModelFromList();
            log.debug(__FILE__, "Subject [" + subjectName + "] was added.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool GroupsPageModel::deleteSubject(const QString& subjectName)
{
    try
    {
        if(currentGroup.deleteSubject(subjectName))
        {
            subjectsDAO->addSubject(subjectName, currentGroup.getName());
            updateSubjectsListModelFromList();
            log.debug(__FILE__, "Subject [" + subjectName + "] was deleted.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool GroupsPageModel::addStudent(const QString &studentName)
{
    Student student(studentName, currentGroup.getName());

    try
    {
        if(currentGroup.addStudent(student))
        {
            studentsDAO->addStudent(studentName, currentGroup.getName());
            updateStudentsListModelFromList();
            log.debug(__FILE__, "Student [" + studentName + "] was added.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

bool GroupsPageModel::deleteStudent(const QString &studentName)
{
    try
    {
        if(currentGroup.deleteStudentByName(studentName))
        {
            studentsDAO->deleteStudent(studentName, currentGroup.getName());
            updateStudentsListModelFromList();
            log.debug(__FILE__, "Student [" + studentName + "] was deleted.");
            return true;
        }
        else
            return false;
    }
    catch (NotWorkingRequest& e)
    {
        log.warning(__FILE__, e.what());
        return false;
    }
}

void GroupsPageModel::loadData()
{
    groupNamesList = groupsDAO->getAllGroupNames();
    loadGroupData(groupNamesList[0]);
}

void GroupsPageModel::loadGroupData(const QString &groupName)
{
    currentGroup = groupsDAO->getGroup(groupName);
    subjectsListModel.setStringList(currentGroup.getSubjectsList());
    studentsListModel.setStringList(currentGroup.getStudentNamesList());
}

void GroupsPageModel::updateGroupsListModelFromList()
{
    groupsListModel.setStringList(groupNamesList);
}

QStringListModel* GroupsPageModel::getGroupsListModel()
{
    return &groupsListModel;
}

void GroupsPageModel::updateSubjectsListModelFromList()
{
    subjectsListModel.setStringList(currentGroup.getSubjectsList());
}

void GroupsPageModel::updateStudentsListModelFromList()
{
    studentsListModel.setStringList(currentGroup.getStudentNamesList());
}

QStringListModel *GroupsPageModel::getSubjectsListModel()
{
    return &subjectsListModel;
}

QStringListModel *GroupsPageModel::getStudentsListModel()
{
    return &studentsListModel;
}
