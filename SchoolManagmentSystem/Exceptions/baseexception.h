#ifndef BASEEXCEPTION_H
#define BASEEXCEPTION_H

#include <QString>

class BaseException
{
public:
    BaseException(const QString& message) : message(message) {}
    virtual ~BaseException() noexcept = default;

    virtual QString what() const { return "Exception: " + message; }

protected:
    QString message;

};

#endif
