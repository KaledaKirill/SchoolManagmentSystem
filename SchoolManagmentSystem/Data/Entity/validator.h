#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <QString>
#include <QList>
#include <QRegularExpression>

class Validator
{
public:
    bool isStudentNameValid(const QString& name);
    bool isGradeValueValid(int grade);
    bool isSubjectValid(const QString& subject);
    bool isGroupNameValid(const QString& group);

};

#endif
