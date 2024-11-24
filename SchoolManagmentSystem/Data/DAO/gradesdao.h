#ifndef GRADESDAO_H
#define GRADESDAO_H

#include "igradesdao.h"

class GradesDAO : public IGradesDAO
{
public:
    QList<Grade> getAllGradesForStudent(const QString& groupName, const QString& studentName) override;
    void addGrade(const Grade& grade) override;
    void deleteGrade(const Grade& grade) override;
    void updateGrade(const Grade& oldGrade, const Grade& newGrade) override;

};

#endif
