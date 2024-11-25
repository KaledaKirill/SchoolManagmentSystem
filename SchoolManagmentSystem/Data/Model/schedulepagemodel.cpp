#include "schedulepagemodel.h"
#include "../../Data/DAO/scheduledao.h"
#include "../../Data/DAO/groupsdao.h"

SchedulePageModel::SchedulePageModel()
    : groupsDAO(new GroupsDAO),
    scheduleDAO(new ScheduleDAO)
{
    loadData();
}

void SchedulePageModel::chooseGroup(const QString &groupName)
{
    scheduleModel.loadSchedule(groupName);
}


void SchedulePageModel::loadData()
{
    groupNamesList = groupsDAO->getAllGroupNames();
    groupsListModel.setStringList(groupNamesList);
    if(!groupNamesList.isEmpty())
        chooseGroup(groupNamesList[0]);
}

QStringListModel* SchedulePageModel::getGroupsListModel()
{
    return &groupsListModel;
}

ScheduleModel *SchedulePageModel::getScheduleModel()
{
    return &scheduleModel;
}
