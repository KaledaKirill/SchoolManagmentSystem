#include "ScheduleModel.h"

ScheduleModel::ScheduleModel(QObject* parent)
    : QAbstractTableModel(parent)
{
}

int ScheduleModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 7;
    }
    return 7;
}

int ScheduleModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return 6;
}

QVariant ScheduleModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        int dayOfWeek = index.column();
        int lessonNumber = index.row() + 1;

        QPair<int, int> key(dayOfWeek + 1, lessonNumber);
        return schedule.value(key, "");
    }

    return QVariant();
}

QVariant ScheduleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            static const QStringList days = {"понедельник", "вторник", "среда", "четверг", "пятница", "суббота"};
            return days.value(section);
        } else if (orientation == Qt::Vertical) {
            static const QStringList times = {
                                              "9:00-9:45", "10:00-10:45", "11:00-11:45", "12:00-12:45",
                                              "13:00-13:45", "14:00-14:45", "15:00-15:45"};
            return times.value(section);
        }
    }
    return QVariant();
}

Qt::ItemFlags ScheduleModel::flags(const QModelIndex& index) const
{
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool ScheduleModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole) {
        int dayOfWeek = index.column();
        int lessonNumber = index.row() + 1;
        QString newSubject = value.toString();

        if (schedule.contains({dayOfWeek + 1, lessonNumber})) {
            updateLesson(dayOfWeek + 1, lessonNumber, newSubject);
        } else {
            addLesson(newSubject, dayOfWeek + 1, lessonNumber);
        }

        schedule[{dayOfWeek + 1, lessonNumber}] = newSubject;
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

void ScheduleModel::loadSchedule(const QString& group)
{
    beginResetModel();
    this->group = group;
    schedule = scheduleDAO.getScheduleForGroup(group);
    endResetModel();
}

void ScheduleModel::addLesson(const QString& subject, int dayOfWeek, int number)
{
    scheduleDAO.addLesson(subject, group, dayOfWeek, number);
    schedule.insert({dayOfWeek, number}, subject);
}

void ScheduleModel::deleteLesson(int dayOfWeek, int number)
{
    QString subject = schedule.value({dayOfWeek, number});
    scheduleDAO.deleteLesson(subject, group, dayOfWeek, number);
    schedule.remove({dayOfWeek, number});
}

void ScheduleModel::updateLesson(int dayOfWeek, int number, const QString& newSubject)
{
    QString oldSubject = schedule.value({dayOfWeek, number});
    scheduleDAO.updateLesson(oldSubject, newSubject, group, dayOfWeek, number);
}
