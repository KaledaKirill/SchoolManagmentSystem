#include "SubjectsDAO.h"
#include "../../Exceptions/notworkingrequest.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QDebug>

QStringList SubjectsDAO::getAllSubjectsForGroup(const QString& groupName)
{
    QStringList subjectNames;
    QSqlQuery query;
    query.prepare("SELECT s.name FROM SUBJECTS s "
                  "JOIN GROUPS g ON s.group_id = g.id "
                  "WHERE g.name = :groupName");
    query.bindValue(":groupName", groupName);

    if (query.exec()) {
        while (query.next()) {
            subjectNames << query.value("name").toString();
        }
    } else {
        QString exceptionMessage = "Error in getting a subjects. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    return subjectNames;
}

void SubjectsDAO::addSubject(const QString& subjectName, const QString& groupName)
{
    QSqlQuery query;
    query.prepare("INSERT INTO SUBJECTS (name, group_id) "
                  "VALUES (:name, (SELECT id FROM GROUPS WHERE name = :groupName))");
    query.bindValue(":name", subjectName);
    query.bindValue(":groupName", groupName);

    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a subject [" + subjectName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void SubjectsDAO::deleteSubject(const QString& subjectName, const QString& groupName)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SUBJECTS WHERE name = :name AND group_id = (SELECT id FROM GROUPS WHERE name = :groupName)");
    query.bindValue(":name", subjectName);
    query.bindValue(":groupName", groupName);

    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a subject [" + subjectName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
