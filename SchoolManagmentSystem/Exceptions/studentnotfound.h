#ifndef STUDENTNOTFOUND_H
#define STUDENTNOTFOUND_H

#include <QString>

class StudentNotFound
{
public:
    StudentNotFound(const QString& message) : _message(message) {}
    QString what() const { return "Student not found. Exception: " + _message; }

private:
    QString _message;

};

#endif
