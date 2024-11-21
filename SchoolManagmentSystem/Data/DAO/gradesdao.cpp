#include "GradesDAO.h"
#include "../../Exceptions/notworkingrequest.h"

#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QDebug>

QList<Grade> GradesDAO::getAllGradesForStudent(const QString& groupName, const QString& studentName)
{
    QList<Grade> grades;
    QSqlQuery query;
    query.prepare("SELECT g.value, g.date, s.name "
                  "FROM GRADES g "
                  "JOIN STUDENTS st ON g.student_id = st.id "
                  "JOIN SUBJECTS s ON g.subject_id = s.id "
                  "JOIN GROUPS gr ON st.group_id = gr.id "
                  "WHERE gr.name = :groupName AND st.name = :studentName");
    query.bindValue(":groupName", groupName);
    query.bindValue(":studentName", studentName);

    if (query.exec()) {
        while (query.next()) {
            int gradeValue = query.value(0).toInt();
            QDate date = query.value(1).toDate();
            QString subject = query.value(2).toString();
            grades.append(Grade(gradeValue, date, subject, studentName));
        }
    } else {
        QString exceptionMessage = "Error in getting a grades. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }

    return grades;
}

void GradesDAO::addGrade(const Grade& grade)
{
    QSqlQuery query;
    query.prepare("INSERT INTO GRADES (value, date, student_id, subject_id) "
                  "VALUES (:value, :date, (SELECT id FROM STUDENTS WHERE name = :studentName), "
                  "(SELECT id FROM SUBJECTS WHERE name = :subject))");
    query.bindValue(":value", grade.getGradeValue());
    query.bindValue(":date", grade.getDate());
    query.bindValue(":studentName", grade.getStudentName());
    query.bindValue(":subject", grade.getSubject());

    if (!query.exec()) {
        QString exceptionMessage = "Error in adding a grades. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void GradesDAO::deleteGrade(const Grade& grade) {
    QSqlQuery query;
    query.prepare("DELETE FROM GRADES WHERE value = :value AND date = :date AND "
                  "student_id = (SELECT id FROM STUDENTS WHERE name = :studentName) AND "
                  "subject_id = (SELECT id FROM SUBJECTS WHERE name = :subject)");
    query.bindValue(":value", grade.getGradeValue());
    query.bindValue(":date", grade.getDate());
    query.bindValue(":studentName", grade.getStudentName());
    query.bindValue(":subject", grade.getSubject());

    if (!query.exec()) {
        QString exceptionMessage = "Error in deleting a grades. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}

void GradesDAO::updateGrade(const Grade& oldGrade, const Grade& newGrade) {
    QSqlQuery query;
    query.prepare("UPDATE GRADES SET value = :newValue, date = :newDate, "
                  "subject_id = (SELECT id FROM SUBJECTS WHERE name = :newSubject) "
                  "WHERE value = :oldValue AND date = :oldDate AND "
                  "student_id = (SELECT id FROM STUDENTS WHERE name = :studentName) AND "
                  "subject_id = (SELECT id FROM SUBJECTS WHERE name = :oldSubject)");
    query.bindValue(":newValue", newGrade.getGradeValue());
    query.bindValue(":newDate", newGrade.getDate());
    query.bindValue(":newSubject", newGrade.getSubject());
    query.bindValue(":oldValue", oldGrade.getGradeValue());
    query.bindValue(":oldDate", oldGrade.getDate());
    query.bindValue(":oldSubject", oldGrade.getSubject());
    query.bindValue(":studentName", oldGrade.getStudentName());

    if (!query.exec()) {
        QString exceptionMessage = "Error in updating a grades. Query: " + query.lastQuery();
        throw NotWorkingRequest(QString(exceptionMessage));
    }
}
