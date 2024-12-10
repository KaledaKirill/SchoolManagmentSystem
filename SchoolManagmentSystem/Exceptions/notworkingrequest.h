#ifndef NOTWORKINGREQUEST_H
#define NOTWORKINGREQUEST_H

#include "baseexception.h"

class NotWorkingRequest : public BaseException
{
public:
    NotWorkingRequest(const QString& message) : BaseException(message) {}
    QString what() const { return "Not working request. Exception: " + _message; }

};

#endif
