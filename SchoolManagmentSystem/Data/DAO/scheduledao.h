#ifndef SCHEDULEDAO_H
#define SCHEDULEDAO_H

#include "IScheduleDAO.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

class ScheduleDAO : public IScheduleDAO {
public:
    QHash<QPair<int, int>, QString> getScheduleForGroup(const QString& group) const override;
    void addLesson(const QString& subject, const QString& group, int dayOfWeek, int number) override;
    void deleteLesson(const QString& subject, const QString& group, int dayOfWeek, int number) override;
    void updateLesson(const QString& oldSubject, const QString& newSubject, const QString& group, int dayOfWeek, int number) override;

private:
    int getGroupIdByName(const QString& group) const;
};

#endif
