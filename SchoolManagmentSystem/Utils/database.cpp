#include "DataBase.h"

DataBase* DataBase::getInstance()
{
    static DataBase instance;
    return &instance;
}

void DataBase::connect()
{
    _dataBase = QSqlDatabase::addDatabase("QSQLITE");
    QString path = "../School.db";
    _dataBase.setDatabaseName(path);
    if (_dataBase.open()) {
        _log.info(__FILE__, "Connection with database was successful");
        createTables();
    } else {
        _log.error(__FILE__, "Connection with database wasn't successful. Path to DB: " + path);
        exit(EXIT_FAILURE);
    }
}

void DataBase::createTables()
{
    QSqlQuery query;

    QString createGradesTable =
        "CREATE TABLE IF NOT EXISTS GRADES ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "value INTEGER, "
        "date TEXT, "
        "student_id INTEGER, "
        "subject_id INTEGER"
        ");";

    if (!query.exec(createGradesTable)) {
        _log.error(__FILE__, "Error creating GRADES table: " + query.lastError().text());
        exit(EXIT_FAILURE);
    } else {
        _log.info(__FILE__, "GRADES table created successfully.");
    }

    QString createSubjectsTable =
        "CREATE TABLE IF NOT EXISTS SUBJECTS ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "group_id INTEGER"
        ");";

    if (!query.exec(createSubjectsTable)) {
        _log.error(__FILE__, "Error creating SUBJECTS table: " + query.lastError().text());
        exit(EXIT_FAILURE);
    } else {
        _log.info(__FILE__, "SUBJECTS table created successfully.");
    }

    QString createStudentsTable =
        "CREATE TABLE IF NOT EXISTS STUDENTS ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL, "
        "group_id INTEGER"
        ");";

    if (!query.exec(createStudentsTable)) {
        _log.error(__FILE__, "Error creating STUDENTS table: " + query.lastError().text());
        exit(EXIT_FAILURE);
    } else {
        _log.info(__FILE__, "STUDENTS table created successfully.");
    }

    QString createGroupsTable =
        "CREATE TABLE IF NOT EXISTS GROUPS ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "name TEXT NOT NULL"
        ");";

    if (!query.exec(createGroupsTable)) {
        _log.error(__FILE__, "Error creating GROUPS table: " + query.lastError().text());
        exit(EXIT_FAILURE);
    } else {
        _log.info(__FILE__, "GROUPS table created successfully.");
    }
}
