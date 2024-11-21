#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"

#include <QString>
#include <QList>

class Student
{
public:
    Student(const QString& name, const QString& group, const QList<Grade>& gradesList = QList<Grade>());

    bool addGrade(const Grade& grade);
    bool deleteGrade(const Grade& grade);

    QString getStudentName() const;
    void setStudentName(const QString& studentName);

    QString getGroup() const;
    void setGroup(const QString& groupName);

    QList<Grade> getGradesList() const;
    void setGradesList(const QList<Grade>& gradesList);

    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;

private:
    QString name;
    QString group;
    QList<Grade> gradesList;

};

#endif
