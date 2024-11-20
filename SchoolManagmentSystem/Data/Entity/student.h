#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"

#include <QString>
#include <QList>

class Student
{

public:
    bool addGrade(const Grade& grade);
    bool deleteGrade(const Grade& grade);

    QString getStudentName() const;
    void setStudentName(const QString& studentName);

    QString getGroup() const;
    void setGroup(const QString& groupName);

    QList<Grade> getGradesList() const;
    void setGradesList(const QList<Grade>& gradesList);

private:
    QString studentName;
    QString group;
    QList<Grade> gradesList;

};

#endif
