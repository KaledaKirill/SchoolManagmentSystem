#include "resjournalmodel.h"

ResJournalModel::ResJournalModel(QObject* parent)
    : QAbstractTableModel(parent), gradesService(new GradesService) {}

int ResJournalModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return students.size();
}

int ResJournalModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return 5;
}

QVariant ResJournalModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= students.size() || index.column() >= 5)
        return QVariant();

    const Student& student = students.at(index.row());

    if (role == Qt::DisplayRole) {
        if (index.column() < 4) { // Четверти
            double average = gradesService->getAverageGradeForQuarter(student, currentSubject, index.column() + 1);
            return average > 0.0 ? QString::number(average, 'f', 2) : "не аттестован";
        } else if (index.column() == 4) { // За год
            double average = gradesService->getAverageGradeForYear(student, currentSubject);
            return average > 0.0 ? QString::number(average, 'f', 2) : "не аттестован";
        }
    }

    return QVariant();
}

QVariant ResJournalModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0: return "1 четверть";
        case 1: return "2 четверть";
        case 2: return "3 четверть";
        case 3: return "4 четверть";
        case 4: return "год";
        }
    } else if (orientation == Qt::Vertical) {
        if (section >= 0 && section < students.size()) {
            return students.at(section).getStudentName();
        }
    }

    return QVariant();
}

void ResJournalModel::setStudentList(const QList<Student>& externalStudents) {
    students = externalStudents;
    emit layoutChanged();
}

void ResJournalModel::setSubject(const QString& subjectName) {
    currentSubject = subjectName;
    emit layoutChanged();
}
