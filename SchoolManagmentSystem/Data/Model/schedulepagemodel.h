#ifndef SCHEDULEPAGEMODEL_H
#define SCHEDULEPAGEMODEL_H

#include "../../Data/DAO/ischeduledao.h"
#include "../../Data/DAO/igroupsdao.h"
#include "schedulemodel.h"

#include <QStringList>
#include <QStringListModel>

class SchedulePageModel
{
public:
    SchedulePageModel();

    void chooseGroup(const QString& groupName);
    void loadData();

    QStringListModel* getGroupsListModel();
    ScheduleModel* getScheduleModel();

private:
    QStringListModel groupsListModel;
    QStringList groupNamesList;
    ScheduleModel scheduleModel;

    QScopedPointer<IGroupsDAO> groupsDAO;

};

#endif
