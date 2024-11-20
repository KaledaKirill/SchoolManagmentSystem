#ifndef GRADE_H
#define GRADE_H

#include <QString>
#include <QDate>

class Grade
{

public:
    int getGradeValue() const;
    void setGradeValue(int value);

    QDate getDate() const;
    void setDate(const QDate& date);

    QString getSubject() const;
    void setSubject(const QString& subject);

    QString getStudentName() const;
    void setStudentName(const QString& studentName);

private:
    int gradeValue;
    QDate date;
    QString subject;
    QString studentName;

};

#endif
