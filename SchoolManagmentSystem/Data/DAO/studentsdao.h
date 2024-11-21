#ifndef STUDENTSDAO_H
#define STUDENTSDAO_H

#include "IStudentsDAO.h"
#include "../Entity/student.h"

class StudentsDAO : public IStudentsDAO
{
public:
    QList<Student> getAllStudentsForGroup(const QString& groupName) override;
    QStringList getAllStudentNamesForGroup(const QString& groupName) override;
    Student getStudent(const QString& studentName, const QString& groupName) override;
    void addStudent(const QString& studentName, const QString& groupName) override;
    void deleteStudent(const QString& studentName, const QString& groupName) override;

};

#endif
