#include "StudentResJournalModel.h"
#include <QDebug>

StudentResJournalModel::StudentResJournalModel(QObject* parent)
    : QAbstractTableModel(parent),
    gradesService(new GradesService) {}

int StudentResJournalModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return subjects.size();
}

int StudentResJournalModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid()) {
        return 0;
    }
    return periods.size();
}

QVariant StudentResJournalModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }

    QString subject = subjects.at(index.row());
    QString period = periods.at(index.column());

    if (gradesMatrix.contains(subject) && gradesMatrix[subject].contains(period)) {
        return gradesMatrix[subject][period];
    }

    return QVariant();
}

QVariant StudentResJournalModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        return periods.at(section);
    } else if (orientation == Qt::Vertical) {
        return subjects.at(section);
    }

    return QVariant();
}

void StudentResJournalModel::setStudent(const Student& student) {
    beginResetModel();
    currentStudent = student;
    initializeData();
    endResetModel();
}

void StudentResJournalModel::initializeData()
{
    subjects.clear();
    periods.clear();
    gradesMatrix.clear();

    periods = {"1 четверть", "2 четверть", "3 четверть", "4 четверть", "Год"};

    QSet<QString> uniqueSubjects;
    for (const Grade& grade : currentStudent.getGradesList()) {
        uniqueSubjects.insert(grade.getSubject());
    }
    subjects = uniqueSubjects.values();

    for (const QString& subject : subjects) {
        for (int quarter = 1; quarter <= 4; ++quarter) {
            double averageGrade = gradesService->getAverageGradeForQuarter(currentStudent, subject, quarter);
            gradesMatrix[subject][QString("%1 четверть").arg(quarter)] = averageGrade >= 0 ? averageGrade : QVariant();
        }

        double yearAverage = gradesService->getAverageGradeForYear(currentStudent, subject);
        gradesMatrix[subject]["Год"] = yearAverage >= 0 ? yearAverage : QVariant();
    }
}
