#ifndef STUDENT_H
#define STUDENT_H

#include "grade.h"
#include "validator.h"

#include <QString>
#include <QList>

class Student
{
public:
    Student();
    Student(const QString& name, const QString& group, const QList<Grade>& gradesList = QList<Grade>());

    bool addGrade(const Grade& grade);
    bool deleteGrade(const Grade& grade);
    bool updateGrade(const Grade& oldGrade, const Grade& newGrade);

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

    Validator validator;

};

#endif
