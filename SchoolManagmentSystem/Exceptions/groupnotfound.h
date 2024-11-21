#ifndef GROUPNOTFOUND_H
#define GROUPNOTFOUND_H

#include <QString>

class GroupNotFound
{
public:
    GroupNotFound(const QString& message) : _message(message) {}
    QString what() const { return "Group not found. Exception: " + _message; }

private:
    QString _message;

};

#endif
