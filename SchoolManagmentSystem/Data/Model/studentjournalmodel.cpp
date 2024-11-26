#include "studentjournalmodel.h"

StudentJournalModel::StudentJournalModel(QObject* parent)
    : QAbstractTableModel(parent) {}

int StudentJournalModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return subjects.size();
}

int StudentJournalModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid()) {
        return 0;
    }
    return dates.size();
}

QVariant StudentJournalModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    QString subject = *std::next(subjects.begin(), index.row());
    QDate date = dates.at(index.column());

    if (gradesMatrix.contains(subject) && gradesMatrix[subject].contains(date)) {
        return gradesMatrix[subject][date];
    }

    return QVariant();
}

QVariant StudentJournalModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        return dates.at(section).toString("dd.MM.yyyy");
    } else if (orientation == Qt::Vertical) {
        return *std::next(subjects.begin(), section);
    }

    return QVariant();
}

void StudentJournalModel::setStudent(const Student& student)
{
    beginResetModel();
    currentStudent = student;
    initializeData();
    endResetModel();
}

void StudentJournalModel::initializeData()
{
    subjects.clear();
    dates.clear();
    gradesMatrix.clear();

    for (const Grade& grade : currentStudent.getGradesList())
    {
        subjects.insert(grade.getSubject());
        if (!dates.contains(grade.getDate())) {
            dates.append(grade.getDate());
        }
        gradesMatrix[grade.getSubject()][grade.getDate()] = grade.getGradeValue();
    }

    std::sort(dates.begin(), dates.end());
}
