#ifndef COMMANDEXCEPTION_H
#define COMMANDEXCEPTION_H

#include "baseexception.h"

class CommandException : public BaseException
{
public:
    CommandException(const QString& message) : BaseException(message) {}
    QString what() const { return "Not working Undo/Redo. Exception: " + _message; }

};

#endif
