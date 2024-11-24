#ifndef ISCHEDULEDAO_H
#define ISCHEDULEDAO_H

#include <QString>
#include <QHash>
#include <QPair>

class IScheduleDAO
{
public:
    virtual QHash<QPair<int, int>, QString> getScheduleForGroup(const QString& group) const = 0;
    virtual void addLesson(const QString& subject, const QString& group, int dayOfWeek, int number) = 0;
    virtual void deleteLesson(const QString& subject, const QString& group, int dayOfWeek, int number) = 0;
    virtual void updateLesson(const QString& oldSubject, const QString& newSubject, const QString& group, int dayOfWeek, int number) = 0;
    virtual ~IScheduleDAO() = default;
};

#endif
