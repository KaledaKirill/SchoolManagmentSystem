#ifndef SCHEDULEMODEL_H
#define SCHEDULEMODEL_H

#include "../DAO/scheduledao.h"
#include "../Entity/validator.h"

#include <QAbstractTableModel>

class ScheduleModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ScheduleModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

    void loadSchedule(const QString& group);
    void addLesson(const QString& subject, int dayOfWeek, int number);
    void deleteLesson(int dayOfWeek, int number);
    void updateLesson(int dayOfWeek, int number, const QString& newSubject);

private:
    ScheduleDAO scheduleDAO;
    QString group;
    QHash<QPair<int, int>, QString> schedule;

    Validator validator;

};

#endif
