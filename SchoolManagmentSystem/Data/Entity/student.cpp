#include "student.h"

Student::Student()
    : name(""),
    group(),
    gradesList() {}

Student::Student(const QString& name, const QString& group, const QList<Grade>& gradesList)
    : name(name),
    group(group),
    gradesList(gradesList) {}

bool Student::addGrade(const Grade& grade)
{
    if (gradesList.contains(grade) || !validator.isGradeValueValid(grade.getGradeValue())) {
        return false;
    }
    gradesList.append(grade);
    return true;
}

bool Student::deleteGrade(const Grade& grade)
{
    return gradesList.removeAll(grade);
}

bool Student::updateGrade(const Grade& oldGrade, const Grade& newGrade)
{
    int index = gradesList.indexOf(oldGrade);
    if (index != -1) {
        gradesList[index] = newGrade;
        return true;
    }
    return false;
}

QString Student::getStudentName() const
{
    return name;
}

void Student::setStudentName(const QString& studentName)
{
    name = studentName;
}

QString Student::getGroup() const
{
    return group;
}

void Student::setGroup(const QString& groupName)
{
    group = groupName;
}

QList<Grade> Student::getGradesList() const
{
    return gradesList;
}

void Student::setGradesList(const QList<Grade>& gradesList)
{
    this->gradesList = gradesList;
}

bool Student::operator==(const Student& other) const
{
    return name == other.name &&
           group == other.group;
}

bool Student::operator!=(const Student& other) const
{
    return !(*this == other);
}
