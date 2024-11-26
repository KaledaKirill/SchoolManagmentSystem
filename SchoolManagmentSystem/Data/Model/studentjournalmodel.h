#ifndef STUDENTJOURNALMODEL_H
#define STUDENTJOURNALMODEL_H

#include "../Entity/student.h"

#include <QAbstractTableModel>
#include <QSet>
#include <QMap>

class StudentJournalModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit StudentJournalModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setStudent(const Student& student);

private:
    Student currentStudent;
    QSet<QString> subjects;
    QList<QDate> dates;
    QMap<QString, QMap<QDate, int>> gradesMatrix;

    void initializeData();

};

#endif
