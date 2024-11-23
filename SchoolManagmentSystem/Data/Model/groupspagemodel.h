#ifndef GROUPSPAGEMODEL_H
#define GROUPSPAGEMODEL_H

#include "../DAO/IGroupsDAO.h"
#include "../DAO/ISubjectsDAO.h"
#include "../DAO/IStudentsDAO.h"
#include "../Entity/group.h"
#include "../../Utils/logger.h"

#include <QStringListModel>
#include <QScopedPointer>

class GroupsPageModel
{
public:
    GroupsPageModel();

    void chooseGroup(const QString& groupName);
    bool addGroup(const QString& groupName);
    bool deleteGroup(const QString& groupName);

    bool addSubject(const QString& subjectName);
    bool deleteSubject(const QString& subjectName);

    bool addStudent(const QString& studentName);
    bool deleteStudent(const QString& studentName);

    QStringListModel* getGroupsListModel();
    QStringListModel* getSubjectsListModel();
    QStringListModel* getStudentsListModel();

private:
    QStringListModel groupsListModel;
    QStringListModel subjectsListModel;
    QStringListModel studentsListModel;

    Group currentGroup;
    QStringList groupNamesList;

    QScopedPointer<IGroupsDAO> groupsDAO;
    QScopedPointer<ISubjectsDAO> subjectsDAO;
    QScopedPointer<IStudentsDAO> studentsDAO;

    Logger log;

    void loadData();
    void loadGroupData(const QString& groupName);
    void updateGroupsListModelFromList();
    void updateSubjectsListModelFromList();
    void updateStudentsListModelFromList();

};

#endif
