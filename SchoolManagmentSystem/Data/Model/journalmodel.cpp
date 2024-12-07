#include "journalmodel.h"
#include "../Entity/grade.h"
#include "../DAO/gradesdao.h"

#include <QDebug>
#include <qmessagebox.h>

JournalModel::JournalModel(QObject* parent)
    : QAbstractTableModel(parent),
    gradesDAO(new GradesDAO) {}

int JournalModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return students.size();
}

int JournalModel::columnCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return dates.size();
}

QVariant JournalModel::data(const QModelIndex& index, int role) const {
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

QVariant JournalModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        if (section >= 0 && section < dates.size()) {
            return dates.at(section).toString("dd.MM.yyyy");
        }
    } else if (orientation == Qt::Vertical) {
        if (section >= 0 && section < students.size()) {
            return students.at(section).getStudentName();
        }
    }

    return QVariant();
}

bool JournalModel::setData(const QModelIndex& index, const QVariant& value, int role) {
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    bool isNumber;
    int intValue = value.toInt(&isNumber);

    if (!isNumber || !validator.isGradeValueValid(intValue))
    {
        QMessageBox::warning(0, "Неуспешная операция", "Такой отметки не существует или значение некорректно");
        return false;
    }

    int row = index.row();
    int col = index.column();

    if (row >= students.size() || col >= dates.size())
        return false;

    Student& student = students[row];
    QDate date = dates[col];

    QVariant currentValue = data(index, Qt::DisplayRole);
    bool gradeUpdated = false;
    for (Grade& grade : student.getGradesList()) {
        if (grade.getDate() == date && grade.getSubject() == currentSubject) {
            if (value == currentValue)
            {
                gradesDAO->deleteGrade(grade);
                gradeUpdated = true;
                break;
            }

            Grade newGrade(value.toInt(), date, currentSubject, student.getStudentName());
            gradesDAO->updateGrade(grade, newGrade);
            student.updateGrade(grade, newGrade);
            gradeUpdated = true;
            break;
        }
    }

    if (!gradeUpdated) {
        Grade newGrade(value.toInt(), date, currentSubject, student.getStudentName());
        student.addGrade(newGrade);
        gradesDAO->addGrade(newGrade);
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

void JournalModel::setStudentList(const QList<Student>& externalStudents)
{
    students = externalStudents;
    emit layoutChanged();
}

void JournalModel::setSubject(const QString& subjectName) {
    currentSubject = subjectName;
    emit layoutChanged();
}

void JournalModel::setDates(const MyList<QDate> &dates)
{
    this->dates = dates;
    emit layoutChanged();
}

void JournalModel::addDate(const QDate& date) {
    if (!date.isValid())
        return;

    if (!dates.contains(date)) {
        dates.append(date);
        emit layoutChanged();
    }
}
