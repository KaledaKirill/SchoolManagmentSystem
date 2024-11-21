#include "grade.h"

Grade::Grade(const int value, const QDate& date, const QString& subject, const QString& studentName)
    : gradeValue(value),
    date(date),
    subject(subject),
    studentName(studentName) {}

int Grade::getGradeValue() const
{
    return gradeValue;
}

void Grade::setGradeValue(int value)
{
    gradeValue = value;
}

QDate Grade::getDate() const
{
    return date;
}

void Grade::setDate(const QDate& date)
{
    this->date = date;
}

QString Grade::getSubject() const
{
    return subject;
}

void Grade::setSubject(const QString& subject)
{
    this->subject = subject;
}

QString Grade::getStudentName() const
{
    return studentName;
}

void Grade::setStudentName(const QString& studentName)
{
    this->studentName = studentName;
}

bool Grade::operator==(const Grade& other) const
{
    return gradeValue == other.gradeValue &&
           date == other.date &&
           subject == other.subject &&
           studentName == other.studentName;
}

bool Grade::operator!=(const Grade& other) const
{
    return !(*this == other);
}
