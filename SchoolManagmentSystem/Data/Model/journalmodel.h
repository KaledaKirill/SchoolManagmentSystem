#ifndef JOURNALMODEL_H
#define JOURNALMODEL_H

#include "../Entity/Student.h"
#include "../DAO/igradesdao.h"

#include <QAbstractTableModel>
#include <QDate>
#include <QDebug>
#include <QScopedPointer>

class JournalModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit JournalModel(QObject* parent = nullptr);

    // Методы для QAbstractTableModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Методы для работы с журналом
    void setStudentList(const QList<Student>& externalStudents); // Передача списка по значению
    void setSubject(const QString& subjectName);
    void setDates(const QList<QDate>& dates);
    void addDate(const QDate& date);

private:
    QString currentSubject;

    QList<QDate> dates;
    QList<Student> students; // Обычный список студентов

    QScopedPointer<IGradesDAO> gradesDAO;
};

#endif // JOURNALMODEL_H
