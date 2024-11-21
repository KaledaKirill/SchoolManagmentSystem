#include "group.h"

Group::Group(const QString& groupName, const QList<Student>& studentsList, const QStringList& subjectsList)
    : name(groupName),
    studentsList(studentsList),
    subjectsList(subjectsList) {}

bool Group::addSubject(const QString& subject)
{
    if (!subjectsList.contains(subject)) {
        subjectsList.append(subject);
        return true;
    }
    return false;
}

bool Group::deleteSubject(const QString& subject)
{
    return subjectsList.removeOne(subject);
}

bool Group::addStudent(const Student& student)
{
    if (!studentsList.contains(student)) {
        studentsList.append(student);
        return true;
    }
    return false;
}

bool Group::deleteStudent(const Student& student)
{
    return studentsList.removeOne(student);
}

QString Group::getName() const
{
    return name;
}

void Group::setGroupName(const QString& groupName)
{
    this->name = groupName;
}

QList<Student> Group::getStudentsList() const
{
    return studentsList;
}

void Group::setStudentsList(const QList<Student>& studentsList)
{
    this->studentsList = studentsList;
}

QStringList Group::getSubjectsList() const
{
    return subjectsList;
}

void Group::setSubjectsList(const QStringList& subjectsList)
{
    this->subjectsList = subjectsList;
}
