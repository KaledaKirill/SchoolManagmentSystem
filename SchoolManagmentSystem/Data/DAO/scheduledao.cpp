#include "ScheduleDAO.h"
#include "../../Exceptions/NotWorkingRequest.h"
#include "../../Exceptions/GroupNotFound.h"

#include <QDebug>

QHash<QPair<int, int>, QString> ScheduleDAO::getScheduleForGroup(const QString& group) const
{
    QHash<QPair<int, int>, QString> schedule;
    int groupId = getGroupIdByName(group);

    QSqlQuery query;
    query.prepare("SELECT number, day_of_week, name FROM SCHEDULE WHERE group_id = :groupId");
    query.bindValue(":groupId", groupId);

    if (!query.exec()) {
        QString exceptionMessage = "Error retrieving schedule for group [" + group + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(exceptionMessage);
    }

    while (query.next()) {
        int number = query.value("number").toInt();
        int dayOfWeek = query.value("day_of_week").toInt();
        QString subject = query.value("name").toString();

        schedule.insert(QPair<int, int>(dayOfWeek, number), subject);
    }

    return schedule;
}

void ScheduleDAO::addLesson(const QString& subject, const QString& group, int dayOfWeek, int number)
{
    int groupId = getGroupIdByName(group);

    QSqlQuery query;
    query.prepare("INSERT INTO SCHEDULE (name, group_id, day_of_week, number) "
                  "VALUES (:name, :groupId, :dayOfWeek, :number)");
    query.bindValue(":name", subject);
    query.bindValue(":groupId", groupId);
    query.bindValue(":dayOfWeek", dayOfWeek);
    query.bindValue(":number", number);

    if (!query.exec()) {
        QString exceptionMessage = "Error adding lesson [" + subject + "] for group [" + group + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(exceptionMessage);
    }
}

void ScheduleDAO::deleteLesson(const QString& subject, const QString& group, int dayOfWeek, int number)
{
    int groupId = getGroupIdByName(group);

    QSqlQuery query;
    query.prepare("DELETE FROM SCHEDULE WHERE name = :name AND group_id = :groupId AND day_of_week = :dayOfWeek AND number = :number");
    query.bindValue(":name", subject);
    query.bindValue(":groupId", groupId);
    query.bindValue(":dayOfWeek", dayOfWeek);
    query.bindValue(":number", number);

    if (!query.exec()) {
        QString exceptionMessage = "Error deleting lesson [" + subject + "] for group [" + group + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(exceptionMessage);
    }

    if (query.numRowsAffected() == 0) {
        QString exceptionMessage = "Lesson [" + subject + "] not found for group [" + group + "].";
        throw NotWorkingRequest(exceptionMessage);
    }
}

void ScheduleDAO::updateLesson(const QString& oldSubject, const QString& newSubject, const QString& group, int dayOfWeek, int number)
{
    int groupId = getGroupIdByName(group);

    QSqlQuery query;
    query.prepare("UPDATE SCHEDULE SET name = :newName WHERE name = :oldName AND group_id = :groupId AND day_of_week = :dayOfWeek AND number = :number");
    query.bindValue(":newName", newSubject);
    query.bindValue(":oldName", oldSubject);
    query.bindValue(":groupId", groupId);
    query.bindValue(":dayOfWeek", dayOfWeek);
    query.bindValue(":number", number);

    if (!query.exec()) {
        QString exceptionMessage = "Error updating lesson [" + oldSubject + "] to [" + newSubject + "] for group [" + group + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(exceptionMessage);
    }

    if (query.numRowsAffected() == 0) {
        QString exceptionMessage = "Lesson [" + oldSubject + "] not found for group [" + group + "].";
        throw NotWorkingRequest(exceptionMessage);
    }
}

int ScheduleDAO::getGroupIdByName(const QString& group) const
{
    QSqlQuery query;
    query.prepare("SELECT id FROM GROUPS WHERE name = :name");
    query.bindValue(":name", group);

    if (!query.exec() || !query.next()) {
        QString exceptionMessage = "Group [" + group + "] does not exist.";
        throw GroupNotFound(exceptionMessage);
    }

    return query.value(0).toInt();
}
