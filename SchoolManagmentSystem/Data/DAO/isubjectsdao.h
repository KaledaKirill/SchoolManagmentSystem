#ifndef ISUBJECTSDAO_H
#define ISUBJECTSDAO_H

#include <QStringList>

class ISubjectsDAO
{

public:
    virtual QStringList getAllSubjectsForGroup(const QString& groupName) = 0;
    virtual void addSubject(const QString& subjectName, const QString& groupName) = 0;
    virtual void deleteSubject(const QString& subjectName, const QString& groupName) = 0;
    virtual ~ISubjectsDAO() = default;

};

#endif
