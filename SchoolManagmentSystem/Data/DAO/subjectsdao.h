#ifndef SUBJECTSDAO_H
#define SUBJECTSDAO_H

#include "isubjectsdao.h"

class SubjectsDAO : public ISubjectsDAO
{
public:
    QStringList getAllSubjectsForGroup(const QString& groupName) override;
    void addSubject(const QString& subjectName, const QString& groupName) override;
    void deleteSubject(const QString& subjectName, const QString& groupName) override;

};

#endif
