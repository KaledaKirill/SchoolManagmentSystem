#ifndef JOURNALPAGEMODEL_H
#define JOURNALPAGEMODEL_H

#include "../DAO/IGroupsDAO.h"
#include "../DAO/ISubjectsDAO.h"
#include "../DAO/IStudentsDAO.h"
#include "../../Utils/logger.h"
#include "../Entity/group.h"
#include "journalmodel.h"

#include <QStringListModel>

class JournalPageModel
{
public:
    JournalPageModel();

    void loadData();
    void loadGroupData(const QString& groupName);
    void chooseGroup(const QString& groupName);
    void chooseSubject(const QString& subjectName);

    QStringListModel* getGroupsListModel();
    QStringListModel* getSubjectsListModel();
    JournalModel* getJournaltModel();

private:
    JournalModel journalModel;
    QStringListModel groupsListModel;
    QStringListModel subjectsListModel;

    QString currentSubject;
    QStringList groupNamesList;
    Group currentGroup;
    int currentQuarter;

    QScopedPointer<IGroupsDAO> groupsDAO;
    QScopedPointer<ISubjectsDAO> subjectsDAO;
    QScopedPointer<IStudentsDAO> studentsDAO;

    Logger log;
};

#endif
