#ifndef ISTUDENTSDAO_H
#define ISTUDENTSDAO_H

#include "../Entity/student.h"

#include <QStringList>
#include <QList>

class IStudentsDAO
{

public:
    virtual QList<Student> getAllStudentsForGroup(const QString& groupName) = 0;
    virtual QStringList getAllStudentNamesForGroup(const QString& groupName) = 0;
    virtual Student getStudent(const QString& studentName, const QString& groupName) = 0;
    virtual void addStudent(const Student& student) = 0; virtual void deleteStudent(const QString& studentName, const QString& groupName) = 0;
    virtual ~IStudentsDAO() = default;

};

#endif
