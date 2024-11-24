#ifndef DATESSERVICE_H
#define DATESSERVICE_H

#include "../Entity/group.h"

#include <QList>
#include <QDate>
#include <QDebug>

class DatesService
{
public:
    struct DateRange
    {
        QDate start;
        QDate end;
    };

    DatesService();

    QList<QDate> getQuarterDatesForGroupForSubject(const Group& group, int quarter, const QString& subject) const;
    DateRange getQuarterDateRange(int quarter) const;
    bool isDateInQuarter(const QDate& date, int quarter) const;

private:
    QHash<int, DateRange> quarterRanges;

    void initializeQuarterRanges();
};

#endif
