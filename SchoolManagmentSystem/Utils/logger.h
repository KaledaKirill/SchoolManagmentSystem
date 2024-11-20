#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QDateTime>

class Logger
{

public:
    void info(const char* file, const QString& message);
    void debug(const char* file, const QString& message);
    void warning(const char* file, const QString& message);
    void error(const char* file, const QString& message);

private:
    std::string getCurrentDateTime();

};

#endif
