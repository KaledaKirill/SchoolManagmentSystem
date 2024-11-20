#ifndef GROUP_H
#define GROUP_H

#include "Student.h"

#include <QString>
#include <QList>
#include <QStringList>

class Group
{

public:
    bool addSubject(const QString& subject);
    bool deleteSubject(const QString& subject);

    bool addStudent(const Student& student);
    bool deleteStudent(const Student& student);

    QString getGroupName() const;
    void setGroupName(const QString& groupName);

    QList<Student> getStudentsList() const;
    void setStudentsList(const QList<Student>& studentsList);

    QStringList getSubjectsList() const;
    void setSubjectsList(const QStringList& subjectsList);

private:
    QString groupName;
    QList<Student> studentsList;
    QStringList subjectsList;

};

#endif
