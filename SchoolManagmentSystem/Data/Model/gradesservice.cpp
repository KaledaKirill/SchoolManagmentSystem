#include "GradesService.h"

GradesService::GradesService() {}

double GradesService::getAverageGradeForQuarter(const Student& student, const QString& subject, int quarter) const
{
    const QList<Grade>& gradesList = student.getGradesList();
    DatesService::DateRange quarterRange = datesService.getQuarterDateRange(quarter);

    int total = 0;
    int count = 0;

    for (const Grade& grade : gradesList)
    {
        if (grade.getSubject() == subject &&
            grade.getDate() >= quarterRange.start &&
            grade.getDate() <= quarterRange.end)
        {
            total += grade.getGradeValue();
            ++count;
        }
    }

    return count > 2 ? static_cast<double>(total) / count : -1.0;
}

double GradesService::getAverageGradeForYear(const Student& student, const QString& subject) const
{
    double totalAverage = 0.0;
    int quarterCount = 0;

    for (int quarter = 1; quarter <= 4; ++quarter)
    {
        double quarterAverage = getAverageGradeForQuarter(student, subject, quarter);
        if (quarterAverage > 0.0)
        {
            totalAverage += quarterAverage;
            ++quarterCount;
        }
    }

    return quarterCount > 0 ? totalAverage / quarterCount : -1.0;
}

double GradesService::getStudentAverageGradeForYear(const Student& student) const
{
    const QList<Grade>& gradesList = student.getGradesList();
    QSet<QString> subjects;

    for (const Grade& grade : gradesList)
    {
        subjects.insert(grade.getSubject());
    }

    double totalAverage = 0.0;
    int subjectCount = 0;

    for (const QString& subject : subjects)
    {
        double subjectAverage = getAverageGradeForYear(student, subject);
        if (subjectAverage > 0.0)
        {
            totalAverage += subjectAverage;
            ++subjectCount;
        }
    }

    return subjectCount > 0 ? totalAverage / subjectCount : 0.0;
}
