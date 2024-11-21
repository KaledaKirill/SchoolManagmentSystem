#ifndef GRADE_H
#define GRADE_H

#include <QString>
#include <QDate>

class Grade
{

public:
    Grade(const int value, const QDate& date, const QString& subject, const QString& studentName);

    int getGradeValue() const;
    void setGradeValue(int value);

    QDate getDate() const;
    void setDate(const QDate& date);

    QString getSubject() const;
    void setSubject(const QString& subject);

    QString getStudentName() const;
    void setStudentName(const QString& studentName);

    bool operator==(const Grade& other) const;

    bool operator!=(const Grade& other) const;

private:
    int gradeValue;
    QDate date;
    QString subject;
    QString studentName;

};

#endif
