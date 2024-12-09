#ifndef JOURNALMODEL_H
#define JOURNALMODEL_H

#include "../Entity/Student.h"
#include "../Entity/validator.h"
#include "../DAO/igradesdao.h"
#include "../../Collections/mylist.h"

#include <QAbstractTableModel>
#include <QDate>
#include <QDebug>
#include <QScopedPointer>

class JournalModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit JournalModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    void setStudentList(const QList<Student>& externalStudents);
    void setSubject(const QString& subjectName);
    void setDates(const MyList<QDate>& dates);
    void addDate(const QDate& date);

private:
    QString currentSubject;

    MyList<QDate> dates;
    QList<Student> students;

    QScopedPointer<IGradesDAO> gradesDAO;
    Validator validator;

    void addGrade(Student &student, const Grade &grade);
    void deleteGrade(Student &student, const Grade &grade);
    void updateGrade(Student &student, const Grade &oldGrade, const Grade &newGrade);
    bool processStudentGrade(Student &student, int oldGradeValue, const Grade &newGrade, bool removeGrade);

};

#endif
