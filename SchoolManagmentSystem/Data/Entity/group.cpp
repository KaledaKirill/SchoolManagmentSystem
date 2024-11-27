#include "group.h"

Group::Group()
    : name(""),
    studentsList(),
    subjectsList() {}

Group::Group(const QString& groupName, const QList<Student>& studentsList, const QStringList& subjectsList)
    : name(groupName),
    studentsList(studentsList),
    subjectsList(subjectsList)
{
    fillStudentNamesList();
}

bool Group::addSubject(const QString& subject)
{
    if (!subjectsList.contains(subject) && validator.isSubjectValid(subject)) {
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
    const QString studentName = student.getStudentName();

    if (!studentNamesList.contains(studentName) && validator.isStudentNameValid(studentName))
    {
        studentsList.append(student);
        studentNamesList.append(student.getStudentName());
        return true;
    }
    return false;
}

bool Group::deleteStudent(const Student& student)
{
    return studentsList.removeOne(student);
}

bool Group::deleteStudentByName(const QString& studentName)
{
    for (int i = 0; i < studentsList.size(); ++i)
    {
        if (studentsList[i].getStudentName() == studentName)
        {
            studentsList.removeAt(i);
            studentNamesList.removeAll(studentName);
            return true;
        }
    }
    return false;
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

QStringList Group::getStudentNamesList() const
{
    return studentNamesList;
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

void Group::fillStudentNamesList()
{
    for (const Student& student : studentsList)
    {
        studentNamesList.append(student.getStudentName());
    }
}
