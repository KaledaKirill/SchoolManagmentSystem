#ifndef GROUPNOTFOUND_H
#define GROUPNOTFOUND_H

#include "notworkingrequest.h"

class GroupNotFound : public NotWorkingRequest
{
public:
    GroupNotFound(const QString& message) : NotWorkingRequest(message) {}
    QString what() const { return "Group not found. Exception: " + _message; }

};

#endif
