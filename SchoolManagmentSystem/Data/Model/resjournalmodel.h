#ifndef RESJOURNALMODEL_H
#define RESJOURNALMODEL_H

#include "gradesservice.h"

#include <QAbstractTableModel>

class ResJournalModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit ResJournalModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    void setStudentList(const QList<Student>& externalStudents);
    void setSubject(const QString& subjectName);

private:
    const QScopedPointer<GradesService> gradesService;
    QList<Student> students;
    QString currentSubject;
};

#endif
