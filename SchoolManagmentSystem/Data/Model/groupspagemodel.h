#ifndef GROUPSPAGEMODEL_H
#define GROUPSPAGEMODEL_H

#include "../DAO/igroupsdao.h"
#include "../DAO/isubjectsdao.h"
#include "../DAO/istudentsdao.h"
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
    Validator validator;

    void loadData();
    void loadGroupData(const QString& groupName);
    void updateGroupsListModelFromList();
    void updateSubjectsListModelFromList();
    void updateStudentsListModelFromList();

};

#endif
