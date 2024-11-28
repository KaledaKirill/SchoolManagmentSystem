#include "GroupsDAO.h"
#include "../../Exceptions/notworkingrequest.h"
#include "../../Exceptions/groupnotfound.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

QStringList GroupsDAO::getAllGroupNames()
{
    QStringList groupNames;
    QSqlQuery query("SELECT name FROM GROUPS");
    while (query.next()) {
        groupNames << query.value(0).toString();
    }
    return groupNames;
}

Group GroupsDAO::getGroup(const QString& groupName)
{
    QSqlQuery query;

    query.prepare("SELECT id, name FROM GROUPS WHERE name = :name");
    query.bindValue(":name", groupName);

    if (!query.exec() || !query.next()) {
        QString exceptionMessage = "Group [" + groupName + "] isn't exist.";
        throw GroupNotFound(exceptionMessage);
    }

    int groupId = query.value("id").toInt();
    QString name = query.value("name").toString();

    QList<Student> studentsList;
    query.prepare("SELECT id, name FROM STUDENTS WHERE group_id = :groupId ORDER BY name ASC");
    query.bindValue(":groupId", groupId);

    if (query.exec()) {
        while (query.next()) {
            int studentId = query.value("id").toInt();
            QString studentName = query.value("name").toString();

            QList<Grade> gradesList;
            QSqlQuery gradeQuery;
            gradeQuery.prepare("SELECT value, date, subject_id FROM GRADES WHERE student_id = :studentId");
            gradeQuery.bindValue(":studentId", studentId);

            if (gradeQuery.exec()) {
                while (gradeQuery.next()) {
                    int gradeValue = gradeQuery.value("value").toInt();
                    QDate date = gradeQuery.value("date").toDate();
                    int subjectId = gradeQuery.value("subject_id").toInt();

                    QSqlQuery subjectQuery;
                    subjectQuery.prepare("SELECT name FROM SUBJECTS WHERE id = :subjectId");
                    subjectQuery.bindValue(":subjectId", subjectId);

                    if (subjectQuery.exec() && subjectQuery.next()) {
                        QString subject = subjectQuery.value("name").toString();
                        gradesList.append(Grade(gradeValue, date, subject, studentName));
                    }
                }
            }

            studentsList.append(Student(studentName, groupName, gradesList));
        }
    }
    else {
        QString exceptionMessage = "Error in getting a group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    QStringList subjectsList;
    query.prepare("SELECT name FROM SUBJECTS WHERE group_id = :groupId ORDER BY name ASC");
    query.bindValue(":groupId", groupId);

    if (query.exec()) {
        while (query.next()) {
            subjectsList.append(query.value("name").toString());
        }
    }
    else {
        QString exceptionMessage = "Error in getting a group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    return Group(name, studentsList, subjectsList);
}


void GroupsDAO::addGroup(const QString& groupName)
{
    QSqlQuery query;
    query.prepare("INSERT INTO GROUPS (name) VALUES (:name)");
    query.bindValue(":name", groupName);
    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void GroupsDAO::deleteGroup(const QString& groupName)
{
    QSqlQuery query;
    query.prepare("DELETE FROM GROUPS WHERE name = :name");
    query.bindValue(":name", groupName);
    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
