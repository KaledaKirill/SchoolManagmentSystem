#include "Validator.h"


bool Validator::isStudentNameValid(const QString& name)
{
    QRegularExpression regex("^[А-ЯЁ][а-яё]+\\s[А-ЯЁ][а-яё]+\\s[А-ЯЁ][а-яё]+$");
    return regex.match(name).hasMatch();
}

bool Validator::isGradeValueValid(int grade)
{
    return grade >= 0 && grade <= 10;
}

bool Validator::isSubjectValid(const QString& subject)
{
    QString lowerSubject = subject.toLower();

    static const QList<QString> validSubjects = {
        "белорусский язык",
        "русский язык",
        "математика",
        "физика",
        "химия",
        "биология",
        "география",
        "история беларуси",
        "иностранный язык",
        "информатика",
        "труд",
        "музыка",
        "физическая культура"
    };

    return validSubjects.contains(lowerSubject);
}

bool Validator::isGroupNameValid(const QString& group)
{
    QRegularExpression regex("^(1[0-1]|[1-9])[а-яё]?$");
    return regex.match(group).hasMatch();
}

