#ifndef GROUP_H
#define GROUP_H

#include "student.h"

#include <QString>
#include <QList>
#include <QStringList>

class Group
{

public:
    Group(const QString& groupName, const QList<Student>& studentsList = QList<Student>(), const QStringList& subjectsList = QStringList());

    bool addSubject(const QString& subject);
    bool deleteSubject(const QString& subject);

    bool addStudent(const Student& student);
    bool deleteStudent(const Student& student);

    QString getName() const;
    void setGroupName(const QString& groupName);

    QList<Student> getStudentsList() const;
    void setStudentsList(const QList<Student>& studentsList);

    QStringList getSubjectsList() const;
    void setSubjectsList(const QStringList& subjectsList);

private:
    QString name;
    QList<Student> studentsList;
    QStringList subjectsList;

};

#endif
