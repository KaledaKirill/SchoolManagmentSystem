#include "journalmodel.h"
#include "../Entity/Grade.h"

JournalModel::JournalModel(QObject* parent)
    : QAbstractTableModel(parent), currentQuarter(1)
{
}

int JournalModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return students.size();
}

int JournalModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return dates.size();
}

QVariant JournalModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= students.size() || index.column() >= dates.size())
        return QVariant();

    const Student& student = students.at(index.row());
    const QDate& date = dates.at(index.column());

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        for (const Grade& grade : student.getGradesList()) {
            if (grade.getDate() == date && grade.getSubject() == currentSubject) {
                return grade.getGradeValue();
            }
        }
    }

    return QVariant();
}

bool JournalModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int row = index.row();
    int col = index.column();

    if (row >= students.size() || col >= dates.size())
        return false;

    Student& student = students[row];
    QDate date = dates[col];

    // Обновляем или добавляем оценку
    bool gradeUpdated = false;
    for (Grade& grade : student.getGradesList()) {
        if (grade.getDate() == date && grade.getSubject() == currentSubject) {
            grade.setGradeValue(value.toInt());
            gradeUpdated = true;
            break;
        }
    }

    if (!gradeUpdated) {
        Grade newGrade(value.toInt(), date, currentSubject, student.getStudentName());
        student.addGrade(newGrade);
    }

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags JournalModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsEditable;
}

void JournalModel::setSubject(const QString& subjectName)
{
    currentSubject = subjectName;
    emit layoutChanged();
}

void JournalModel::setGroup(const QString& groupName)
{
    currentGroup = groupName;
    emit layoutChanged();
}

void JournalModel::setQuarter(int quarter)
{
    currentQuarter = quarter;
    // Здесь можно фильтровать даты по текущей четверти
    emit layoutChanged();
}

void JournalModel::loadGrades(const QList<Student>& newStudents)
{
    students = newStudents;
    emit layoutChanged();
}

void JournalModel::addGrade(const QString& studentName, const QDate& date, int gradeValue)
{
    for (Student& student : students) {
        if (student.getStudentName() == studentName) {
            Grade newGrade(gradeValue, date, currentSubject, studentName);
            student.addGrade(newGrade);
            emit layoutChanged();
            return;
        }
    }
}

void JournalModel::addDate(const QDate& date)
{
    if (!dates.contains(date)) {
        dates.append(date);
        emit layoutChanged();
    }
}
