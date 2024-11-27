#include "logger.h"
#include <iostream>
#include <QTextStream>

void Logger::info(const char* file, const QString& message)
{
    std::cout << "[INFO]  " << getCurrentDateTime() << "  " << file << "  " << message.toLocal8Bit().constData() << std::endl;
}

void Logger::debug(const char* file, const QString& message)
{
    std::cout << "[DEBUG]  " << getCurrentDateTime() << "  " << file << "  " << message.toLocal8Bit().constData() << std::endl;
}

void Logger::warning(const char* file, const QString& message)
{
    std::cerr << "[WARNING]  " << getCurrentDateTime() << "  " << file << "  " << message.toLocal8Bit().constData() << std::endl;
}

void Logger::error(const char* file, const QString& message)
{
    std::cerr << "[ERROR]  " << getCurrentDateTime() << "  " << file << "  " << message.toLocal8Bit().constData() << std::endl;
}

std::string Logger::getCurrentDateTime()
{
    return QDateTime::currentDateTime().toString("dd.MM.yy HH:mm:ss").toLocal8Bit().constData();
}
