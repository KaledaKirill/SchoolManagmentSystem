#ifndef ADMINISTRATORNOTFOUND_H
#define ADMINISTRATORNOTFOUND_H

#include <QString>

class AdministratorNotFound
{

public:
    AdministratorNotFound(const QString& message) : _message(message) {}
    QString what() const { return "Administraot not found. Exception: " + _message; }

private:
    QString _message;
};

#endif
