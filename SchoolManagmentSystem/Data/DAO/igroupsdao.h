#ifndef IGROUPSDAO_H
#define IGROUPSDAO_H

#include "../Entity/group.h"

#include <QStringList>

class IGroupsDAO
{

public:
    virtual QStringList getAllGroupNames() = 0;
    virtual Group getGroup(const QString& groupName) = 0;
    virtual void addGroup(const QString& groupName) = 0;
    virtual void deleteGroup(const QString& groupName) = 0;
    virtual ~IGroupsDAO() = default;

};

#endif
