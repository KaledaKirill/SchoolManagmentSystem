#ifndef JOURNALPAGEMODEL_H
#define JOURNALPAGEMODEL_H

#include "../DAO/igroupsdao.h"
#include "../DAO/istudentsdao.h"
#include "../../Utils/logger.h"
#include "../Entity/group.h"
#include "journalmodel.h"
#include "resjournalmodel.h"
#include "DatesService.h"

#include <QStringListModel>

class JournalPageModel
{
public:
    JournalPageModel();

    void loadData();
    void loadGroupData(const QString& groupName);
    void chooseGroup(const QString& groupName);
    void chooseSubject(const QString& subjectName);
    void chooseQuarter(int quarter);
    bool addDate(const QDate& date);

    QStringListModel* getGroupsListModel();
    QStringListModel* getSubjectsListModel();
    JournalModel* getJournalModel();
    ResJournalModel* getResJournalModel();

private:
    JournalModel journalModel;
    QStringListModel groupsListModel;
    QStringListModel subjectsListModel;
    ResJournalModel resJournalModel;

    QString currentSubject;
    QStringList groupNamesList;
    Group currentGroup;
    int currentQuarter;

    QScopedPointer<IGroupsDAO> groupsDAO;
    QScopedPointer<IStudentsDAO> studentsDAO;

    QScopedPointer<DatesService> datesService;

    Logger log;
};

#endif
