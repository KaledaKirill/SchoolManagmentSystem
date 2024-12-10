#ifndef STUDENTNOTFOUND_H
#define STUDENTNOTFOUND_H

#include "notworkingrequest.h"

class StudentNotFound : public NotWorkingRequest
{
public:
    StudentNotFound(const QString& message) : NotWorkingRequest(message) {}
    QString what() const { return "Student not found. Exception: " + message; }

};

#endif
