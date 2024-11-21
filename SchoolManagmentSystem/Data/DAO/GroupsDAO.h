#ifndef GROUPSDAO_H
#define GROUPSDAO_H

#include "IGroupsDAO.h"

class GroupsDAO : public IGroupsDAO
{
public:
    QStringList getAllGroupNames() override;
    Group getGroup(const QString& groupName) override;
    void addGroup(const QString& groupName) override;
    void deleteGroup(const QString& groupName) override;

};

#endif

