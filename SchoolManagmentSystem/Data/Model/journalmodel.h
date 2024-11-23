#ifndef JOURNALMODEL_H
#define JOURNALMODEL_H

#include "../Entity/Student.h"

#include <QAbstractTableModel>
#include <QDate>

class JournalModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit JournalModel(QObject* parent = nullptr);

    // Методы для QAbstractTableModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Методы для работы с журналом
    void setSubject(const QString& subjectName);
    void setGroup(const QString& groupName);
    void setQuarter(int quarter);
    void loadGrades(const QList<Student>& students);

    void addGrade(const QString& studentName, const QDate& date, int gradeValue);
    void addDate(const QDate& date);

private:
    QString currentGroup;
    QString currentSubject;
    int currentQuarter;

    QList<QDate> dates; // Даты текущей четверти
    QList<Student> students; // Список учеников с их оценками
};

#endif

