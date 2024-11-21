#ifndef NOTWORKINGREQUEST_H
#define NOTWORKINGREQUEST_H

#include <QString>

class NotWorkingRequest
{
public:
    NotWorkingRequest(const QString& message) : _message(message) {}
    QString what() const { return "Not working request. Exception: " + _message; }

private:
    QString _message;

};

#endif
