#include "StudentsDAO.h"
#include "../../Exceptions/notworkingrequest.h"
#include "../../Exceptions/studentnotfound.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QDebug>
#include "../Entity/grade.h"

QList<Student> StudentsDAO::getAllStudentsForGroup(const QString& groupName)
{
    QList<Student> students;
    QSqlQuery query;
    query.prepare("SELECT id, name FROM STUDENTS WHERE group_id = (SELECT id FROM GROUPS WHERE name = :groupName) ORDER BY name ASC");
    query.bindValue(":groupName", groupName);

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

            students.append(Student(studentName, groupName, gradesList));
        }
    } else {
        QString exceptionMessage = "Error in getting students for group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    return students;
}

QStringList StudentsDAO::getAllStudentNamesForGroup(const QString& groupName)
{
    QStringList studentNames;
    QSqlQuery query;
    query.prepare("SELECT name FROM STUDENTS WHERE group_id = (SELECT id FROM GROUPS WHERE name = :groupName) ORDER BY name ASC");
    query.bindValue(":groupName", groupName);

    if (query.exec()) {
        while (query.next()) {
            studentNames << query.value("name").toString();
        }
    } else {
        QString exceptionMessage = "Error in getting student names for group[" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    return studentNames;
}

Student StudentsDAO::getStudent(const QString& studentName, const QString& groupName)
{
    QSqlQuery query;
    query.prepare("SELECT id, name FROM STUDENTS WHERE name = :name AND group_id = (SELECT id FROM GROUPS WHERE name = :groupName)");
    query.bindValue(":name", studentName);
    query.bindValue(":groupName", groupName);

    if (!query.exec() || !query.next()) {
        QString exceptionMessage = "Student [" + studentName + "] from group [" + groupName + "] isn't exist.";
        throw StudentNotFound(exceptionMessage);
    }

    int studentId = query.value("id").toInt();
    QString name = query.value("name").toString();

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

    return Student(name, groupName, gradesList);
}

void StudentsDAO::addStudent(const QString& studentName, const QString& groupName)
{
    QSqlQuery query;
    query.prepare("INSERT INTO STUDENTS (name, group_id) VALUES (:name, (SELECT id FROM GROUPS WHERE name = :groupName))");
    query.bindValue(":name", studentName);
    query.bindValue(":groupName", groupName);

    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a student [" + studentName + "] from group [" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void StudentsDAO::deleteStudent(const QString& studentName, const QString& groupName)
{
    QSqlQuery query;
    query.prepare("DELETE FROM STUDENTS WHERE name = :name AND group_id = (SELECT id FROM GROUPS WHERE name = :groupName)");
    query.bindValue(":name", studentName);
    query.bindValue(":groupName", groupName);

    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a student [" + studentName + "] from group [" + groupName + "]. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
