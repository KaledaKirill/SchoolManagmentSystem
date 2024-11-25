#ifndef GRADESSERVICE_H
#define GRADESSERVICE_H

#include "../../Data/Entity/student.h"
#include "DatesService.h"

class GradesService
{
public:
    GradesService();

    double getAverageGradeForQuarter(const Student& student, const QString& subject, int quarter) const;
    double getAverageGradeForYear(const Student& student, const QString& subject) const;
    double getStudentAverageGradeForYear(const Student& student) const;

private:
    const DatesService datesService;
};

#endif
