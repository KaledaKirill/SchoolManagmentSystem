#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QString>

class BaseException
{
public:
    BaseException(const QString& message) : _message(message) {}
    virtual ~BaseException() noexcept = default;

    virtual QString what() const { return "Exception: " + _message; }

protected:
    QString _message;

};

#endif
