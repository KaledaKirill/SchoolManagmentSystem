#ifndef IGRADESDAO_H
#define IGRADESDAO_H

#include <QList>
#include <QString>

class IGradesDAO
{

public:
    virtual QList<Grade> getAllGradesForStudent(const QString& groupName, const QString& studentName) = 0;
    virtual void addGrade(const Grade& grade) = 0; virtual void deleteGrade(const Grade& grade) = 0;
    virtual void updateGrade(const Grade& oldGrade, const Grade& newGrade) = 0;
    virtual ~IGradesDAO() = default;

};

#endif
