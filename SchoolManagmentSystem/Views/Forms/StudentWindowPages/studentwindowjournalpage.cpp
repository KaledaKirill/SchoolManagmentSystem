#include "studentwindowjournalpage.h"
#include "ui_studentwindow.h"


StudentWindowJournalPage::StudentWindowJournalPage(Ui::StudentWindow *studentWindow, const Student &student)
    : studentJournalModel(new StudentJournalModel),
    studentResJournalModel(new StudentResJournalModel),
    gradesService(new GradesService),
    ui(studentWindow),
    student(student)
{
    ui->resTableView->setModel(studentResJournalModel);
    ui->journalTableView->setModel(studentJournalModel);
    studentResJournalModel->setStudent(student);
    studentJournalModel->setStudent(student);

    showStudentData();
}

void StudentWindowJournalPage::showStudentData()
{
    if (student.getStudentName().isEmpty() || student.getGroup().isEmpty())
    {
        ui->nameLabel->setText("ФИО: данные отсутствуют");
        ui->groupLabel->setText("Класс: данные отсутствуют");
        ui->avgGradeLabel->setText("Средний балл: данные отсутствуют");
        return;
    }

    ui->nameLabel->setText("ФИО: " + student.getStudentName());
    ui->groupLabel->setText("Класс: " + student.getGroup());
    double avgGrade = gradesService->getStudentAverageGradeForYear(student);
    ui->avgGradeLabel->setText("Средний балл: " + QString::number(avgGrade, 'f', 2));
}


StudentWindowJournalPage::~StudentWindowJournalPage()
{
    delete studentResJournalModel;
    delete studentJournalModel;
    delete gradesService;
}
