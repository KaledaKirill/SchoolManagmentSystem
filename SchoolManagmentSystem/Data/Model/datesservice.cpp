#include "datesservice.h"

DatesService::DatesService()
{
    initializeQuarterRanges();
}

MyList<QDate> DatesService::getQuarterDatesForGroupForSubject(const Group& group, int quarter, const QString& subject) const
{
    MyList<QDate> result;

    if (!quarterRanges.contains(quarter))
        return result;

    DateRange range = quarterRanges.value(quarter);

    for (const Student& student : group.getStudentsList())
    {
        for (const Grade& grade : student.getGradesList())
        {
            if (grade.getDate() >= range.start && grade.getDate() <= range.end && grade.getSubject() == subject)
            {
                if (!result.contains(grade.getDate()))
                {
                    result.append(grade.getDate());
                }
            }
        }
    }

    std::sort(result.rabegin(), result.raend());
    return result;
}

DatesService::DateRange DatesService::getQuarterDateRange(int quarter) const
{
    if (!quarterRanges.contains(quarter))
        return {QDate(), QDate()};

    return quarterRanges.value(quarter);
}

bool DatesService::isDateInQuarter(const QDate& date, int quarter) const
{
    if (!quarterRanges.contains(quarter))
        return false;

    DateRange range = quarterRanges.value(quarter);
    return date >= range.start && date <= range.end;
}

void DatesService::initializeQuarterRanges()
{
    quarterRanges[1] = {QDate(2024, 9, 1), QDate(2024, 10, 31)};
    quarterRanges[2] = {QDate(2024, 11, 1), QDate(2024, 12, 31)};
    quarterRanges[3] = {QDate(2025, 1, 8), QDate(2025, 3, 22)};
    quarterRanges[4] = {QDate(2025, 3, 25), QDate(2025, 5, 31)};
}
