#ifndef STUDENTRESJOURNALMODEL_H
#define STUDENTRESJOURNALMODEL_H

#include "../Entity/student.h"
#include "GradesService.h"

#include <QAbstractTableModel>

class StudentResJournalModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit StudentResJournalModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setStudent(const Student& student);

private:
    const QScopedPointer<GradesService> gradesService;
    Student currentStudent;
    QList<QString> subjects;
    QList<QString> periods;
    QMap<QString, QMap<QString, QVariant>> gradesMatrix;

    void initializeData();
};

#endif
